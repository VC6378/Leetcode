class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int cnt=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') cnt++;
        }
        int ans=cnt;
        int left=0;
        int right = k;
        while(right<n){
            if(blocks[left]=='W'){
                cnt--;
            }
            left++;
            if(blocks[right]=='W') cnt++;
            right++;
            ans=min(ans,cnt);
        }
        return ans;
    }
};