#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <tuple>
#include <fstream>
#include <wchar.h>
#include <locale.h>
#include <curses.h>
#include <cstdlib>

using namespace std;


//#define FILENAME "is_leap.txt"
#define FILENAME "one_too_many.txt"
// #define FILENAME "z.txt"


bool DEBUG = false;
void wait()
{
    if(DEBUG) 
        getch();
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
    mvprintw(row++, col, text.c_str());
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

void setup_colors()
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
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_YELLOW);
    wbkgd(stdscr, COLOR_PAIR(1)); 
}

void do_code(auto& instruction, auto& code_lines, auto& globals)
{
    static int previous_line = 0;
    auto line = stoi(instruction[1]);
    attrset(COLOR_PAIR(2));
    output(line, globals["CODE_COL"], code_lines[line-1]);
    if(previous_line > 0)
    {
        attrset(COLOR_PAIR(1));
        output(previous_line, globals["CODE_COL"], code_lines[previous_line-1]);
    }
    previous_line = line;
    attrset(COLOR_PAIR(1));
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
    int row = globals["RETURN_STACK_ROW"] + 2*size + 1;
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

auto do_loop(auto& instruction, auto& variables, auto& globals)
{
    int jump_back  = stoi(instruction[1]);
    int repeats  = stoi(instruction[2]);
    tuple result = (jump_back, repeats);
    // string value = next((instruction));
    // int row = variables[variable];
    // string blanks(6,' ');
    // output(row, globals["VALUE_COL"], blanks);
    // output(row, globals["VALUE_COL"], value);
}

void do_value(auto& instruction, auto& variables, auto& globals)
{
    string variable = instruction[1];
    string value = instruction[2];
    int row = variables[variable];
    string blanks(6,' ');
    output(row, globals["VALUE_COL"], blanks);
    output(row, globals["VALUE_COL"], value);
}

void process_instructions(auto& instructions, auto& code)
{
    vector<string> code_lines(code.begin(), code.end());
    map<string, int> globals;
    map<string, int> variables;
    int stack_position = 1;

    for(unsigned i = 0; i < instructions.size(); i++)
    {
        auto& instruction = instructions[i];
        auto& command = instruction[0];
        attrset(COLOR_PAIR(1));
        if(command == "CODE") do_code(instruction, code_lines, globals);
        if(command == "GLOBAL") do_global(instruction, globals);
        if(command == "LOAD") do_load(instruction, code, globals);
        if(command == "MESSAGE") do_message(instruction, globals);
        if(command == "PUSH_NEW") do_push_new(instruction, stack_position, variables, globals);
        if(command == "VISIBLE") do_visible(instruction, stack_position, variables, globals);
        if(command == "PUSH_RETURN") do_push_return(instruction, stack_position, variables, globals);
        if(command == "VALUE") do_value(instruction, variables, globals);
        if(command == "WAIT") wait();
        if(command == "END") {} // used for debugging
        if(command == "LOOP") do_loop(instruction, variables, globals);
    }
}

int main(int argc, char** argv) 
{
    if(argc > 1) DEBUG = true;
    initialize_ncurses();
    setup_colors();
    auto ifs = read_file(FILENAME);
    auto code = get_code(ifs);
    auto instructions = get_instructions(ifs);
    process_instructions(instructions, code);
    clear();
    endwin();
}

