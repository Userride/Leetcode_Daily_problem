// Last updated: 11/30/2025, 10:59:56 PM
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        int INF = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, INF));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        heap.push({0, 0, 0});
        moveTime[0][0] = 0;
        vector<pair<int, int>> ways = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!heap.empty()){
            int time = heap.top()[0];
            int row = heap.top()[1];
            int col = heap.top()[2];
            heap.pop();
            if (time >= dp[row][col]){
                continue;
            }
            if (row == n - 1 && col == m - 1){
                return time;
            }
            dp[row][col] = time;
            for (auto& move : ways){
                int nextRow = row + move.first;
                int nextCol = col + move.second;
                if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && dp[nextRow][nextCol] == INF){
                    int cost = (row + col) % 2 + 1;
                    int count = max(moveTime[nextRow][nextCol], time);
                    int nextTime = count + cost;
                    heap.push({nextTime, nextRow, nextCol});
                }
            }
        }
        return -1;
    }
};