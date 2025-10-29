class Solution {
public:
    int countSubarrays(vector<int>& nums, int bound) {
        int count = 0, curr = 0;
        for (int num : nums) {
            if (num <= bound)
                curr++;
            else
                curr = 0;
            count += curr;
        }
        return count;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countSubarrays(nums, right) - countSubarrays(nums, left - 1);
    }
};
