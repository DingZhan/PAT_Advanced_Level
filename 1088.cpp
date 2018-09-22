#include <iostream>
#include <sstream>

using namespace std;

#define MAX_N 100001
/*
Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
long long gcd(long long a, long long b)
{
    long long c;
    c = a%b;
    while(c)
    {
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}
std::string AssemblyData(long long a, long long b)
{
    std::ostringstream oss;
    long long i;
    bool bNeg=false;
    if(a<0)
    {
        bNeg = true;
        a = -a;
    }
    if(a!=0)
    {
        i=gcd(a, b);
        a/=i;
        b/=i;
    }
    if(a!=0)
    {
        if(bNeg)
            oss<<"(-";
        if(a/b)
            oss<<a/b;
        if(b!=1)
        {
            if(a/b)
                oss<<" ";
            oss<<a%b<<"/"<<b;
        }
        if(bNeg)
            oss<<")";
    }
    else
        oss<<"0";
    return oss.str();
}
int main()
{
    long long a1, b1, a2, b2, a, b;
    std::string str1, str2, str;
    char c;
    cin>>a1>>c>>b1>>a2>>c>>b2;

    str1 = AssemblyData(a1, b1);
    str2 = AssemblyData(a2, b2);
    a = a1*b2+a2*b1;
    b = b1*b2;
    str = AssemblyData(a, b);
    cout<<str1<<" + "<<str2<<" = "<<str<<endl;

    a = a1*b2-a2*b1;
    b = b1*b2;
    str = AssemblyData(a, b);
    cout<<str1<<" - "<<str2<<" = "<<str<<endl;

    a = a1*a2;
    b = b1*b2;
    str = AssemblyData(a, b);
    cout<<str1<<" * "<<str2<<" = "<<str<<endl;

    if(a2==0)
        cout<<str1<<" / "<<str2<<" = Inf"<<endl;
    else
    {
        a = a1*b2;
        b = a2*b1;
        if(b<0)
        {
            b = -b;
            a = -a;
        }
        str = AssemblyData(a, b);
        cout<<str1<<" / "<<str2<<" = "<<str<<endl;
    }
    return 0;
}
