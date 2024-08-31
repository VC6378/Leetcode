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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        
        TreeNode *root=f(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }

    TreeNode *f(vector<int> &preorder,int prst,int pren,vector<int> &inorder,int inst,int inen,map<int,int> &mp){
        if(prst>pren || inst>inen) return NULL;
        TreeNode *root = new TreeNode(preorder[prst]);
        int pos=mp[preorder[prst]];
        int lft=pos-inst;
        root->left=f(preorder,prst+1,prst+lft,inorder,inst,pos-1,mp);
        root->right=f(preorder,prst+lft+1,pren,inorder,pos+1,inen,mp);
        return root;
    }
};