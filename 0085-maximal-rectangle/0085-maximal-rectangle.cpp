class Solution {
public:

    int f(vector<int> &heights){
        int n=heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty()) left[i]=-1;
            else if(st.top().first<heights[i]) left[i]=st.top().second;
            else if(st.top().first>=heights[i]){
                while(!st.empty() && st.top().first>=heights[i]){
                    st.pop();
                }
                if(!st.empty()) left[i]=st.top().second;
                else left[i]=-1;
            }
            st.push({heights[i],i});
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            if(st.empty()) right[i]=n;
            else if(st.top().first<heights[i]) right[i]=st.top().second;
            else if(st.top().first>=heights[i]){
                while(!st.empty() && st.top().first>=heights[i]){
                    st.pop();
                }
                if(!st.empty()) right[i]=st.top().second;
                else right[i]=n;
            }
            st.push({heights[i],i});
        }

        int area=0;
        for(int i=0;i<n;i++){
            area=max(area,(right[i]-left[i]-1)*heights[i]);
        }
        return area;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxarea=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            }
            int area=f(height);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};