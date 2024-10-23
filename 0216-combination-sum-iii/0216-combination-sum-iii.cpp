class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind,vector<int> &temp,vector<int> &vec,int k,int tar){
        if(tar==0){
            if(temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }

        for(int i=ind;i<vec.size();i++){
            if(i>ind && vec[i]==vec[i-1]) continue;
            if(vec[i]>tar) break;
            temp.push_back(vec[i]);
            solve(i+1,temp,vec,k,tar-vec[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int tar) {
        vector<int> vec;
        for(int i=1;i<=9;i++){
            vec.push_back(i);
        }
        vector<int> temp;
        solve(0,temp,vec,k,tar);
        return ans;
    }
};