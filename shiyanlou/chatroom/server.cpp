#define _WIN32_WINNT 0x602

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int __cdecl main(){
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	char sendbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
	
	// Initialize winsock
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if(iResult != 0){
		printf("WSAStartup failed: %d\n",iResult);
		return 1;
	}

	
	ZeroMemory(&hints, sizeof (hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if(iResult != 0){
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}



	// Create a Socket for the server to listen for client connections
	ListenSocket = socket(result->ai_family, result->ai_socktype,
	 result->ai_protocol);
	if(ListenSocket == INVALID_SOCKET){
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket 
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if(iResult == SOCKET_ERROR){
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// no longer need addr information
	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if(iResult == SOCKET_ERROR){
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}


	// Accept a client socket
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if(ClientSocket == INVALID_SOCKET) {
		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// No longer need server socket
	closesocket(ListenSocket);

	printf("*****************server start***************\n");
	// Receive until the peer shuts down the connection
	do {
		memset(sendbuf, '\0',DEFAULT_BUFLEN);
		printf("enter your msg :");
		fgets(sendbuf, DEFAULT_BUFLEN, stdin);
		if(!strncasecmp(sendbuf,"quit",4)){
			printf("server stop\n");
			break;
		}

		if(strchr(sendbuf,'\n'))
            iSendResult = send(ClientSocket, sendbuf,strlen(sendbuf)-1,0);
        else
            iSendResult = send(ClientSocket, sendbuf,strlen(sendbuf),0);
		if (iSendResult == SOCKET_ERROR) {
	        printf("send failed with error: %d\n", WSAGetLastError());
	        closesocket(ClientSocket);
	        WSACleanup();
	        return 1;
	    }        
	    memset(recvbuf, '\0', DEFAULT_BUFLEN);
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if(iResult > 0){
			printf("receive message: %s\n", recvbuf);
		
		} else if (iResult == 0)
			printf("Connection closing...\n");
		else{
			printf("recv failed: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}
	} while (iResult > 0);

	// shutdown the send half of the connection since no more data will be sent
	iResult = shutdown(ClientSocket, SD_SEND);
	if(iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}
	//cleanup
	closesocket(ClientSocket);
	WSACleanup();
	return 0;
}