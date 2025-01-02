class Solution {
public:
    int compress(vector<char>& chars) {
        int k=0; 
        int i=0,j=0;
        while(i<chars.size()&&j<chars.size()){
            while(j+1<chars.size()&&chars[j+1]==chars[i])j++;
            chars[k]=chars[i];
            k++;
            if(j>i){
                int n=j-i+1;
                string len=to_string(n);
                int l=0;
                while(l<len.size()){
                    chars[k++]=len[l++];
                }
            }
            i=j+1;
        }
        return k;
    }
};