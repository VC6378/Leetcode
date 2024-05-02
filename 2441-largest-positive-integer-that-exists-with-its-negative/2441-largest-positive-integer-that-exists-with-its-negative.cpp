class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        set<int> neg;
        set<int> pos;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos.insert(nums[i]);
            }
            else{
                neg.insert(nums[i]);
            }
        }
        for(auto it:neg){
            int num=abs(it);
            if(pos.find(num)!=pos.end()) return abs(num);
        }
        return -1;
    }
};