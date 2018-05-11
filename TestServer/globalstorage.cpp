#include "globalstorage.h"

GlobalStorage::GlobalStorage()
{

}

std::unordered_set<std::string> GlobalStorage::getUsers()
{
    QMutexLocker locker(&mutex);
    return users;
}

void GlobalStorage::addUser(const std::string &user)
{
    QMutexLocker locker(&mutex);
    users.insert(user);
}

void GlobalStorage::removeUser(const std::string &user)
{
    QMutexLocker locker(&mutex);
    users.erase(users.find(user));
}
