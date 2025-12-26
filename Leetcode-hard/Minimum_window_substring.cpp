class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> freq(128, 0);
        for (char c : t) freq[c]++;

        int required = t.size();   // total characters to be matched
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            // include current character
            if (freq[s[right]] > 0)
                required--;
            freq[s[right]]--;
            right++;

            // when all characters are matched
            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // remove left character
                freq[s[left]]++;
                if (freq[s[left]] > 0)
                    required++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
