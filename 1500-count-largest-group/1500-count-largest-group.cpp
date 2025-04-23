class Solution {
public:
    int countLargestGroup(int n) {
        int ans=0;
        vector<int> vec(37,0);
        for(int i=1;i<=n;i++){
            vec[f(i)]++;
        }
        int maxi = 0;
        for(auto it:vec){
            if(it>maxi) maxi = it,ans=1;
            else if(it==maxi) ans++;
        }
        return ans;
    }
    int f(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num = num/10;
        }
        return sum;
    }
};