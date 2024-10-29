class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int maxPath = 0;

        // Try starting from each cell in the first column
        for (int i = 0; i < n; ++i) {
            maxPath = max(maxPath, dfs(grid, i, 0, memo));
        }
        
        return maxPath;
    }

private:
    // Directions to move (only right, up-right, and down-right)
    vector<pair<int, int>> directions = {{0, 1}, {-1, 1}, {1, 1}};
    
    // Depth-First Search with memoization
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& memo) {
        if (y == grid[0].size() - 1) return 0; // Reached the last column
        
        if (memo[x][y] != -1) return memo[x][y]; // Return cached result
        
        int maxMoves = 0;
        
        for (auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            
            // Check bounds and ensure next cell has a strictly greater value
            if (newX >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] > grid[x][y]) {
                maxMoves = max(maxMoves, 1 + dfs(grid, newX, newY, memo));
            }
        }
        
        memo[x][y] = maxMoves; // Store result in memo table
        return maxMoves;
    }
};