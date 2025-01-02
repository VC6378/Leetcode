class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int sp=0;
        int tp=0;
        while(sp<n && tp<m){
            if(s[sp]==t[tp]){
                sp++;
            }
            tp++;
        }
        return sp == s.length();
    }
};