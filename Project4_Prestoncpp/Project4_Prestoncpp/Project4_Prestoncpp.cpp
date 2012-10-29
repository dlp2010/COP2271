// Project4_Prestoncpp.cpp 
//Stores grades and computes averages

#include "stdafx.h"
#include <cstdlib>
#include <cmath>
#include <Windows.h>
#include <iostream>
using namespace std;

float score;
char gradeletter[2];

void grade(float score1){
	if (score1 >= 93){
		gradeletter[0] = 'A';
		gradeletter[1]=' ';
	}
	else if (score1 < 93 && score1 >= 87){
		gradeletter[0] = 'A';
		gradeletter[1]='-';
	}
	else if (score1 < 87 && score1 >= 83){
		gradeletter[0] = 'B';
		gradeletter[1]='+';
	}
	else if (score1 < 83 && score1 >= 80){
		gradeletter[0] = 'B';
		gradeletter[1] = ' ';
	}
	else if (score1 < 80 && score1 >= 77){
		gradeletter[0] = 'B';
		gradeletter[1]='-';
	}
	else if (score1 < 77 && score1 >= 73){
		gradeletter[0] = 'C';
		gradeletter[1] = '+';
	}
	else if (score1 < 73 && score1 >= 70){
		gradeletter[0] = 'C';
		gradeletter[1]=' ';
	}
	else if (score1 < 70 && score1 >= 67){
		gradeletter[0] = 'C';
		gradeletter[1] = '-';
	}
	else {
		gradeletter[0]= 'F';
		gradeletter[1]= ' ';
	}
}

int main(void){
	int option;
	int n= 0;
	int array1[8][250];
	bool exits=false;
	while (!exits){
	cout << "Student Project Database"<<endl;
	cout << "This program stores the project scores" <<endl;
	cout << "of a number of students and produces" <<endl;
	cout << "the average and letter grades" <<endl;
	cout << "Please choose an option."<<endl<<endl;
	cout << "1. To store students projects."<<endl;
	cout << "2. To compute class average on specific project." <<endl;
	cout << "3. To compute overall class average in the course."<<endl;
	cout << "4. To see the letter grade of a specific student."<<endl;
	cout << "Press 0 to quit." <<endl;
	cout << "Please choose: ";
	cin >> option;
	switch (option){
		case 0: cout <<"Now quitting..";
			exits = true;
			break;
		case 1: cout <<"Please give number of students ";
			cin >> n;
			for (int i=0; i<=7; i++){
				for (int j=0; j<=n-1; j++){
					cout <<"Please give grade of student "<<j+1<<" in project "<< i+1<< ": ";
					cin >> array1[i][j];
				}
			}
			cout <<endl;
			break;
		case 2: if (n==0){
			cout << "No scores stored yet."<<endl;
			    break;
				}
				else {
					int projectnumber;
					cout << "Give the number of the project: ";
					cin >> projectnumber;
					cout <<endl;
					if (projectnumber >8 || projectnumber<1){
						cout<<"Invalid choice. Only projects 1-8 can be chosen."<<endl<<endl;
					break;
					}
					float average;
					int sum=0;
					for(int k=0; k<n; k++){
						sum += array1[projectnumber][k];
					}
					average = (float)sum/n;
					cout <<average<<endl<<endl;
				break;
				}
		case 3: if (n==0){
			cout << "No scores stored yet."<<endl;
			    break;
				}
				else {
					int sum2=0;
					float average2;
					for(int l=0; l<8; l++){
						for (int m=0; m<n; m++){
							sum2 += array1[l][m];
						}
					}
					average2= (float)sum2/(n*8);
					cout << "The average of the class is: "<<average2<<"."<<endl<<endl;
				break;
				}
		case 4: if (n==0){
			cout << "No scores stored yet."<<endl;
			    break;
				}
				else {
					int n2;
					int sum3=0;
					float average3;
					cout <<"Please give the student #: ";
					cin >> n2;
					if (n2>n){
						cout <<"Invalid choice for student #."<<endl<<endl;
						break;
					}
					for (int l=0; l<8; l++){
						sum3 += array1[l][n2-1];
					}
					average3= (float)sum3/8;
					grade(average3);
					if (gradeletter[0]=='F'){
						cout <<"student "<<n2<<" failed the course."<<endl<<endl;
					}
					else {
						cout <<"The letter grade for student "<<n2<<" is " <<gradeletter[0]<<gradeletter[1]<<endl<<endl;
					}
				break;
				}
		default: {
			cout << "Invalid choice. Only options 1-4 are allowed." <<endl;
			break;
				 }


	}
	}
}




