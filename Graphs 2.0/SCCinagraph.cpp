//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int node,stack<int>st,vector<vector<int>>&adj,vector<bool>&vis)
    {
        vis[node]=true;
        for(auto child : adj[node])
        {
            if(vis[child]==false)
            {
                dfs(child,st,adj,vis);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node,vector<vector<int>>&adj,vector<bool>&vis)
    {
        vis[node]=true;
        for(auto child : adj[node])
        {
            if(vis[child]==false)
            {
                dfs2(child,adj,vis);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        //well first call for dfs and store nodes in the basis or ther decreasing time
        // likw the last node would processed first
        //reverse the graph, reverse the edges
        // perform dfs traversal from the stack,,poping the elements from the stack 
        // every dfs cycle gives us 1 scc at a time
        int n = adj.size();
        vector<bool>vis(n,false);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,st,adj,vis);
            }
        }
        
        vector<vector<int>>transpose(n);
        //by this time we will have our stack ready in decreasing order of node
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            for(auto j : adj[i])
            {
                transpose[j].push_back(i);
            }
        }
        int cnt=0;
        //amin twist just go for the dfs but this time with stack placement
        while(!st.empty())
        {
            int t = st.top();
            st.pop();
            if(vis[t]==false)
            {
                cnt++;
                dfs2(t,transpose,vis);
            }
        }
        return cnt;
    }
};
