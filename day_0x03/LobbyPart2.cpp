#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define int long long
#define BATTERIES 12
#define BANKS 100

int getMax(vector<int> &numbers)
{
    int dp[BANKS][BATTERIES + 1];
    dp[0][0] = 0;
    dp[0][1] = numbers[0];

    for(int i = 1; i < BANKS; i++)
    {
        dp[i][0] = 0;
        for(int j = 1; j <= BATTERIES; j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] * 10LL + numbers[i]);
    }
    return dp[BANKS - 1][BATTERIES];
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