#include <iostream>
#include <string>
#include <list>

using namespace std;

/*
Sample Input 1:
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
Sample Output 1:
Mike CS991301
Mary EE990830
Joe Math990112
Sample Input 2:
2
Jean AA980920 60
Ann CS01 80
90 95
Sample Output 2:
NONE
*/
#define MAX_N 101
#define MAX_L 11
struct Student
{
    char name[MAX_L];
    char ID[MAX_L];
    short grade;
};
int main()
{
    std::list<Student> students[MAX_N];
    std::list<Student>::iterator it;
    int n, i, grade1, grade2;
    Student s;
    bool bSucc=false;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>s.name>>s.ID>>s.grade;
        students[s.grade].push_back(s);
    }
    cin>>grade1>>grade2;
    for(i=grade2; i>=grade1; --i)
    {
        for(it=students[i].begin(); it!=students[i].end(); ++it)
        {
            cout<<it->name<<" "<<it->ID<<endl;
            bSucc = true;
        }
    }
    if(!bSucc)
        cout<<"NONE"<<endl;
    return 0;
}
