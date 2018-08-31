#include<stdio.h>
#include<Winsock2.h>
#pragma comment(lib,"ws2_32")
#pragma warning(disable:4996)
int main(int argc, char *argv[])
{
	SOCKET sockfd;
	sockaddr_in their_addr;
	
	WSADATA ws;
	if (WSAStartup(MAKEWORD(2, 2), &ws)!=0)
	{
		return 0;
	}
	
	if ((sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==INVALID_SOCKET)
	{
		printf("socket error");
		return -1;
	}
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = 2000;
	their_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (connect(sockfd,(sockaddr*)&their_addr,sizeof(their_addr))==SOCKET_ERROR)
	{
		printf("connect error");
		closesocket(sockfd);
		return 0;
	}
	char buf;
	char *Buffer=&buf;
	scanf("%s", &buf);
    send(sockfd, Buffer, strlen(Buffer), 0);
	char revData[255];
	int ret = recv(sockfd, revData, 255, 0);
	if (ret>0)
	{
		revData[ret] = 0X00;
		printf(revData);
	}
	closesocket(sockfd);
	WSACleanup();
	system("pause");
	return 0;
}