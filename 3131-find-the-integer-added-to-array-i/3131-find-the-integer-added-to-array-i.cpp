class Solution {
public:
    int addedInteger(vector<int>& one, vector<int>& two) {
        int n=one.size();
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        return (two[0]-one[0]);
    }
};