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
    
    vector<vector<int>> grid;
    vector<char> operations;
    
    while (getline(infile, line)) 
    {
        bool isOpLine = find (line.begin(), line.end(), '+') != line.end() || find(line.begin(), line.end(), '*') != line.end();
        if(isOpLine)
            for (char c : line)
                if (c == '+' || c == '*')
                    operations.push_back(c);

        if (!isOpLine) 
        {
            vector<int> row;
            stringstream ss(line);
            string token;
            while (ss >> token) 
                if (!token.empty())
                    row.push_back(stoull(token));
            grid.push_back(row);
        }
    }
    
    int res{0};

    for(int i = 0; i < grid[0].size(); i++)
    {
        int cur = grid[0][i];
        for(int j = 1; j < grid.size(); j++)
            if(operations[i] == '+') cur += grid[j][i];
            else cur *= grid[j][i];
        res += cur;
    }

    printf("\n\n%lld\n\n", res);

    return 0;
}