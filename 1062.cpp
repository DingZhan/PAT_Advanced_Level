#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
/*
Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/
struct People
{
    char ID[9];
    unsigned short virtue;
    unsigned short talent;
};
bool SortFunPeople(const People&a, const People&b)
{
    if(a.talent+a.virtue>b.talent+b.virtue)
        return true;
    else if(a.talent+a.virtue<b.talent+b.virtue)
        return false;
    else if(a.virtue>b.virtue)
        return true;
    else if(a.virtue<b.virtue)
        return false;
    else
    {
        int ret = strcmp(a.ID, b.ID);
        if(ret<0)
            return true;
        else
            return false;
    }
}
int main()
{
    size_t i, N, L, H;
    std::vector<People> sages, noblemen, foolmen, normalmen;
    People p;
    //this statement is most important, and it must locate before any cin or cout calling
    std::ios::sync_with_stdio(false);

    cin>>N>>L>>H;

    for(i=0; i<N; ++i)
    {
        cin>>p.ID>>p.virtue>>p.talent;
        if(p.virtue>=H && p.talent>=H)
            sages.push_back(p);
        else if(p.virtue>=H && p.talent>=L)
            noblemen.push_back(p);
        else if(p.talent>=L && p.virtue>=L && p.talent<H && p.virtue<H && p.virtue>=p.talent)
            foolmen.push_back(p);
        else if(p.talent>=L && p.virtue>=L)
            normalmen.push_back(p);
    }

    std::sort(sages.begin(), sages.end(), SortFunPeople);
    std::sort(noblemen.begin(), noblemen.end(), SortFunPeople);
    std::sort(foolmen.begin(), foolmen.end(), SortFunPeople);
    std::sort(normalmen.begin(), normalmen.end(), SortFunPeople);

    cout<<sages.size()+noblemen.size()+foolmen.size()+normalmen.size()<<endl;
    for(i=0; i<sages.size(); ++i)
        cout<<sages[i].ID<<" "<<sages[i].virtue<<" "<<sages[i].talent<<"\n";
    for(i=0; i<noblemen.size(); ++i)
        cout<<noblemen[i].ID<<" "<<noblemen[i].virtue<<" "<<noblemen[i].talent<<"\n";
    for(i=0; i<foolmen.size(); ++i)
        cout<<foolmen[i].ID<<" "<<foolmen[i].virtue<<" "<<foolmen[i].talent<<"\n";
    for(i=0; i<normalmen.size(); ++i)
        cout<<normalmen[i].ID<<" "<<normalmen[i].virtue<<" "<<normalmen[i].talent<<"\n";
//    system("pause");
    return 0;
}
