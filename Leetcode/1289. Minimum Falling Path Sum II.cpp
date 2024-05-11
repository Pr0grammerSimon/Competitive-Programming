class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int MAXN = 1e6,n=grid.size();
        int pop_mini=0,pop_mini_2=0,pos_pop_mini=-1;
        int akt_mini,akt_mini_2,akt_pos;
        for (int y=0; y<n; y++){
            akt_mini = MAXN;
            akt_mini_2 = MAXN;
            for (int x=0; x<n; x++){
                if (pos_pop_mini != x){
                    if (akt_mini>=pop_mini+grid[y][x]){
                        akt_mini_2 = akt_mini;
                        akt_mini = pop_mini+grid[y][x];
                        akt_pos = x;
                    }
                    else if (akt_mini_2>pop_mini+grid[y][x]){
                        akt_mini_2 = pop_mini+grid[y][x];
                    }
                }
                else{
                    if (akt_mini>=pop_mini_2+grid[y][x]){
                        akt_mini_2 = akt_mini;
                        akt_mini = pop_mini_2+grid[y][x];
                        akt_pos = x;
                    }
                    else if (akt_mini_2>pop_mini_2+grid[y][x]){
                        akt_mini_2 = pop_mini_2+grid[y][x];
                    }
                }
            
            }
            pop_mini=akt_mini,pop_mini_2=akt_mini_2,pos_pop_mini=akt_pos;
        }
        return pop_mini;
    }
};