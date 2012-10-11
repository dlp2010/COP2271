// Project3_Preston: Functions and the Taylor Series

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

int factorial (int a){
	int fact;
	for (int i=a; i>0; i--){
		fact *=i;
	}
	return fact;
}

double Taylorsine (float x, int n){
	double Taylorval;
	for (n; n>=0; n--){
	Taylorval += ((pow(-1,n)/factorial(2*n+1))*pow(x,(2*n+1)));
	}
	return Taylorval;
}

double Taylorcos (float x, int n){
	double Taylorval;
	for (n; n>=0; n--){
	Taylorval += ((pow(-1,n)/factorial(2*n))*pow(x,(2*n)));
	}
	return Taylorval;
}

int main (void){
	int option;
	int angle1 = NULL;
	int n1= NULL;

	while (boolean continues = true){
	cout << "MAIN MENU" <<endl;
	cout << "1. To enter the data." <<endl;
	cout << "2. To calculate and approximate the sin(x)" <<endl;
	cout <<	"3. To calculate and approximate the cos(x)" <<endl;
	cout << "4. To modify data." <<endl;
	cout << "Please make a choice:" <<endl;
	cin >> option;
	switch (option){
		case 0: cout << "Are you sure you want to quit? (Y/N):"<<endl;
				char input;
				cin >> input;
				if (input=='y'||input =='Y'){
					continues = false;
					break;
				}
		case 1: if (angle1==NULL){
				cout <<"Please give a value for the angle:"<<endl;
				cin >> angle1;
				}
				if (n1==NULL){
				cout <<"Please give a value for the approximation order n:" <<endl;
				cin >> n1;
				}
				else {
					cout << "Please use the modify option to enter a new angle." <<endl; 
				}
				break;
		case 2: if (angle1==NULL || n1==NULL){
					cout << "You have to enter a value first!" <<endl;
				}
				cout << "The sine of x is: " << sin(angle1) << endl;
				cout << "Using Taylor series it is: " << Taylorsine(angle1,n1) <<endl;
				break;
		case 3:if (angle1==NULL || n1==NULL){
					cout << "You have to enter a value first!" <<endl;
				}
				cout << "The cosine of x is: " << cos(angle1) << endl;
				cout << "Using Taylor series it is: " << Taylorcos(angle1,n1) <<endl;
				break;
		case 4: cout << "Old angle = " << angle1 <<endl;
				cout << "Old approximation = " << n1 <<endl;
				cout << "Please give new angle: "<<endl;
				cin >> angle1;
				cout << "Please give new n: "<<endl;
				cin >> n1;
				break;
		default: {
			cout << "Wrong choice. Only options 1-4 are available."<< endl;

				 }
	}
	}
}
			
				


