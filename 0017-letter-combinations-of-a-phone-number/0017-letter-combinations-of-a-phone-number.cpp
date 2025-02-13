class Solution {
public:

    void solve(string digits,vector<string> &ans,string mapping[],int ind,string output){
        if(ind>=digits.size()){
            ans.push_back(output);
            return;
        }
        int num = digits[ind]-'0';
        string corr = mapping[num];
        for(int i=0;i<corr.size();i++){
            output.push_back(corr[i]);
            solve(digits,ans,mapping,ind+1,output);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output="";
        int ind=0;
        solve(digits,ans,mapping,ind,output);
        return ans;
    }
};