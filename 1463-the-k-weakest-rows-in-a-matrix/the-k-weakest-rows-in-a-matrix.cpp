class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int, int> m;

        int s_n = mat.size();
        int s_m = mat[0].size();

        for (int j = 0; j < s_n; ++j) {
            int count = 0;
            int i = 0;
            while (i < s_m && mat[j][i]) {
                count++;
                ++i;
            }
            m.insert({count, j});
        }

        vector<int> res;
        for (auto [u, v] : m) {
            if (!k) break;
            res.push_back(v);
            --k;
        }

        return res;
    }
};