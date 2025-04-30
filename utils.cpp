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