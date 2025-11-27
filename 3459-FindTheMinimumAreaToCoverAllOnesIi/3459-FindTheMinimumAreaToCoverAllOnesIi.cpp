// Last updated: 11/27/2025, 5:16:26 PM
class Solution {
public:
    int minarea(vector<vector<int>>& grid,int t,int b,int l,int r){
        int r1=1e9,r2=-1,c1=1e9,c2=-1;
        bool found=false;
        for(int i=t;i<=b;i++){
            for(int j=l;j<=r;j++){
                if(grid[i][j]){
                    r1=min(r1,i);
                    r2=max(r2,i);
                    c1=min(c1,j);
                    c2=max(c2,j);
                    found=true;
                }
            }
        }
        if(!found) return 0;
        return (r2-r1+1)*(c2-c1+1);
    }

    vector<vector<int>> rotate90(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[m-j-1][i]=grid[i][j];
            }
        }
        return ans;
    }

    int first_case(vector<vector<int>> grid){
        int n=grid.size(),m=grid[0].size();
        int mini=INT_MAX;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int one=minarea(grid,0,i,0,m-1);
                int two=minarea(grid,i+1,j,0,m-1);
                int three=minarea(grid,j+1,n-1,0,m-1);
                mini=min(mini,one+two+three);
            }
        }
        return mini;
    }

    int second_case(vector<vector<int>> grid){
        int n=grid.size(),m=grid[0].size();
        int mini=INT_MAX;
        for(int i=0;i<m-2;i++){
            for(int j=i+1;j<m-1;j++){
                int one=minarea(grid,0,n-1,0,i);
                int two=minarea(grid,0,n-1,i+1,j);
                int three=minarea(grid,0,n-1,j+1,m-1);
                mini=min(mini,one+two+three);
            }
        }
        return mini;
    }

    int third_case(vector<vector<int>> grid){
        int n=grid.size(),m=grid[0].size();
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                int one=minarea(grid,0,i,0,m-1);
                int two=minarea(grid,i+1,n-1,0,j);
                int three=minarea(grid,i+1,n-1,j+1,m-1);
                mini=min(mini,one+two+three);

                one=minarea(grid,0,n-1,0,j);
                two=minarea(grid,0,i,j+1,m-1);
                three=minarea(grid,i+1,n-1,j+1,m-1);
                mini=min(mini,one+two+three);

                one=minarea(grid,0,i,0,j);
                two=minarea(grid,0,i,j+1,m-1);
                three=minarea(grid,i+1,n-1,0,m-1);
                mini=min(mini,one+two+three);

                one=minarea(grid,0,i,0,j);
                two=minarea(grid,i+1,n-1,0,j);
                three=minarea(grid,0,n-1,j+1,m-1);
                mini=min(mini,one+two+three);
            }
        }
        return mini;
    }

    int minimumSum(vector<vector<int>>& grid){
        vector<vector<int>> rotated=rotate90(grid);
        int ans=INT_MAX;
        ans=min(ans,first_case(grid));
        ans=min(ans,second_case(grid));
        ans=min(ans,third_case(grid));
        ans=min(ans,first_case(rotated));
        ans=min(ans,second_case(rotated));
        ans=min(ans,third_case(rotated));
        return ans;
    }
};


