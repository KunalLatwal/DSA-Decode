// User function Template for C++
class Solution {
  public:
  
  class dsu{
    public:
    
    vector<int>parent,size;
    
    public:
    dsu(int n)
    {
        size.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int find(int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
      
    void unite(int x,int y)
    {
        int px=find(x);
        int py=find(y);
        if(px==py) return;
          
        if(size[px] > size[py])
        {
            parent[py]=px;
            size[px]+=size[py];
        }
        else{
            parent[px]=py;
            size[py]+=size[px];
        }
    }
  };
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        dsu d1(n*m);
        //delcared our disjoint set 
        
        vector<vector<int>>vis(n,vector<int>(m,0));     //mark all as one
        int cnt=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<int>ans;
        for(auto i : operators)
        {
            int r=i[0];
            int c=i[1];
            
            if(vis[r][c]==1)
            {
                //mtlb already marked hai 
                ans.push_back(cnt);
                continue;
            }
            //idr aye mtlb ni hai marked 
            vis[r][c]=1;
            cnt++;
            //mark them as visited and inrease the cnt;
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                
                //explore the neighbours
                //check for the boundries
                
                if(nr >= 0 && nr < n && nc < m && nc >= 0)
                {
                    //if inside the block
                    if(vis[nr][nc]==1)
                    {
                        //if already a island go for its numbered block
                        int node=r*m+c;
                        int newnode=nr*m+nc;
                        
                        //check kahi connected to ni hai 
                        if(d1.find(node)!=d1.find(newnode))
                        {
                            //mtlb connected ni hai 
                            //connect krdo or make sure to decreamenet counter
                            d1.unite(node,newnode);
                            cnt--;
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
