class Solution {
public:
    
    bool check(string st){
        int n=st.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            if(st[start]==st[end]){
                start++;
                end--;
            }
            else return false;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        string ans;
        for(int i=0;i<n;i++){
            if(check(words[i])){
                ans=words[i];
                return ans;
            }
        }
        return "";
    }
};