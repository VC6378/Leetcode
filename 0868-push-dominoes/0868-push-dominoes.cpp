class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        string temp = "L"+dominoes+"R";
        string ans="";
        int prev=0;
        for(int i=1;i<temp.size();i++){
            if(temp[i]=='.') continue;
            if(prev>0) ans+=temp[prev];
            int diff = i-prev-1;
            if(temp[prev]==temp[i]){
                ans+=string(diff,temp[prev]);
            }

            else if(temp[prev]=='L' && temp[i]=='R'){
                ans+=string(diff,'.');
            }
            else{
                ans+=string(diff/2,'R')+string(diff%2,'.')+string(diff/2,'L');
            }
            prev=i;
        }

        return ans;
    }
};