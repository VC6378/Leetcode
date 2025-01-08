class Solution {
public:
    
    int check(string one,string two){
        if(one.size()>two.size()) return false;
        bool f=true;
        int n=two.size();
        for(int i=0;i<one.size();i++){
            if(two[i]!=one[i]){
                f=false;
                break;
            }
        }
        string temp=two.substr(n-one.size());
        bool s=true;
        for(int i=0;i<one.size();i++){
            if(temp[i]!=one[i]){
                s=false;
                break;
            }
        }
        
        return (f&s);
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(check(words[i],words[j])) cnt++;
            }
        }
        return cnt;
    }
};