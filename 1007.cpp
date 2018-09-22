#include <iostream>
using namespace std;
/*

*/
#define MAX_K 10001

int main()
{
    int i, j, k, maxSum=0, bPos=0;
    int data[MAX_K], maxSums[MAX_K], ii[MAX_K], jj[MAX_K];
    cin>> k;
    for(i=0; i<k; ++i)
    {
        maxSums[i]=-1;
        cin>>data[i];
        if(data[i]>=0)
            bPos = 1;
        if(i>0 && maxSums[i-1]>= 0 && data[i]+maxSums[i-1]>0)
        {
            maxSums[i]= maxSums[i-1]+data[i];
            ii[i]=ii[i-1];
            jj[i] = i;
        }
        else if(data[i]>=0)
        {
            maxSums[i] = data[i];
            ii[i] = i;
            jj[i] = i;
        }
    }
    maxSum = -1;
    for(i=0; i<k; ++i)
    {
        if(maxSums[i]>maxSum)
        {
            maxSum = maxSums[i];
            j = i;
        }
    }
    if(!bPos)
        cout<<0<<" "<<data[0]<<" "<<data[k-1];
    else
        cout<<maxSum<<" "<<data[ii[j]]<<" "<<data[jj[j]];
    return 0;
}
