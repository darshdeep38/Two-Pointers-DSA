class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;   // "122" → only one '1'

        vector<int> s(n + 1);  // store generated magical string
        s[0] = 1; 
        s[1] = 2; 
        s[2] = 2;

        int head = 2;          // points to the element telling how many times to append next digit
        int tail = 3;          // next index to fill in s
        int num = 1;           // next number to append (toggle between 1 and 2)
        int countOnes = 1;     // initial '1' count (for index 0 only)

        while (tail < n) {
            int repeat = s[head];  // how many times to insert num

            while (repeat--) {
                if (tail >= n) break;
                s[tail] = num;
                if (num == 1) countOnes++;
                tail++;
            }

            num = 3 - num;  // toggle 1↔2
            head++;
        }

        return countOnes;
    }
};
