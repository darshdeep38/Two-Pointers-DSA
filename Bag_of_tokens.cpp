#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size() - 1;
        int score = 0, maxScore = 0;
        
        while (low <= high) {
            // Play face-up: spend power to gain score
            if (power >= tokens[low]) {
                power -= tokens[low++];
                score++;
                maxScore = max(maxScore, score);
            } 
            // Play face-down: spend score to gain power
            else if (score > 0) {
                power += tokens[high--];
                score--;
            } 
            else break;
        }
        
        return maxScore;
    }
};
