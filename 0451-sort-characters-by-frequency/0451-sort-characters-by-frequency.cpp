class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            int freq=pq.top().first;
            char ch=pq.top().second;
            while(freq--){
                ans+=ch;
            }
            pq.pop();
        }
        
        return ans;
    }
};