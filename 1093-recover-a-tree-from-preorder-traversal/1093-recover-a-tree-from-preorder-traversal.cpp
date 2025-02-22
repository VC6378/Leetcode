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
    int ind=0;
    int level=0;
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.size();
        string s = traversal;
        TreeNode *node = new TreeNode(-1);
        helper(node,0,s);
        return node->left;
    }

    void helper(TreeNode *parent,int lvl,string s){
        while(ind<s.size() && lvl == level){
            int num=0;
            while(ind<s.size() && isdigit(s[ind])){
                num = num*10+(s[ind++]-'0');
            }
            TreeNode *newNode = new TreeNode(num);
            if(!parent->left){
                parent->left=newNode;
            }
            else{
                parent->right=newNode;
            }
            level=0;
            while(ind<s.size() && s[ind]=='-'){
                level++;
                ind++;
            }
            helper(newNode,lvl+1,s);
        }
    }
};