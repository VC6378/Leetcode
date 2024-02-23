class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxp=0;
        int low=0;
        for(int i=0;i<n;i++){
            if(prices[i]<prices[low]){
                low=i;
            }
            maxp=max(maxp,prices[i]-prices[low]);
        }
        return maxp;
    }
};