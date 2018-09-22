#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;
/*
Sample Input:
12345
Sample Output:
one five
*/
int main()
{
    string N;
    vector<string> results;
    int i, sum=0;
    cin>>N;
    for(i=0; i<N.size(); ++i)
        sum+=N[i]-'0';
    while(sum)
    {
        switch(sum%10)
        {
        case 0:
            results.push_back("zero");
            break;
        case 1:
            results.push_back("one");
            break;
        case 2:
            results.push_back("two");
            break;
        case 3:
            results.push_back("three");
            break;
        case 4:
            results.push_back("four");
            break;
        case 5:
            results.push_back("five");
            break;
        case 6:
            results.push_back("six");
            break;
        case 7:
            results.push_back("seven");
            break;
        case 8:
            results.push_back("eight");
            break;
        case 9:
            results.push_back("nine");
            break;
        default:
            break;
        }
        sum = sum/10;
    }
    if(results.empty())
        results.push_back("zero");
    for(i=(int)results.size()-1; i>=0; --i)
    {
        cout<<results[i];
        if(i>0)
            cout<<" ";
    }
    return 0;
}
