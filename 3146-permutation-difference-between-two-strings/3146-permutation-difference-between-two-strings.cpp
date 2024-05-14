class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n=s.size();
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        for(int i=0;i<n;i++){
            mps[s[i]]=i;
            mpt[t[i]]=i;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int diff=abs(mps[s[i]]-mpt[s[i]]);
            sum+=diff;
        }
        return sum;
    }
};