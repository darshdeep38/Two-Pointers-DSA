// Count Unique Characters of All Substrings of a Given String


class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> pos(26);
        
        // Store positions of each character
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'A'].push_back(i);
        }
        
        int ans = 0;
        
        // Contribution calculation
        for (int c = 0; c < 26; c++) {
            auto &v = pos[c];
            int m = v.size();
            
            for (int i = 0; i < m; i++) {
                int prev = (i == 0) ? -1 : v[i - 1];
                int next = (i == m - 1) ? n : v[i + 1];
                
                ans += (v[i] - prev) * (next - v[i]);
            }
        }
        
        return ans;
    }
};
