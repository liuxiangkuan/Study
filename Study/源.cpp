#include<iostream>
#include<Windows.h>
#include<string>
#pragma warning(disable:4996)
int main()
{
	FILE *fp;
	char ch;
	if ((fp=fopen("C:/Users/Administrator/Desktop/test.txt","rb+"))==NULL)
	{
		printf_s("error open");
		return -1;
	}
	
	while (!feof(fp))
	{
		ch = fgetc(fp);
		printf("%c", ch);	
	}
	fclose(fp);
	system("pause");
	return 0;
}