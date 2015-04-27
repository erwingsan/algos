#include <iostream>
#include <vector>

using namespace std;



class Solution{
public:
	vector<vector<int> > res;
	void goforit(vector<int> &num, vector<int> &visited, vector<int> curr, int pos){

		// update curr and visited
		curr.push_back(num[pos]);

		// check if we're done
		if(curr.size() == num.size()){
			res.push_back(curr);
			curr.pop_back();
			return;
		}
		visited[pos] = 1;

		for(int i = 0; i < num.size(); ++i){
			if(visited[i] == 0)
				goforit(num, visited, curr, i);
		}

		curr.pop_back();
		visited[pos] = 0;
	}

	vector<vector<int> > permut(vector<int> &num){

		vector<int> visited(num.size(), 0);
		vector<int> curr;

		for(int i = 0; i < num.size(); ++i){

			goforit(num, visited, curr, i);

		}


	}
};

void printonev(vector<int> myv){
	for (int i = 0; i< myv.size(); ++i){
		cout << myv[i] << " ";
	}
	cout << endl;
}

void printmanyv(vector<vector<int> > myvv){
	for (int i = 0; i< myvv.size(); ++i){
		printonev(myvv[i]);
	}
	cout << endl;
}

int main(){

	cout << "Permutation "<< endl;

	vector<int> myv;
	myv.push_back(1);
	myv.push_back(2);
	myv.push_back(3);

	cout << "Initial vector " << endl;
	printonev(myv);

	Solution sol;
	vector<vector<int> > myvv = sol.permut(myv);


	printmanyv(myvv);


}
