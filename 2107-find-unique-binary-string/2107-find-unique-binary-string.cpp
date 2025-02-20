class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        int ind=0;
        for(auto it:nums){
            ans+=to_string('1'-it[ind]);
            ind++;
        }
        return ans;
    }
};