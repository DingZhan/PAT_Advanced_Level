#include <stdio.h>
#include <string.h>

#define MAX_N 22

int main()
{
    int buckets[10] = {0}, i, rawLen, doubleLen=0, sum, add=0;
    char rawData[MAX_N], doubleData[MAX_N];
    scanf("%s", rawData);
    rawLen = strlen(rawData);
    for(i=rawLen-1; i>=0; --i)
    {
        ++buckets[rawData[i]-'0'];
        sum = (rawData[i]-'0')*2+add;
        doubleData[doubleLen]='0'+sum%10;
        add = sum/10;
        ++doubleLen;
    }
    if(add)
        doubleData[doubleLen++] = '0'+add;
    doubleData[doubleLen] = '\0';

    for(i=0; i<doubleLen; ++i)
        --buckets[doubleData[i]-'0'];
    for(i=0; i<10; ++i)
    {
        if(buckets[i]!=0)
            break;
    }
    if(i!=10)
        printf("No\n");
    else
        printf("Yes\n");
    for(i=doubleLen-1; i>=0; --i)
        printf("%c", doubleData[i]);
}
