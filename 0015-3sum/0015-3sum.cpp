class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        for(int i=0;i<n-1;i++){
            int first=nums[i];
            int low=i+1;
            int high=n-1;
            while(low<high){
                if(first+nums[low]+nums[high]>0){
                    high--;
                }
                else if(first+nums[low]+nums[high]<0){
                    low++;
                }
                else{
                    st.insert({first,nums[low],nums[high]});
                    high--;
                    low++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};