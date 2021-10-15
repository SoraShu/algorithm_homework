int merge_stone(int n, int w[])
{
    int p[n + 1][n + 1];
    int dp[n + 1][n + 1];
    int inf = 10000;
    for (int i = 1; i <= n; ++i)
    {
        p[i][i] = w[i];
        for (int j = i; j <= n; ++j)
            p[i][j] = p[i][j - 1] + w[j];
    }

    for (int i = 1; i <= n; ++i)
        dp[i][i] = 0;
    for (int l = 2; l <= n; ++l)
    {
        for (int i = 1; i < n - l + 1; ++i)
        {
            int j = i + l - 1;
            dp[i][j] = inf;
            for (int k = i; k < j; ++k)
                dp[i][j] = (dp[i][k] + dp[k + 1][j] + p[i][j] < dp[i][j]) ? dp[i][k] + dp[k + 1][j] + p[i][j] : dp[i][j];
        }
    }
    return dp[1][n];
}