#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 101
#define MAX_K 301
#define MAX_TESTEES  30002

typedef struct _Testee
{
    char ID[14];
    int score;
    short localID;
}Testee;

int SortByScore(const void *a, const void *b)
{
    Testee* aa = (Testee*)a;
    Testee* bb = (Testee*)b;
    if(aa->score<bb->score)
        return 1;
    else if(aa->score>bb->score)
        return -1;
    return strcmp(aa->ID, bb->ID);
}

Testee testees[MAX_TESTEES];
int numTestees=0;

int main()
{
    int i, j, N, K, lastRank=0, lastScore=-1, locationID;
    int localRanks[MAX_N] = {0}, localRankNum[MAX_N]={0},localLastScores[MAX_N];
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &K);
        for(j=0; j<K; ++j)
        {
            scanf("%s%d", testees[numTestees].ID, &(testees[numTestees].score));
            testees[numTestees].localID = i+1;
            ++numTestees;
        }
    }
    qsort(testees, numTestees, sizeof(Testee), SortByScore);
    printf("%d\n", numTestees);
    for(i=0; i<MAX_N; ++i)
        localLastScores[i] = -1;
    for(i=0; i<numTestees; ++i)
    {
        locationID = testees[i].localID;
        printf("%s ", testees[i].ID);
        if(testees[i].score!=lastScore)
            lastRank = i+1;
        lastScore = testees[i].score;
        printf("%d %d ", lastRank, testees[i].localID);
        if(testees[i].score!=localLastScores[locationID])
            localRanks[locationID] = localRankNum[locationID];
        localLastScores[locationID] = testees[i].score;
        ++localRankNum[locationID];
        printf("%d\n", localRanks[locationID]+1);
    }
}
