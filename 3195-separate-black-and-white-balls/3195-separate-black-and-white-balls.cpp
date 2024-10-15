class Solution {
public:
    
    bool check(string &s){
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]>s[i+1]) return false;
        }
        return true;
    }
    
    long long minimumSteps(string s) {
        int n=s.size();
        if(check(s)) return 0;
        long long ones=0;
        int zeros=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') zeros++;
            else ones+=(long long)zeros;
        }
        return ones;
    }
};