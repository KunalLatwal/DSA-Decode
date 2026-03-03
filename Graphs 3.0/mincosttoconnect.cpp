//bhai bs isme itna catch hai ki smjh jao ki kese  yh cooridanates ko points s nodes mai convert krke ,, kya distnce kese manage krni hai 
//weight nikl kr bs distance caluclate krke , kya kro adj list banalo bs 
//edges k madt s list bangyi to bs fir prims laga do 
class Solution {
public:
    //points ki jarurt thi sirf idtance calulate krne k liye 
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                //ab  isko push krdo adj mai 
                //mtlb har aek idnx mai lgbg n-1 pairs honge v,w k formate mai
                adj[i].push_back({j,w});
                adj[j].push_back({i,w});
            }
        }
        //adjancy list mai humne weight ko peche rkha ahi to fir min haep mia ab age rkhnege 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        q.push({0,0});  //yh kya tha dist on src node 
        int total =0 ;
        while(!q.empty())
        {
            auto [d,u] = q.top();
            q.pop();

            if(vis[u]==true)  continue;

            if(vis[u]==false)
            {
                total+=d;
                vis[u]=true;
            }

            for(auto [v,w] : adj[u])
            {
                if(vis[v]==false)
                {
                    q.push({w,v});
                }
            }
        }
        return total;
    }
};
