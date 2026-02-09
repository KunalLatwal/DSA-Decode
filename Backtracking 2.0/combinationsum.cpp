void solve(int ind, vector<int>& a, int target, vector<int>& temp, vector<vector<int>>& ans){
    if(target==0){ ans.push_back(temp); return; }
    if(ind==a.size() || target<0) return;

    temp.push_back(a[ind]);
    solve(ind,a,target-a[ind],temp,ans);
    temp.pop_back();

    solve(ind+1,a,target,temp,ans);
}
