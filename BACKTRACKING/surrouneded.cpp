https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int r=board.size(), c=board[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<r;i++){
            if(board[i][0]=='O'){ board[i][0]='#'; q.push({i,0}); }
            if(board[i][c-1]=='O'){ board[i][c-1]='#'; q.push({i,c-1}); }
        }
        for(int j=0;j<c;j++){
            if(board[0][j]=='O'){ board[0][j]='#'; q.push({0,j}); }
            if(board[r-1][j]=='O'){ board[r-1][j]='#'; q.push({r-1,j}); }
        }

        int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto [x,y]=q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(nx>=0 && nx<r && ny>=0 && ny<c && board[nx][ny]=='O'){
                    board[nx][ny]='#';
                    q.push({nx,ny});
                }
            }
        }

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                board[i][j]=(board[i][j]=='#')?'O':'X';
    }
};
