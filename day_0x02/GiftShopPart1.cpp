#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

#define int unsigned long long

set<int>nums;

void build()
{
    for(int i=1; i<=100000;i++)
        nums.insert(stoll(to_string(i)+to_string(i)));
}

signed main()
{
    build();
    string line;
    std::ifstream infile("input.txt");
    infile >> line;
    vector<pair<long long, long long>> points;
    size_t start = 0;
    while (start < line.size()) 
    {
        size_t comma = line.find(',', start);
        string token = line.substr(start, (comma == string::npos ? line.size() : comma) - start);
        size_t dash = token.find('-');
        if (dash != string::npos) 
        {
            long long first = stoll(token.substr(0, dash));
            long long second = stoll(token.substr(dash + 1));
            points.emplace_back(first, second);
        }
        if (comma == string::npos) break;
        start = comma + 1;
    }
    int ans = 0;
    for(auto i:nums)
        for(auto [a,b]:points)
            if(i>=a and b>=i)ans+=i;

    cout<<ans<<"\n";
    return 0;
}