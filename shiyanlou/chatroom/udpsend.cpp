
#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "Ws32_2.lib")

#define DEFAULT_PORT 27015
#define DEFAULT_BUFLEN 512

int __cdecl main(int argc, char** argv)
{
	WSADATA wsaData;
	SOCKET SendSocket;
	sockaddr_in RecvAddr;
	char SendBuf[DEFAULT_BUFLEN];

	WSAStartup(MAKEWORD(2,2), &wsaData);

	SendSocket = socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP);

	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = DEFAULT_PORT;
	RecvAddr.sin_addr.s_addr = inet_addr("127.0.0.100");

	printf("Sending a datagram to the receiver...\n");
	sendto(SendSocket,
		SendBuf,
		DEFAULT_BUFLEN,
		0,
		(SOCKADDR *) &RecvAddr,
		sizeof(RecvAddr));
	printf("Finished sending. Closing socket.\n");

	closesocket(SendSocket);
	printf("Exiting.\n");
	WSACleanup();
	return 0;

}