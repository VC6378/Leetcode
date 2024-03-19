class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int n=points.size();
        int cnt=0;
        for(int i=0;i<k;i++){
            cnt+=points[i];
        }
        int ans=cnt;
        for(int i=k-1;i>=0;i--){
            cnt-=points[i];
            cnt+=points[n-k+i];
            ans=max(ans,cnt);
        }
        return ans;
    }
};