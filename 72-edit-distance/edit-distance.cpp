class Solution {
public:
    string s1, s2;
    vector<std::vector<int>> dp;

    int editDist(int n, int m) {
        if (dp[n][m] != -1)
            return dp[n][m];
        if (n == 0 || m == 0)
            return (m + n);

        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = editDist(n - 1, m - 1);
        } else {
            int r1 = editDist(n - 1, m - 1);
            int r2 = editDist(n, m - 1);
            int r3 = editDist(n - 1, m);

            return dp[n][m] = 1 + std::min({r1, r2, r3});
        }
    }
    int minDistance(string word1, string word2) {
        s1 = word1;
        s2 = word2;
        int n = s1.size(), m = s2.size();
        dp.assign(n + 1, std::vector<int>(m + 1, -1));
        return editDist(n, m);
    }
};