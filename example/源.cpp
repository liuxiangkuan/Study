#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream infile;
	char buffer[256];
	infile.open("C:/Users/Administrator/Desktop/test.txt",ios::in);
	while (!infile.eof())
	{
		infile.getline(buffer,sizeof(buffer));
		cout << buffer << endl;
	}
	infile.close();
	system("pause");
	return 0;
}