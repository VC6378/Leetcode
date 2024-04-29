class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wl) {
        unordered_set<string> st;
        for(int i=0;i<wl.size();i++){
            st.insert(wl[i]);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string s=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(s==endWord) return cnt;
            for(int i=0;i<s.size();i++){
                char ch=s[i];
                for(char c='a';c<='z';c++){
                    s[i]=c;
                    if(st.find(s)!=st.end()){
                        q.push({s,cnt+1});
                        st.erase(s);
                    }
                }
                s[i]=ch;
            }
        }
        return 0;
    }
};