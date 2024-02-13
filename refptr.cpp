#include<iostream>

using namespace std;



int main(){
	
	string months[] {"Jan", "Feb", "Mar", "Apr", "May", "JUN", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	string pos5copy = months[5];
	string& pos5ref = months[5];
	string* arrayPtr = &months[0];
	
	cout << "Fifth position of the array being called directly: " << months[5] << endl;
	cout << "Value being called from another (copy) variable: " << pos5copy << endl;
	cout << "Position 5's value being called from a reference: " << pos5ref << endl;
	cout << "\nNow the value will be modified...\n" << endl;
	
	pos5ref = "Jun";
	
	cout << "Fifth position of the array being called directly: " << months[5] << endl;
	cout << "Value being called from another (copy) variable: " << pos5copy << endl;
	cout << "Position 5's value being called from a reference: " << pos5ref << endl;
	
	cout << "\nNow, we have initialised a special kind of variable which points at the array's first element: " << arrayPtr << endl;
	cout << "This is a Hexadecimal code that represents the elements's positon in the stack and, as references, needs to be initialised as the same type as the original variable" << endl;
	cout << "We can use it to access its value: " << *arrayPtr;
}

int egFunc(){
	
}