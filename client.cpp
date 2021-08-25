#include "communication/communication.h"

int main()
{
    cout << "start" << endl;
    Communication connection;
    try
    {
        connection.Connect("127.0.0.1", 8080);
        cout << "connect success" << endl;
        connection.SendMsg("whos your daddy");
        connection.SendMsg("ceshi");
        cout << "send success" << endl;
    }
    catch (SocketException e)
    {
        cout << "error:" << e.what() << endl;
    }
    return 0;
}