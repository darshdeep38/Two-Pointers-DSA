class Solution {
public:
    // Helper function to get the maximum subsequence of length k from nums
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> stack;
        int toRemove = nums.size() - k;
        for (int num : nums) {
            while (!stack.empty() && toRemove > 0 && stack.back() < num) {
                stack.pop_back();
                toRemove--;
            }
            stack.push_back(num);
        }
        stack.resize(k);
        return stack;
    }

    // Helper function to compare sequences lexicographically
    bool greaterSeq(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        int m = nums1.size(), n = nums2.size();
        while (i < m && j < n && nums1[i] == nums2[j]) {
            i++; j++;
        }
        return j == n || (i < m && nums1[i] > nums2[j]);
    }

    // Merge two subsequences into the maximum possible number
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (greaterSeq(nums1, i, nums2, j))
                res.push_back(nums1[i++]);
            else
                res.push_back(nums2[j++]);
        }
        return res;
    }

    // Main function
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        int m = nums1.size(), n = nums2.size();
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> seq1 = maxSubsequence(nums1, i);
            vector<int> seq2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(seq1, seq2);
            if (greaterSeq(candidate, 0, best, 0))
                best = candidate;
        }
        return best;
    }
};
