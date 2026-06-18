# Two Sum (sort + two pointer)

**Pattern:** Two Pointers
**Time:** O(n log n) | **Space:** O(n)

## Approach
Pair each value with its original index, sort by value, then two-pointer scan to find the pair summing to target. Sorting needed to track original indices.

## Code
\`\`\`cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target) return {arr[left].second, arr[right].second};
            else if (sum < target) left++;
            else right--;
        }
        return {};
    }
};
\`\`\`

## Learned
Two-pointer needs sorted data; store original index before sorting since order is lost.