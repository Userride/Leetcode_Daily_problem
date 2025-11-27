// Last updated: 11/27/2025, 5:18:14 PM
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Map each value in the matrix to its (row, column) index
        unordered_map<int, pair<int, int>> valueToIndex;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                valueToIndex[mat[i][j]] = {i, j};
            }
        }
        
        // Keep track of how many cells are painted in each row and column
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // Iterate through `arr` to paint cells
        for (int i = 0; i < arr.size(); i++) {
            int value = arr[i];
            auto [r, c] = valueToIndex[value]; // Get the row and column of the value
            
            rowCount[r]++;
            colCount[c]++;
            
            // Check if row `r` or column `c` is completely painted
            if (rowCount[r] == n || colCount[c] == m) {
                return i; // Return the first index where this happens
            }
        }
        
        return -1; // Should never reach here due to problem constraints
    }
};
