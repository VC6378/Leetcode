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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        bool f=true;
        while(!q.empty()){
            int si=q.size();
            vector<int> temp(si);
            for(int i=0;i<si;i++){
                TreeNode *t=q.front();
                q.pop();
                int ind=f?i:si-i-1;
                temp[ind]=t->val;
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            f=!f;
            ans.push_back(temp);
        }
        return ans;
    }
};