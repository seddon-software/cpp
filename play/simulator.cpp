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

typedef struct
{
    string cursor;
    string stack;
    string value;
    string label;
    string message;
} Param;

string blank(25, ' ');


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

auto get_instructions(ifstream& ifs)
{
    string text;
    list<Param> lines;
    Param param;
    while(ifs)
    {
        getline(ifs, text);
        if(text.starts_with("%END")) return lines;
        stringstream ss;
        ss << text;
        getline(ss, param.cursor, ',');
        getline(ss, param.stack, ',');
        getline(ss, param.value, ',');
        getline(ss, param.label, ',');
        getline(ss, param.message, ',');
        lines.push_back(param);
    }
    return lines;
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

list<Param> read_file(const string& fileName)
{
    int row = 2;
    int col = 2;
    string text;
    ifstream ifs(fileName.c_str()); 

    vector<string> code;
    list<Param> instructions;
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

void label(int row, int col, const string& text)
{
    out(row, col, text.c_str());
}

void do_next(auto& params, int col)
{
    static Param last = {};
    getch();
    auto p = params.front();
    params.pop_front();

    if(last.cursor != "")
        out(stoi(last.cursor), col, "  ");
    go_red();
    out(stoi(p.cursor), col, "> ");
    label(20, STACK, blank);  // clear message
    label(20, STACK+2, p.message);
    stop_red();
    label(stoi(p.stack), STACK+12, p.label);
    label(stoi(p.stack), STACK+4, p.value);
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
    list<Param> params;
    params = read_file("z.txt");
    draw_stack(2, STACK, 6);
    auto size = params.size();
    for(unsigned i = 0; i < size; i++)
    {
        do_next(params, 2);
    }
    getch();
    clear();
    endwin();
}

