#include <QCoreApplication>
#include "../Common/chatrequest.h"
#include "../Common/common_consts.h"
#include <iostream>
#include <QStringList>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    chat::ChatRequest req;
    req.addProperty(chat::COMMAND_ID, chat::C_AUTH_REQ);
    req.addProperty("User_id", "Yura");
    req.addProperty(chat::USER_NAME, "Vik");
    chat::ChatRequest req1("Obj","my_obj");
    req1.addChildObj("child", req);
    QStringList list;
    list << "a" << "b" << "c" << "d" << "e";
    req1.addArray("Arr", list);
    cout << req1.toString();
    req.clear();
    return a.exec();
}
