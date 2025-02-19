class Solution {
public:
    int count = 0;
    string res="";
    string getHappyString(int n, int k) {
        string temp="";
        f(n,k,temp,' ');
        return res;
    }

    void f(int n,int k,string &temp, char lastChar){
        if(temp.length()==n){
            if(++count==k){
                res=temp;
            }
            return;
        }
        char chars[]={'a','b','c'};
        for(int i=0;i<3;i++){
            char c = chars[i];
            if(c!=lastChar){
                temp.push_back(c);
                f(n,k,temp,c);
                temp.pop_back();
                if(!res.empty()) return;
            }
        }
    }
};