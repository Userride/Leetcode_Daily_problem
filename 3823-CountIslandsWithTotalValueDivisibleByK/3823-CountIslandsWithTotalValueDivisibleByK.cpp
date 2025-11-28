// Last updated: 11/28/2025, 12:49:02 PM
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int coloum = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(coloum, false));
        int res = 0;

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        function<long long(int, int)> dfs = [&](int x, int y) {
            vis[x][y] = true;
            long long sum = grid[x][y];

            for (auto [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < coloum &&
                    grid[nx][ny] > 0 && !vis[nx][ny]) {
                    sum += dfs(nx, ny);
                }
            }

            return sum;
        };

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < coloum; ++j) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long sum = dfs(i, j);
                    if (sum % k == 0) res++;
                }
            }
        }

        return res;
    }
};
