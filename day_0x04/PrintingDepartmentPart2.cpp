#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int dx[] = {0, 1, 0, -1, 1, -1, -1, 1};
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

signed main()
{
    std::ifstream infile("input.txt");
    vector<string> lines;
    string line;
    while (getline(infile, line))
        lines.push_back(line);

    auto isRollsOfPaper=[&](int x, int y)->bool
    {
        return (x < line.size() and y < lines.size() and lines[y][x] == '@');
    };
    int res{0};

    for(;;)
    {
        vector<pair<int, int>> rem;
        for(int i = 0; i < lines.size(); i++)
        {
            for(int j = 0; j < line.size(); j++)if(lines[i][j] == '@')
            {
                int cur{0};
                for(int k = 0; k < 8; k++)
                    cur += isRollsOfPaper(j + dx[k], i + dy[k]);

                if(cur < 4)
                    rem.push_back({i, j});
            }
        }
        if(rem.size() == 0)break;
        res += rem.size();
        for(auto [y,x] : rem)
            lines[y][x] = 'x';
    }

    printf("\n %d \n", res);

    return 0;
}