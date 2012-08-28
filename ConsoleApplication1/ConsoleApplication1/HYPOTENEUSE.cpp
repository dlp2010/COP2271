//HYPOTENEUSE.cpp
//Computes hypoteneuse 

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;


int main(void)
{
		float side1;
		float side2;
		float hypot;

		cout << "Length of Side 1?";
		cin >> side1;
		cout << "Length of Side 2?";
		cin >> side2;
		hypot = sqrt ( side1*side1 + pow(side2,2) );
		cout << "Hypoteneuse is:" << hypot << endl;
		
		system("PAUSE");
		return 0;
}