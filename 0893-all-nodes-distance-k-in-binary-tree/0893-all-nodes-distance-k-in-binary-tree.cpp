/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void makPar(unordered_map<TreeNode*,TreeNode*> &mp,TreeNode*root,TreeNode*target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        makPar(mp,root,target);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=1;
        int lvl=0;
        while(!q.empty()){
            int sz=q.size();
            if(lvl++==k) break;
            for(int i=0;i<sz;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(mp[node] && !vis[mp[node]]){
                    vis[mp[node]]=1;
                    q.push(mp[node]);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};