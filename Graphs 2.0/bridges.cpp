/*today i learned about bridges in a graph 
can be  detected using the TARJANS algorithm ,, kya krna hota hai ki bs tume har node ko dfs k through traverse krke make sure krna hai ki tum uska TIN and LOW adjust krdo 
tin hamesha increase hota rahega but low change hota hai kyuki , tumhe pata hai ki tere can be sevral ways out there jinsse traverse krke i can reach to you 
aek classic example lelo ki suppose mere dost k timeofinsertion kisi bhi skill k 1yr hai , usne muje 2 mai bataya but cahnges hai ki merko phele s pata ho ,, agr muje hele s pata hoga to i cant refuse ki muje tune ni bataya
ill show ki haan bhai tune hi batay muje so mera tin hamesha uske liye 2 hi rahega no matter agr muje wohi skill bca s ati hai 
if koi node first time dfs k liye jari hai to as usal node k lsht jaegi then wps ake ,, apne dost s yh mai clear krskta hu ki kb meine last time chnge kra tha so this is tin and low cconcept*/

<H1>BRIDGES IN GRAPH</H2>

  class Solution {
public:
    int timer = 1;   // global timer rakha hai taaki har node ka unique time aaye

    void dfs(int node, int parent,
             vector<bool>& vis,
             vector<int>& tin,
             vector<int>& low,
             bool &ans,
             vector<vector<int>>& adj,
             int c, int d)
    {
        vis[node] = true;

        // jab visit kiya tabhi iska time set kar diya
        tin[node] = low[node] = timer++;

        // ab neighbours mai jao bhai
        for(auto i : adj[node])
        {
            // agar parent hai to ignore karo warna galat back edge ban jayega
            if(i == parent) continue;

            // agar visited nahi hai to tree edge hai
            if(!vis[i])
            {
                // dfs chalao child pe
                dfs(i, node, vis, tin, low, ans, adj, c, d);

                // wapas aake check karo kya child ke through koi aur rasta mila
                low[node] = min(low[node], low[i]);

                // agar child apne upar wapas nahi ja sakta
                // mtlb low[child] > tin[parent] -> bridge
                if(low[i] > tin[node])
                {
                    // ab check karo kya yehi wala edge (c,d) hai
                    if((node == c && i == d) || (node == d && i == c))
                    {
                        ans = true;   // mil gaya bridge
                    }
                }
            }
            else
            {
                // yaha back edge mila hai
                // matlab koi ancestor tak alternate rasta hai
                low[node] = min(low[node], tin[i]);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d)
    {
        // pehle adjacency list banao
        vector<vector<int>> adj(V);

        for(auto i : edges)
        {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(V, false);
        vector<int> tin(V), low(V);

        bool ans = false;

        // ho sakta hai graph disconnected ho
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i, -1, vis, tin, low, ans, adj, c, d);
            }
        }

        return ans;   // true -> bridge hai, false -> nahi hai
    }
};
