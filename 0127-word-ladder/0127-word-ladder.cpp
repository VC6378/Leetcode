class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto it:wordList){
            st.insert(it);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string s=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(s==endWord){
                return cnt;
            }
            for(int i=0;i<s.size();i++){
                char c=s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        q.push({s,cnt+1});
                        st.erase(s);
                    }
                }
                s[i]=c;
            }
        }
        return 0;
    }
};