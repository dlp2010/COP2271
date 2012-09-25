// Project2_Preston.cpp : Performs various operations involving the Lucas Sequence
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
using namespace std;

int main(void)
{
	int n;
	int L1;
	int L2;
	int L3;
	char option;
	int num;
	
	while(boolean exits = true){
	cout <<"Lucas Numbers Calculator" << endl;
	cout <<"Please enter one of the following choices."<< endl;
	cout <<"1. To find if a number belongs to the series or not." << endl;
	cout <<"2. To find the n-th number in rank." << endl;
	cout <<"3. To compute the sum of all the Lucas numbers up to a given bound."<< endl <<endl;
	cout <<"Please choose. ";
	cin >> option;
	cout << endl;
	switch(option) {
		case '1':{ cout <<"Please give the number you want to check.";
				cin >> num;
				L1=2;
				L2=1;
				if(num <=0){
				cout << "Only positive numbers are accepted." << endl;
				}
				else if (num==2){
					cout << num << " IS a Lucas number " << endl;
				}
				else if (num==1){
					cout << num << " IS a Lucas number " << endl;
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
			   }
				 break;
		case '2': {cout <<"Please give the rank of the number you are looking for: ";
				cin >> n;
				int fnum;
				L1=2;
				L2=1;
				if(n <= 0){
					cout << "Only positive numbers are accepted." << endl;
				}
				else if(n == 1){
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
					cout << fnum<< " is the " << n << "-"<< "st" << " Lucas number.\n" << endl;
				}
				else if(onesdigit == 2){
					cout << fnum<< " is the " << n << "-"<< "nd" << " Lucas number.\n" << endl;
				} 
				else if(onesdigit == 3){
					cout << fnum<< " is the " << n << "-"<< "rd" << " Lucas number.\n" << endl;
				}
				else{
					cout << fnum<< " is the " << n << "-"<< "th" << " Lucas number.\n" << endl;
				}

				
				}
				  break;
		case '3': cout <<"Please enter the upper bound of the summation you are looking for: ";
				cin >> num;
				L1=2;
				L2=1;
				L3=L2+L1;
				int total;
				if(num <= 0){
					cout << "Only positive numbers are accepted." << endl;
				}
				else if(num == 1){
					total=L1+L2;
				}
				else if(num == 2){
					total=L1;
				}
				else{
					total=3;
				while(boolean sum = true){
					if (L3 > num){
						break;
					}
					else {
					 L3=L1+L2;
				 	 L1=L2;
					 L2=L3;
				     total= total+L3;
					}
			    }
				}
				cout << total << " is the summation of all Lucas numbers until " << num << endl;

				break;
		case 'q':{
			     cout << "Now quitting." << endl;
				 exits = false;
				 exit(0);
				 }

		default:{
				cout << "Wrong choice. Please choose again." << endl;
				}
				
		}
		
	}
	}