using namespace std;
#include <vector>

vector <vector <int> > permute(vector <int> nums);
void btPerm(vector <int> & nums, vector <vector <int> > & res, int ind);
void swapper(int & a, int & b);