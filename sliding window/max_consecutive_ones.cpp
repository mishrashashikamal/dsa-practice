// 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int low = 0;
        int zeroCount = 0;
        int res = 0;

        for (int high = 0; high < nums.size(); high++) {

            // Include the new element
            if (nums[high] == 0)
                zeroCount++;

            // Shrink the window if it becomes invalid
            while (zeroCount > k) {
                if (nums[low] == 0)
                    zeroCount--;
                low++;
            }

            // Update the answer
            res = max(res, high - low + 1);
        }

        return res;
    }
};