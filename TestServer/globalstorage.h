#ifndef GLOBALSTORAGE_H
#define GLOBALSTORAGE_H

#include <QStringList>
#include <QMutex>
#include <QMutexLocker>
#include <unordered_set>

class GlobalStorage
{
private:
    GlobalStorage();
    GlobalStorage(const GlobalStorage& root) = delete;
    GlobalStorage& operator=(const GlobalStorage&) = delete;
    std::unordered_set<std::string> users;
    QMutex mutex;
public:
    static GlobalStorage& instance()
    {
        static GlobalStorage theSingleInstance;
        return theSingleInstance;
    }
    std::unordered_set<std::string> getUsers();
    void addUser(const std::string &user);
    void removeUser(const std::string &user);
};

#endif // GLOBALSTORAGE_H
