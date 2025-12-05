#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <set>

#define int long long

using namespace std;

signed main()
{
    std::ifstream infile("input.txt");
    string line;
    
    vector<pair<int, int>> ranges;        
    while (getline(infile, line))
    {
        if(line.empty())break;
        ranges.push_back({stoll(line.substr(0, line.find('-'))), stoll(line.substr(line.find('-') + 1))});
    }

    sort(ranges.begin(), ranges.end());
    
    int res{0};

    int max_reach = 0;
    for(int i = 0; i < ranges.size() - 1; i++)
    {
        ranges[i].first =max(max_reach, ranges[i].first);
        if(ranges[i].second < ranges[i].first) continue;
        res += (ranges[i].second - ranges[i].first) + 1;
        max_reach = ranges[i].second + 1;
    }
    ranges[ranges.size() - 1].first =max(max_reach, ranges[ranges.size() - 1].first);
    res += max(0LL, (ranges[ranges.size() - 1].second - ranges[ranges.size() - 1].first) + 1);
    
    printf("\n\n%lld\n\n", res);
    return 0;
}