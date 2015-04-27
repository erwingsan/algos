#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        
        //Traverse string to find directories
        char token = '/';
        int dpos;
        queue<string> qq;
        while((dpos = path.find(token)) != string::npos){
            string dir = path.substr(0,dpos+1);
            
            //remove dir from path
            path.erase(0,dir.length());
            
            if(dir.size() <= 1) //empty dir
                continue;
                
                //push directory
            if(dir == "../"){
                if(!qq.empty())
                    qq.pop();
            }
            else if(dir == "./")
                dir = dir; // do nothing
            else
                qq.push(dir.substr(0,dir.size()-1));
        }
            
            string simp_path = "";
            while(!qq.empty()){
                simp_path += "/" + qq.front();
                qq.pop();
            }
            
            if (simp_path == "")
                return "/";
        
            
            return simp_path;
            
        }
};



int mainSP(){
    //string path = "/a/./b/../../c/";
    string path = "/...";
    cout << "Simplify Path" << endl;
    Solution sol;
    cout << sol.simplifyPath(path)<< endl;

    return 0;
}
    


