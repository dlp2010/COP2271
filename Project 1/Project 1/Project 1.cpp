#include <iostream>
//add math header
using namespace std;


	
int main()
{
  int input;
  
  cout<<"1. Play game\n"; //Change to match pdf
  cout<<"2. Load game\n";//Change to match pdf
  cout<<"3. Play multiplayer\n";//Change to match pdf
  cout<<"4. Exit\n";//Change to match pdf
  cout<<"Selection: ";//Change to match pdf
  cin>> input;
  switch ( input ) {
  case 1:            // Note the colon, not a semicolon
    //Input temperature here
    break;
  case 2:            // Note the colon, not a semicolon
    //Distance
    break;
  case 3:            // Note the colon, not a semicolon
    //Weight
    break;
  default:            // Note the colon, not a semicolon, default means any other input besides cases states above
    cout<<"Error, bad input, quitting\n"; //Change to match pdf
    break;
  }
  cin.get();
}