int coinChange(int *coins, int coinsSize, int amount)
{
    int inf = amount + 1;
    if (coinsSize == 0 || !coins || amount < 0)
        return -1;
    if (!amount)
        return 0;
    if (coinsSize == 1 && amount % coins[0])
        return -1;

    int *dp = (int *)malloc(sizeof(int) * (amount + 1));
    for (int i = 0; i <= amount; ++i)
        dp[i] = inf;
    dp[0] = 0;

    for (int i = 0; i <= amount; ++i)
    {
        for (int j = 0; j < coinsSize; ++j)
        {
            if (i < coins[j])
                continue;
            if (dp[i] > dp[i - coins[j]] + 1)
                dp[i] = dp[i - coins[j]] + 1;
        }
    }
    return (dp[amount] == inf) ? -1 : dp[amount];
}