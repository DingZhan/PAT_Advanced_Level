#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX_V 202

bool matrix[MAX_V][MAX_V];
int main()
{
    int nv, ne, i, j, k, v1, v2, M, K;
    int verIDs[MAX_V];
    bool bTakens[MAX_V] ={false};
    cin>>nv>>ne;
    for(i=0; i<ne; ++i)
    {
        cin>>v1>>v2;
        matrix[v1][v2] =  true;
        matrix[v2][v1] = true;
    }

    cin>>M;
    for(i=0; i<M; ++i)
    {
        cin>>K;
        bool bTakens[MAX_V] = {false};
        for(j=0; j<K; ++j)
        {
            cin>>verIDs[j];
            bTakens[verIDs[j]] = true;
        }
        //clique tag
        bool bSucc=true;
        for(j=0; j<K; ++j)
        {
            for(k=j+1; k<K; ++k)
            {
                //if one vertex is not neighbor with another vertex in verIDs group
                //then it's not Clique
                if(!matrix[verIDs[j]][verIDs[k]])
                {
                    bSucc=false;
                    break;
                }
            }
            if(!bSucc)
                break;
        }
        if(bSucc)
        {
            //try to extend(test) one more data which not inside verIDs
            for(j=1; j<=nv; ++j)
            {
                //if it's in the verIDs, skip it
                if(bTakens[j])
                    continue;
                bool bOneMoreFound = true;
                //using verIDs[0] as row, it's enough
                if(matrix[verIDs[0]][j])
                {
                    for(k=0; k<K; ++k)
                    {
                        if(!matrix[verIDs[k]][j])
                        {
                            bOneMoreFound = false;
                            break;
                        }
                    }
                }
                else
                    continue;
                if(bOneMoreFound)
                    break;
            }
            if(j<=nv)
                cout<<"Not Maximal"<<endl;
            else
                cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"Not a Clique"<<endl;
        }
    }
}
