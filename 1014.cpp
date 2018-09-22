#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;
/*
Sample Input
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output
08:07
08:06
08:10
17:00
Sorry
*/
#define MAX_K 1001

struct CustomerData
{
    int ID;
    int time;
};
int main()
{
    int i, j, N, M, K, Q, a, h, m, limitTime;
    int times[MAX_K], curTime = 0;
    int queryCustomers[MAX_K], results[MAX_K];
    std::vector<std::deque<CustomerData> > NMArray;
    CustomerData cd;

    cin>>N>>M>>K>>Q;
    NMArray.resize(N);
    for(i=0; i<K; ++i)
    {
        cin>>times[i];
        results[i]=-1;
    }
    for(i=0; i<Q; ++i)
        cin>>queryCustomers[i];

    limitTime = (17-8)*60;

    a = std::min(N*M, K);
    //align lines firstly
    for(i=0, j=0; i<a; ++i)
    {
        cd.time = times[i];
        cd.ID = i;
        NMArray[j].push_back(cd);
        j=(j+1)%N;
    }
    while(true)
    {
        bool bSucc=false;
        ++curTime;
//        if(curTime>limitTime)
//            break;
        for(i=0; i<N; ++i)
        {
            if(NMArray[i].empty())
                continue;
            if(NMArray[i][0].time>0)
                bSucc=true;
            if(--NMArray[i][0].time==0)
            {
                results[NMArray[i][0].ID] = curTime;
                if(curTime<limitTime)
                {
                    NMArray[i].pop_front();
                    if(a<K)
                    {
                       cd.time = times[a];
                       cd.ID = a;
                       NMArray[i].push_back(cd);
                       ++a;
                    }
                }
            }
        }
        if(!bSucc)
            break;
    }


    for(i=0; i<Q; ++i)
    {
        j = queryCustomers[i]-1;
        if(results[j]==-1)
            cout<<"Sorry"<<endl;
        else
        {
            h = results[j]/60;
            m = results[j]%60;
            cout<<std::setfill('0')<<std::setw(2)<<8+h<<":"<<std::setfill('0')<<std::setw(2)<<m<<endl;
        }
    }
	return 0;
}
