
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 100001
struct Student
{
    char ID[7];
    char name[9];
    short grade;
};
bool SortByID(const Student& a, const Student& b)
{
    return strcmp(a.ID, b.ID)<0;
}
bool SortByName(const Student& a, const Student& b)
{
    int ret = strcmp(a.name, b.name);
    if(ret<0) return true;
    else if(ret>0) return false;
    return strcmp(a.ID, b.ID)<0;
}
bool SortByGrade(const Student& a, const Student& b)
{
    int ret = a.grade-b.grade;
    if(ret<0) return true;
    else if(ret>0) return false;
    return strcmp(a.ID, b.ID)<0;
}
Student students[MAX_N];
int main()
{
    std::ios::sync_with_stdio(false);
    int N, C, i;
    cin>>N>>C;
    for(i=0; i<N; ++i)
    {
        cin>>students[i].ID>>students[i].name>>students[i].grade;
    }
    if(C==1)
        std::sort(students, students+N, SortByID);
    else if(C==2)
        std::sort(students, students+N, SortByName);
    else if(C==3)
        std::sort(students, students+N, SortByGrade);
    for(i=0; i<N; ++i)
        cout<<students[i].ID<<" "<<students[i].name<<" "<<students[i].grade<<"\n";
    return 0;  // 程序结束，返回操作系统
}
