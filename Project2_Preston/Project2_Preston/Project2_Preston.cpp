// Project2_Preston.cpp : Performs various operations involving the Lucas Sequence
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

int main(void)
{
	int n;
	int L1;
	int L2;
	int L3;
	int Lucas;
	int option;
	int num;
	
	cout <<"Lucas Numbers Calculator" << endl;
	cout <<"Please enter one of the following choices."<< endl;
	cout <<"1. To find if a number belongs to the series or not." << endl;
	cout <<"2. To find the n-th number in rank." << endl;
	cout <<"3. To compute the sum of all the Lucas numbers up to a given bound."<< endl <<endl;
	cout <<"Please choose. ";
	cin >> option;
	cout << endl;
	switch(option) {
		case 1: cout <<"Please give the number you want to check." << endl;
				cin >> num;
				L1=2;
				L2=1;
				if (num==2){
					cout << num << " IS a Lucas number" << endl;
				}
				else if (num==1){
					cout << num << " IS a Lucas number" << endl;
				}
				else {
					while(boolean found = false){
						   L3=L1+L2;
						   if(L3 == num){
							  cout << num << " IS a Lucas number" << endl;
						      found = true;
						   }
						   else if(L3>num){
							   cout << num << " is NOT a Lucas number" << endl;
							   found = true;
						   }
						   L1=L2;
						   L2=L3;
						
					}
				}
		
		case 2: cout <<"Please give the rank of the number you are looking for: " <<endl;
				cin >> n;
				int fnum;
				L1=2;
				L2=1;
				if(n == 1){
                   fnum=L1;
				}
				else if(n == 2){
					fnum=L2;
				}
				else{
				   for(int i=3; i<=n; i++){
					 L3=L1+L2;
				 	 L1=L2;
					 L2=L3;
				   }
				fnum=L3;
				}
				string ending;
				int onesdigit = fnum % 10;
				if(onesdigit == 1){
					ending = "st";
				}
				else if(onesdigit == 2){
					ending = "nd";
				}
				else if(onesdigit == 3){
					ending = "rd";
				}
				else{
					ending = "th";
				}

				cout << fnum<< " is the " << &ending << "- Lucas number." << endl;
		
		case 3: cout <<"Please enter the upper bound of the summation you are looking for: " <<endl;
				cin >> num;



				


