class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        // Helper lambda to expand around center
        auto expand = [&](int left, int right) {
            int cnt = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                cnt++;
                left--;
                right++;
            }
            return cnt;
        };

        // Each character can be a center of odd or even length palindrome
        for (int i = 0; i < n; i++) {
            count += expand(i, i);       // Odd length palindrome
            count += expand(i, i + 1);   // Even length palindrome
        }

        return count;
    }
};
