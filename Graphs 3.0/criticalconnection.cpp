// User function Template for C++

class Solution {
    public : 
    int timer=1;
    
  public:
  
    void dfs(int node,int parent,vector<bool>&vis,vector<int>&tin,
            vector<int>&low,vector<vector<int>>&adj,vector<vector<int>>&con)
    {
        //first step is makr the visited
        vis[node]=true;
        tin[node]=low[node]=timer++;
        
        //then go for processing the neighbours
        for(auto n : adj[node])
        {
            vector<int>f;
            
            if(n==parent) continue;
            
            if(vis[n]==false)
            {
                //go for dfs with parent as node // kyuki tum use hi wps aye ho
                dfs(n,node,vis,tin,low,adj,con);
                low[node]=min(low[node],low[n]);
                
                //check if it can go up form parent
                if(tin[node] < low[n]) //is yes it cannot go up here 
                {
                    f.push_back(node);
                    f.push_back(n);
                }
            }
            else{
                //it means that the neighbour that can be traversed is the back edge here 
                //pass it the tin of insertion of that particular node
                low[node]=min(low[node],tin[n]);
            }
            if(f.size() > 0) con.push_back(f);
        }
    }
        
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        // Code here
        // so in thsi question we need to find out the cirital connection also know as the bridges 
        //in a graph
        vector<vector<int>>adj(v);
        for(auto i : edges)
        {
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //created the adjacency list using the edges vector
        //now the tsk is to perform the dfs ..// since dfs requires the helper function
        //so just make a dfs function with TIN[] ADN LOW[]
        vector<int>tin(v);
        vector<int>low(v);
        vector<bool>vis(v,false);
        vector<vector<int>>con;
        for(int i=0;i<v;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,-1,vis,tin,low,adj,con);
            }
        }
        return con;
    }
};
