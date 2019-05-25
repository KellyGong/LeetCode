class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int j = 2; j < n; j++){
            for(int i = 0; i + j < n; i++){
                for(int k = i + 1; k - i < j; k++){
                    dp[i][i + j] = max(dp[i][i + j], dp[i][k] + dp[k][i + j] + nums[i] * nums[k] * nums[i + j]);
                }
            }
        }
        
        
        return dp[0][n - 1];
    }
};