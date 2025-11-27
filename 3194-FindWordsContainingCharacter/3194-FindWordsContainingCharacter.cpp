// Last updated: 11/27/2025, 5:17:21 PM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> idx;
        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i]) {
                if (ch == x) {
                    idx.push_back(i);
                    break;
                }
            }
        }
        return idx;
    }
};