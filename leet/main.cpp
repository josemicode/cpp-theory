#include <chrono>
#include <vector>
#include "maps.h"

class Timer{
	private:
		auto start;
		auto end;
	public:
		Timer(){
			start = chrono::high_resolution_clock::now();
		}
		auto getPerformance(){
			end = chrono::high_resolution_clock::now();
			return ((end - start).count());
		}
};

int main(){
	vector<string> problems = {"ransomNote"};
	cout << "Select test case index: " << endl;
	int index;
	cin >> index;
	switch(index){
		case 1:{
			Timer ti = Timer();
			string* a = new string;
			string* b = new string;

			cout << "\na: ";
			cin >> *a;
			cout << "\nb: ";
			cin >> *b;

			canConstruct(*a, *b) ? cout << *a << " can be constructed with " << *b << endl : cout << "Incompatible strings" << endl;
			delete a;
			delete b;

			cout << ti.getPerformance;
			break;
		       }
		default:
			cout << "DEFAULT" << endl;
	}
	return 0;
}
