class Solution {
public:
    string mergeAlternately(string one, string two) {
        int m=one.size();
        int n=two.size();
        bool flag=true;
        string ans="";
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(flag){
                ans+=one[i];
                i++;
                flag=!flag;
            }
            else{
                ans+=two[j];
                j++;
                flag=!flag;
            }
        }
        
        while(i<m){
            ans+=one[i];
            i++;
        }
        
        while(j<n){
            ans+=two[j];
            j++;
        }
        
        return ans;
    }
};