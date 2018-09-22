#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
/*
Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/

bool IsPrime(int v)
{
    if(v==1)
        return false;
    int i, t = sqrt(v);
    for(i=2; i<=t; ++i)
    {
        if((v%i)==0)
            return false;
    }
    return true;
}

int main()
{
    int i, v, D, t, N;
    std::vector<bool> bResults;
    std::vector<int> digits;
    while(true)
    {
        cin>>N;
        if(N<0)
            break;
        cin>>D;
        if(!IsPrime(N))
        {
            bResults.push_back(false);
            continue;
        }
        digits.clear();
        while(N)
        {
            digits.push_back(N%D);
            N/=D;
        }
        t=0;
        v = 1;
        //cout<<"--------"<<endl;
        for(i=(int)digits.size()-1; i>=0; --i)
        {
        //    cout<<digits[i];
            t+=digits[i]*v;
            v*=D;
        }
        //cout<<"--------"<<endl;
        bResults.push_back(IsPrime(t));
    }
    for(i=0; i<(int)bResults.size(); ++i)
    {
        if(bResults[i])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}
