class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> mp;
        int maxfreq=-1;
        for(auto e:tasks){
            mp[e]++;
            maxfreq=max(maxfreq,mp[e]);
        }
        
        int maxi=(maxfreq-1)*(n+1);
        for(auto it:mp){
            if(it.second==maxfreq) maxi++;
        }
        return max((int)tasks.size(),maxi);
    }
};