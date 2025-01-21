#include <iostream>
#include <chrono>
#include <vector>
#include "maps.h"

class Timer{
	private:
		chrono::high_resolution_clock::time_point start;
		chrono::high_resolution_clock::time_point end;

	public:
		Timer() {
			start = chrono::high_resolution_clock::now();
		}

		void stopTimer() {
			end = chrono::high_resolution_clock::now();
		}

		auto getPerformance() {
			return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		}
};

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

			bool compatible;
			Timer ti = Timer();
			compatible = canConstruct(*a, *b);
			ti.stopTimer();

			compatible ? cout << *a << " can be constructed with " << *b << endl : cout << "Incompatible strings" << endl;
			delete a;
			delete b;

			cout << ti.getPerformance() << " ns" << endl;
			break;
		}
		default:
			cout << "DEFAULT" << endl;
	}
	return 0;
}
