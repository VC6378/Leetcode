class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int remove=0;
        int prev=points[0][1];
        for(int i=1;i<n;i++){
            if(prev>=points[i][0]){
                remove++;
            }
            else{
                prev=points[i][1];
            }
        }
        return (n-remove);
    }
};