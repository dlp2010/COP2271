//test program


#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(){
	char name1[12];
	cout <<"Hello, what is your name?" <<endl;
	cin >> name1[0]>>name1[2]>>name1[3];
	ofstream file1;
	file1.open("test.txt");
	file1 <<name1[0]<<name1[1]<<name1[2]<<name1[3]<<endl;
	system("PAUSE");

}


