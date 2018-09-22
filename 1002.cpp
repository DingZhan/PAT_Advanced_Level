#include <iostream>
#include <cstring>
#include <iomanip>

/*
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*/

#define N 1001
int main()
{
    int K, i, n;
    float exps[N]={0}, exp;
    bool bFirst=true;
    std::cin>>K;
    for(i=0; i<K; ++i)
    {
        std::cin>>n;
        std::cin>>exp;
        exps[n]+=exp;
    }
    std::cin>>K;
    for(i=0; i<K; ++i)
    {
        std::cin>>n;
        std::cin>>exp;
        exps[n]+=exp;
    }
    n = 0;
    for(i=0; i<N; ++i)
    {
        if(exps[i]!=0)
            ++n;
    }
    std::cout<<n;
    if(n!=0)
    {
        std::cout<<" ";
        for(i=N-1; i>=0; --i)
        {
            if(exps[i]!=0)
            {
                if(bFirst)
                    bFirst=false;
                else
                    std::cout<<" ";
                std::cout<<i<<" "<<std::fixed<<std::setprecision(1)<<exps[i];
            }
        }
    }
    std::cout<<std::endl;

    return 0;
}
