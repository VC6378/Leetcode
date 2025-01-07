class Solution {
public:


    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n=words.size();
        sort(words.begin(),words.end(),[](const string& s,const string& t){
            return s.size()<t.size();
        });
        for(int i=0;i<n-1;i++){
            string s = words[i];
            for(int j=i+1;j<n;j++){
                string t = words[j];

                if(s==t) continue;
                else{
                    if(t.find(s)!=-1){
                        ans.push_back(s);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};