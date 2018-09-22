#include <iostream>

using namespace std;

/*
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
*/
int main()
{
    int N, i, lockTime=-1, unlockTime=100000, hour, minute,second, time;
    std::string ID, IDUnlock, IDLock;
    char c;
    cin>>N;
    for(i=0; i<N; ++i)
    {
        cin>>ID;
        cin>>hour>>c>>minute>>c>>second;
        time = hour*3600+minute*60+second;
        if(time<unlockTime)
        {
            unlockTime = time;
            IDUnlock = ID;
        }
        cin>>hour>>c>>minute>>c>>second;
        time = hour*3600+minute*60+second;
        if(time>lockTime)
        {
            lockTime = time;
            IDLock = ID;
        }
    }
    cout<<IDUnlock<<" "<<IDLock<<endl;
    return 0;
}
