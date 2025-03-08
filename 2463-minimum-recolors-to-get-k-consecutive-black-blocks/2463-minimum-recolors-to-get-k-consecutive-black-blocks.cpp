class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n=s.size();
        int l=0;
        int r=k;
        int cnt=0;
        int ans=0;
        for(int i=0;i<k;i++){
            if(s[i]=='W'){
                cnt++;
            }
        }
        ans=cnt;
        while(r<n){
            if(s[l]=='W'){
                if(cnt>0) cnt--;
            }
            l++;
            if(s[r]=='W'){
                cnt++;
            }
            r++;
            ans = min(ans,cnt);
        }
        return ans;
    }
};