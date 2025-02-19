class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> result;
        int n = exp.size();
        for(int i=0;i<n;i++){
            char ch = exp[i];
            if(ch=='+' || ch=='-' || ch=='*'){
                vector<int> one = diffWaysToCompute(exp.substr(0,i));
                vector<int> two = diffWaysToCompute(exp.substr(i+1,n));
                for(auto i:one){
                    for(auto j:two){
                        if(ch=='+'){
                            result.push_back(i+j);
                        }
                        else if(ch=='-'){
                            result.push_back(i-j);
                        }
                        else if(ch=='*'){
                            result.push_back(i*j);
                        }
                    }
                }
            }
        }
        if(result.empty()){
            result.push_back(atoi(exp.c_str()));
        }
        return result;
    }
};