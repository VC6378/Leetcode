class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> comb;
        for(int i=0;i<nums1.size();i++){
            comb.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            comb.push_back(nums2[i]);
        }
        sort(comb.begin(),comb.end());
        if(comb.size()&1){
            return (double)(comb[comb.size()/2]);
        }
        else{
            double first=(double)comb[comb.size()/2-1];
            double second = (double)comb[comb.size()/2];
            return (double)(first+second)/(2.0);
            // cout<<first<<" "<<second<<endl;
            // return 0;
            
        }
    }
};