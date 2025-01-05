class Solution {
public:
    long long calculateScore(string s) {
        int n=s.size();
        long long ans=0;
        unordered_map<char,vector<int>> mirror;
        for(int i=0;i<n;i++){
            int mirrorch=('z'-s[i])+'a';

            if(mirror[mirrorch].size()>0){
                int lst=mirror[mirrorch].back();
                mirror[mirrorch].pop_back();
                ans+=(i-lst);
            }
            else{
                mirror[s[i]].push_back(i);
            }
        }
        return ans;
    }
};