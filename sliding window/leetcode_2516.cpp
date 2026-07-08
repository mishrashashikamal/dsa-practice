class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        vector<int> total(3, 0);

        for (char c : s)
            total[c - 'a']++;

        for (int i = 0; i < 3; i++)
            if (total[i] < k)
                return -1;

        vector<int> window(3, 0);

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {

            window[s[right] - 'a']++;

            while (
                window[0] > total[0] - k ||
                window[1] > total[1] - k ||
                window[2] > total[2] - k
            ) {
                window[s[left] - 'a']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return n - maxLen;
    }
};