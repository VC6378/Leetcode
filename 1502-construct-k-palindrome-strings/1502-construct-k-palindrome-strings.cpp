class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n<k) return false;
        else{
            unordered_map<char,int> mp;
            for(int i=0;i<n;i++){
                mp[s[i]]++;
            }
            int cnt=0;
            for(auto it:mp){
                if(it.second&1) cnt++;
            }
            if(cnt>k) return false;
            else return true;
        }
    }
};