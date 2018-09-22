#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

#define MAX_N 100001
/*
Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2
*/

int parents[MAX_N]={0};
int levels[MAX_N]={0};
int main()
{
    int i, N, level, maxLevel=0, maxLevelCount=0,parent;
    double P, r, price;
    cin>>N>>P>>r;
    for(i=0; i<N; ++i)
    {
        cin>>parents[i];
    }
    for(i=0; i<N; ++i)
    {
        if(levels[i]!=0)
            continue;
        level = 0;
        parent = parents[i];
        while(true)
        {
            if(parent==-1)
                break;
            if(levels[parent]!=0)
            {
                level=level+levels[parent]+1;
                break;
            }
            ++level;
            parent = parents[parent];
        }
        if(level>maxLevel)
        {
            maxLevel = level;
            maxLevelCount = 1;
        }
        else if(level==maxLevel)
        {
            ++maxLevelCount;
        }
        parent = parents[i];
        levels[i] = level;
        while(true)
        {
            if(parent==-1)
                break;
            if(levels[parent]!=0)
                break;
            levels[parent] = --level;
            parent = parents[parent];
        }
    }
    i=0;
    price = P;
    while(i<maxLevel)
    {
        price = price*(1+r/100.0);
        ++i;
    }
    cout<<std::fixed<<setprecision(2)<<price<<" "<<maxLevelCount<<endl;
}
