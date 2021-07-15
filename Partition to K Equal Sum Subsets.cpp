class Solution {
public:
    
    bool dfs(vector<int>& nums, vector<int>& vis, int idx , int k, int curS, int tSum) {

    if (k == 1) return true;
    
    if (curS == tSum) 
        return dfs(nums, vis, 0, k-1, 0, tSum);
    
    for (int i=idx; i<nums.size(); i++) {
        if (vis[i] == false && tSum >= curS+nums[i]) {
            vis[i] = true;
            if(dfs(nums, vis, i+1, k, curS+nums[i], tSum))
                return true;
            vis[i] = false;
        }
    }
    return false;
}
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum = 0;
    for (int i=0; i<nums.size(); i++) { 
        sum += nums[i];
    }
    
    if (sum % k != 0 || k > nums.size()) return false;
    
    int tarS = sum/k;
    vector<int>vis(nums.size(), 0);
    sort(nums.rbegin(), nums.rend());
    return dfs(nums, vis, 0, k, 0, tarS);
    }
};
