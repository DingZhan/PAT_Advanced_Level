#include <iostream>
#include <sstream>

using namespace std;

/*
-1000000 9
*/
int main()
{
    int a, b, sum;
    std::ostringstream oss;
    std::string str;
    cin>>a>>b;
    sum=a+b;
    oss<<sum;
    str = oss.str();
    int len = str.size(), lastInsertPos=0;
    if(sum<0)
    {
        --len;
        str.erase(str.begin());
    }
    while(len>3)
    {
        if(lastInsertPos==0)
            lastInsertPos = (len-1)%3+1;
        else
            lastInsertPos+=4;
        str.insert(str.begin()+lastInsertPos, ',');
        len-=3;
    }
    if(sum<0)
        str.insert(str.begin(), '-');
    cout<<str<<endl;
    return 0;
}
