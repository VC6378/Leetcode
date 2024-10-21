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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int first;
            int second;
            int mini=q.front().second;
            int si=q.size();
            for(int i=0;i<si;i++){
                int currid=q.front().second-mini;
                TreeNode *node=q.front().first;
                q.pop();
                if(i==0) first=currid;
                if(i==si-1) second=currid;

                if(node->left){
                    q.push({node->left,(long long)2*currid+1});
                }
                if(node->right){
                    q.push({node->right,(long long)2*currid+2});
                }
            }
            ans=max(ans,second-first+1);
        }
        return ans;
    }
};