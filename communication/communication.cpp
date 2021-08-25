#include "communication.h"

Communication::Communication()
{
    Init();
    CreateSocket();
}

Communication::~Communication()
{
    closesocket(con);
    WSACleanup();
}

void Communication::Init()
{
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsaData;
    if (WSAStartup(sockVersion, &wsaData) != 0)
    {
        throw SocketException(INIT_SOCKET_FAILED);
    }
}

void Communication::CreateSocket()
{
    con = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (con == INVALID_SOCKET)
    {
        throw SocketException(CREATE_SOCKET_FAILED);
    }
}

void Communication::Listen(int port, int size)
{
    Address addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.S_un.S_addr = INADDR_ANY;
    if (bind(con, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
    {
        throw SocketException(BIND_ADDRESS_FAILED);
    }
    if (listen(con, size) == SOCKET_ERROR)
    {
        throw SocketException(LISTEN_PORT_FAILED);
    }
}

int Communication::SendMsg(const char *msg, int flags)
{
    int status = send(con, msg, strlen(msg), flags);
    if (status == SOCKET_ERROR)
    {
        throw SocketException(SEND_DATA_ERROR);
    }
    return status;
}

int Communication::RcvMsg(string &msg, int flags)
{
    char buff[256];
    int count = 0;
    int status = 0;
    do
    {
        status = recv(target, buff, 255, flags);
        if (status == SOCKET_ERROR)
        {
            throw SocketException(RECIVE_DATA_ERROR);
        }
        buff[status] = 0;
        msg += buff;
        count += status;
    } while (status > 0);
    return count;
}

void Communication::Connect(const char *serverIp, int port)
{
    Address addr;
    addr.sin_addr.S_un.S_addr = inet_addr(serverIp);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    SOCKET status = connect(con, (LPSOCKADDR)&addr, sizeof(addr));

    if (INVALID_SOCKET == status)
    {
        throw SocketException(SOCKET_CONNECT_ERROR);
    }
    target = status;
}

void Communication::Accept()
{
    Address addr;
    int len = sizeof(addr);
    SOCKET status = 0;
    status = accept(con, (SOCKADDR *)&addr, &len);
    if (INVALID_SOCKET == status)
    {
        throw SocketException(SOCKET_ACCEPT_ERROR);
    }
    target = status;
}

const char *SocketException::what()
{
    switch (status)
    {
    case INIT_SOCKET_FAILED:
        return "init socket error";
    case CREATE_SOCKET_FAILED:
        return "create socket error";
    case BIND_ADDRESS_FAILED:
        return "bind address failed";
    case LISTEN_PORT_FAILED:
        return "listen prot failed";
    case SEND_DATA_ERROR:
        return "send data error";
    case RECIVE_DATA_ERROR:
        return "recive data error";
    case SOCKET_CONNECT_ERROR:
        return "socket connect error";
    case SOCKET_ACCEPT_ERROR:
        return "socket accept error";
    default:
        return "unknown error";
    }
}

SocketException::SocketException(int code)
{
    status = code;
}