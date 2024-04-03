class Solution {
public:
    long long maximumSumOfHeights(vector<int>& mh) {
        int n=mh.size();
        vector<long long> pref(n,0);
        vector<long long> suff(n,0);
        stack<int> st;
        st.push(0);
        pref[0]=mh[0];
        for(int i=1;i<n;i++){
            while(!st.empty() && mh[st.top()]>mh[i]) st.pop();
            if(st.empty()){
                pref[i]=1ll*(i+1)*mh[i];
                st.push(i);
                continue;
            }
            int it=st.top();
            pref[i]=pref[it]+1ll*(i-it)*mh[i];
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n-1);
        suff[n-1]=mh[n-1];
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && mh[st.top()]>mh[i]) st.pop();
            if(st.empty()){
                suff[i]=1ll*(n-i)*mh[i];
                st.push(i);
                continue;
            }
            int it=st.top();
            suff[i]=suff[it]+1ll*(it-i)*mh[i];
            st.push(i);
        }
        
        long long maxSum=0;
        for(int i=0;i<n;i++){
            maxSum=max(maxSum,pref[i]+suff[i]-mh[i]);
        }
        return maxSum;
    }
};