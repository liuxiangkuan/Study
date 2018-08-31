#include<stdio.h>
#include<Winsock2.h>

//SERVER
#pragma warning(disable:4996)
#pragma comment(lib,"ws2_32")
int main(int argc,char *argv[])
{
	SOCKET sListen;
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData)!=0)
	{
		return 0;
	}
	
	
	if ((sListen=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==INVALID_SOCKET)
	{
		printf("sockfd赋值失败");
		return 0;
	}
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port =2000;
	sin.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(sListen,(LPSOCKADDR)&sin,sizeof(sin))==-1)
	{
		closesocket(sListen);
		printf("bind失败");
		return 0;
	}
	if (listen(sListen,10)==SOCKET_ERROR)
	{
		closesocket(sListen);
		printf("listen失败");
		return 0;
	}

	sockaddr_in remoteAddr;
	SOCKET sClient;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255];
	while (true)
	{
		sClient = accept(sListen, (SOCKADDR *)&remoteAddr, &nAddrlen);
		if (sListen==INVALID_SOCKET)
		{
			printf("accept error");
			return 0;
		}
		printf("接受到一个链接： %s", inet_ntoa(remoteAddr.sin_addr));
		int ret = recv(sClient, revData, nAddrlen, 0);
		if (ret>0)
		{
			revData[ret] = 0X00;
			printf(revData);
		}
		char buffer[] = "hellow";
		send(sListen, buffer, strlen(buffer), 0);
		closesocket(sClient);
	}
	closesocket(sListen);
	system("pause");
	return 0;
}