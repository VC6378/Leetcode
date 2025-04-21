class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n=instructions.size();
        vector<bool> vis(n,false);
        int i=0;
        long long ans=0;
        while(i<n && !vis[i]){
            vis[i]=true;
            if(instructions[i]=="jump"){
                i+=values[i];
                if(i<0 or i>=n) break;
            }
            else{
                ans+=values[i];
                i++;
            }
        }
        return ans;
    }
};