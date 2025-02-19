class Solution {
public:
    vector<string> ans;

    bool valid(string &hehe){
        int num = stoi(hehe);
        if(num>=0 && num<=255 && to_string(num)==hehe) return true;
        return false;
    }

    bool check(string ip){
        int n = ip.size();
        ip.push_back('.');
        int i=0;
        while(i<n){
            string hehe;
            while(ip[i]!='.'){
                hehe.push_back(ip[i]);
                i++;
            }
            i++;
            if(hehe.size()>3 || !valid(hehe)) return false;
        }
        return true;
    }

    void solve(int ind,int dot,string &s,string &temp){
        int n=s.size();
        if(ind==n){
            if(check(temp) && dot==0){
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(s[ind]);
        if(dot>=1 && temp.back()!='.' && ind!=n-1){
            temp.push_back('.');
            solve(ind+1,dot-1,s,temp);
            temp.pop_back();
        }
        solve(ind+1,dot,s,temp);
        temp.pop_back();
    }

    vector<string> restoreIpAddresses(string s) {
        string temp="";
        solve(0,3,s,temp);
        return ans;
    }
};