#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX_N 100002

struct PATScore
{
    char ID[7];
    short score;
    char school[7];
};
struct SchoolScore
{
    char school[7];
    int numStudents;
    double totalWeightScore;
};

bool SortBySchool(const PATScore& a, const PATScore& b)
{
    return strcmp(a.school, b.school)<0;
}
bool SortTWS(const SchoolScore& a, const SchoolScore& b)
{
    if((int)a.totalWeightScore>(int)b.totalWeightScore)
        return true;
    else if((int)a.totalWeightScore<(int)b.totalWeightScore)
        return false;
    if(a.numStudents<b.numStudents)
        return true;
    else if(a.numStudents>b.numStudents)
        return false;
    return strcmp(a.school, b.school)<0;
}


PATScore scores[MAX_N];
SchoolScore schoolScores[MAX_N];

int main()
{
    int i, n, numSchools, numStudents;
    double TWS;
    char c;
    char currentSchool[7];
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>scores[i].ID>>scores[i].score>>scores[i].school;
        std::transform(scores[i].school, scores[i].school+7, scores[i].school, ::tolower);
    }
    std::sort(scores, scores+n, SortBySchool);

    /*
    cout<<">>>>>>>"<<n<<endl;
    for(i=0; i<n; ++i)
        cout<<scores[i].ID<<" "<<scores[i].score<<scores[i].school<<endl;
    cout<<endl;
    */

    numSchools = 0;
    TWS = 0.0;
    strcpy(currentSchool, scores[0].school);
    numStudents = 0;
    for(i=0; i<n; ++i)
    {
        if(strcmp(currentSchool, scores[i].school)==0)
        {
            if(scores[i].ID[0]=='A')
                TWS += scores[i].score;
            else if(scores[i].ID[0]=='B')
                TWS += scores[i].score/1.5;
            else
                TWS += scores[i].score*1.5;
            ++numStudents;
        }
        else
        {
            schoolScores[numSchools].totalWeightScore = TWS;
            strcpy(schoolScores[numSchools].school, currentSchool);
            schoolScores[numSchools].numStudents = numStudents;
            ++numSchools;

            numStudents = 0;
            TWS = 0;
            strcpy(currentSchool, scores[i].school);
            if(scores[i].ID[0]=='A')
                TWS += scores[i].score;
            else if(scores[i].ID[0]=='B')
                TWS += scores[i].score/1.5;
            else
                TWS += scores[i].score*1.5;
            ++numStudents;
        }
    }
    schoolScores[numSchools].totalWeightScore = TWS;
    strcpy(schoolScores[numSchools].school, currentSchool);
    schoolScores[numSchools].numStudents = numStudents;
    ++numSchools;

    std::sort(schoolScores, schoolScores+numSchools, SortTWS);

    std::cout<<numSchools<<endl;
    int rank=1;
    int lastTWS = -1;
    for(i=0; i<numSchools; ++i)
    {
        if((int)schoolScores[i].totalWeightScore==lastTWS)
        {
        }
        else
            rank = i+1;
        cout<<rank<<" "<<schoolScores[i].school<<" "<<(int)schoolScores[i].totalWeightScore<<" "<<
        schoolScores[i].numStudents<<endl;
        lastTWS = (int)schoolScores[i].totalWeightScore;
    }
    return 0;
}
