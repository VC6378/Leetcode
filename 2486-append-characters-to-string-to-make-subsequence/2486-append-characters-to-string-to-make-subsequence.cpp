class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=0;
        int j=0;
        int cnt=0;
        while(i<n){
            if(s[i]==t[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                i++;
            }
        }
        return m-cnt;
    }
};