class Solution {
    public:
 int coinChange(vector<int>& coins, int amount) {
        // dp[i] = min coins to make up to amount i
       std::sort(coins.rbegin(),coins.rend());
       int ans = INT_MAX;
        coinChange(coins,0,amount,0,ans);
        return ans == INT_MAX? -1:ans;
    }
private:
    void coinChange(const vector<int>& coins, int s, int amount, int count, int& ans)
    {
        if (amount == 0)
        {
            ans = min(ans, count);
            return;
        }
        if (s == coins.size()) return;
        const int coin = coins[s];

        if (s == coins.size()-1)
        {
            if (amount%coin == 0)
            {
                ans = min(ans, count + amount/coin);
            }
        }
        else
        {
            for (int k = amount/coin; k >= 0 && count + k < ans; k--)
            {
                coinChange(coins,s+1,amount - k*coin, count + k, ans);
            }
        }

    }
};
