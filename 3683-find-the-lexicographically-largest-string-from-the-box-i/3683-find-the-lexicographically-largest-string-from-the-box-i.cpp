class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        if(numFriends==1) return word;
        vector<string> temp;
        for(int i=0;i<n;i++){
            string sub = word.substr(i,n-numFriends+1);
            temp.push_back(sub);
        }

        sort(temp.begin(),temp.end());
        return temp[temp.size()-1];
    }
};