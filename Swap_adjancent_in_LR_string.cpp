class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip 'X' in both strings
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;

            // If both pointers reach the end, transformation is possible
            if (i == n && j == n) return true;
            // If only one reaches end, mismatch
            if (i == n || j == n) return false;

            // Check if same character (L or R)
            if (start[i] != end[j]) return false;

            // Movement rules:
            // 'L' can only move left → start index must be >= end index
            if (start[i] == 'L' && i < j) return false;
            // 'R' can only move right → start index must be <= end index
            if (start[i] == 'R' && i > j) return false;

            i++;
            j++;
        }
        return true;
    }
};
