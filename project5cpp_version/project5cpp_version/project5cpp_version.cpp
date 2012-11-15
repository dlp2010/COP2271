// NAME: Daniel Preston
//UFID: 3391-0966

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

void numtimes(char character){
	int times;

}
void frequency (char character){

}



int main(void){
	ifstream file1;
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
		file1.open(filename);
		if (file1.fail()){
			file1.clear();
		}
		else open=true;
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


