/*
  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.

  The matching should cover the entire input string (not partial).

  The function prototype should be:
    bool isMatch(const char *s, const char *p)

  Some examples:
    isMatch("aa","a") �� false
    isMatch("aa","aa") �� true
    isMatch("aaa","aa") �� false
    isMatch("aa", "a*") �� true
    isMatch("aa", ".*") �� true
    isMatch("ab", ".*") �� true
    isMatch("aab", "c*a*b") �� true
*/

class Solution {
public:
    bool isEqual(char s, char p) {
        if (s == p || p == '.' && s != '\0') return true;
        return false;
    }
    
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0' && *p == '\0') return true;
        
        if (*p != '\0' && *(p + 1) == '*') {
            // '*' represents zero of preceding element.
            if (isMatch(s, p + 2)) return true;
            // '*' represents one or more of preceding element.
            while (isEqual(*s, *p)) {
                ++s;
                if (isMatch(s, p + 2)) return true;
            }
        } else if (isEqual(*s, *p)) {
            if (isMatch(s + 1, p + 1)) return true;
        }
        
        return false;
    }
};
