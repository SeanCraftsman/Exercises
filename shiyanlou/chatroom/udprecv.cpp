
#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "Ws32_2.lib")

#define DEFAULT_PORT 27015
#define DEFAULT_BUFLEN 512

int __cdecl main(int argc, char** argv)
{
	WSADATA wsaData;
	SOCKET RecvSocket;
	sockaddr_in RecvAddr;
	char RecvBuf[DEFAULT_BUFLEN];
	sockaddr_in SenderAddr;
	int SenderAddrSize = sizeof(SenderAddr);

	WSAStartup(MAKEWORD(2,2), &wsaData);

	RecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = DEFAULT_PORT;
	RecvAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(RecvSocket, (SOCKADDR *) &RecvAddr, sizeof(RecvAddr));
	printf("Receiving datagrams...\n");
	recvfrom(RecvSocket,
		RecvBuf,
		DEFAULT_BUFLEN,
		0,
		(SOCKADDR *)&SenderAddr,
		&SenderAddrSize);
	printf("Finished receiving. Closing socket.\n");
	closesocket(RecvSocket);

	printf("Exiting.\n");
	WSACleanup();
	return 0;
}