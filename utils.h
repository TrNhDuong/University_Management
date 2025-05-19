#ifndef _UTILS_H_
#define _UTILS_H_
#include <vector>
#include <string>
#include <iostream>
#include <format>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
using namespace std;


template <class T>
void addData(vector<T>& data, T& newData){
    data.push_back(newData);
}

template <class T>
void removeData(vector<T>& data, T& remove){
    vector<T> newList;
    for (const T&x: data){
        if (x.getId() != remove.getId()){
            newList.push_back(x);
        }
    }
    data = newList;
}

template <class T>
void replaceData(vector<T>& data, T& oldData, T& newData){
    vector<T> newList;
    for (const T&x: data){
        if (x.getId() != oldData.getId()){
            newList.push_back(x);
        }else{
            newList.push_back(newData);
        }
    }
    data = newList;
}

class displayAList{
    public:
        static void displayList(vector<string>&);
};

class ValidChoice{
    public:
        static bool checkValidChoice(vector<string>&, string&);
};

void setColor(int color);
void clearScreen();
char getch();
std::string toUpper(const std::string& str);

#endif