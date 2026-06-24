class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int low = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int high = 0; high < nums.size(); high++) {

            sum += nums[high];

            while (sum >= target) {

                ans = min(ans, high - low + 1);

                sum -= nums[low];
                low++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};