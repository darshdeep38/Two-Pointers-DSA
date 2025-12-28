class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

       
       
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        
        int wordLen = words[0].size();

        // Total number of words
        int wordCount = words.size();

        // Total length of concatenated substring
        // Example: words = ["foo","bar"] → 3 * 2 = 6
        int windowLen = wordLen * wordCount;

        // Store frequency of each required word
        unordered_map<string, int> freq;
        for (auto &w : words) {
            freq[w]++;
        }
        // Example: ["foo","bar"] → { "foo":1, "bar":1 }

        // Try all possible starting offsets
        // Because words have fixed length, valid substrings
        // can start only at index:
        // 0, wordLen, 2*wordLen...
        // 1, 1+wordLen, 1+2*wordLen...
        // ...
        for (int i = 0; i < wordLen; i++) {

            // Stores words seen in current sliding window
            unordered_map<string, int> seen;

            // Left pointer of sliding window
            int left = i;

            // Count of valid words matched in current window
            int count = 0;

            //  Slide the window word by word (not char by char)
            for (int right = i; right + wordLen <= s.size(); right += wordLen) {

                // Extract the current word of size wordLen
                string word = s.substr(right, wordLen);

                //  If word exists in required list
                if (freq.count(word)) {

                    // Add word to seen map
                    seen[word]++;
                    count++;

                    //  If a word appears more times than allowed
                    // shrink window from left until valid
                    while (seen[word] > freq[word]) {

                        // Remove leftmost word from window
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;

                        // Move left pointer forward
                        left += wordLen;

                        // Reduce matched count
                        count--;
                    }

                    //  If all words matched exactly once
                    // we found a valid starting index
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                }
                //  If word is NOT part of required list
                // Reset window completely
                else {
                    seen.clear();      // Clear seen words
                    count = 0;         // Reset count
                    left = right + wordLen; // Move left after this word
                }
            }
        }

       
        return result;
    }
};
