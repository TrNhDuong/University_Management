#include "student.h"
#include "individual.h"
#include "instructor.h"
#include "studentDataReader.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;


int main() {
    Read_Data dataReader;
vector<Student> studentList;
studentList = dataReader.readFromFile();
    return 0;
}
