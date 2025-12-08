#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>

#define int long long
using namespace std;

struct DSU
{
    int par[2000];
    int sizes[2000];
    DSU()
    {
        for(int i = 0; i < 2000; i++)
        {
            par[i] = i;
            sizes[i] = 1;
        }
    }

    void merge(int a, int b)
    {
        int aa = parent(a);
        int bb = parent(b);
        if(aa != bb)
        {
            if(sizes[aa] > sizes[bb])
            {
                sizes[aa] += sizes[bb];
                par[bb] = aa;
            }
            else
            {
                sizes[bb] += sizes[aa];
                par[aa] = bb;
            }
        }
    }

    int parent(int i)
    {
        if(i != par[i]) return par[i] = parent(par[i]);
        return i;
    }
};



struct Point
{
    int x{0};
    int y{0};
    int z{0};
};

double dis(const Point &p1, const Point &p2)
{
    double ans{0.0};
    ans += (p1.x - p2.x) * (p1.x - p2.x);
    ans += (p1.y - p2.y) * (p1.y - p2.y);
    ans += (p1.z - p2.z) * (p1.z - p2.z);
    return sqrt(ans);
}

signed main()
{
    std::ifstream infile("input.txt");
    string line;
    
    vector<Point> points;
    
    while (getline(infile, line)) 
    {
        int x, y, z;
        char comma;
        std::istringstream iss(line);
        iss >> x >> comma >> y >> comma >> z;
        points.push_back({x, y, z});
    }

    DSU dsu;
    int res{1};

    vector<pair<double, pair<int, int>>> cache;
    for(int i = 0; i < points.size() - 1; i++)
    {
        for(int j = i + 1; j < points.size(); j++)
        {
            cache.push_back({dis(points[i], points[j]),{i, j}});
        }
    }

    sort(cache.begin(), cache.end());
    int f = 0;
    for(auto ok: cache)
    {
        if(f == 1000 ) break;
        ++f;
        if(dsu.parent(ok.second.first) == dsu.parent(ok.second.second)) continue;
        dsu.merge(ok.second.first, ok.second.second);
    }

    vector<int> kk;
    for(int i = 0; i < points.size(); i++)
    {
        if(dsu.parent(i) == i)
            kk.push_back(dsu.sizes[i]);
    }

    sort(kk.rbegin(), kk.rend());

    for(int i = 0; i < 3; i++) res*=kk[i];

    printf("\n\n%d\n\n", res);

    return 0;
}