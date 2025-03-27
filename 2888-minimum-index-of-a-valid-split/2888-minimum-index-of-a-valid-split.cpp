class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        bool flag=false;
        int de=-1;
        int mf=-1;
        for(auto it:mp){
            if(it.second*2>n){
                flag=true;
                de=it.first;
                mf=it.second;
                break;
            }
        }
        if(!flag) return -1;
        if(flag){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]==de){
                    cnt++;
                    
                    if(cnt*2>(i+1) && (2*(mf-cnt)>(n-i-1))){
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};