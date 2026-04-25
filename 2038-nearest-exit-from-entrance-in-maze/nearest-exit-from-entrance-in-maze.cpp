class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        
        maze[entrance[0]][entrance[1]] = '+';
        
        int steps = 0;
        
        vector<pair<int,int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while (!q.empty()) {
            int sz = q.size();
            steps++;
            
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                    if (maze[nr][nc] == '+') continue;

                    if (nr == 0 || nc == 0 || nr == m-1 || nc == n-1) {
                        return steps;
                    }

                    maze[nr][nc] = '+';
                    q.push({nr, nc});
                }
            }
        }
        
        return -1;
    }
};