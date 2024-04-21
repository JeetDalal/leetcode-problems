#include <vector>
#include <string>

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> v(52, 0);
        int count = 0;

        for (int i = 0; i < word.size(); i++) {
            int asciiValue = (int)word[i];

            if (asciiValue < 65 || (asciiValue > 90 && asciiValue < 97) || asciiValue > 122) {
                count++;
            } else if (asciiValue < 97) {
                v[asciiValue - 'A']++;
            } else {
                v[asciiValue - 'a' + 26]++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (v[i] > 0 && v[i + 26] > 0) {
                count++;
            }
        }

        return count;
    }
};
