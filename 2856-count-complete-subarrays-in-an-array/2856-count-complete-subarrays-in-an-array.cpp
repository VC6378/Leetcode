class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int> temp;
            for(int j=i;j<n;j++){
                temp.insert(nums[j]);
                if(temp.size()==st.size()) ans++;
            }
        }
        return ans;
    }
};

