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

    void inorder(TreeNode* root,vector<int> &vec){
        if(root==NULL) return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root,vec);
        int i=0;
        int j=vec.size()-1;
        int sum;
        while(i<j){
            sum=vec[i]+vec[j];
            if(sum==k) return true;
            else if(sum>k){
                j--;
            }
            else if(sum<k){
                i++;
            }
        }
        // cout<<vec[i]<<" "<<vec[j]<<endl;
        return false;
    }
};