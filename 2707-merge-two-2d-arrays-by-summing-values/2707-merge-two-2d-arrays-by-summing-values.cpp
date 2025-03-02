class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i=0;int j=0;
        while(i<nums1.size() && j<nums2.size()){
            int ind1=nums1[i][0],val1=nums1[i][1];
            int ind2=nums2[j][0],val2=nums2[j][1];

            if(ind1<ind2){
                ans.push_back({ind1,val1});
                i++;
            }
            else if(ind2<ind1){
                ans.push_back({ind2,val2});
                j++;
            }
            else{
                ans.push_back({ind1,val1+val2});
                i++;
                j++;
            }
        }

        while(i<nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j<nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
};