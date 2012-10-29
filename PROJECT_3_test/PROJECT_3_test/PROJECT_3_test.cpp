// Project3_Preston: Functions and the Taylor Series

#include "stdafx.h" 
#include <cstdlib> //uses the standard C++ Library
#include <iostream> //Input/output for C++
#include <cmath> //allows for use of the math directory
#include <Windows.h>
using namespace std; //uses standard namespace

int factorial (int a){ //first function. returns factorial
	int fact=1; //initializes factorial term
	for (int i=a; i>0; i--){ //initializes for loop for factorial
		fact *=i; //recursive term for factorial
	}
	return fact;
}

double Taylorsine (float x, int n){ //function for Taylor approximation of the sine function
	double Taylorval=0; //initializes the Taylor sine approximation function
	for (n; n>=0; n--){ //initializes for loop for Taylor series
	Taylorval += ((pow(-1,n)/factorial(2*n+1))*pow(x,(2*n+1))); //recursive term
	}
	return Taylorval;
}

double Taylorcos (float x, int n){ //Taylor cosine approximation 
	double Taylorval=0;//initializes Taylor series approximations
	for (n; n>=0; n--){ //initializes for loop for Taylor cosine approximation
	Taylorval += ((pow(-1,n)/factorial(2*n))*pow(x,(2*n))); //recursive term
	}
	return Taylorval;
}

int main (void){ //start of main function
	int option; //Main menu option set
	float angle1 = NULL; //will check if angle is already stored or needs to be stored for the first time
	int n1= NULL; //will check if approximation term is already stored

	while (boolean continues = true){ //term that allows main menu to continue looping
	cout << "MAIN MENU" <<endl; //main user menu
	cout << "1. To enter the data." <<endl;
	cout << "2. To calculate and approximate the sin(x)" <<endl;
	cout <<	"3. To calculate and approximate the cos(x)" <<endl;
	cout << "4. To modify data." <<endl;
	cout << "Please make a choice:";
	cin >> option; //user choice from main menu
	switch (option){
		case 0: cout << "\nAre you sure you want to quit? (Y/N): ";//quitting term
				char input;
				cin >> input;
				cout << endl;
				if (input=='y'||input =='Y'){ //allows for upper and lowercase "y"
					continues = false; //terminated the while loop , quitting the main menu
					exit(0); //terminates program
				}
				break;
		case 1: if (angle1==NULL){ //checks if angle is stored already
				cout <<"Please give a value for the angle:"; //requests user to input angle (in radians)
				cin >> angle1; // user input of angle
				}
				if (n1==NULL){// checks if approximation term is stored already
				cout <<"Please give a value for the approximation order n:"; //request for approximation term
				cin >> n1; //user input for approximation term
				cout << endl;
				}
				else { //warns user that data is already stored
					cout << "Please use the modify option to enter a new angle.\n" <<endl; 
				}
				break;
		case 2: if (angle1==NULL || n1==NULL){ //warns the user that they cannot approximate sine or cosine without values 
					cout << "You have to enter a value first!\n" <<endl;
				}
				else { //uses pre-stored values
					cout << "The sine of x is: " << sin(angle1) << endl; //gives the REAL sine function
					cout << "Using Taylor series it is: " << Taylorsine(angle1,n1) <<endl <<endl; //gives the TAYLOR APPROXIMATION for sine
				}
				break;
		case 3:if (angle1==NULL || n1==NULL){ //prohibits user from calculating cosine without values
					cout << "You have to enter a value first!\n"<<endl; 
				}
				else{ 
					cout << "The cosine of x is: " << cos(angle1) << endl; //gives the REAL cosine function
				cout << "Using Taylor series it is: " << Taylorcos(angle1,n1) <<endl << endl; //gives the TAYLOR APPROXIMATION for cosine
				}
				break;
		case 4: cout << "Old angle = " << angle1 <<endl; //displays previous angle
				cout << "Old approximation = " << n1 <<endl; //displays previous approximation term
				cout << "Please give new angle: "; //request for new angle
				cin >> angle1;
				cout << "Please give new n: "; //request for new approximation term
				cin >> n1;
				cout << endl;
				break;
		default: {
			cout << "Wrong choice. Only options 1-4 are available.\n"<< endl; //tells user that they have to select only listed options

				 }
	}
	}
}

