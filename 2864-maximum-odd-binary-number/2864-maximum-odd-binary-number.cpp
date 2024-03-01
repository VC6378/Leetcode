class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int ones=0;
        int zeros=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones++;
            else zeros++;
        }
        string ans="";
        if(ones==1){
            while(zeros-->0){
                ans+="0";
            }
            ans+="1";
        }
        else{
            while(ones-->1){
                ans+="1";
            }
            while(zeros-->0){
                ans+="0";
            }
            ans+="1";
        }
        return ans;
    }
};