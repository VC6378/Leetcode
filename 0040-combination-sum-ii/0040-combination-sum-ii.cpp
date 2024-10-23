class Solution {
public:
    vector<vector<int>> ans;

    void solve(int ind,vector<vector<int>> &ans,vector<int> &vec,vector<int> &candi,int target){
        if(target==0){
            ans.push_back(vec);
            return;
        }
        for(int i=ind;i<candi.size();i++){
            if(i>ind && candi[i]==candi[i-1]) continue;
            if(candi[ind]>target) break;
            vec.push_back(candi[i]);
            solve(i+1,ans,vec,candi,target-candi[i]);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(),candi.end());
        vector<int> vec;
        solve(0,ans,vec,candi,target);
        return ans;
    }
};