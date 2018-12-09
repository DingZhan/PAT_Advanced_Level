#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    std::string str;
    std::ostringstream oss;
    char c;
    int n, i, j, cCount=0;
    cin>>str>>n;
    for(i=1; i<n; ++i)
    {
        oss.clear();
        oss.str("");
        for(j=0; j<str.length(); ++j)
        {
            if(j==0)
            {
                c = str[j];
                cCount = 1;
            }
            else
            {
                if(c==str[j])
                {
                    ++cCount;
                }
                else
                {
                    oss<<c<<cCount;
                    c = str[j];
                    cCount = 1;
                }
            }
        }
        oss<<c<<cCount;
        str = oss.str();
    }
    cout<<str<<endl;

    return 0;
}
