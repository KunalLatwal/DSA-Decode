//classic exempler question for breidges in a graph 
//count krna hai kitne edges is like a connections jinhe hatne s graph 2 compononts mai tut jaega

// User function Template for C++

class Solution {
  public:
    int timer=1;
  
    void dfs(int node,int parent,vector<bool>&vis,vector<int>&tin,vector<int>&low,
                vector<vector<int>>&adj,vector<vector<int>>&ans)
    {
        vis[node]=true;
        tin[node]=low[node]=timer++;
        
        for( auto  i :adj[node])
        {
            //any node visiting its parent would be just a waste of time 
            if(parent==i) continue;
            
            if(vis[i]==false)
            {
                //here to go deep 
                dfs(i,node,vis,tin,low,adj,ans);
                vector<int>cmp;
                low[node]=min(low[node],low[i]);
                //check for the bridge
                if(tin[node] < low[i])
                {
                    cmp.push_back(node);
                    cmp.push_back(i);
                }
                if(cmp.size() > 1)
                {
                    ans.push_back(cmp);
                }
            }
            
            else{
                low[node]=min(low[node],tin[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        // Code here
        //here in this questin we wil be solving this using bridges in graph 
        // bridges in a graoh can be defined as a edge
        //on which removing it breaks the graph into 2 or  more components
        // we will be using th e concept of time of insertion and lowest tie of insertins
        
        vector<vector<int>>adj(v);
        for(auto i : edges)
        {
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // now we will be applyin the concept of bridges 
        //creating the time of insertion and lowest time vectors
        vector<int>tin(v);
        vector<int>low(v);
        vector<bool>vis(v,false);
        
        vector<vector<int>>ans;
        for(int i=0;i<v;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,-1,vis,tin,low,adj,ans);
            }
        }
        return ans;
    }
};
