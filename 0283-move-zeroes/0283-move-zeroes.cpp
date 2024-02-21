class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        int zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++;
            else temp.push_back(nums[i]);
        }
        if(zero!=0){
            while(zero-->0){
                temp.push_back(0);
            }
        }

        for(int i=0;i<n;i++){
            nums[i]=temp[i];
        }
    }
};