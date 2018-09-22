#include <iostream>

using namespace std;

//3 2 3 1
int main()
{
    int N, i, sum=0, curFloor=0, nextFloor;
    cin>>N;
    for(i=0; i<N; ++i)
    {
        cin>>nextFloor;
        if(nextFloor>curFloor)
            sum+=(nextFloor-curFloor)*6+5;
        else if(nextFloor<curFloor)
            sum+=(curFloor-nextFloor)*4+5;
        else
            sum+=5;
        curFloor = nextFloor;
    }
    cout<<sum<<endl;
    return 0;
}
