class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        int minieven = INT_MAX;
        int maxiodd = INT_MIN;
        for(auto it:mp){
            if(it.second&1){
                maxiodd = max(maxiodd,it.second);
            }
            else{
                minieven = min(minieven,it.second);
            }
        }
        return maxiodd-minieven;
    }
};