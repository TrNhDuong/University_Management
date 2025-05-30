#include "search.h"


vector<BaseEntity*> IdSearch::search(IDatabase* database, const string& id){
    vector<BaseEntity*> ans;
    int size = database->getSize();
    for (int i = 0; i < size; i++)
        if (database->getData(i)->getId().find(id) != string::npos)
            ans.push_back(database->getData(i));
    return ans;
}

vector<BaseEntity*> NameSearch::search(IDatabase* database, const string& name){
    vector<BaseEntity*> ans;
    int size = database->getSize();
    for (int i = 0; i < size; i++)
        if (database->getData(i)->getName().find(name) != string::npos)
            ans.push_back(database->getData(i));
    return ans;
}