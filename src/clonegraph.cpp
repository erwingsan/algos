#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

void printg(UndirectedGraphNode *node);





class Solution {
public:
	 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

	        //Create queue for traversing
	        queue<UndirectedGraphNode*> qq;
	        queue<UndirectedGraphNode*> qClone;

	        //mark item
	        map<UndirectedGraphNode*, bool> marked;
	        map<int, UndirectedGraphNode*> pool;

	        //clone root
	        UndirectedGraphNode *rootClone = new UndirectedGraphNode(node->label);
	        marked[node] = true;
	        pool[rootClone->label] = rootClone;

	        qq.push(node);
	        qClone.push(rootClone);

	        while(!qq.empty()){
	            //get elements from queue;
	            UndirectedGraphNode *c = qq.front();
	            UndirectedGraphNode *cClone = qClone.front();
	            qq.pop();
	            qClone.pop();

	            //iterate in neighbors
	            for(vector<UndirectedGraphNode*>::iterator it = c->neighbors.begin(); it != c->neighbors.end(); ++it){
	                if(!marked[(*it)]){
	                    UndirectedGraphNode* nClone = new UndirectedGraphNode((*it)->label);
	                    //add to clone neighbor
	                    cClone->neighbors.push_back(nClone);
	                    //add to queues
	                    qq.push((*it));
	                    qClone.push(nClone);
	                    marked[(*it)] = true;
	                    pool[(*it)->label] = nClone;
	                }
	                else{
	                     //add to clone neighbor
	                    cClone->neighbors.push_back(pool[(*it)->label]);
	                }
	            }

	        }

	    return rootClone;
	    }
};




int mainCG() {

	// Create nodes

	UndirectedGraphNode *zero = new UndirectedGraphNode(0);
	UndirectedGraphNode *one = new UndirectedGraphNode(1);
	UndirectedGraphNode *two = new UndirectedGraphNode(2);

	// set neighbors
	zero->neighbors.push_back(one);
	zero->neighbors.push_back(two);
	one->neighbors.push_back(two);
	two->neighbors.push_back(two);

	printg(zero);

	Solution sol;

	UndirectedGraphNode *clone = sol.cloneGraph(zero);

	printg(clone);

    return 0;

}




void printg(UndirectedGraphNode *node){

	queue<UndirectedGraphNode*> q;
	q.push(node);
	map<int, bool> marked;

	marked[node->label] = true;

	while(!q.empty()){
		UndirectedGraphNode* c = q.front();
		q.pop();
		// print node
		cout << c->label << " -> ";

		//it trough neighbors
        for(vector<UndirectedGraphNode*>::iterator it = c->neighbors.begin(); it != c->neighbors.end(); ++it){
        	if(!marked[(*it)->label]){
        		q.push(*it);
        		marked[(*it)->label] = true;
        	}
        	//print neighbor
        	cout << (*it)->label << " ";
        }

        cout << endl;
	}
}
