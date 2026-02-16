class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start, int end) {
        
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> prob(n,0);
        priority_queue<pair<double,int>> pq;
        
        pq.push({1,start});
        prob[start]=1;
        
        while(!pq.empty()){
            auto [p,u]=pq.top(); pq.pop();
            if(u==end) return p;
            
            for(auto [v,w]:adj[u]){
                if(prob[v] < p*w){
                    prob[v]=p*w;
                    pq.push({prob[v],v});
                }
            }
        }
        return 0;
    }
};
