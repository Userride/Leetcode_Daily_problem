// Last updated: 11/27/2025, 5:16:18 PM
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int N = n + (k - 1);

        
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int i = 0;
        int j = 0;
        int result = 0;

        while (j < N) {
            if (j > 0 && colors[j] == colors[j - 1]) { 
                i = j;
                j++;
                continue;
            }

            if (j - i + 1 == k) {
                result++;
                i++;
            }

            j++;
        }

        return result;
    }
};
