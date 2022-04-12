#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <wchar.h>
#include <locale.h>
#include <curses.h>
#include <cstdlib>

using namespace std;


// #define STACK_COL 50
// #define MESSAGE_ROW 25
// #define MESSAGE_COL 50
#define FILENAME "one_too_many2.txt"
// #define VALUE_COL STACK_COL+4
// #define VARIABLE_COL STACK_COL+12

void wait()
{
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
    list<list<string>> instructions;
    while(ifs)
    {
        string text;
        getline(ifs, text);
        if(text.empty()) continue;
        if(text.starts_with("%END")) break;

        char space_char = ' ';
        list<string> words{};
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

auto next(auto& theList)
{
    auto word = theList.front();
    theList.pop_front();
    return word;
}

void do_code(auto& instruction, auto& code_lines, auto& globals)
{
    static int previous_line = 0;
    auto line = stoi(next(instruction));
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
    auto symbol = next(instruction);
    auto value = next(instruction);
    globals[symbol] = stoi(value);
}

void do_load(auto& instruction, auto& code, auto& globals)
{
    auto what = next(instruction);
    if(what == "CODE") print_code(1, globals["CODE_COL"], code);
    if(what == "STACK") 
    {
        auto size = stoi(next(instruction));
        draw_stack(1, globals["STACK_COL"], size);
    }
}

void do_message(auto& instruction, auto& globals)
{
    string text("");
    while(!instruction.empty())
    {
        text += next(instruction) + " "s;
    }
    attrset(COLOR_PAIR(3));
    string blanks(60,' ');
    output(globals["MESSAGE_ROW"], globals["MESSAGE_COL"], blanks);
    output(globals["MESSAGE_ROW"], globals["MESSAGE_COL"], text);
        attrset(COLOR_PAIR(1));
}

void do_push_new(auto& instruction, int& stack_position, auto& variables, auto& globals)
{
    string variable = next((instruction));
    int row = stack_position * 2;
    variables[variable] = row;
    output(row, globals["VARIABLE_COL"], variable);
    stack_position++;
}

void do_value(auto& instruction, auto& variables, auto& globals)
{
    string variable = next((instruction));
    string value = next((instruction));
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

    for(auto& instruction : instructions)
    {
        attrset(COLOR_PAIR(1));
        auto command = next(instruction);
        if(command == "CODE") do_code(instruction, code_lines, globals);
        if(command == "GLOBAL") do_global(instruction, globals);
        if(command == "LOAD") do_load(instruction, code, globals);
        if(command == "MESSAGE") do_message(instruction, globals);
        if(command == "PUSH_NEW") do_push_new(instruction, stack_position, variables, globals);
        if(command == "VALUE") do_value(instruction, variables, globals);
        if(command == "WAIT") wait();
        if(command == "END") {} // used for debugging
    }
}

int main(int argc, char** argv) 
{
    initialize_ncurses();
    setup_colors();
    auto ifs = read_file(FILENAME);
    auto code = get_code(ifs);
    auto instructions = get_instructions(ifs);
    process_instructions(instructions, code);
    clear();
    endwin();
}

