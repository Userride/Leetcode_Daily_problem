// Last updated: 11/27/2025, 5:16:49 PM
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (auto c : word) {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end());

        int i = 0;
        while (i < 26 && freq[i] == 0) i++;

        int range = freq[25];
        int ans = INT_MAX;

        for (int x = freq[i]; x <= range - k; x++) {
            int temp = 0;
            for (int j = i; j < 26; j++) {
                int high = x + k;
                if (freq[j] < x) {
                    temp += freq[j]; 
                } else if (freq[j] > high) {
                    temp += freq[j] - high; 
                }
            }
            ans = min(ans, temp);
        }

        return ans == INT_MAX ? 0 : ans;
    }
};