class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> minDo(n, 0);
        minDo[0] = INT_MAX;
        vector<int> maxVir(n, 0);
        int max = 0;

        for(int i = 1; i < n; ++i) {
            minDo[i] = min(minDo[i-1], prices[i-1]);
        }

        for(int i = 1; i < n; ++i) {
            maxVir[i] = prices[i] - minDo[i];
            max = maxVir[i] > max ? maxVir[i] : max;
        }

        return max;
    }
};