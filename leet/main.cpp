#include <chrono>
#include <vector>
#include "maps.h"

int main(){
	vector<string> problems = {"ransomNote"};
	cout << "Select test case index: " << endl;
	int index;
	cin >> index;
	switch(index){
		case 1:{
			string* a = new string;
			string* b = new string;

			cout << "\na: ";
			cin >> *a;
			cout << "\nb: ";
			cin >> *b;

			canConstruct(*a, *b) ? cout << *a << " can be constructed with " << *b << endl : cout << "Incompatible strings" << endl;
			delete a;
			delete b;
			break;
		       }
		default:
			cout << "DEFAULT" << endl;
	}
	return 0;
}
