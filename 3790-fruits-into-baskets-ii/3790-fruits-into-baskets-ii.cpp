class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool> check(n);
        for(int i=0;i<n;i++){
            check[i]=false;
        }
        vector<bool> basketcheck(n,false);
        for(int i=0;i<n;i++){
            int quantity = fruits[i];
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i] && !basketcheck[j]){
                    basketcheck[j]=true;
                    check[i]=true;
                    break;
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!check[i]) cnt++;
        }
        return cnt;
    }
};