class Solution {
public:

    int f(vector<int> &tops,vector<int> &bottoms,int target){
        int cnttop=0,cntbottom=0;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=target && bottoms[i]!=target) return INT_MAX;
            if(tops[i]!=target) cnttop++;
            if(bottoms[i]!=target) cntbottom++;
        }
        return min(cnttop,cntbottom);
        
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res1 = f(tops,bottoms,tops[0]);
        int res2 = f(tops,bottoms,bottoms[0]);
        int ans = min(res1,res2);
        cout<<res1<<" "<<res2<<endl;
        if(ans==INT_MAX) return -1;
        return ans;
    }
};