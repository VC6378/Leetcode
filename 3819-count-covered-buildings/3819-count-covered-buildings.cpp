class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> xmin(n+1,1e6);
        vector<int> xmax(n+1,0);
        vector<int> ymin(n+1,1e6);
        vector<int> ymax(n+1,0);
        for(auto it:buildings){
            int x = it[0];
            int y = it[1];
            ymin[x] = min(ymin[x],y);
            ymax[x] = max(ymax[x],y);

            xmin[y] = min(xmin[y],x);
            xmax[y] = max(xmax[y],x);
        }

        int cnt=0;
        for(auto it:buildings){
            int x = it[0];
            int y = it[1];
            if(y<ymax[x] && y>ymin[x] && x<xmax[y] && x>xmin[y]) cnt++;
        }
        return cnt;
    }
};