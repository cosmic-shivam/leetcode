class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        //copied
        // If out of bounds or water in grid2, return true
        if (i < 0 || j < 0 || i >= grid2.size() || j >= grid2[0].size() || grid2[i][j] == 0) {
            return true;
        }

        // If there is land in grid2 but not in grid1, it's not a sub-island
        if (grid2[i][j] == 1 && grid1[i][j] == 0) {
            return false;
        }

        // Mark the current cell in grid2 as visited
        grid2[i][j] = 0;

        // Recursively check all 4 directions
        bool top = dfs(grid1, grid2, i-1, j);
        bool bottom = dfs(grid1, grid2, i+1, j);
        bool left = dfs(grid1, grid2, i, j-1);
        bool right = dfs(grid1, grid2, i, j+1);

        // Return true only if all parts of the island are valid sub-islands
        return top && bottom && left && right;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslandsCount = 0;

        // Iterate through grid2 to find islands
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1) { // If there's an unvisited island part in grid2
                    if (dfs(grid1, grid2, i, j)) { // Perform DFS and check if it's a sub-island
                        subIslandsCount++;
                    }
                }
            }
        }

        return subIslandsCount;
    }
};