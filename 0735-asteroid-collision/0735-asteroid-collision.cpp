class Solution {
public:
    vector<int> asteroidCollision(vector<int>& aster) {
        int n=aster.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() || aster[i]>0) st.push(aster[i]);
            else{
                while(!st.empty() && abs(aster[i])>st.top() && st.top()>0) st.pop();
                if(st.empty() || st.top()<0) st.push(aster[i]);
                if(!st.empty() && abs(aster[i])==st.top()) st.pop();
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};