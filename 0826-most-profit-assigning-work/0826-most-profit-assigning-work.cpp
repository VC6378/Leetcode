class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ma = *max_element(difficulty.begin(),difficulty.end());
        int arr[ma+1];
        for(int i=0; i<ma+1; i++){
            arr[i] = 0;
        }
        for(int i = 0; i<difficulty.size(); i++){
            arr[difficulty[i]] = max(arr[difficulty[i]],profit[i]);
        }
        for(int i=1; i<ma+1; i++){
            arr[i] = max(arr[i-1],arr[i]);
        }
        int res = 0;
        for(int i=0; i<worker.size(); i++){
            res += arr[min(worker[i],ma)];
        }
        return res;
    }
};