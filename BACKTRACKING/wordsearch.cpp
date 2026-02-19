class Solution {
public:

    void dfs(vector<vector<char>>&board,vector<vector<bool>>&vis,int r,int c,int index,
                bool &found,string word)
    {
        int row=board.size();
        int col=board[0].size();

        //pjela dekkheneg boundry check
        if(r>=row || r<0 || c>=col || c<0) return;

        if(vis[r][c]==true || board[r][c]!=word[index]) return;

        //ab check hogi age badhne ki commands
        if(index==word.length()-1 && board[r][c]==word[index]) 
        {
            found=true;
            return;
        }

        vis[r][c]=true;

        dfs(board,vis,r-1,c,index+1,found,word);
        dfs(board,vis,r+1,c,index+1,found,word);
        dfs(board,vis,r,c-1,index+1,found,word);
        dfs(board,vis,r,c+1,index+1,found,word);

        vis[r][c]=false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();

        vector<vector<bool>>vis(row,vector<bool>(col,false));
        int index=0;
        bool found=false;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==word[index] && vis[i][j]==false)
                {
                    dfs(board,vis,i,j,index,found,word);
                }
            }
        }
        return found;
    }
};
