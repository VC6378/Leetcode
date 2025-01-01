class Solution {
public:
    string mergeAlternately(string one, string two) {
        int n=one.size();
        int m=two.size();
        bool flag=1;
        int i=0;
        int j=0;
        string ans="";
        while(i<n && j<m){
            if(flag){
                ans.push_back(one[i]);
                i++;
            }
            else{
                ans.push_back(two[j]);
                j++;
            }
            flag=!flag;
        }

        while(i<n){
            ans.push_back(one[i]);
            i++;
        }

        while(j<m){
            ans.push_back(two[j]);
            j++;
        }

        return ans;
    }
};