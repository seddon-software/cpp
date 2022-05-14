/*
 *  To run on command line:
 *        simulator2.exe run
 * 
 *  To debug, just run inside vscode or from the command line type:
 *        simulator2.exe
 * 
 *  In debug mode, output uses cout, in normal mode output uses ncurses.
 *  Commands available in simulator are:
 *          CODE n                          move cursor to line n of the code
 *          GLOBAL symbol value             set global symbol to given value
 *          LOAD CODE                       display code on terminal
 *          LOAD STACK n                    display stack with n slots on terminal
 *          MESSAGE word1 word2 ... wordn   display message under the stack on terminal
 *          PUSH_NEW variable               define a variable for use in simulation (order important)
 *          VISIBLE                         make variable visible on terminal
 *          PUSH_RETURN name                define name (variable) of return stack
 *          VALUE variable value            set variable to given value and display
 *          WAIT                            wait for user input (any key) before continuing
 *          END                             add code here to run at end of simulation
 *          LOOP n m                        jump back n instructions and repeat code m times
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <tuple>
#include <fstream>
#include <cstdio>
#include <wchar.h>
#include <locale.h>
#include <curses.h>
#include <cstdlib>

using namespace std;


//#define FILENAME "is_leap.txt"
// #define FILENAME "one_too_many.txt"
//#define FILENAME "z.txt"
#define FILENAME "z2.txt"

int output(int row, int col, const string& text);
void wait();

bool VSCODE = false;
bool DEBUG = false;

void debug(const string& s)
{
    if(DEBUG)
    {
        string blanks(60,' ');
        output(3, 70, blanks);
        output(3, 70, s);
        wait();
    }
}

void wait()
{
    if(VSCODE)
    {
        getchar();
    }
    else
    { 
        getch();
    }
}

int draw(int row, int col, const string& s)
{
    move(row++, col);
    addstr(s.c_str());
    return row;
}

void draw_stack(int row, int col, int boxes)
{
    row = draw(row, col, "┌─────────┐");
    for(int i = 0; i < boxes-1; i++)
    {
        row = draw(row, col, "│         │");
        row = draw(row, col, "├─────────┤");
    }
    row = draw(row, col, "│         │");
    row = draw(row, col, "└─────────┘");
    refresh();
}

int output(int row, int col, const string& text)
{
    if(VSCODE)
    {
        cout << text.c_str() << "\r" << endl;
    }
    else
    {
        mvprintw(row++, col, text.c_str());
    }
    return row;
}

string& trim(string& str)
{
    str.erase(0, str.find_first_not_of(" ")); // left trim
    str.erase(str.find_last_not_of(" ") + 1); // right trim
    return str;
}

auto get_instructions(ifstream& ifs)
{
    vector<vector<string>> instructions;
    while(ifs)
    {
        string text;
        getline(ifs, text);
        if(text.empty()) continue;
        if(text.starts_with("%END")) break;

        char space_char = ' ';
        vector<string> words{};
        stringstream sstream(text);
        string word;
        while (std::getline(sstream, word, space_char)){
            words.push_back(word);
        }
        instructions.push_back(words);
    }
    return instructions;
}

void print_code(int row, int col, auto& code)
{
    for(auto& line: code)
    {
        output(row++, col, line);
    }
}

auto get_code(ifstream& ifs)
{
    int line = 1;
    list<string> code;
    while(ifs)
    {
        string text;
        getline(ifs, text);
        if(text.starts_with("%CODE")) continue;
        if(text.starts_with("%INSTRUCTIONS")) break;
        // add line numbers
        stringstream ss;
        ss << line++ << ":  " << text;
        text = ss.str();
        code.push_back(text);
    }
    return code;
}

auto read_file(const string& fileName)
{
    ifstream ifs(fileName.c_str()); 
    return ifs;
}

void initialize_ncurses()
{
    addstr("");
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    curs_set(0);        // hide cursor
}

auto setup_colors()
{
    try
    {
        if(start_color() != OK) throw exception();
    }
    catch(const std::exception& e)
    {
        std::cerr << "no colors" << '\n';
        exit(1);
    }
    map<string, int> colors;
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    colors["WHITE"] = 1;
    colors["GREEN"] = 2;
    colors["RED"] = 3;
    wbkgd(stdscr, COLOR_PAIR(1));
    return colors; 
}

void do_code(auto& instruction, auto& code_lines, auto& globals)
{
    static int previous_line = 0;
    auto line = stoi(instruction[1]);
    int current_color = globals["CURRENT_COLOR"];
    attrset(COLOR_PAIR(current_color));
    output(line, globals["CODE_COL"], code_lines[line-1]);
    if(previous_line > 0)
    {
       attrset(COLOR_PAIR(1));
        if(!VSCODE)
            output(previous_line, globals["CODE_COL"], code_lines[previous_line-1]);
    }
    previous_line = line;
    attrset(COLOR_PAIR(current_color));
//    attrset(COLOR_PAIR(1));
    wait();
}

void do_global(auto& instruction, auto& globals)
{
    auto symbol = instruction[1];
    auto value = instruction[2];
    globals[symbol] = stoi(value);
}

void do_load(auto& instruction, auto& code, auto& globals)
{
    auto what = instruction[1];
    if(what == "CODE") print_code(1, globals["CODE_COL"], code);
    if(what == "STACK") 
    {
        auto size = stoi(instruction[2]);
        draw_stack(globals["STACK_ROW"], globals["STACK_COL"], size);
    }
    if(what == "RETURN_STACK") 
    {
        auto size = stoi(instruction[2]);
        draw_stack(globals["RETURN_STACK_ROW"], globals["RETURN_STACK_COL"], size);
    }
}

void do_message(auto& instruction, auto& globals)
{
    string text("");
    for(unsigned i = 1; i < instruction.size(); i++)
    {
        text += instruction[i] + " "s;
    }
    attrset(COLOR_PAIR(3));
    string blanks(60,' ');
    output(globals["MESSAGE_ROW"], globals["MESSAGE_COL"], blanks);
    output(globals["MESSAGE_ROW"], globals["MESSAGE_COL"], text);
        attrset(COLOR_PAIR(1));
}

void do_visible(auto& instruction, auto& stack_position, auto& variables, auto& globals)
{
    string variable = instruction[1];
    int row = variables[variable];
    output(row, globals["VARIABLE_COL"], variable);
}

void do_push_return(auto& instruction, int& stack_position, auto& variables, auto& globals)
{
    string variable = instruction[1];
    int size = variables.size(); 
    int row = globals["RETURN_STACK_ROW"] + 2*size - 1;
    variables[variable] = row;
    stack_position++;
}

void do_push_new(auto& instruction, int& stack_position, auto& variables, auto& globals)
{
    string variable = instruction[1];
    int size = variables.size(); 
    int row = globals["STACK_ROW"] + 2*size + 1;
    variables[variable] = row;
    stack_position++;
}

void do_value(auto& instruction, auto& variables, auto& values, auto& globals)
{
    string variable = instruction[1];
    string value = instruction[2];
    // value will be a value or variable name
    if(values.contains(value))
    {
        value = values[value];
    }
    // update variable value
    values[variable] = value;
    int row = variables[variable];
    string blanks(6,' ');
    output(row, globals["VALUE_COL"], blanks);
    output(row, globals["VALUE_COL"], value);
}

void do_add(auto& instruction, auto& variables, auto& values)
{
    string variable = instruction[1];
    string value = instruction[2];
    int new_value = stoi(values[variable]);
    new_value++;
    values[variable] = to_string(new_value);
}

void do_color(auto& instruction, auto& colors, auto& globals)
{
    string color = instruction[1];
    int color_code = colors[color.c_str()];
    globals["CURRENT_COLOR"] = color_code;
    attrset(COLOR_PAIR(color_code));
}

void process_instructions(auto& instructions, auto& code)
{
    vector<string> code_lines(code.begin(), code.end());
    map<string, int> globals;
    map<string, int> variables;
    map<string, string> values;
    int stack_position = 1;
    int repeats = 0;
    bool loop = false;
    int jump_back = 0;
    auto colors = setup_colors();

    for(unsigned index = 0; index < instructions.size(); index++)
    {
        auto& instruction = instructions[index];
        auto& command = instruction[0];
        debug("index = "s + to_string(index) + ": " + instruction[0] + " " + instruction[1]);
        if(command == "CODE") do_code(instruction, code_lines, globals);
        if(command == "GLOBAL") do_global(instruction, globals);
        if(command == "LOAD") do_load(instruction, code, globals);
        if(command == "MESSAGE") do_message(instruction, globals);
        if(command == "PUSH_NEW") do_push_new(instruction, stack_position, variables, globals);
        if(command == "VISIBLE") do_visible(instruction, stack_position, variables, globals);
        if(command == "PUSH_RETURN") do_push_return(instruction, stack_position, variables, globals);
        if(command == "VALUE") do_value(instruction, variables, values, globals);
        if(command == "ADD") do_add(instruction, variables, values);
        if(command == "COLOR") do_color(instruction, colors, globals);
        if(command == "WAIT") wait();
        if(command == "END") {} // used for debugging
        if(command == "LOOP") 
        {   
            debug("loop: "s + to_string(jump_back) + "," + to_string(repeats));
            if(loop == true && repeats > 0)
            {
                index -= jump_back;
                repeats--;
            }

            // if(loop == false && repeats == 0)
            if(repeats == 0)
            {
                loop = true;
                jump_back  = stoi(instruction[1]) + 1;
                repeats = stoi(instruction[2]) + 1;
                index -= jump_back;
                repeats--; 
            }
        }
    }
}

int main(int argc, char** argv) 
{
    if(argc == 1) VSCODE = true;
    if(argc == 2)
    {
        if("debug"s == argv[1]) DEBUG = true;
    }
    
    initialize_ncurses();
//    setup_colors();
    auto ifs = read_file(FILENAME);
    auto code = get_code(ifs);
    auto instructions = get_instructions(ifs);
    process_instructions(instructions, code);
    clear();
    endwin();
}

