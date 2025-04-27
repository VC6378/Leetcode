class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        vector<set<string>> st;
        for(int i=0;i<responses.size();i++){
            set<string> temp;
            for(int j=0;j<responses[i].size();j++){
                string s = responses[i][j];
                temp.insert(s);
            }
            st.push_back(temp);
        }

        map<string,int> mp;
        for(int i=0;i<st.size();i++){
            for(auto it:st[i]){
                mp[it]++;
            }
        }

        int maxfreq = -1;
        string s = "";
        for(auto it:mp){
            if(it.second>maxfreq){
                maxfreq = it.second;
                s = it.first;
            }
        }

        return s;
    }
};