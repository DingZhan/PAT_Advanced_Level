#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;
/*
Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
*/

int main()
{
    size_t i, N, M, K, j, id1, id2;
    unsigned long d;
    double ratio;
    std::set<unsigned long> dataSet;
    std::vector<std::set<unsigned long> > dataSets;

    std::ios::sync_with_stdio(false);
    cin>>N;
    for(i=0; i<N; ++i)
    {
        cin>>M;
        dataSet.clear();
        for(j=0; j<M; ++j)
        {
            cin>>d;
            dataSet.insert(d);
        }
        dataSets.push_back(dataSet);
    }
    cin>>K;
    for(i=0; i<K; ++i)
    {
        cin>>id1>>id2;
        id1-=1;
        id2-=1;
        std::vector<unsigned long> commonIDs, unionIDs;
        std::set_intersection(dataSets[id1].begin(), dataSets[id1].end(),
                              dataSets[id2].begin(),dataSets[id2].end(), std::back_inserter(commonIDs));
        std::set_union(dataSets[id1].begin(), dataSets[id1].end(),
                              dataSets[id2].begin(),dataSets[id2].end(), std::back_inserter(unionIDs));
        ratio = commonIDs.size()*100.0/unionIDs.size();
        //FYI: you can't use std::ios::fixed
        cout<<std::fixed<<std::setprecision(1)<<ratio<<"%\n";
    }

//    system("pause");
    return 0;
}
