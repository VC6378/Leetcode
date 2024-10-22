class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int maxi=INT_MIN;
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]==0) cnt++;
            while(cnt>k){
                if(nums[i]==0) cnt--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};