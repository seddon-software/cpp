#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <wchar.h>
#include <locale.h>
#include <curses.h>
#include <cstdlib>

using namespace std;

#define STACK 50
#define MESSAGE 20
#define FILENAME argv[1]

typedef struct
{
    string cursor;
    string stack;
    string value;
    string label;
    string message;
} Param;

typedef struct
{
    int cursor;
    int stack;
    string value;
    string label;
    string message;
} P;

string blank(50, ' ');

P normalize(const Param& param)
{
    P p;
    p.cursor = stoi("0"s + param.cursor);
    return p;
}
void go_red()
{
    init_pair(1, COLOR_RED, COLOR_WHITE);
    attrset(COLOR_PAIR(1));
}

void stop_red()
{
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attrset(COLOR_PAIR(2));
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
    for(int i = 0; i <= boxes; i++)
    {
        row = draw(row, col, "│         │");
        row = draw(row, col, "├─────────┤");
    }
    row = draw(row, col, "│         │");
    row = draw(row, col, "└─────────┘");
    refresh();
}

int out(int row, int col, const char* text)
{
    move(row++, col);
    addstr(text);
    refresh();
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
    string text;
    list<Param> lines;
    Param param;
    while(ifs)
    {
        getline(ifs, text);
        if(text.starts_with("%END")) break;
        stringstream ss;
        ss << text;
        getline(ss, param.cursor, ',');
        getline(ss, param.stack, ',');
        getline(ss, param.value, ',');
        getline(ss, param.label, ',');
        getline(ss, param.message, ',');
        lines.push_back(param);
    }
    list<P> instructions;
    for(auto& line: lines)
    {
        P p;
        p.cursor = stoi("0"s + trim(line.cursor));
        p.stack = stoi("0"s + trim(line.stack));
        p.label = trim(line.label);
        p.value = trim(line.value);
        p.message = trim(line.message);
        instructions.push_back(p);
    }
    return instructions;
}

auto get_code(ifstream& ifs)
{
    int line = 2;
    string text;
    vector<string> lines;
    while(ifs)
    {
        getline(ifs, text);
        if(text.starts_with("%CODE")) continue;
        if(text.starts_with("%INSTRUCTIONS")) return lines;
        stringstream ss;
        ss << setw(4) << line++ << ":  " << text;
        string text = ss.str();
        lines.push_back(ss.str());
    }
    return lines;
}

auto read_file(const string& fileName)
{
    int row = 2;
    int col = 2;
    string text;
    ifstream ifs(fileName.c_str()); 

    vector<string> code;
    list<P> instructions;
    code = get_code(ifs);
    instructions = get_instructions(ifs);
    ifs.close();    

    for(auto str:code)
    {
        row = out(row, col, str.c_str());
        refresh();
    }
    return instructions;
}

void label(int row, int col, const string& text, int cols=4)
{
    string blank(cols, ' ');
    if(text != ""s) 
    {
        if(text == "_"s) {
            out(row, col, blank.c_str());
        }
        else
        {
            out(row, col, blank.c_str());
            out(row, col, text.c_str());
        }
    }
}

void do_next(auto& params, int col)
{
    static P last = {};
    getch();
    auto p = params.front();
    params.pop_front();

    if(last.cursor != 0)
        out(last.cursor, col, "  ");
    go_red();
    out(p.cursor, col, "> ");
    label(MESSAGE, STACK, blank);  // clear message
    label(MESSAGE, STACK+2, p.message);
    stop_red();
    label(p.stack, STACK+12, p.label, 30);
    label(p.stack, STACK+4, p.value);
    last = p;
    refresh();
}

int main(int argc, char** argv) 
{
    addstr("");
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    curs_set(0);        // hide cursor
    try
    {
        if(start_color() != OK) throw exception();
    }
    catch(const std::exception& e)
    {
        std::cerr << "no colors" << '\n';
        return 1;
    }
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(3));
    list<P> instructions = read_file(FILENAME);
    draw_stack(2, STACK, 6);
    auto size = instructions.size();
    for(unsigned i = 0; i < size; i++)
    {
        do_next(instructions, 2);
    }
    getch();
    clear();
    endwin();
}

