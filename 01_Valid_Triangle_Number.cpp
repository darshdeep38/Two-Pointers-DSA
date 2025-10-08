class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix the third side (nums[k]) and find valid pairs (i, j)
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // All values from i to j-1 will also satisfy the condition
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }

        return count;
    }
};
