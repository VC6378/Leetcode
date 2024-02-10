class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        int n=s.size();
        int start=0;
        int end=n-1;
        while(start<=end){
          if(s[start]!=s[end]){
            return false;
          }
          start++;
          end--;
        }
        return true;
    }
};