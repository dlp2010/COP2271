// Project1_Preston.cpp :Provides Common Unit Conversions
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

int main(void) 
{
	int number
	float Tc; //Temperature in Celsius
	float Tf; //Temperature in Fahrenheit
	float Dist_met; //Distance in meters
	float Dist_ft; //Distance in feet
	float Kg; //Weight in Kilograms
	float Lb; //Weight in pounds

	cout << "Converter Main Menu\n";
	cout << "1. For Temperature Conversions";
	cout << "2. For Distance Conversions";
	cout << "3. For Weight Conversions\n";
	cout << "Press any other number to quit";
	cout << "Enter your choice here:\n";
	cin >> number;
	switch(number) {
		case 1: cout << "Please choose";
			cout << "1. Fahrenheit --> Celsius";
			cout << "2. Celsius --> Fahrenheit";
			cin >> option;
				switch(option) {
					case 1: cout << "Please give the degrees in Fahrenheit";
						cin >> Tf;
						Tc = (5/9)*(Tf-32);
						cout << Tf << "degrees in Fahrenheit corresponds to" << Tc <<"degrees in Celsius";
					case 2 : cout << "Please give the degrees in Celsius";
						cin >> Tc;
						Tf = ((9/5)*Tc)+32
						cout << Tc << "degrees in Celsius corresponds to" << Tf << "degrees Fahrenheit";
					break; 
		case 2: cout << "Please choose";
			cout << "1. Feet --> Meters";
			cout << "2. Meters --> Feet";
			cin >> optionset2
				switch(optionset2) {




