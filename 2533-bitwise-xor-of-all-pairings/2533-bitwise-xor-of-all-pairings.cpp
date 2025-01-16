class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int x=0;
        int y=0;

        if(m&2!=0){
            for(int i=0;i<n;i++){
                x=x^nums1[i];
            }
        }

        if(n%2!=0){
            for(int i=0;i<m;i++){
                y=y^nums2[i];
            }
        }

        return x^y;
    }
};