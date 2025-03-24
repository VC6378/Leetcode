class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        vector<vector<int>> vec;
        sort(meetings.begin(),meetings.end());
        int currstart = meetings[0][0];
        int currend = meetings[0][1];
        for(int i=1;i<n;i++){
            int nextstart = meetings[i][0];
            int nextend = meetings[i][1];
            if(nextstart<=currend){
                currend = max(currend,nextend);
            }
            else{
                vec.push_back({currstart,currend});
                currstart = nextstart;
                currend=nextend;
            }
        }
        int meetday = 0;
        vec.push_back({currstart,currend});
        for(int i=0;i<vec.size();i++){
            meetday+=(vec[i][1]-vec[i][0]+1);
        }

        return days-meetday;
    }
};