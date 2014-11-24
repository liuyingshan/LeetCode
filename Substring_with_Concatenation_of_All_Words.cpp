/*
  Substring with Concatenation of All Words
  You are given a string, S, and a list of words, L, that are all of the same
  length. Find all starting indices of substring(s) in S that is a
  concatenation of each word in L exactly once and without any intervening
  characters.

  For example, given:
  S: "barfoothefoobarman"
  L: ["foo", "bar"]

  You should return the indices: [0,9].
  (order does not matter).
*/

class Solution {
public:
    // Increase reference
    int increase(unordered_map<string, int> &hash, string key) {
        if (hash.find(key) == hash.end()) {
            hash.insert(pair<string, int>(key, 1));
        } else {
            hash[key] = hash[key] + 1;
        }
        return hash[key];
    }

    // Decrease reference
    int decrease(unordered_map<string, int> &hash, string key) {
        if (hash.find(key) == hash.end())
            return -1;
        if (hash[key] == 1) {
            hash.erase(key);
            return 0;
        }
        hash[key] = hash[key] - 1;
        return hash[key];
    }

    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        unordered_map<string, int> toFind, found;
        int n = L.size(), m = L[0].length();
        
        for (int i=0; i<n; i++)
            increase(toFind, L[i]);

        for (int delta=0; delta<m; delta++) {
            if (delta + n * m > S.length()) break;
            found.clear();
            int l = delta, r = delta;
            while (r < S.length()) {
                string s = S.substr(r, m);
                r += m;
                
                if (toFind.find(s) == toFind.end()) {
                    found.clear();
                    l = r;
                    continue;
                }

                increase(found, s);
                while (found[s] > toFind[s]) {
                    string tmp = S.substr(l, m);
                    decrease(found, tmp);
                    l += m;
                }

                if (r - l == n * m)
                    result.push_back(l);
            }
        }

        return result;
    }
};
