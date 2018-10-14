#include <stdio.h>

#define MAX_N 300

int IsPalindromic(short data[MAX_N], short dataLen)
{
    int i, j;
    i = 0;
    j = dataLen-1;
    while(i<j)
    {
        if(data[i]!=data[j])
            break;
        ++i;
        --j;
    }
    if(i>=j)
        return 1;
    else
        return 0;
}

int main()
{
    long long N;
    short sum[MAX_N], sumLen, data[MAX_N], dataLen, add;
    int K, i, j, steps;
    scanf("%lld%d", &N, &K);
    dataLen = 0;
    while(N)
    {
        data[dataLen++] = N%10;
        N/=10;
    }
    steps = K;
    for(i=0; i<K; ++i)
    {
        if(IsPalindromic(data, dataLen))
        {
            steps = i;
            break;
        }
        for(j=0, add=0, sumLen=0; j<dataLen; ++j)
        {
            add = add + data[j] + data[dataLen-j-1];
            sum[sumLen++] = add%10;
            add/=10;
        }
        if(add)
            sum[sumLen++] = add%10;
        memcpy(data, sum, sizeof(short)*sumLen);
        dataLen = sumLen;
    }
    for(i=dataLen-1; i>=0; --i)
        printf("%d", data[i]);
    printf("\n%d\n", steps);
}
