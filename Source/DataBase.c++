#include <iostream>
#include <string.h>

using namespace std;

class DataBase{
private:
    static DataBase *uniqueDatabase;
    int mRecord;
    string mName;

public:
    DataBase(string name)
    {
        mName= name;
        mRecord= 0;
    }

    void editRecord(string operation)
    {
        cout<<"Performing a " << operation<<"operation on record "<< mRecord<<" in database "<< mName<<endl;
    }
    string getName()
    {
        return mName;
    }

    static DataBase* getInstance(string name)
    {
        if(uniqueDatabase == nullptr)
        {
            uniqueDatabase = new DataBase(name);
        }
        return uniqueDatabase;
    }
};

DataBase* DataBase::uniqueDatabase = nullptr;

int main()
{
    DataBase *database;
    database = DataBase::getInstance("products");
    cout<<"This is the "<<database->getName() <<" database."<<endl;
    database= DataBase::getInstance("employees");
    cout<<"This is the "<< database->getName() <<" database. "<<endl;
    return 0;
}   