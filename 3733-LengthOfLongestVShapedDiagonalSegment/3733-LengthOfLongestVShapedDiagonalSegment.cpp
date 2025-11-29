// Last updated: 11/29/2025, 4:15:43 PM
class Solution {
public:
    vector<pair<int,int>> dirs = {{1,1},{1,-1},{-1,-1},{-1,1}};

    void dfs(vector<vector<int>>& grid, int i, int j, int dir, int len, int expected, bool canTurn, int &ans) {
        ans = max(ans, len);

        int n = grid.size(), m = grid[0].size();
        int nx = i + dirs[dir].first;
        int ny = j + dirs[dir].second;
        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==expected) {
            dfs(grid,nx,ny,dir,len+1,nextExpected(expected),canTurn,ans);
        }
        if(canTurn) {
            int ndir = (dir+1)%4;
            int tx = i + dirs[ndir].first;
            int ty = j + dirs[ndir].second;
            if(tx>=0 && ty>=0 && tx<n && ty<m && grid[tx][ty]==expected) {
                dfs(grid,tx,ty,ndir,len+1,nextExpected(expected),false,ans);
            }
        }
    }

    int nextExpected(int val) {
        if(val==1) return 2;
        if(val==2) return 0;
        return 2; 
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int d=0;d<4;d++){
                        dfs(grid,i,j,d,1,2,true,ans);
                    }
                }
            }
        }
        return ans;
    }
};