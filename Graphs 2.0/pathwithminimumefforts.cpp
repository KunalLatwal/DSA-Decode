class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size(), m=h[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0,0,0});
        dist[0][0]=0;
        
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        
        while(!pq.empty()){
            auto cur=pq.top(); pq.pop();
            int d=cur[0], x=cur[1], y=cur[2];
            
            if(x==n-1 && y==m-1) return d;
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int effort=max(d, abs(h[nx][ny]-h[x][y]));
                    if(dist[nx][ny] > effort){
                        dist[nx][ny]=effort;
                        pq.push({effort,nx,ny});
                    }
                }
            }
        }
        return 0;
    }
