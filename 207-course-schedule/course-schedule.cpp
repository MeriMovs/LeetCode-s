class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> vec(numCourses, 0);

        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]);
            vec[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (vec[i] == 0) q.push(i);

        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;
            for (int next : adj[node])
                if (--vec[next] == 0) q.push(next);
        }

        return count == numCourses;
    }
};