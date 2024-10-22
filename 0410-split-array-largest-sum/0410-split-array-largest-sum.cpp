class Solution {
public:

    bool check(int mid,int k,vector<int> &nums){
        int n=nums.size();
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
                cnt++;
                sum=nums[i];
            }
        }
        return (cnt<=k);
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(mid,k,nums)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};