// Example program
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;


class Solution {
public:
    bool attached(string s1, string s2){
        if(s1.size() != s2.size())
            return false;

        int diff = 0;
        for(int i = 0; i<s1.size() && diff <2; ++i){
            if(s1[i] != s2[i])
                ++diff;
        }

        return diff>1? false : true;
    }

    int ladderLength(string start, string end, set<string> &dict) {

    // create a map to store marked nodes and parent and distance
    map<string, bool> marked;
    map<string, string> parent;
    map<string, int> distance;

    distance[start] = 1;
    marked[start] = true;

    // queue
    queue<string> q;
    q.push(start);

    dict.insert(end);
    marked[end] = false;

    while(!q.empty() && marked[end] == false){
        string current = q.front();
        q.pop();

        for(set<string>::iterator it = dict.begin(); it != dict.end() && marked[end] == false; ++it){
            if(!marked[(*it)]){
                if(attached(current, *it)){
                    q.push(*it);
                    marked[*it] = true;
                    parent[*it] = current;
                    distance[*it] = distance[current] + 1;
                }
            }
        }

    }

    cout <<"Path: " << endl;
    cout << end << endl;
    string p = parent[end];
    while(p != start){
    	cout << p << endl;
    	p = parent[p];
    }
    cout << p << endl;
    return distance[end];
}

};



int mainWL() {

//get strings

	Solution sol;

	string start = "hit";
	string end = "cog";

	set<string> dict;

	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");


	cout << "Dict suboptimal" << endl;

	int d = sol.ladderLength(start, end, dict);

	cout << "Distance from " << start << " to " << end << ": " << d;

    return 0;

}


