/* 
  Longest Substring Without Repeating Characters

  Given a string, find the length of the longest substring without repeating
  characters. For example, the longest substring without repeating letters for
  "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
  is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // String only contains ASCII characters.
        // The function of array isAppeared equals to hash.
        bool isAppeared[256];
        for (int i=0; i<256; i++)
            isAppeared[i] = false;

        // To maintain a sliding window, in where each characters at most appears
        // once.
        int l = 0, r = 0, result = 0;
        while (r < s.length()) {
            while (isAppeared[s[r]]) {
                isAppeared[s[l]] = false;
                l++;
            }
            isAppeared[s[r]] = true;
            if (r - l + 1 > result)
                result = r - l + 1;
            r++;
        }
        return result;
    }
};
