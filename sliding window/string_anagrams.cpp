class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.size() > s.size()) return ans;

        vector<int> pFreq(26, 0), window(26, 0);

        // Frequency of characters in p
        for (char c : p)
            pFreq[c - 'a']++;

        int k = p.size();
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            // Add current character
            window[s[right] - 'a']++;

            // Maintain window size k
            if (right - left + 1 > k) {
                window[s[left] - 'a']--;
                left++;
            }

            // Check if current window is an anagram
            if (right - left + 1 == k && window == pFreq) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};