#include <iostream>
#include <string>
#include <mutex>
#include <map>

using namespace std;

class DataBase {
private:
    int mRecord;
    string mName;

public:
    DataBase(string name) {
        mName = name;
        mRecord = 0;
        cout << "Database created with name: " << mName << endl;
    }

    void editRecord(string operation) {
        cout << "Performing a " << operation << " operation on record " << mRecord << " in database " << mName << endl;
    }

    string getName() {
        return mName;
    }
};

class DatabaseManager {
private:
    static map<string, DataBase*> databases;
    static mutex mLock;

public:
    static DataBase* getInstance(string name) {
        lock_guard<mutex> lock(mLock); // Sử dụng lock_guard để đảm bảo an toàn khi có ngoại lệ
        if (databases.find(name) == databases.end()) {
            databases[name] = new DataBase(name);
        }
        return databases[name];
    }
};

map<string, DataBase*> DatabaseManager::databases;
mutex DatabaseManager::mLock;

int main() {
    DataBase *database1;
    database1 = DatabaseManager::getInstance("products");
    cout << "This is the " << database1->getName() << " database." << endl;

    DataBase *database2;
    database2 = DatabaseManager::getInstance("employees");
    cout << "This is the " << database2->getName() << " database." << endl;

    return 0;
}
