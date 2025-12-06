class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.length();

        // Step 1: Find first decreasing element from the right
        int i = len -  2 ;
        while( i>= 0  && s[i] >= s[i + 1]){
                i--;
        }

        if( i< 0 ) return  -1 ; 

        // Step 2: Find element just greater than s[i] (on right)
        int j = len - 1;
        while (j > i && s[j] <= s[i])
            j--;

        // Step 3: Swap
        swap(s[i], s[j]);

        // Step 4: Reverse suffix
        reverse(s.begin() + i + 1, s.end());

        // Step 5: Check for overflow
        long long ans = stoll(s);
        if (ans > INT_MAX) return -1;

        return (int)ans;
            

    }
};
