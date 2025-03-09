class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int l=0;
        int cnt=0;
        for(int r=0;r<colors.size();r++){
            if(r>0 && colors[r]==colors[r-1]){
                l=r;
            }
            if(r-l+1>=k){
                cnt++;
            }
        }
        return cnt;
    }
};