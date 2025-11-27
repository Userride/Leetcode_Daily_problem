// Last updated: 11/27/2025, 5:18:22 PM
class Solution {
public:
    void call(int top,int right,int bottom,int left,vector<vector<int>>& ans){
        for(int i = top;i <= bottom;i++){
            for(int j=right;j<= left;j++){
                ans[i][j] += 1;
            }
        }
    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n));
        int s = queries.size();
        for(int i=0;i<s;i++){
            call(queries[i][0],queries[i][1],queries[i][2],queries[i][3],ans);
        }
        return ans;
    }
};