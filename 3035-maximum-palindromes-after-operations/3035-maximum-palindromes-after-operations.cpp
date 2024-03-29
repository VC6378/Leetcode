class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n=words.size();
        vector<int> temp;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            for(auto it:words[i]){
                mp[it]++;
            }
            temp.push_back(words[i].size());
        }
        sort(temp.begin(),temp.end());
        
        int pairs=0;
        for(auto it:mp){
            pairs+=(it.second/2);
        }
        for(int i=0;i<n;i++){
            if((pairs-=temp[i]/2)<0) return i;
        }
        return n;
    }
};