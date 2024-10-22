class Solution {
public:

    bool check(int mid,int days,vector<int> &weights){
        int n=weights.size();
        int cnt=0;
        int d=1;
        for(int i=0;i<n;i++){
            cnt+=weights[i];
            if(cnt>mid){
                d++;
                cnt=weights[i];
            }
        }

        return (d<=days);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int start=*max_element(weights.begin(),weights.end());
        int end= 0 ;
        for(int i=0;i<n;i++){
            end+=weights[i];
        }
        int mincp;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(mid,days,weights)){
                mincp=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return mincp;
    }
};