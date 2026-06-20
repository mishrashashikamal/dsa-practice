class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg, pos;

        // Step 1: Divide into negative and non-negative parts
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        // Step 2: Square all elements
        for (int i = 0; i < neg.size(); i++) {
            neg[i] = neg[i] * neg[i];
        }

        for (int i = 0; i < pos.size(); i++) {
            pos[i] = pos[i] * pos[i];
        }

        // Step 3: Reverse negative squares
        reverse(neg.begin(), neg.end());

        // Step 4: Merge two sorted arrays
        int n = neg.size(), m = pos.size();
        vector<int> res(n + m);

        int i = 0, j = 0, id = 0;

        while (i < n && j < m) {
            if (neg[i] <= pos[j])
                res[id++] = neg[i++];
            else
                res[id++] = pos[j++];
        }

        while (i < n) {
            res[id++] = neg[i++];
        }

        while (j < m) {
            res[id++] = pos[j++];
        }

        return res;
    }
};