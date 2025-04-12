class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int left = bounds[0][0];
        int right = bounds[0][1];

        for (size_t i = 1; i < original.size(); ++i) {
            int diff = original[i] - original[i - 1];

            left = std::max(left + diff, bounds[i][0]);
            right = std::min(right + diff, bounds[i][1]);

            if (left > right)
                return 0;
        }

        return right - left + 1;
    }
};