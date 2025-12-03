#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define int long long

int getMax(const vector<int> &numbers)
{
    int maxSum{0};

    for(int i = 0; i < numbers.size() - 1; i++)
        for(int j = i + 1; j < numbers.size(); j++)
            maxSum = max(maxSum, numbers[i] * 10LL + numbers[j]);
    
    return maxSum;
}

signed main()
{
    std::ifstream infile("input.txt");

    int res=0;
    string c;
    while (infile >> c)
    {
        std::vector<int> numbers;
        for(char ch : c)
            numbers.push_back(ch - '0');
        res+=getMax(numbers);
    }
    cout<<res<<'\n';
    return 0;
}