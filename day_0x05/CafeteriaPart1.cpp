#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#define int unsigned long long

using namespace std;

signed main()
{
    std::ifstream infile("input.txt");
    string line;
    
    vector<pair<int, int>> ranges;    
    vector<int> numbers;
    
    while (getline(infile, line))
    {
        if(line.empty())break;
        ranges.push_back({stoll(line.substr(0, line.find('-'))), stoll(line.substr(line.find('-') + 1))});
    }
    
    while (getline(infile, line))
        numbers.push_back(stoll(line));

    int res{0};
    for(auto Q:numbers)
        for(auto [l,r]:ranges)
            if(Q >= l and r >= Q)
            {
                res++;
                break;
            }
    printf("\n %d \n\n", res);
    return 0;
}