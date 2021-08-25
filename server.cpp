#include "communication/communication.h"

int main()
{
    cout << "start" << endl;
    Communication connection;
    string str;
    connection.Listen(8080);
    cout << "listen 8080" << endl;
    try
    {
        connection.Accept();
        connection.RcvMsg(str);
    }
    catch (SocketException e)
    {
        cout << "error:" << e.what() << endl;
    }
    cout << "get msg" << str << endl;
    return 0;
}