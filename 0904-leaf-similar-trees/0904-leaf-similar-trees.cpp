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

    void f(TreeNode *root,vector<int> &inorder){
        if(root==NULL) return;
        f(root->left,inorder);
        if(root->left==NULL and root->right==NULL){
            inorder.push_back(root->val);
            return;
        }
        f(root->right,inorder);
    }

    bool leafSimilar(TreeNode* one, TreeNode* two) {
        vector<int> o;
        vector<int> t;
        f(one,o);
        f(two,t);

        if(o.size()!=t.size()) return false;
        int n=o.size();
        for(int i=0;i<n;i++){
            if(o[i]!=t[i]) return false;
        }
        return true;
    }
};