#ifndef _STUDENT_READER_H_
#define _STUDENT_READER_H_
#include <vector>
#include "student.h"
#include "individual.h"
#include "instructor.h"
#include <fstream>
using std::vector;


class Read_Data{
public:
    Student ReadLine(const string&);
    vector<Student> readFromFile();
};

Student Read_Data::ReadLine(const string& line){
    int n = line.size();
    vector<string> list;
    string tmp = "";
    for (int i = 0; i < n; i++)
        if (line[i] != '|'){
            tmp += line[i];
        } else {
            list.push_back(tmp);
            tmp = "";
        }
    list.push_back(tmp);
    Student ans;
    ans.setName(list[0]);
    ans.setId(list[1]);
    ans.setBirth(list[2]);
    return ans;
}

vector<Student> Read_Data::readFromFile(){
    std::fstream file("input1.txt", std::ios::in);
    vector<Student> v;
    string line;
    while (getline(file, line))
        v.push_back(ReadLine(line));
    file.close();
    return v;
}
#endif