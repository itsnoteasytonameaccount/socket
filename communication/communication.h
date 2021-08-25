#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <string>

using namespace std;

#define INIT_SOCKET_FAILED 1
#define CREATE_SOCKET_FAILED 2
#define BIND_ADDRESS_FAILED 3
#define LISTEN_PORT_FAILED 4
#define SEND_DATA_ERROR 5
#define RECIVE_DATA_ERROR 6
#define SOCKET_CONNECT_ERROR 7
#define SOCKET_ACCEPT_ERROR 8

typedef struct sockaddr_in Address;

class Communication
{
public:
    Communication();
    void CreateSocket();
    int SendMsg(const char *msg, int flags = 0);
    void Connect(const char *serverIp, int port);
    int RcvMsg(string &msg, int flags = 0);
    void Listen(int port, int size = 5);
    void Accept();
    ~Communication();

private:
    void Init();
    SOCKET con;
    SOCKET target;
};

class SocketException : public exception
{
public:
    SocketException(int);
    virtual const char *what();

private:
    SocketException(){};
    int status;
};