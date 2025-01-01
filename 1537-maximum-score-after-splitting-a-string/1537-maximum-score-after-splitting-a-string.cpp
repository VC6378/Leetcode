class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int zeroes=0;
        int ones=0;
        int best=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1') ones++;
            else zeroes++;
            best=max(best,zeroes-ones);
        }
        if(s[n-1]=='1') ones++;
        return best+ones;
    }
};