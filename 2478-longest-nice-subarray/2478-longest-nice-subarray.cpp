class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=0;
        int prev=0;
        int ans=0;
        while(e<n){
            if((nums[e]&prev)==0){
                prev=prev|nums[e];
                ans = max(ans,e-s+1);
                e++;
            }
            else{
                while(s<e and (nums[e]&prev)!=0){
                    prev=prev&(~nums[s]);
                    s++;
                }
                prev=prev|nums[e];
                e++;
            }
        }
        return ans;
    }
};