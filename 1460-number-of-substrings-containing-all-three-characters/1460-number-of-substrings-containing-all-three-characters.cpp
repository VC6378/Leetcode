class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        vector<int> freq(3,0);
        int ans=0;
        while(j<n){
            freq[s[j]-'a']++;
            while(freq[0] && freq[1] && freq[2]){
                ans+=(n-j);
                freq[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};