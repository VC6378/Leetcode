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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode *node = new TreeNode(val);
            return node;
        }
        TreeNode *curr=root;
        while(true){
            if(curr->val <= val){
                if(curr->right){
                    curr=curr->right;
                }
                else{
                    TreeNode *hehe = new TreeNode(val);
                    curr->right=hehe;
                    break;
                }
            }
            else{
                if(curr->left){
                    curr=curr->left;
                }
                else{
                    TreeNode *hehe = new TreeNode(val);
                    curr->left=hehe;
                    break;
                }
            }
        }
        return root;
    }
};