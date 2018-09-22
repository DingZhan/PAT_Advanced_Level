#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

/*
Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0
*/
#define MAX_S 101
#define MAX_N 501
#define MAX_INT 1000000000

class Graph
{
public:
    Graph(int numVer, int numEdge, int bikeLimit)
    {
        m_numVer = numVer;
        m_numEdge = numEdge;
        m_BikeLimit = bikeLimit;

        int i, j;
        for(i=0; i<m_numVer; ++i)
        {
            std::ostringstream oss;
            oss<<i<<" ";
            m_VerInfor[i]=oss.str();
            for(j=0; j<m_numVer; ++j)
                m_EdgeLens[i][j]=MAX_INT;
        }
        m_BikeCounts[0] = 0;
    }
    void AddEdge(int v1, int v2, int len)
    {
        m_EdgeLens[v1][v2] = len;
        m_EdgeLens[v2][v1] = len;
    }
    void SetBikeNumber(int id, int bikeNum)
    {
        m_BikeCounts[id] = bikeNum - m_BikeLimit/2;
    }
    void ShortestPathWithMinCenterBikes(int desVer)
    {
        bool bTakens[MAX_N];
        string paths[MAX_N];
        int diss[MAX_N];
        int totalBikes[MAX_N], truckBikes[MAX_N], centerBikes[MAX_N];
        std::ostringstream oss;
        int i, id, srcVerID =  0;

        for(i=0; i<m_numVer; ++i)
        {
            diss[i] = m_EdgeLens[srcVerID][i];
            bTakens[i]=false;
            totalBikes[i] = 0;
            truckBikes[i] = 0;
            centerBikes[i] = 0;
            if(m_EdgeLens[srcVerID][i]<MAX_INT)
            {
                paths[i]=m_VerInfor[srcVerID]+m_VerInfor[i];
                totalBikes[i] = m_BikeCounts[i];

                if(truckBikes[i]+m_BikeCounts[i]>=0)
                    truckBikes[i]=(truckBikes[i]+m_BikeCounts[i]);
                else
                {
                    centerBikes[i] += - (truckBikes[i]+m_BikeCounts[i]);
                    truckBikes[i] = 0;
                }
            }
        }
        diss[srcVerID] = 0;
        bTakens[srcVerID] = true;

        while(true)
        {
            int minLen=MAX_INT;
            id = -1;
            //find next nearest neighbor
            for(i=0; i<m_numVer; ++i)
            {
                if(!bTakens[i] && minLen>diss[i])
                {
                    minLen = diss[i];
                    id = i;
                }
            }
            if(id==-1)
                break;
            bTakens[id]=true;
 //           cout<<"Path: "<<paths[id]<<" Len:"<<diss[id]<<endl;
            if(id==desVer)
            {
                OutputResult(paths[id]);
                return;
            }
            //path[id]=path[id];
            for(i=0; i<m_numVer; ++i)
            {
                if(!bTakens[i] && diss[i]>diss[id]+m_EdgeLens[i][id])
                {
                    diss[i] = diss[id]+m_EdgeLens[i][id];
                    paths[i] = paths[id]+m_VerInfor[i];
                    totalBikes[i] = totalBikes[id]+m_BikeCounts[i];
                }
                else if(!bTakens[i] && diss[i]==diss[id]+m_EdgeLens[i][id])
                {
                    int centerBikes1, truckBikes1,centerBikes2, truckBikes2;
                    NeedCenterBikes(paths[i], truckBikes1, centerBikes1);
                    NeedCenterBikes(paths[id]+m_VerInfor[i], truckBikes2, centerBikes2);
                    if(centerBikes2<centerBikes1)
                    {
                        diss[i] = diss[id]+m_EdgeLens[i][id];
                        paths[i] = paths[id]+m_VerInfor[i];
                        totalBikes[i]=totalBikes[id]+m_BikeCounts[i];
                    }
                    else if(centerBikes2==centerBikes1 && truckBikes2<truckBikes1)
                    {
                        diss[i] = diss[id]+m_EdgeLens[i][id];
                        paths[i] = paths[id]+m_VerInfor[i];
                        totalBikes[i]=totalBikes[id]+m_BikeCounts[i];
                    }
                }
                /*
                else if(!bTakens[i] && diss[i]==diss[id]+m_EdgeLens[i][id] &&
                        centerBikes[i]>centerBikes[id]+m_BikeCounts[i])
                {
                    diss[i] = diss[id]+m_EdgeLens[i][id];
                    paths[i] = paths[id]+m_VerInfor[i];
                    totalBikes[i]=totalBikes[id]+m_BikeCounts[i];
                }*/
                /*
                else if(!bTakens[i] && diss[i]==diss[id]+m_EdgeLens[i][id] &&
                        totalBikes[i]<totalBikes[id]+m_BikeCounts[i])
                {
                    diss[i] = diss[id]+m_EdgeLens[i][id];
                    paths[i] = paths[id]+m_VerInfor[i];
                    totalBikes[i]=totalBikes[id]+m_BikeCounts[i];
                }*/
            }

        }
    }

    void NeedCenterBikes(const std::string& path, int& truckBikes, int& centerBikes)
    {
        std::istringstream iss;
        std::vector<int> pathA;
        int idx;
        iss.str(path);
        while(true)
        {
            iss>>idx;
            if(iss.fail())
                break;
            pathA.push_back(idx);
        }
        NeedCenterBikes(pathA, truckBikes, centerBikes);
    }
    void NeedCenterBikes(const std::vector<int>& path, int& truckBikes, int& centerBikes)
    {
        int i;
        truckBikes=0;
        centerBikes=0;
        for(i=1; i<path.size(); ++i)
        {
            if(truckBikes+m_BikeCounts[path[i]]>=0)
                truckBikes=(truckBikes+m_BikeCounts[path[i]]);
            else
            {
                centerBikes += - (truckBikes+m_BikeCounts[path[i]]);
                truckBikes = 0;
            }
        }
    }
    void OutputResult(const std::string& path)
    {
        std::istringstream iss;
        std::vector<int> pathA;
        int i;
        iss.str(path);
        while(true)
        {
            iss>>i;
            if(iss.fail())
                break;
            pathA.push_back(i);
        }

        int centerBikes, truckBikes;
        NeedCenterBikes(pathA, truckBikes, centerBikes);
        cout<<centerBikes<<" ";
        for(i=0; i<pathA.size(); ++i)
        {
            if(i!=0)
                cout<<"->";
            cout<<pathA[i];
        }
        cout<<" ";
        cout<<truckBikes<<endl;
    }
private:
  int m_EdgeLens[MAX_N][MAX_N];
  string m_VerInfor[MAX_N];
  int m_BikeCounts[MAX_N];
  int m_numEdge;
  int m_numVer;
  int m_BikeLimit;
};

int main()
{
    int i, bikeTotalNum, stationNum, desStation, edgeNum, bikeNum, id1, id2, len;

    cin>>bikeTotalNum>>stationNum>>desStation>>edgeNum;
    Graph g(stationNum+1, edgeNum, bikeTotalNum);
    for(i=1; i<=stationNum; ++i)
    {
        cin>>bikeNum;
        g.SetBikeNumber(i, bikeNum);
    }
    for(i=0; i<edgeNum; ++i)
    {
        cin>>id1>>id2>>len;
        g.AddEdge(id1, id2, len);
    }
    g.ShortestPathWithMinCenterBikes(desStation);

    return 0;
}
