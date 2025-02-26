class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans1=INT_MIN;
        int ans2=INT_MAX;
        int curr1=0;
        int curr2=0;
        for(auto it:nums){
            curr1+=it;
            curr2+=it;
            if(ans2>curr2){
                ans2=curr2;
            }
            if(ans1<curr1){
                ans1=curr1;
            }
            if(curr1<0)curr1=0;
            if(curr2>0)curr2=0;
        }

        return max(abs(ans2),abs(ans1));
    }
};