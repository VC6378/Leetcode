class Solution {
public:

int atMostK(vector<int> a, int k){
        int i=0, sum = 0, res=0;
        if(k<0) return 0;
        for(int j=0; j<a.size(); j++){
            sum+=a[j];
            if(sum>k){
                while(i<a.size() && sum > k){
                    sum -= a[i];
                    i++;
                }
            }
            res += j-i+1;
        }
        return res;
    }
    
    int numSubarraysWithSum(vector<int>& a, int k) {
        return atMostK(a,k) - atMostK(a,k-1);
    }
};