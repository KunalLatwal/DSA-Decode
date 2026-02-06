https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        int r=grid.size(), c=grid[0].size();
        if(i<0||i>=r||j<0||j>=c||grid[i][j]==0) return;
        grid[i][j]=0;
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        for(int i=0;i<r;i++){
            dfs(grid,i,0);
            dfs(grid,i,c-1);
        }
        for(int j=0;j<c;j++){
            dfs(grid,0,j);
            dfs(grid,r-1,j);
        }
        int cnt=0;
        for(auto& row:grid)
            for(int x:row) cnt+=x;
        return cnt;
    }
};
