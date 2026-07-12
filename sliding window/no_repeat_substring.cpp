#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Stores frequency of characters inside current window
        unordered_map<char, int> freq;

        int left = 0;
        int ans = 0;

        // Expand the window
        for (int right = 0; right < s.size(); right++) {

            // Include current character
            freq[s[right]]++;

            // If duplicate exists, shrink window
            while (freq[s[right]] > 1) {

                // Remove left character from window
                freq[s[left]]--;

                // Move left pointer
                left++;
            }

            // Current window has all unique characters
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
int lengthOfLongestSubstring(string s) {
       int n=s.size();
       int low=0,high=0;
       int res=INT_MIN;
       unordered_map<char,int> f;
       for(high=0;high<n;high++)
       {
           f[s[high]]++;
           int len=high-low+1;
           while(f.size()<len)
           {
               f[s[low]]--;
               if(f[s[low]] ==0)
               f.erase(s[low]);
               low++;
               len=high-low+1;
           }
           // now ewual
           len=high-low+1;
           res=max(res,len);
       }
       if(res==INT_MIN)
       return 0;
       return res;
   }
