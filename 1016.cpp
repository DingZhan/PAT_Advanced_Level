#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;
/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/
struct User
{
    std::string name;
    std::string time;
    bool bOn;
};
bool SortUser(const User& a, const User& b)
{
    int result = a.name.compare(b.name);
    if(result<0)
        return true;
    else if(result>0)
        return false;
    result = a.time.compare(b.time);
    return result<0;
}

int main()
{
    int i, j, N,  sumPrice, totalPrice, h1, h2, m, d1, d2, mi1, mi2, sumMinutes;
    int prices[24];
    std::string str, str2, name;
    std::vector<User> users;
    std::istringstream iss;
    char c;
    bool bUserFirst;
    User user;

    for(i=0; i<24; ++i)
        cin>>prices[i];

    cin>>N;
    for(i=0; i<N; ++i)
    {
        cin>>user.name>>user.time;
        cin>>str;
        cin.ignore();
        if(str=="on-line")
            user.bOn = true;
        else
            user.bOn = false;
        users.push_back(user);
    }
    std::sort(users.begin(), users.end(), SortUser);
    /*
    cout<<"--------------------------------"<<endl;
    for(i=0; i<(int)users.size(); ++i)
        cout<<users[i].name<<" "<<users[i].time<<" "<<(users[i].bOn?"On":"Off")<<endl;
    cout<<"--------------------------------"<<endl;
    */
    str="";
    for(i=0; i<(int)users.size()-1; )
    {
        name = users[i].name;
        totalPrice = 0;
        bUserFirst = true;
        for(j=i; j<(int)users.size()-1; )
        {
            sumPrice = 0;
            sumMinutes = 0;
            if(users[j].name!=name)
                break;
            if(users[j+1].name!=name)
            {
                ++j;
                break;
            }
            if(users[j].bOn && !users[j+1].bOn)
            {
                iss.clear();
                iss.str(users[j].time);
                iss>>m>>c>>d1>>c>>h1>>c>>mi1;

                iss.clear();
                iss.str(users[j+1].time);
                iss>>m>>c>>d2>>c>>h2>>c>>mi2;

                if(bUserFirst)
                {
                    cout<<users[j].name<<" "<<std::setw(2)<<std::setfill('0')<<m<<std::endl;
                }
                while(d1<d2)
                {
                    sumPrice+=prices[h1]*(60-mi1);
                    sumMinutes+=(60-mi1);
                    mi1 = 0;
                    ++h1;
                    if(h1==24)
                    {
                        ++d1;
                        h1 = 0;
                    }
                }
                while(h1<h2)
                {
                    sumPrice+=prices[h1]*(60-mi1);
                    sumMinutes+=(60-mi1);
                    mi1 = 0;
                    ++h1;
                }
                sumPrice+=prices[h1]*(mi2-mi1);
                sumMinutes+=(mi2-mi1);
                str.assign(users[j].time.begin()+3,users[j].time.end());
                str2.assign(users[j+1].time.begin()+3,users[j+1].time.end());
                cout<<str<<" "<<str2<<" "<<sumMinutes<<" "<<"$"<<std::setprecision(2)<<std::fixed<<sumPrice/100.0<<endl;
                totalPrice+=sumPrice;
                bUserFirst = false;
                j+=2;
            }
            else if(users[j+1].bOn)
                j+=1;
            else
                j+=2;
        }
        i = j;
        if(totalPrice)
            cout<<"Total amount: $"<<std::setprecision(2)<<std::fixed<<totalPrice/100.0<<endl;
    }
	return 0;
}
