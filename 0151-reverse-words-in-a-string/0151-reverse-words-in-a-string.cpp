class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp="";
        vector<string> hehe;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                temp.push_back(s[i]);
            }
            else{
                hehe.push_back(temp);
                temp="";
            }
        }
        hehe.push_back(temp);
        reverse(hehe.begin(),hehe.end());
        string ans="";
        for(int i=0;i<hehe.size();i++){
            if(hehe[i]!=""){
                ans+=hehe[i];
                ans+=" ";
            }
        }
        ans.pop_back();
        return ans;
    }
};