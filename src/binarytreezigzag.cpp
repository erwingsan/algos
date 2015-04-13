//
//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example:
//Given binary tree {3,9,20,#,#,15,7},
//
//3
/// \
//9  20
///  \
//15   7
//
//return its zigzag level order traversal as:
//
//[
// [3],
// [20,9],
// [15,7]
// ]

//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <stack> 
#include <queue> 
#include <iostream> 

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        //BFS with stack and queue
        stack<TreeNode*> qq;
        stack<TreeNode*> ss;
        
        vector<vector<int> > v;
        
        if(root)
            qq.push(root);

        vector<int> tmp;
        
        while(!ss.empty() || !qq.empty()){
            //Empty queue
            if(!qq.empty()){
                while(!qq.empty()){
                    // take item
                    TreeNode *c = qq.top();
                    qq.pop();
                
                    //Insert in vector
                    tmp.push_back(c->val);
                
                    //Insert children in stack
                    if(c->left)
                        ss.push(c->left);
                    if(c->right)
                        ss.push(c->right);
                
                }
                //increment
                v.push_back(tmp);
                tmp.clear();
            }
            else{
                while(!ss.empty()){
                    // take item
                    TreeNode *c = ss.top();
                    ss.pop();
                
                    //Insert in vector
                    tmp.push_back(c->val);
                
                    //Insert children in queue
                    if(c->left)
                        qq.push(c->left);
                    if(c->right)
                        qq.push(c->right);
                
                }
                //increment
                v.push_back(tmp);
                tmp.clear();
            }
            
        }
        return v;
    }
};

int main(){
    Solution sol;
    // 	{1,2,3,4,#,#,5}
    TreeNode *root = new TreeNode(1);
    TreeNode *two = new TreeNode(2);
    TreeNode *three = new TreeNode(3);
    TreeNode *four = new TreeNode(4);
    TreeNode *five = new TreeNode(5);
    
    root->left = two;
    root->right = three;
    two->left = four;
    three->right = five;
    
    vector<vector<int> > ans = sol.zigzagLevelOrder(root);
    
    cout << "Done! " << endl;
    
}
