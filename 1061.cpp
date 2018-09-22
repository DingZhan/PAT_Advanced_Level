#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/*
Sample Input:
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
Sample Output:
THU 14:04
*/


int main()
{
    const char* weekdayStr[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int weekday=-1, hour, minute;
    size_t i;

    std::string A, B, C, D;
    std::getline(std::cin, A);
    std::getline(std::cin, B);
    std::getline(std::cin, C);
    std::getline(std::cin, D);
    for(i=0; i<A.size() && i<B.size(); ++i)
    {
        if(A[i]==B[i])
        {
            if(weekday==-1)
            {
                if(A[i]>='A' && A[i]<='G')
                    weekday = A[i]-'A';
                else
                    continue;
            }
            else
            {
                if(A[i]>='A' && A[i]<='N')
                    hour = A[i]-'A'+10;
                else if(A[i]>='0' && A[i]<='9')
                    hour = A[i]-'0';
                else
                    continue;
                break;
            }
        }
    }
    for(i=0; i<C.size() && i<D.size(); ++i)
    {
        if(C[i]==D[i] && (C[i]>='A' && C[i]<='Z' || C[i]>='a' && C[i]<='z'))
        {
            minute = i;
            break;
        }
    }
    cout<<weekdayStr[weekday]<<" "<<\
        std::setw(2)<<std::setfill('0')<<hour<<":"<<\
        std::setw(2)<<std::setfill('0')<<minute<<std::endl;
    return 0;
}
