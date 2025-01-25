#include <iostream>
#include "backtracking.h"

vector <vector <int> > permute(vector <int> nums) {
    vector <vector <int> > permutations;
	btPerm(nums, permutations, 0);
	return permutations;
}

void btPerm(vector <int> & nums, vector <vector <int> > & res, int ind) {
	if(ind == nums.size()) {
		res.push_back(nums);
		return;
	}
	
	int i = ind;
	while(i < nums.size()) {
		swapper(nums.at(ind), nums.at(i));
		btPerm(nums, res, ind + 1);
		swapper(nums.at(ind), nums.at(i));
		i++;
	}
}

void swapper(int & a, int & b) {
	//std::cout << a << b << " xx " << endl;
	/*a = a + b;
	b = a - b;
	a = a - b;*/
	//? Why not the aritmetic swap? Well, references...
	int aux = a;
	a = b;
	b = aux;
	//std::cout << a << b << " zz " << endl;
}