class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mps;
        unordered_map<char,char> mpt;
        
        for(int i=0; i<s.size(); i++){
            if(mps[s[i]] and mps[s[i]]!=t[i]) return false;
            if(mpt[t[i]] and mpt[t[i]]!=s[i]) return false;
            
            mps[s[i]]=t[i];
            mpt[t[i]]=s[i];
        }
        
        return true;
    }
};