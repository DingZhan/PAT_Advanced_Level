#include <iostream>

int main()
{
    int buckets[10]={0};
    std::string rawStr, doubleStr;
    int i, add=0, sum;
    std::cin>>rawStr;
    for(i=(int)rawStr.size()-1; i>=0; --i)
    {
        ++buckets[rawStr[i]-'0'];
        sum = (rawStr[i]-'0')*2+add;
        doubleStr+= '0'+(sum%10);
        add  = sum/10;
    }
    if(add!=0)
        doubleStr+= '0'+add;
    for(i=0; i<doubleStr.size(); ++i)
    {
        --buckets[doubleStr[i]-'0'];
    }
    for(i=0; i<10; ++i)
    {
        if(buckets[i]!=0)
            break;
    }
    if(i==10)
        std::cout<<"Yes"<<std::endl;
    else
        std::cout<<"No"<<std::endl;
    for(i=(int)doubleStr.size()-1; i>=0; --i)
        std::cout<<doubleStr[i];
}
