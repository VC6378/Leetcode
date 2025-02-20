class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n=pizzas.size();
        int totalDays = n/4;
        long long ans=0;
        int oddDays = (totalDays+1)/2;
        sort(pizzas.begin(),pizzas.end());
        reverse(pizzas.begin(),pizzas.end());
        for(int i=0,day=1;day<=totalDays;i++,day++){
            if(day>oddDays)i++;
            ans+=(long long)pizzas[i];
        }
        return ans;
    }
};