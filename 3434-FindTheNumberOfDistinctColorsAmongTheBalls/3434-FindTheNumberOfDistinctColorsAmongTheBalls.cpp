// Last updated: 11/27/2025, 5:16:33 PM
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result;
        result.reserve(n); // Prevents unnecessary reallocation

        unordered_map<int, int> colormp; // color -> count
        unordered_map<int, int> ballmp;  // ball -> color

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            if (ballmp.find(ball) != ballmp.end()) { // If ball already has a color
                int prevColor = ballmp[ball];
                if (--colormp[prevColor] == 0) { // Decrement count and remove if zero
                    colormp.erase(prevColor);
                }
            }

            // Assign new color and update color count
            ballmp[ball] = color;
            colormp[color]++;

            // Store the number of unique colors
            result.push_back(colormp.size());
        }

        return result;
    }
};
