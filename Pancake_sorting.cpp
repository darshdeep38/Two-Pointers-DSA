class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();

        for (int curr = n; curr > 1; curr--) {
            // Find index of maximum element in arr[0..curr-1]
            int maxIndex = 0;
            for (int i = 1; i < curr; i++) {
                if (arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }

            // If already in correct position, skip
            if (maxIndex == curr - 1)
                continue;

            // Step 1: Bring max element to front if not already there
            if (maxIndex != 0) {
                reverse(arr.begin(), arr.begin() + maxIndex + 1);
                result.push_back(maxIndex + 1);
            }

            // Step 2: Move max element to its correct position
            reverse(arr.begin(), arr.begin() + curr);
            result.push_back(curr);
        }

        return result;
    }
};
