class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        unsigned int poo = pow(2,n);
        sort(nums.begin(),nums.end());
        vector<string> list;
        for(int cnt=0;cnt<poo;cnt++){
            vector<int> subsets;
            string temp="";
            for(int j=0;j<n;j++){
                if(cnt&(1<<j)){
                    subsets.push_back(nums[j]);
                    temp+=to_string(nums[j]+'$');
                }
            }
            if(find(list.begin(),list.end(),temp)==list.end()){
                ans.push_back(subsets);
                list.push_back(temp);
            }
        }
        return ans;
    }
};