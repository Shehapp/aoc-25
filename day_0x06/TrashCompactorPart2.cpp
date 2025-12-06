#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#define int long long

using namespace std;

signed main()
{
    std::ifstream infile("input.txt");
    string line;
    
    vector<string> grid;
    vector<char> operations;
    
    while (getline(infile, line)) 
        grid.push_back(line);

    for (char c : grid.back())
        if (c == '+' || c == '*')
            operations.push_back(c);
    grid.pop_back();


    int res{0};
    int opt{0};
    int ans{operations[0] == '*'};
    for(int i = 0; i < grid[0].size(); i++)
    {
        int cur{-1};
        for(int j = 0; j < grid.size(); j++)
        {
            if(grid[j][i] != ' ' and cur == -1) cur = 0;
            if(grid[j][i] != ' ') cur = cur * 10 + (grid[j][i] - '0');
        }
        if(cur == -1)
        {
            res += ans;
            ans = (operations[++opt] == '*');
        }
        else{
            if(operations[opt] == '+') ans += cur;
            else ans *= cur;
        }
    }
    res += ans;


    printf("\n\n%lld\n\n", res);

    return 0;
}