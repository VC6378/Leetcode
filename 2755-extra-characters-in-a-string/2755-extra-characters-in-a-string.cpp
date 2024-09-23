class Solution {
public:

    int solve(int ind,int n,set<string> &st,vector<int> &dp,string s){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int a = 1+solve(ind+1,n,st,dp,s);
        string temp="";
        for(int i=ind;i<n;i++){
            temp+=s[i];
            if(st.count(temp)){
                a=min(a,solve(i+1,n,st,dp,s));
            }
        }
        return dp[ind]=a;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        vector<int> dp(n,-1);
        set<string> st;
        for(int i=0;i<dictionary.size();i++){
            st.insert(dictionary[i]);
        }
        return solve(0,n,st,dp,s);
    }
};