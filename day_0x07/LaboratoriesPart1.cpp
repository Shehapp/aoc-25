#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

signed main()
{
    std::ifstream infile("input.txt");
    string line;
    
    vector<string> grid;
    
    while (getline(infile, line)) 
        grid.push_back(line);
    
    int res{0};

    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size() ; j++)
        {
            if(grid[i][j] == 'S' and (i + 1) != grid.size())
            {
                if(grid[i + 1][j] == '.') grid[i + 1][j] = 'S';
                else if(grid[i + 1][j] == '^') grid[i + 1][j + 1] = grid[i + 1][j - 1] = 'S' , res++;
            }
        }
    }

    printf("\n\n%d\n\n", res);

    return 0;
}