#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
/*
Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
*/

void FormatString(int N, std::string&A, std::string& A2)
{
    int i, integerA;
    A2.clear();
    //remove extra 0 in the front of A
    for(i=0; i<(int)A.size()-1; ++i)
    {
        if(A[i]=='0' && A[i+1]!='.')
            continue;
        else
        {
            if(i!=0)
                A.erase(A.begin(), A.begin()+i);
            i=0; // for all zero tag
            break;
        }
    }
    //all zero in A, such as 0000
    if(i!=0)
        A="0";
    //calculate integer number
    size_t pos = A.find('.');
    if(pos==std::string::npos)
    {
        integerA = A.length();
        // zero
        if(integerA==1 && A[0]=='0')
            integerA = 0;
        A2 = A;
    }
    else
    {
        if((pos==1 && A[pos-1]=='0')||pos==0)
        {
            integerA = 0;
            ++pos;
            while(pos<A.length() && A[pos]=='0')
            {
                ++pos;
                --integerA;
            }
            A2.assign(A.begin()+pos, A.end());
            // zero
            if(A2.empty())
            {
                A2.push_back('0');
                integerA = 0;
            }
        }
        else
        {
            integerA = pos;
            A2.assign(A.begin(), A.begin()+pos);
            ++pos;
            A2.insert(A2.end(), A.begin()+pos, A.end());
        }
    }

    if((int)A2.size()<N)
    {
        std::string str;
        str.resize(N-A2.size(), '0');
        A2+=str;
    }
    if((int)A2.size()>N)
        A2.erase(A2.end()-(A2.size()-N), A2.end());
    std::ostringstream oss;
    oss<<"0."<<A2<<"*10^"<<integerA;
    A2 = oss.str();
}

int main()
{
    int N;
    std::string A, B, A2, B2;

    /*
    cin>>N>>A;
    FormatString(N, A, A2);
    cout<<A2<<std::endl;
    return 0;
    */

    cin>>N>>A>>B;
    FormatString(N, A, A2);
    FormatString(N, B, B2);
    if(A2==B2)
        cout<<"YES "<<A2<<std::endl;
    else
        cout<<"NO "<<A2<<" "<<B2<<std::endl;
    return 0;
}
