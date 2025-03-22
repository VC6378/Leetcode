class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int maxele = *max_element(nums.begin(),nums.end());
        if(maxele<0) return maxele;
        else{
            int sum=0;
            unordered_set<int> st;
            for(int i=0;i<n;i++){
                if(st.find(nums[i])==st.end() and nums[i]>=0){
                    sum+=nums[i];
                    st.insert(nums[i]);
                }
            }
            return sum;
        }
    }
};