class Solution {
public:
    string gcdOfStrings(string one, string two) {
        int n=one.size();
        int m=two.size();
        if(one+two == two+one) return one.substr(0, gcd(size(one),size(two)));
        else return "";
    }
};