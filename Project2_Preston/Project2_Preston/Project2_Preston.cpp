// Project2_Preston.cpp : Performs various operations involving the Lucas Sequence
//

#include "stdafx.h" //Visual C++ standard
#include <iostream>
#include <cmath> //allows use of mathematical library
#include <stdlib.h> //denotes use of standard library
#include <string.h> //allows a string of characters
#include <Windows.h>
using namespace std;

int main(void)
{
	int n; //term in the series
	int L1; //first term
	int L2; //second term
	int L3; //final term
	char option; //allows for the "q" to be used as a quit function
	int num; //the number input required for options 1 and 3
	
	while(boolean exits = true){ //boolean while loop
	cout <<"Lucas Numbers Calculator" << endl; //Main Menu
	cout <<"Please enter one of the following choices."<< endl; //option selection request
	cout <<"1. To find if a number belongs to the series or not." << endl; //option 1
	cout <<"2. To find the n-th number in rank." << endl; //option 2
	cout <<"3. To compute the sum of all the Lucas numbers up to a given bound."<< endl <<endl; //option 3
	cout <<"Please choose. ";
	cin >> option; //user input from main menu
	cout << endl;
	switch(option) { //start of code for first option
		case '1':{ cout <<"Please give the number you want to check.";
				cin >> num; //user input for Lucas series number verification
				L1=2; //defining intial condition
				L2=1; //defining intial condition
				if(num <=0){ //negative numbers case
				cout << "Only positive numbers are accepted." << endl;
				}
				else if (num==2){ //intial case
					cout << num << " IS a Lucas number\n " << endl;
				}
				else if (num==1){ //intial case
					cout << num << " IS a Lucas number\n " << endl;
				}
				else {
					while(boolean found = true){ //another boolean while loop
						   L3=L1+L2; //defining L3 in terms of L1 and L2 for the loop
						   if(L3 == num){ //output equals input, so belongs to the lucas series
							  cout << num << " IS a Lucas number\n" << endl;
						      found = false;
							  break;
						   }
						   else if(L3>num){ //if L3 is larger than the input, the input does not belong in the series
							   cout << num << " is NOT a Lucas number\n" << endl;
							   found = false;
							   break;
						   }
						   L1=L2; //a way to update L1 and L2 terms on a continuous basis
						   L2=L3; //a way to update L2 and L3 terms on a continuous basis
						
					}
				}
			   }
				 break;
		case '2': {cout <<"Please give the rank of the number you are looking for: ";
				cin >> n; //user inputs the term they are looking for
				int fnum; //variable "fnum" is the final number 
				L1=2; //intial conditions
				L2=1; //intial conditions
				if(n <= 0){ //negative number case
					cout << "Only positive numbers are accepted." << endl;
				}
				else if(n == 1){ //initial case
					fnum=L1;
				}
				else if(n == 2){ //inital case
					fnum=L2;
				}
				else{
				   for(int i=3; i<=n; i++){ //loop term
					 L3=L1+L2;
				 	 L1=L2;
					 L2=L3;
				   }
				fnum=L3;
				}
				string ending; //solution to the -th, -rd, -nd, and -st number suffixes
				int onesdigit = fnum % 10; //modular division gives only remainder
				if(onesdigit == 1){ //final digit is one
					cout << fnum<< " is the " << n << "-"<< "st" << " Lucas number.\n" << endl;
				}
				else if(onesdigit == 2){ //final digit is two
					cout << fnum<< " is the " << n << "-"<< "nd" << " Lucas number.\n" << endl;
				} 
				else if(onesdigit == 3){ //final digit is three
					cout << fnum<< " is the " << n << "-"<< "rd" << " Lucas number.\n" << endl;
				}
				else{ //all other final digits (4, 5, 6, 7, 8, 9)
					cout << fnum<< " is the " << n << "-"<< "th" << " Lucas number.\n" << endl;
				}

				
				}
				  break;
		case '3': cout <<"Please enter the upper bound of the summation you are looking for: ";
				cin >> num; //number the user wants to sum to
				L1=2; //intial
				L2=1; //initial
				L3=L2+L1; //equation for L3 based on the other two terms
				int total; //new variable for the summation
				if(num <= 0){ //negative case
					cout << "Only positive numbers are accepted.\n" << endl;
				}
				else if(num == 1){ //1 is the second number, so the sum up to and including 2 is 3
					total=L1+L2;
				}
				else if(num == 2){ //sum of the first term
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
				     total= total+L3; //final total
					}
			    }
				}
				cout << total << " is the summation of all Lucas numbers until " << num << endl <<endl; //displays final total

				break;
		case 'q':{ //manual quit option 
			     cout << "Now quitting." << endl;
				 exits = false;
				 exit(0); //exits the program
				 }

		default:{
				cout << "Wrong choice. Please choose again.\n" << endl;
				} //excludes any other options other than those strictly provided
				
		}
		
	}
	}