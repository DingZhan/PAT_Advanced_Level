#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
/*
Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false
*/
#include <sstream>
//violent testing API
bool Test()
{
    int  j, AA, BB, CC;
    int sum, step=0;
    std::string A, B, C, D;
    bool bNegaA=false, bNegaB=false, bNegaC=false, bNegaD=false, bALargeB;


    AA = rand()%100000;
    BB = rand()%100000;
    AA = ((rand()%2)?-1:1)*AA;
    BB = ((rand()%2)?-1:1)*BB;
    CC = rand()%100000;
    CC = ((rand()%2)?-1:1)*CC;
    /*
    AA = 41;
    BB = 18467;
*/
    std::ostringstream oss;
    oss.str("");
    oss<<AA;
    A = oss.str();
    oss.str("");
    oss<<BB;
    B = oss.str();
    oss.str("");
    oss<<CC;
    C = oss.str();

    bNegaA = (A[0]=='-');
    bNegaB = (B[0]=='-');
    bNegaC = (C[0]=='-');
    if(bNegaA)
        A.erase(A.begin());
    if(bNegaB)
        B.erase(B.begin());
    if(bNegaC)
        C.erase(C.begin());
    while(A.size() && A[0]=='0')
        A.erase(A.begin());
    while(B.size() && B[0]=='0')
        B.erase(B.begin());
    while(C.size() && C[0]=='0')
        C.erase(C.begin());
    if(A.empty())
        bNegaA = false;
    if(B.empty())
        bNegaB = false;
    if(C.empty())
    {
        bNegaC = false;
        C.push_back('0');
    }
    bNegaD=false;

    while(A.size()<B.size())
        A.insert(A.begin(), '0');
    while(B.size()<A.size())
        B.insert(B.begin(), '0');
    bALargeB = A>B;
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());

    //        std::reverse(C.begin(), C.end());
    D="";
    step = 0;
    if(bNegaA==bNegaB)
    {
        for(j=0; j<A.size(); ++j)
        {
            sum = (A[j]-'0')+(B[j]-'0')+step;
            if(sum>=10)
            {
                step=1;
                sum-=10;
            }
            else
                step = 0;
            D.push_back('0'+sum);
        }
        if(step)
            D.push_back('1');
        bNegaD = bNegaA;
    }
    else //A-B or B-A
    {
        std::string S1, S2;
        if(bALargeB)
        {
            S1 = A;
            S2 = B;
        }
        else
        {
            S1 = B;
            S2 = A;
        }
        for(j=0; j<S1.size(); ++j)
        {
            sum = (S1[j]-'0'+0)+step-(S2[j]-'0'+0);
            if(sum<0)
            {
                step = -1;
                sum+=10;
            }
            else
                step = 0;
            D.push_back('0'+sum);
        }
        if((bNegaA && bALargeB) || (!bNegaA && !bALargeB))
            bNegaD=true;
    }
    std::reverse(D.begin(), D.end());
    while(D.size() && D[0]=='0')
        D.erase(D.begin());
    if(bNegaD)
        D="-"+D;
    if(atoi(D.c_str())!=AA+BB)
    {
        cout<<AA<<"+"<<BB<<"!="<<D<<std::endl;
        return false;
    }
    bool bRet = (AA+BB)>CC;
    bool bRet2;
    if(bNegaD==bNegaC)
    {
        if(!bNegaD)
        {
            if(D>C)
                bRet2 = true;
            else
                bRet2 = false;
        }
        else
        {
             if(D>=C)
                bRet2 = false;
            else
                bRet2 = true;
        }
    }
    else
    {
        if(!bNegaD)
            bRet2 = true;
        else
            bRet2 = false;
    }
    if(bRet!=bRet2)
    {
        cout<<AA<<"+"<<BB<<"="<<D<<std::endl;
        cout<<"But compare result is wrong with"<<C<<std::endl;
        return false;
    }
    return true;
}

int main()
{
    /*
    while(true)
    {
        if(Test()==false)
            return 0;
    }*/
    int i, j, T;
    int sum, step=0;
    std::string A, B, C, D;
    bool bNegaA=false, bNegaB=false, bNegaC=false, bNegaD=false, bALargeB;

    cin>>T;
    for(i=0; i<T; ++i)
    {
        cin>>A>>B>>C;
        bNegaA = (A[0]=='-');
        bNegaB = (B[0]=='-');
        bNegaC = (C[0]=='-');
        if(bNegaA)
            A.erase(A.begin());
        if(bNegaB)
            B.erase(B.begin());
        if(bNegaC)
            C.erase(C.begin());
        while(A.size() && A[0]=='0')
            A.erase(A.begin());
        while(B.size() && B[0]=='0')
            B.erase(B.begin());
        while(C.size() && C[0]=='0')
            C.erase(C.begin());
        if(A.empty())
            bNegaA = false;
        if(B.empty())
            bNegaB = false;
        if(C.empty())
        {
            bNegaC = false;
            C.push_back('0');
        }
        bNegaD=false;

        while(A.size()<B.size())
            A.insert(A.begin(), '0');
        while(B.size()<A.size())
            B.insert(B.begin(), '0');
        bALargeB = A>B;
        std::reverse(A.begin(), A.end());
        std::reverse(B.begin(), B.end());

//        std::reverse(C.begin(), C.end());
        D="";
        step = 0;
        if(bNegaA==bNegaB)
        {
            for(j=0; j<A.size(); ++j)
            {
                sum = (A[j]-'0')+(B[j]-'0')+step;
                if(sum>=10)
                {
                    step=1;
                    sum-=10;
                }
                else
                    step = 0;
                D.push_back('0'+sum);
            }
            if(step)
                D.push_back('1');
            bNegaD = bNegaA;
        }
        else //A-B or B-A
        {
            std::string S1, S2;
            if(bALargeB)
            {
                S1 = A;
                S2 = B;
            }
            else
            {
                S1 = B;
                S2 = A;
            }
            for(j=0; j<S1.size(); ++j)
            {
                sum = (S1[j]-'0'+0)+step-(S2[j]-'0'+0);
                if(sum<0)
                {
                    step = -1;
                    sum+=10;
                }
                else
                    step = 0;
                D.push_back('0'+sum);
            }
            if((bNegaA && bALargeB) || (!bNegaA && !bALargeB))
                bNegaD=true;
        }
        std::reverse(D.begin(), D.end());
        while(D.size() && D[0]=='0')
            D.erase(D.begin());
            /*
        if(bNegaD)
            cout<<"-";
        cout<<D<<endl;
        */
        while(C.size()<D.size())
            C.insert(C.begin(), '0');
        while(D.size()<C.size())
            D.insert(D.begin(), '0');
        if(bNegaD==bNegaC)
        {
            if(!bNegaD)
            {
                if(D>C)
                    cout<<"Case #"<<i+1<<": true";
                else
                    cout<<"Case #"<<i+1<<": false";
            }
            else
            {
                 if(D>=C)
                    cout<<"Case #"<<i+1<<": false";
                else
                    cout<<"Case #"<<i+1<<": true";
            }
        }
        else
        {
            if(!bNegaD)
                cout<<"Case #"<<i+1<<": true";
            else
                cout<<"Case #"<<i+1<<": false";
        }
        cout<<endl;
    }

    return 0;
}
