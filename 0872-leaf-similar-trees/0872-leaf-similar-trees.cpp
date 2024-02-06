/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void f(TreeNode *root,vector<int> &vec){
        if(root==NULL) return;
        f(root->left,vec);
        if(root->left==NULL && root->right==NULL){
            vec.push_back(root->val);
        }
        f(root->right,vec);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> one;
        vector<int> two;
        f(root1,one);
        f(root2,two);
        if(one.size()!=two.size()) return false;
        else{
            for(int i=0;i<one.size();i++){
                if(one[i]!=two[i]) return false;
            }
            return true;
        }
    }
};