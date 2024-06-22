class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        
        for(int ind=0;ind<t.size();ind++){
            if(t[ind]==s[i]){
                i++;
            }
            // else continue;
        }
        return i==s.size();
    }
};