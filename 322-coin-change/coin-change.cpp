class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for(int i = 1; i < amount+1; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                int m = coins[j];
                if(i > m-1)
                    dp[i] = min(dp[i], dp[i-m] + 1);
            }
        }

        int res = dp[amount] > amount ? -1 : dp[amount];
        return res;
    }
};