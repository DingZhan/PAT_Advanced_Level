#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
/*
Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
*/
#define MAX_N 1000000
#define MAX_M 2001
#define MAX_K 101
struct Student
{
    bool bValid;
    char cGrade;
    char mGrade;
    char eGrade;
    char aGrade;
    Student()
    {
        bValid = false;
    }
};

int main()
{
    int i, id, N, M, c, m, e, a, r, t;
    Student *students;
    int cRanks[MAX_K]={0}, mRanks[MAX_K]={0}, eRanks[MAX_K]={0}, aRanks[MAX_K]={0}, ids[MAX_M]={0};

    students = new Student[MAX_N];
    cin>>N>>M;

    for(i=0; i<N; ++i)
    {
        cin>>id>>c>>m>>e;
        students[id].cGrade = c;
        students[id].mGrade = m;
        students[id].eGrade = e;
        a = (c+m+e)/3;
        students[id].aGrade = a;
        students[id].bValid = true;
        ++cRanks[c];
        ++mRanks[m];
        ++eRanks[e];
        ++aRanks[a];
    }
    for(i=0; i<M; ++i)
        cin>>ids[i];
    r = 1;
    for(i=100; i>=0; i--)
    {
        if(cRanks[i])
        {
            t = cRanks[i];
            cRanks[i]=r;
            r+=t;
        }
    }
    r = 1;
    for(i=100; i>=0; i--)
    {
        if(mRanks[i])
        {
            t = mRanks[i];
            mRanks[i]=r;
            r+=t;
        }
    }
    r = 1;
    for(i=100; i>=0; i--)
    {
        if(eRanks[i])
        {
            t = eRanks[i];
            eRanks[i]=r;
            r+=t;
        }
    }
    r = 1;
    for(i=100; i>=0; i--)
    {
        if(aRanks[i])
        {
            t = aRanks[i];
            aRanks[i]=r;
            r+=t;
        }
    }
    for(i=0; i<M; ++i)
    {
        id = ids[i];
        if(!students[id].bValid)
        {
            cout<<"N/A"<<endl;
            continue;
        }
        c = cRanks[students[id].cGrade];
        m = mRanks[students[id].mGrade];
        e = eRanks[students[id].eGrade];
        a = aRanks[students[id].aGrade];
        if(a<=c && a<=m && a<=e)
            cout<<a<<" A"<<endl;
        else if(c<=m && c<=e)
            cout<<c<<" C"<<endl;
        else if(m<=e)
            cout<<m<<" M"<<endl;
        else
            cout<<e<<" E"<<endl;
    }
    delete []students;
	return 0;
}
