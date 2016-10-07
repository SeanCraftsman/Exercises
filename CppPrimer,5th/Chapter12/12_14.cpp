#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct connection{
    string ip;
    int port;
    connection(string _ip, int _port): ip(_ip), port(_port) { }
};

struct destination{
    string ip;
    int port;
    destination(string _ip, int _port): ip(_ip), port(_port) { }
};

connection connect(destination* pDest){
    shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    cout << "creating connection(" << pConn.use_count() << ")" << endl;
    return *pConn;
}

void disconnect(connection pConn){
    cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << endl;
}

void end_connection(connection *pConn){
    disconnect(*pConn);
}

void f(destination &d){
    connection conn = connect(&d);
    shared_ptr<connection> p(&conn, end_connection);
    cout << "connecting now("<< p.use_count() << ")" << endl;
}

int main(){
    destination dest("202.118.176.67", 3316);
    f(dest);
    return 0;
}





