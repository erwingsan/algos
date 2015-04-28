#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

class Solution {
public:
    vector<string> res;
    map<string, int> resmap;
    vector<string> generateParenthesis(int n) {
        int left(n-1);
        int right(n);
        
        string curr = "(";
        
        goforit(curr, left, right);
        
        return res;
        
    }
    
    void goforit(string curr, int left, int right){
        
        if(left == 0  && right == 0){
            if( resmap.find(curr) == resmap.end()){
                res.push_back(curr);
                resmap[curr] = 1;
            }
            return;
        }
        
        if(left == right){
            goforit(curr+"(", left-1, right);
        }
        else{
            // open a new one
            if(left != 0){
                goforit(curr+"(", left-1, right);
            }
            // close one
            for(int i = 0; i < right; ++i){
                goforit(curr+")", left, right-1);
            }
        }
    }
};

int mainPAR(){
    
    Solution sol;
    
    cout << " Parenthesis" << endl;
    vector<string> r = sol.generateParenthesis(2);
    
    for(int i =0; i<r.size(); ++i){
        cout << r[i] << endl;
    }
    
    return 0;
}
