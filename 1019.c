#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10002

int main()
{
    int N, b, data[MAX_LEN], len=0, i, j, bSucc=1;
    scanf("%d%d", &N, &b);
    while(N)
    {
        data[len++] = N%b;
        N/=b;
    }
    j = len-1;
    i = 0;
    while(i<j)
    {
        if(data[i]!=data[j])
        {
            bSucc=0;
            break;
        }
        ++i;
        --j;
    }

    if(bSucc)
        printf("Yes\n");
    else
        printf("No\n");
    //len==0 doesn't make sense according to the given N>0
    if(len==0)
        printf("0");
    else
    {
        for(i=len-1; i>=0; --i)
        {
            if(i!=len-1)
                printf(" ");
            printf("%d", data[i]);
        }
    }
    printf("\n");
    return 0;
}
