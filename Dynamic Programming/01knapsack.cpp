class Solution {
  public:
    
    
    //agr hum 0 s length minus one tk jare hai to kya kro
    //agr mai last element mai pahuch jau to kya hoga ya fir mera jo W hoga wo chota hoga ya 
    //bada hoga
    
    //har index mai 2 moves possible hai eith take or non take
    //ab non take to har zgha possible hhai 
    //ab rahi baat take ki agr tumne take krna hai to uske liye kya jaruri hai ki
    //jo element tum lere ho uska weight kya ho kam ho required s 
    //tle ko hatane k loye kya kro memoization krdo asnwer mai 
    //isme kya kya chnge hora hai W orr index
    
    int helper(int i,int W,vector<int>&val,vector<int> &wt,vector<vector<int>>&dp)
    {
        //zero s strt kra hu to agr mai out of bound chlejau to kya hoga
        if(i == val.size()) return 0;
        
        if(i == val.size()-1 && W >= wt[i]) return val[i];
        
        if(dp[i][W]!=-1) return dp[i][W];
        //ab dekho possibilties 
        int take=-1e9,untake=-1e9;
        //ab lega kb jb uska wt[i] km hofa
        if(wt[i] <= W)
        {
            //lega to kyu hoga jise lega wo add hoga or weight minus hoga
            take = val[i] + helper(i+1,W-wt[i],val,wt,dp);
        }
        untake = 0 + helper(i+1,W,val,wt,dp);
        
        return dp[i][W] = max(take,untake);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        //hume diya hai aaek kanpack we need to figure out the maximum value from the napsack
        //taking 1 element at 1 time
        //strting element s strt krle
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        //hwy did i take W +1 kyu muje W bhi include krna tha naki sirf W-1 last indx mai 
        return helper(0,W,val,wt,dp);
    }
};
