class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n-1;i++){
            int first=s[i]-'a';
            int second=s[i+1]-'a';
            sum+=abs(first-second);
        }
        return sum;
    }
};