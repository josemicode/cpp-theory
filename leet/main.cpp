#include <iostream>
#include <chrono>
#include <vector>
#include "maps.h"
#include "backtracking.h"

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

template <typename T>
void printV(vector <T> v) {
	int i = 0;
	cout << "[ ";
	while(i < v.size()) {
		cout << v.at(i) << " ";
		i++;
	}
	cout << "]" << endl;
}

int main(){
	vector<string> problems = {"ransomNote, permutations"};
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

		case 2:{
			cout << "How many numbers? " << endl;
			int n;
			cin >> n;
			vector <int> nums;
			while(n>0) {
				cout << "--> ";
				int aux;
				cin >> aux;
				nums.push_back(aux);
				cout << endl;
				n--;
			}
			printV(nums);
			vector <vector <int> > res = permute(nums);
			cout << "\nPermutations: " << endl;
			for(int i = 0; i < res.size(); i++) {
				cout << i+1 << " -> ";
				printV(res.at(i));
			}
			break;
		}

		default:
			cout << "DEFAULT" << endl;
	}
	return 0;
}
