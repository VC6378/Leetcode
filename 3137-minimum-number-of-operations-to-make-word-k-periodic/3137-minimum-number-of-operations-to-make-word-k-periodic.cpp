class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n=word.size();
        if(n%k!=0) return -1;
        unordered_map<string,int> mp;
        for(int i=0;i<n;i+=k){
            mp[word.substr(i,k)]++;
        }
        int mini=INT_MAX;
        for(auto it:mp){
            int ops=n/k-it.second;
            mini=min(mini,ops);
        }
        return mini;
    }
};