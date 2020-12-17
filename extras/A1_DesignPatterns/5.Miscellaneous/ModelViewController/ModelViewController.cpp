////////////////////////////////////////////////////////////
//
//    Model, View, Controller
//
////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

class Model
{
public:
    Model(string name) : name(name) {}
    string getData()
    {
        if(name == "soccer") 
            return "ManUtd 3-0; Spurs 2-1; Chelsea 1-2; Villa 0-3";
        if(name == "football") 
            return "Giants 3-0; Cowboys 2-1; Broncos 1-2; Dolphins 0-3";
        return "";
    }
private:
    string name;
};

class View
{
public:
    View(string name) : name(name) {}
    string Format(string data)
    {
        if(name == "barChart") return FormatBarChart(data);
        if(name == "text") return FormatText(data);
    }
private:
    string FormatBarChart(string data);
    string FormatText(string data);
    string name;
};

class Controller
{
public:
    string Request(Model model, View view)
    {
        string data = model.getData();
        string formattedData = view.Format(data);
        return formattedData;
    }
};

string View::FormatBarChart(string data)
{
    stringstream input(data);
    string teams[4];
    int wins[4];
    string bars[4];
    string ignore;
    //"ManUtd 3-0; Liverpool 2-1; Chelsea 1-2; Arsenal 0-3";
    // parse input data
    for(int i = 0; i < 4; i++)
    {
        input >> teams[i] >> wins[i] >> ignore;
    }

    // convert to bars
    for(int i = 0; i < 4; i++)
    {
        switch(wins[i])
        {
        case 0: bars[i] = "";   break;
        case 1: bars[i] = "X";  break;
        case 2: bars[i] = "XX"; break;
        case 3: bars[i] = "XXX";break;
        }
    }


    // build output
    stringstream output;
    for(int i = 0; i < 4; i++)
    {
        output << teams[i] << "\t" << bars[i] << "\n";
    }
    return output.str();
}

string View::FormatText(string data)
{
    return data;
}


int main()
{
    Controller controller;   
    Model soccer("soccer");
    Model football("football");
    View barChart("barChart");
    View text("text");

    cout << controller.Request(soccer, barChart) << endl;
    cout << controller.Request(soccer, text) << endl;
    cout << controller.Request(football, barChart) << endl;
    cout << controller.Request(football, text) << endl;
}
