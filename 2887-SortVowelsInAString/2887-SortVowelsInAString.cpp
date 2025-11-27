// Last updated: 11/27/2025, 5:17:44 PM
// Input: s = "lEetcOde", Output: "lEOtcede"
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end());

        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                 //jaha jaha vowel hai waha sorted wala voewl dal do
                s[i] = vowels[idx]; 
                idx++;
            }
        }

        return s;
    }
};
