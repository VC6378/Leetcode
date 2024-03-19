class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        unordered_map<int,int> mp;
        int maxfreq=-1;
        int ans=-1;
        while(j<n){
            mp[s[j]]++;
            maxfreq=max(maxfreq,mp[s[j]]);
            if(j-i+1-maxfreq>k){
                while(j-i+1-maxfreq>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};