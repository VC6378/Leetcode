class Solution {
public:

    bool check(string s){
        string x = s;
        reverse(x.begin(), x.end());
        if (s == x) return true;
        return false;
    }

    void solve(string s,vector<vector<string>> &ans,vector<string> temp,int ind){
        if(ind>=s.size()){
            ans.push_back(temp);
            return;
        }
        string t="";
        for(int i=ind;i<s.size();i++){
            t+=s[i];
            if(check(t)){
                temp.push_back(t);
                solve(s,ans,temp,i+1);
                temp.pop_back();
            }

        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp,0);
        return ans;
    }
};