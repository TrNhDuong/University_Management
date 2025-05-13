#include "utils.h"

void displayAList::displayList(vector<string>& list){
    for (size_t i = 0; i < list.size(); ++i) {
        cout << i + 1 << ". " << list[i] << endl;
    }
}

bool ValidChoice::checkValidChoice(vector<string>& checkList, string& choice){
    for (const string &x: checkList){
        if (choice == x) return true;
    }

    return false;
}

void setColor(int color) {
    cout << "\033[" << color << "m";
}

void clearScreen() {
    system("clear");
}

char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}