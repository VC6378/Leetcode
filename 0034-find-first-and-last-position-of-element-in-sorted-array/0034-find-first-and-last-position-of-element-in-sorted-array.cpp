class Solution {
public:
    int lowerbound(vector<int>&nums,int low,int high,int target){
        while(low<=high){
            int mid = (high+low)>>1;
            if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return low;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int startpos = lowerbound(nums,low,high,target);
        int endpos = lowerbound(nums,low,high,target+1)-1;
        
        if(startpos<nums.size()&&nums[startpos]==target){
            return {startpos,endpos};
        }
        return {-1,-1};
    }
};