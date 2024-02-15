class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int si=nums.size();
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<si;i++){
            if(nums[i]>=0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        vector<int> ans;
        int posidx=0;
        int negidx=0;
        for(int i=0; i<si; i++){
            if(i%2==0){
                ans.push_back(pos[posidx]);
                posidx++;
            }
            else{
                ans.push_back(neg[negidx]);
                negidx++;
            }
        }
        return ans;
    }
};