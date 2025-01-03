class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        int sum=0;
        int k=0;
        vector<int> freq(n+1,0);
        for(int i=0;i<n;i++){
            while(sum+freq[i] < nums[i]){
                if(k==queries.size()) return -1;
                int left=queries[k][0];
                int right=queries[k][1];

                int val=queries[k][2];
                k++;

                if(right<i) continue;
                freq[max(left,i)]+=val;
                freq[right+1]-=val;
            }
            sum+=freq[i];
        }
        return k;
    }
};