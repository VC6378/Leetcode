class Solution {
public:

    bool check(string temp){
        int n=temp.size();
        if(n&1) return false;
        int half = n/2;
        int sum1=0;
        int ind=0;
        while(ind<half){
            sum1+=(temp[ind]-'0');
            ind++;
        }
        int sum2=0;
        while(ind<n){
            sum2+=(temp[ind]-'0');
            ind++;
        }
        return (sum1==sum2);
    }

    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string temp = to_string(i);
            if(check(temp)) cnt++;
        }
        return cnt;
    }
};