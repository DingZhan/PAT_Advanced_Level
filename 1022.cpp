#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

#define MAX_YEAR 3001
#define MAX_N 10001
struct Book
{
    char ID[8];
    /*
    char title[81];
    char author[81];
    char keywords[5][11];
    char keywordNum;
    char publisher[81];
    short year;
    */
};
std::map<std::string, std::vector<short> > keywordMapID;
std::map<std::string, std::vector<short> > publisherMapID;
std::map<std::string, std::vector<short> > titleMapID;
std::map<std::string, std::vector<short> > authorMapID;
std::vector<std::vector<short> > yearIDs;

int main()
{
    short i, N, year;
    std::string ID, title, author, keyword, publisher, lineStr;
    Book books[MAX_N];

    yearIDs.resize(MAX_YEAR);
    std::cin>>N;
    //skip \n
    std::getline(std::cin, lineStr);
    for(i=0; i<N; ++i)
    {
        std::getline(std::cin, ID);
        std::getline(std::cin, title);
        std::getline(std::cin, author);
        std::getline(std::cin, lineStr);
        std::istringstream iss(lineStr);
        while(true)
        {
            iss>>keyword;
            if(iss.fail())
                break;
            keywordMapID[keyword].push_back(i);
        }
        std::getline(std::cin, publisher);
        std::getline(std::cin, lineStr);
        year = atoi(lineStr.c_str());
        publisherMapID[publisher].push_back(i);
        titleMapID[title].push_back(i);
        authorMapID[author].push_back(i);
        yearIDs[year].push_back(i);
        strcpy(books[i].ID, ID.c_str());

    }
    short M, j;
    char t, c;
    std::map<std::string, std::vector<short> >::iterator it;
    std::cin>>M;
    std::getline(std::cin, lineStr);
    for(i=0; i<M; ++i)
    {
        std::getline(std::cin, lineStr);
        t = lineStr[0];
        lineStr.erase(lineStr.begin(), lineStr.begin()+3);
        if(t=='1')
        {
            it = titleMapID.find(lineStr);
            std::cout<<t<<": "<<lineStr<<"\n";
            if(it==titleMapID.end())
                std::cout<<"Not Found\n";
            else
            {
                std::vector<std::string> strs;
                for(j=0; j<it->second.size(); ++j)
                    strs.push_back(books[it->second[j]].ID);
                std::sort(strs.begin(), strs.end());
                for(j=0; j<strs.size(); ++j)
                    std::cout<<strs[j]<<"\n";
            }
        }
        else if(t=='2')
        {
            it = authorMapID.find(lineStr);
            std::cout<<t<<": "<<lineStr<<"\n";
            if(it==authorMapID.end())
                std::cout<<"Not Found\n";
            else
            {
                std::vector<std::string> strs;
                for(j=0; j<it->second.size(); ++j)
                    strs.push_back(books[it->second[j]].ID);
                std::sort(strs.begin(), strs.end());
                for(j=0; j<strs.size(); ++j)
                    std::cout<<strs[j]<<"\n";
            }
        }
        else if(t=='3')
        {
            it = keywordMapID.find(lineStr);
            std::cout<<t<<": "<<lineStr<<"\n";
            if(it==keywordMapID.end())
                std::cout<<"Not Found\n";
            else
            {
                std::vector<std::string> strs;
                for(j=0; j<it->second.size(); ++j)
                    strs.push_back(books[it->second[j]].ID);
                std::sort(strs.begin(), strs.end());
                for(j=0; j<strs.size(); ++j)
                    std::cout<<strs[j]<<"\n";
            }
        }
        else if(t=='4')
        {
            it = publisherMapID.find(lineStr);
            std::cout<<t<<": "<<lineStr<<"\n";
            if(it==publisherMapID.end())
                std::cout<<"Not Found\n";
            else
            {
                std::vector<std::string> strs;
                for(j=0; j<it->second.size(); ++j)
                    strs.push_back(books[it->second[j]].ID);
                std::sort(strs.begin(), strs.end());
                for(j=0; j<strs.size(); ++j)
                    std::cout<<strs[j]<<"\n";
            }
        }
        else if(t=='5')
        {
            year = atoi(lineStr.c_str());
            std::cout<<t<<": "<<lineStr<<"\n";
            if(year<1000 || year>3000 || yearIDs[year].size()==0)
                std::cout<<"Not Found\n";
            else
            {
                std::vector<std::string> strs;
                for(j=0; j<yearIDs[year].size(); ++j)
                    strs.push_back(books[yearIDs[year][j]].ID);
                std::sort(strs.begin(), strs.end());
                for(j=0; j<strs.size(); ++j)
                    std::cout<<strs[j]<<"\n";
            }
        }
    }
    return 0;

}
