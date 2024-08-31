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
    TreeNode* solve(vector<int> &postorder,int ps,int pe,vector<int> &inorder,int is,int ie,map<int,int> &mp){
        if(ps>pe || is>ie) return NULL;
        TreeNode *root = new TreeNode(postorder[pe]);
        int inroot = mp[root->val];
        int left = inroot-is;
        root->left = solve(postorder,ps,ps+left-1,inorder,is,inroot-1,mp);
        root->right = solve(postorder,ps+left,pe-1,inorder,inroot+1,ie,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in = inorder.size();
        int po = postorder.size();
        map<int,int> mp;
        for(int i=0;i<in;i++){
            mp[inorder[i]]=i;
        }
        TreeNode *root = solve(postorder,0,po-1,inorder,0,in-1,mp);
        return root;
    }
};