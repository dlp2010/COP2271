// NAME: Daniel Preston
//UFID: 3391-0966

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

ifstream file1;

int numtimes(char character,char file[40]){
	int times=0;
	char letter;
	fileopen(file);
	while (!file1.eof()){
		file1>>letter;
		if (letter==character){
			times++;
		}
	}
	fileclose();
	return times;
}
float frequency (char character,char file[40]){
	return numtimes(character,file)/count(file);
}
int count(char file[40]){
	int sum=0;
	fileopen(file);
	while (!file1.eof()){
		sum++;
	}
	fileclose();
	return sum;
}
bool fileopen(char file[40]){
	file1.open(file);
	if (file1.fail()){
		file1.clear();
		return false;
		}
	return true;
}
void fileclose(void){
	file1.close();
}



int main(void){
	bool open=false;
	char filename[40];
	int choice;
	char character;

	cout <<"This program accepts a text file from a user and performs"<<endl;
	cout <<"an analysis of the letters and characters used by the author."<<endl<<endl;
	do{
		cout <<"Please give a file name: ";
		cin.getline(filename, sizeof(filename));
		cout<<endl;
		if(fileopen(filename)){
			open=true;
			fileclose();
		}
	} while (!open);
	while (bool exits=false){
		cout<<"Choose:"<<endl;
		cout<<"1. To perform analysis on a single character."<<endl;
		cout<<"2. To write analysis for all alphabet in a file."<<endl;
		cout<<"0. To quit."<<endl;
		cout<<"Choose: ";
		cin>>choice;
		switch (choice){
			case 1:cout <<"Please give character to check: ";
				cin>> character;

				cout<<"Character "<<character<<" appears "<<x<<" times in the text."<<endl;
				cout<<"It has a frequency of "<<frequency<<" ."<<endl;
				break;
			case 2: 
				cout<<"Report stored in file: report.txt."<<endl;
				break;
			case 0: cout<<"Now quitting...";
				exits=true;
				break;
			default:{
				cout<<"Not a valid choice."<<endl;
				break;
			}


		}

		
	}

}


