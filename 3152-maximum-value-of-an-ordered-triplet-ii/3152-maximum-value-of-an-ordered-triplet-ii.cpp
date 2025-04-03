class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        vector<long long> left(n,0);
        vector<long long> right(n,0);
        left[0]=nums[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],(long long)nums[i]);
        }
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],(long long)nums[i]);
        }
        
        long long maxi=0;
        for(int j=1;j<=n-2;j++){
            maxi=max(maxi,((left[j-1]-nums[j])*1ll*right[j+1]));
        }
        return maxi;
    }
};