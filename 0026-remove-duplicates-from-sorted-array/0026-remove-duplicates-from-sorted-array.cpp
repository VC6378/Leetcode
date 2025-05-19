class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        nums.clear();
        for(auto it:st){
            nums.push_back(it);
        }
        return nums.size();
    }
};