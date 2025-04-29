#include "manageSystem.h"
#include "faculty.h"
#include "menu.h"

void UniversitySystem::Run(){
    Instructor truongkhoa;
    truongkhoa.setName("Nguyễn Phúc Hậu");
    truongkhoa.setBirth("1/1/2005");
    truongkhoa.setId("23120252");

    Faculty cntt;
    cntt.setName("Công nghệ thông tin");
    cntt.setId("1200");
    cntt.setBirth("12/2/2022");
    cntt.setMail("fit@hcmus.edu.vn");
    cntt.setDean(truongkhoa);
    
    // FacultyInfo::printFacultyInfo(cntt);
    Menu menu;
    // menu.displayMenu();
    string choice = menu.getChoice();
    cout << "Lua chon cua may la: " << choice << endl;

}