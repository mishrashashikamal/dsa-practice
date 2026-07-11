class Solution {
public:
    int longestKSubstr(string &s, int k) {

        int low = 0;
        int n = s.size();
        int res = INT_MIN;

        unordered_map<char, int> f;

        for (int high = 0; high < n; high++) {

            f[s[high]]++;

            while (f.size() > k) {
                f[s[low]]--;

                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }

                low++;
            }

            if (f.size() == k) {
                int len = high - low + 1;
                res = max(res, len);
            }
        }

        return (res == INT_MIN) ? -1 : res;
    }
};