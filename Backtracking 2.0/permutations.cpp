void solve(vector<int>& nums, vector<int>& path, vector<int>& used, vector<vector<int>>& ans){
    if(path.size()==nums.size()){
        ans.push_back(path); return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]) continue;
        used[i]=1;
        path.push_back(nums[i]);
        solve(nums,path,used,ans);
        path.pop_back();
        used[i]=0;
    }
}
