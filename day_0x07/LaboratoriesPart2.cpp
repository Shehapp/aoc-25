#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#define int long long 

using namespace std;

vector<vector<int>> dp(200, vector<int>(200, -1));
int dfs(int i, int j, vector<string> &grid)
{
    if(i == grid.size() - 1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(grid[i + 1][j] == '^') return dp[i][j] = dfs(i + 1, j + 1, grid) + dfs(i + 1, j - 1, grid);
    return dp[i][j] = dfs(i + 1, j, grid);
}

signed main()
{
    std::ifstream infile("input.txt");
    string line;
    
    vector<string> grid;
    
    while (getline(infile, line)) 
        grid.push_back(line);
    
    for(int j = 0; j < grid[0].size() ; j++)
    {
        if(grid[0][j] == 'S')
        {
            printf("\n\n%lld\n\n", dfs(0, j, grid));
            break;
        }
    }

    return 0;
}