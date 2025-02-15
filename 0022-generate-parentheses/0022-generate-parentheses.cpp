class Solution {
public:

    void f(string s,int open,int close,vector<string> &ans){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open>0){
            s.push_back('(');
            f(s,open-1,close,ans);
            s.pop_back();
        }
        if(close>0){
            if(open<close){
                s.push_back(')');
                f(s,open,close-1,ans);
                s.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        f(s,n,n,ans);
        return ans;
    }
};