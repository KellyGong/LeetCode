class Solution {
public:
    int res = 0;
    
    int startx = 0;
    int starty = 0;
    
    int endx = 0;
    int endy = 0;
    
    void dfs(int x, int y, vector<vector<int>>& grid){
        if(grid[x][y] == -1 || grid[x][y] == 3) return;
        if(grid[x][y] == 2){
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    if(grid[i][j] == 0)return;
                }
            }
            res++;return;
        }
        
        grid[x][y] = -1;
        
        if(x - 1 >= 0){
            dfs(x-1, y, grid);
        }
        if(x + 1 < grid.size()){
            dfs(x + 1, y, grid);
        }
        if(y - 1 >= 0){
            dfs(x, y-1, grid);
        }
        if(y + 1 < grid[0].size()){
            dfs(x, y + 1, grid);
        }
        
        grid[x][y] = 0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        if(m == 0) return 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    startx = i;
                    starty = j;
                }
                else if(grid[i][j] == 2){
                    endx = i;
                    endy = j;
                }
            }
        }
        
        dfs(startx, starty, grid);
        
        return res;
    }
};