// Project4_Prestoncpp.cpp 
//Stores grades and computes averages

#include "stdafx.h"//necessary for Visual C++
#include <cstdlib>//accesses standard C++ library
#include <cmath>//allows for use of math operators
#include <Windows.h>
#include <iostream>//input/output for c++
using namespace std;//employs standard namespace

float score;
char gradeletter[2];//array for grade letter. first character is letter, second is sign

void grade(float score1){//function to determine grade letter
	if (score1 >= 93){//based off grade scale
		gradeletter[0] = 'A';//letter
		gradeletter[1]=' ';//grade sign
	}
	else if (score1 < 93 && score1 >= 87){
		gradeletter[0] = 'A';//letter
		gradeletter[1]='-';//sign
	}
	else if (score1 < 87 && score1 >= 83){
		gradeletter[0] = 'B';//letter
		gradeletter[1]='+';//sign
	}
	else if (score1 < 83 && score1 >= 80){
		gradeletter[0] = 'B';//letter
		gradeletter[1] = ' ';//no sign for regular B
	}
	else if (score1 < 80 && score1 >= 77){
		gradeletter[0] = 'B';//letter
		gradeletter[1]='-';//sign
	}
	else if (score1 < 77 && score1 >= 73){
		gradeletter[0] = 'C';//letter
		gradeletter[1] = '+';//sign
	}
	else if (score1 < 73 && score1 >= 70){
		gradeletter[0] = 'C';//letter
		gradeletter[1]=' ';//no sign for regular C
	}
	else if (score1 < 70 && score1 >= 67){
		gradeletter[0] = 'C';//letter
		gradeletter[1] = '-';//sign
	}
	else {
		gradeletter[0]= 'F';//failing grade
		gradeletter[1]= ' ';//no sign for failure
	}
}

int main(void){//main function
	int option;//main option set
	int n= 0;//initialized variable for number of students
	int array1[8][250];//array with space for 8 projects and 250 students
	bool exits=false;//cycles continuously back to main menu
	while (!exits){//while exits is not true
	cout << "Student Project Database"<<endl;//main menu
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
	switch (option){//switch case for option set
		case 0: cout <<"Now quitting..";//pressing 0 to quit
			exits = true;//cuts off loop to main menu
			break;//terminates case
		case 1: cout <<"Please give number of students ";
			cin >> n;
			for (int i=0; i<=7; i++){//for loop for projects
				for (int j=0; j<=n-1; j++){//for loop for students
					cout <<"Please give grade of student "<<j+1<<" in project "<< i+1<< ": ";
					cin >> array1[i][j];////locates point in array
				}
			}
			cout <<endl;
			break;
		case 2: if (n==0){//warns user about not entering data yet
			cout << "No scores stored yet."<<endl<<endl;
			    break;
				}
				else {
					int projectnumber;//number of projects 
					cout << "Give the number of the project: ";
					cin >> projectnumber;
					if (projectnumber >8 || projectnumber<1){//filters through numbers to make sure only 1-8 are accepted
						cout<<"Invalid choice. Only projects 1-8 can be chosen."<<endl<<endl;
					break;
					}
					float average;//average for a project
					int sum=0;//total sum for project 2
					for(int k=0; k<n; k++){
						sum += array1[projectnumber][k];
					}
					average = (float)sum/n;//divides total score by number of students
					cout <<average<<endl<<endl;
				break;
				}
		case 3: if (n==0){//makes sure scores have been input
			cout << "No scores stored yet."<<endl<<endl;
			    break;
				}
				else {
					int sum2=0;//total sum of all scores for all projects for all students
					float average2;
					for(int l=0; l<8; l++){
						for (int m=0; m<n; m++){
							sum2 += array1[l][m];
						}
					}
					average2= (float)sum2/(n*8);//total sum divided by the TOTAL number of projects
					cout << "The average of the class is: "<<average2<<"."<<endl<<endl;//displays class average
				break;
				}
		case 4: if (n==0){
			cout << "No scores stored yet."<<endl<<endl;
			    break;
				}
				else {
					int n2;//student number
					int sum3=0;//sum of all projects for 1 student
					float average3;//average for one student
					cout <<"Please give the student #: ";
					cin >> n2;
					if (n2>n){//makes sure that student number is not higher than the number of students
						cout <<"Invalid choice for student #."<<endl<<endl;
						break;
					}
					for (int l=0; l<8; l++){
						sum3 += array1[l][n2-1];//sums one students score for all projects
					}
					average3= (float)sum3/8;//total score over number of projects
					grade(average3);//runs average3 through grade function
					if (gradeletter[0]=='F'){
						cout <<"student "<<n2<<" failed the course."<<endl<<endl;//accounts for failures
					}
					else {
						cout <<"The letter grade for student "<<n2<<" is " <<gradeletter[0]<<gradeletter[1]<<endl<<endl;//displays result as a character array
					}
				break;
				}
		default: {
			cout << "Invalid choice. Only options 1-4 are allowed." <<endl<<endl;//allows for only appropriate main menu choices
			break;
				 }


	}
	}
}

