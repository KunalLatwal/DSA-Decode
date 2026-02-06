https://leetcode.com/problems/n-queens/

class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        for(int j=col;j>=0;j--)
            if(board[row][j]=='Q') return false;

        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
            if(board[i][j]=='Q') return false;

        for(int i=row,j=col;i<n && j>=0;i++,j--)
            if(board[i][j]=='Q') return false;

        return true;
    }

    void dfs(int col, vector<string>& board,
             vector<vector<string>>& res, int n) {
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                dfs(col+1,board,res,n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        dfs(0,board,res,n);
        return res;
    }
};
