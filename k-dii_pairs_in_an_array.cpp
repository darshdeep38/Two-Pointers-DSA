class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0; // absolute difference can't be negative
        
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        int count = 0;

        // Case 1: k == 0 → count numbers appearing at least twice
        if (k == 0) {
            for (auto &p : freq) {
                if (p.second > 1) count++;
            }
            return count;
        }

        // Case 2: k > 0 → check if (num + k) exists
        for (auto &p : freq) {
            int num = p.first;
            if (freq.count(num + k)) {
                count++;
            }
        }

        return count;
    }
};
