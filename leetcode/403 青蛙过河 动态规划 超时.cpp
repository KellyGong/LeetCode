class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp = vector(stones.size(), vector(stones.size(), 0));
        dp[0][1] = 1;
        vector<int> jumpmax = vector(stones.size(), 0);
        jumpmax[1] = 2;
        
        if(stones[1] - stones[0] != 1) return false;
        for(int i = 2; i < stones.size(); i++){
            for(int j = i - 1; j > 0; j--){
                int sub = stones[i] - stones[j];
                if(sub > jumpmax[j]) continue;
                for(int k = 0; k < j; k++){
                    if(abs(sub - dp[k][j]) <= 1 && dp[k][j] > 0){
                        dp[j][i] = sub;
                        jumpmax[i] = max(jumpmax[i], sub + 1);
                    }
                }
            }
        }
        
        bool flag = false;
        for(int i = 0; i < stones.size(); i++){
            if(dp[i][stones.size() - 1] != 0) flag = true;
        }
        
        return flag;
    }
};