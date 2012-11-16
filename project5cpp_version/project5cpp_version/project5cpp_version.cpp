// NAME: Daniel Preston
//UFID: 3391-0966

#include "stdafx.h"//necessary Visual C++ header
#include <Windows.h>//Windows header
#include <iostream>//allows use of input/output
#include <cmath>//allows use of mathematical operations
#include <fstream>//allows for file I/O
#include <cstdlib>//standard c++ library
using namespace std;
bool fileopen(char file[]);//function prototype
void fileclose(void);//function prototype
float frequency(char character, char file[40]);//funtion prototype
int numtimes (char character, char file[40]);//function prototype
int count (char file[40]);//funtion prototype

ifstream file1;//global declaration of input file (not good practice, but was necessary for compilation)
ofstream file2;//global declaration of output file (same as above)

int numtimes(char character,char file[40]){//function that counts the number of times a character appears
	int times=0;//initializing
	char letter;//declaring letter
	fileopen(file);//calls the 'fileopen' function, which checks and opens the file
	while (!file1.eof()){//while loop that continues until program has read whole text file
		file1>>letter;//takes input from file1
		if (letter==character){//if a letter in the text matches user-input letter
			times++;//adds the number of times the letter appears
		}
	}
	fileclose();//closes input file
	return times;//return for the function
}
float frequency (char character,char file[40]){//function that calculates frequency
	return (float)(numtimes(character,file))/(count(file));//frequency is just the number of times the letter appears divided by the number of letters in the text file
}
int count(char file[40]){//counts all of the characters in the file
	int sum=0;//initializes sum to 0
	char letter;//declares letter variable
	fileopen(file);//opens the file
	while (file1>>letter){
		sum++;//adds all letters
	}
	fileclose();//closes the file
	return sum;//returns the total number of letters
}
bool fileopen(char file[40]){//boolean variable that opens the input file
	file1.open(file);//opens file given by user
	if (file1.fail()){//checks to see if file exists
		file1.clear();//if file doesnt exists, clears the failbit flags to eventually ask for more input
		return false;//returns a false value; the file was not opened successfully
		}
	return true;//else, file is open and the variable switches to true
}
void fileclose(void){//function to close file
	file1.close();//closes file(not really necessary, but calling the function neatens up the main function
}

int main(void){//main function
	bool open=false;//intializes the boolean variable open
	char filename[40];//declares a char array of 40 characters to store file name
	int choice;//user option selection
	char character;//character that the user inputs

	cout <<"This program accepts a text file from a user and performs"<<endl;//options display
	cout <<"an analysis of the letters and characters used by the author."<<endl<<endl;
	do{//do-while loop for file opening. will continue to loop until file is successfully opened
		cout <<"Please give a file name: ";//asking for user input
		cin.getline(filename, sizeof(filename));//how to get a char array
		if(fileopen(filename)){//passes the file name to the 'fileopen' function
			open=true;
			fileclose();
		}
	} while (!open);//last part of do-while loop; loops until open is true
        bool exits = false;
	while (exits==false){//new boolean while loop; done this way to allow for a 'quit' option
		cout<<"Choose:"<<endl;
		cout<<"1. To perform analysis on a single character."<<endl;
		cout<<"2. To write analysis for all alphabet in a file."<<endl;
		cout<<"0. To quit."<<endl;
		cout<<"Choose: ";
		cin>>choice;//recieves user choice input
		char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};//declares array for alphabet
		switch (choice){
			case 1:cout <<"Please give character to check: ";//first case
				cin>> character;//asks for the character to analyze
				cout<<"Character "<<character<<" appears "<<numtimes(character,filename)<<" times in the text."<<endl;//passes character to 'numtimes' function
				cout<<"It has a frequency of "<<frequency(character,filename)<<" ."<<endl;//passes character to 'frequency' function
				break;
				break;
			case 2: 
				file2.open("report.txt");
				for(int i=0; i < sizeof(alphabet);i++){//for loop to loop through the entire alphabet
					file2<< "Character "<< alphabet[i]<<" appears "<<numtimes(alphabet[i],filename) <<" times in the text."<<endl;//passes each character of array through 'numtimes'.
					file2<<"It has a frequency of "<<frequency(alphabet[i],filename)<<" ."<<endl;//passes each character of the array through 'frequency'
				}
				file2.close();//closes function
				cout<<"Report stored in file: report.txt."<<endl;
				break;
			case 0: cout<<"Now quitting...";//quit function
				exits=true;//exits main while loop
				break;
			default:{//provides option to warn user if they enter an invalid option
				cout<<"Not a valid choice."<<endl;
				break;
			}


		}

		
	}

}
