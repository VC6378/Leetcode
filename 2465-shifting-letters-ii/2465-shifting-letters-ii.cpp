class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        int m=shifts.size();
        vector<int> shift(n+1,0);
        for(int i=0;i<m;i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direc = shifts[i][2];
            shift[start]+= (direc==1 ? 1 : -1);
            shift[end+1]-= (direc==1? 1: -1);
        }

        int current=0;
        for(int i=0;i<n;i++){
            current+=shift[i];
            shift[i]=current;
        }

        for(int i=0;i<n;i++){
            int net = (shift[i]%26+26)%26;
            s[i]='a'+(s[i]-'a'+net)%26;
        }

        return s;
    }
};