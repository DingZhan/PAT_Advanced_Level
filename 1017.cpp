#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
*/
struct SevericeData
{
    int arriveTime;
    int costTime;
};
bool SortFunc(const SevericeData& a,const SevericeData& b)
{
    return a.arriveTime<b.arriveTime;
}

#define MAX_N 10001
#define MAX_K 101

int main()
{
    int i, j, N, K, h, m, s, m2, totalWaitTime=0, startTime, endTime, curTime, validService=0;
    SevericeData datas[MAX_N];
    int windowTaken[MAX_K]={0};
    char c;
    cin>>N>>K;
    for(i=0; i<N; ++i)
    {
        cin>>h>>c>>m>>c>>s>>m2;
        datas[i].arriveTime = h*60*60+m*60+s;
        datas[i].costTime = m2*60;
    }
    startTime = 8*60*60;
    endTime = 17*60*60;

    std::sort(datas, datas+N, SortFunc);
    /*
    std::cout<<"-------------------------------"<<endl;
    std::sort(datas, datas+N, SortFunc);
    for(i=0; i<N; ++i)
        std::cout<<datas[i].arriveTime<<" "<<datas[i].costTime<<endl;
    std::cout<<"-------------------------------"<<endl;
    */

    i = 0;
    curTime = startTime;
    while(true)
    {
        //find a empty window
        for(j=0; j<K; ++j)
        {
            if(windowTaken[j]==0)
            {
                if(datas[i].arriveTime>curTime||datas[i].arriveTime>endTime)
                    break;
                totalWaitTime+=curTime-datas[i].arriveTime;
                windowTaken[j] = datas[i].costTime;
                ++i;
                ++validService;
                if(i==N)
                    break;
            }
        }

        int minWindowTime = 100000000;
        for(j=0; j<K; ++j)
        {
            if(windowTaken[j]>0 && minWindowTime>windowTaken[j])
                minWindowTime = windowTaken[j];
        }
        if(i<N && datas[i].arriveTime>curTime && datas[i].arriveTime<curTime+minWindowTime)
            minWindowTime = datas[i].arriveTime-curTime;
        for(j=0; j<K; ++j)
        {
            if(windowTaken[j]>0)
                windowTaken[j]-=minWindowTime;
        }
        curTime+=minWindowTime;
        if(i==N||datas[i].arriveTime>endTime)
            break;
    }
    cout<<std::fixed<<setprecision(1)<<totalWaitTime/(validService+0.0)/60<<endl;
    return 0;
}
