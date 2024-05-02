class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> st;
        for(int i=0;i<word.size(); i++){
            st.insert(word[i]);
        }
        int cnt=0;
        for(auto it:st){
            if(it>='a' && it<='z'){
                char ch=toupper(it);
                if(st.find(ch)!=st.end()) cnt++;
            }
        }
        return cnt;
    }
};