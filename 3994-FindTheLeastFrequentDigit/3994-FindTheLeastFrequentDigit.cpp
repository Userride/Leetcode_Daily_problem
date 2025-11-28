// Last updated: 11/28/2025, 12:48:36 PM
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> mp;
        string s = to_string(n);
        
        for(char c : s) {
            int digit = c - '0';
            mp[digit]++;
        }
        int minFreq = INT_MAX;
        int result = 9; 

        for(auto &it : mp) {
            if(it.second < minFreq) {
                minFreq = it.second;
                result = it.first;
            } else if(it.second == minFreq && it.first < result) {
                result = it.first;
            }
        }

        return result;
    }
};