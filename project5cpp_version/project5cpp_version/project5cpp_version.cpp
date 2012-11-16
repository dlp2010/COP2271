// NAME: Daniel Preston
//UFID: 3391-0966

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;
bool fileopen(char file[]);
void fileclose(void);
float frequency(char character, char file[40]);
int numtimes (char character, char file[40]);
int count (char file[40]);

ifstream file1;
ofstream file2;

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
	return (float)(numtimes(character,file))/(count(file));
}
int count(char file[40]){
	int sum=0;
	char letter;
	fileopen(file);
	while (file1>>letter){
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
		if(fileopen(filename)){
			open=true;
			fileclose();
		}
	} while (!open);
        bool exits = false;
	while (exits==false){
		cout<<"Choose:"<<endl;
		cout<<"1. To perform analysis on a single character."<<endl;
		cout<<"2. To write analysis for all alphabet in a file."<<endl;
		cout<<"0. To quit."<<endl;
		cout<<"Choose: ";
		cin>>choice;
		char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};;
		switch (choice){
			case 1:cout <<"Please give character to check: ";
				cin>> character;
				cout<<"Character "<<character<<" appears "<<numtimes(character,filename)<<" times in the text."<<endl;
				cout<<"It has a frequency of "<<frequency(character,filename)<<" ."<<endl;
				break;
				break;
			case 2: 
				file2.open("report.txt");
				for(int i=0; i < sizeof(alphabet);i++){
					file2<< "Character "<< alphabet[i]<<" appears "<<numtimes(alphabet[i],filename) <<" times in the text."<<endl;
					file2<<"It has a frequency of "<<frequency(alphabet[i],filename)<<" ."<<endl;
				}
				file2.close();
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
