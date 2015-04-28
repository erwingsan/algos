#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:

	int recursiveme(vector<int> &num, vector<vector<int> > &res, vector<int> &curr, int pos, int target){

		// check limit for pos
		if(pos >= num.size())
			return 0;

		// push the element in curr
		curr.push_back(num[pos]);

		// check sum

		int sum = target - num[pos];

		if(sum == 0){ //found!
			res.push_back(curr);
			curr.pop_back();
			return 1;
		}

		if(sum > 0){
			int tmp = recursiveme(num, res, curr, pos+1, sum);
			curr.pop_back();
			return tmp + recursiveme(num, res, curr, pos+1, target);
		}

		//else dont use it
		curr.pop_back();
		return recursiveme(num, res, curr, pos+1, target);

	}

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    	vector<vector<int> > res;
    	vector<int> curr;

    	sort(num.begin(), num.end());

    	int total = recursiveme(num, res, curr, 0, target);

    	cout << total << endl;

    	return res;

    }
};

void print1v(vector<int> myv){
	for (int i = 0; i< myv.size(); ++i){
		cout << myv[i] << " ";
	}
	cout << endl;
}

void printvs(vector<vector<int> > myvv){
	for (int i = 0; i< myvv.size(); ++i){
		print1v(myvv[i]);
	}
	cout << endl;
}

int main(){

	vector<int> num;
	num.push_back(10);
	num.push_back(1);
	num.push_back(2);
	num.push_back(7);
	num.push_back(6);
	num.push_back(1);
	num.push_back(5);

	cout << "Combinatorial Sum: " << endl;

	Solution sol;
	vector< vector<int> > resp = sol.combinationSum2(num, 8);

	printvs(resp);






}
