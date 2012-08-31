// Project1_Preston.cpp :Provides Common Unit Conversions
//

#include "stdafx.h" //required for Visual C++ solutions
#include <iostream>
#include <stdlib.h>
#include <cmath> //allows mathematical operations
#include <Windows.h>
using namespace std; //denotes use of the standard namespace 

int main(void) 
{
	int number; //input for first selection set
	int option; //input for temperature conversion
	int optionset2; //input for distance conversions
	int optionset3; //input for weight conversions
	float Tc; //Temperature in Celsius
	float Tf; //Temperature in Fahrenheit
	float Dist_met; //Distance in meters
	float Dist_ft; //Distance in feet
	float Kg; //Weight in Kilograms
	float Lb; //Weight in pounds

	cout << "Converter Main Menu\n";
	cout << "1. For Temperature Conversions\n";
	cout << "2. For Distance Conversions\n";
	cout << "3. For Weight Conversions\n";
	cout << "Press any other number to quit\n";
	cout << endl;
	cout << "Enter your choice here:";
	cin >> number; //first user input
	switch(number) {
		case 1: cout << "Please choose\n"; //first sub-option set
			cout << "1. Fahrenheit --> Celsius\n";
			cout << "2. Celsius --> Fahrenheit\n";
			cout << endl; //extra space for aesthetic reasons
			cout << "Enter your choice here:";
			cin >> option;
				switch(option) {
					case 1: cout << "Please give the degrees in Fahrenheit: "; //requesting user input
						cin >> Tf;
						Tc = (float) ((5.0/9.0)*(Tf-32.0)); //formula for conversion
						cout << Tf << " degrees in Fahrenheit corresponds to " << Tc << " degrees Celsius\n";
						cout << "Program finished. Quitting\n";
						cout << endl;
						Sleep(2000); //temporary delay before shutdown
						exit(0);
					case 2 : cout << "Please give the degrees in Celsius: ";
						cin >> Tc;
						Tf = (float) (((9.0/5.0)*Tc)+32.0);
						cout << Tc << " degrees in Celsius corresponds to " << Tf << " degrees Fahrenheit\n";
						cout << "Program finished. Quitting\n";
						cout << endl;
						Sleep(2000);
						exit(0);
					break; //denotes the end of the first switch case sub-option set
								}
		case 2: cout << "Please choose\n";
			cout << "1. Feet --> Meters\n";
			cout << "2. Meters --> Feet\n";
			cout << endl;
			cout << "Enter your choice here:";
			cin >> optionset2;
				switch(optionset2) {
					case 1: cout << "Please give the distance in feet: ";
						cin >> Dist_ft;
						Dist_met = (float) (Dist_ft*0.3048);
						cout << Dist_ft << " feet corresponds to " << Dist_met << " meters.\n";
						cout << "Program finished. Quitting\n";
						cout << endl;
						Sleep(2000);
						exit(0);
					case 2: cout << "Please give the distance in meters: ";
						cin >> Dist_met;
						Dist_ft = (float) (Dist_met/0.3048);
						cout << Dist_met << " meters corresponds to " << Dist_ft << " feet.\n";
						cout << "Program finished. Quitting\n";
						cout << endl;
						Sleep(2000);
						exit(0);
					break;
									}
		case 3: cout << "Please choose\n";
			cout << "1. Kilogram --> Pounds\n";
			cout << "2. Pounds --> Kilograms\n";
			cout << endl;
			cout << "Enter your choice here:";
			cin >> optionset3;
				switch(optionset3) {
					case 1: cout << "Please give the weight in kilograms: ";
						cin >> Kg;
						Lb = (float) (Kg*2.2);
						cout << Kg << " kilograms" << "corresponds to " << Lb << " pounds.\n";
						cout << "Program finished. Quitting\n";
						cout << endl;
						Sleep(2000);
						exit(0);
					case 2: cout << "Please give the weight in pounds: ";
						cin >> Lb;
						Kg = (float) (Lb/2.2);
						cout << Lb << " pounds corresponds to " << Kg << " kilogram(s).\n";
						cout << "Program finished. Quitting\n";
						cout << endl;
						Sleep(2000);
						exit(0);
					break; 
									}
					
		default: //what to display when the user selects a different option than those provided
			cout << "manual quit\n"; //output when user selects anything else
			cout << endl;
			Sleep(2000);
			exit(0);
			break; 
			break; //end of switch case
				}

	exit(0); //program finished
}


