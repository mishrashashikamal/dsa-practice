class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        unordered_set<int> st;

        int left = 0;
        int currSum = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            while (st.count(nums[right])) {
                st.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }

            st.insert(nums[right]);
            currSum += nums[right];

            ans = max(ans, currSum);
        }

        return ans;
    }
};