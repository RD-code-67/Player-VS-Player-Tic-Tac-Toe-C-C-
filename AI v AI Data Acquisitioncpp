#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int x,countZZ=0,CH=0,rd1,rd2,PP;
int bod[3][3];
char C[3][3];
map<string,int>His;
struct Hh
{
    string st;
    int sc;
};
string ma= {"000000000"};
vector<Hh>his;
void drawbod()
{
    cout<<C[0][0]<<"|"<<C[0][1]<<"|"<<C[0][2]<<endl
        <<"-+-+-"<<endl
        <<C[1][0]<<"|"<<C[1][1]<<"|"<<C[1][2]<<endl
        <<"-+-+-"<<endl
        <<C[2][0]<<"|"<<C[2][1]<<"|"<<C[2][2]<<endl;
}
void clean()
{
    ma= {"000000000"};
    memset(bod,0,sizeof(bod));
    memset(C,' ',sizeof(C));
    his.clear();
    countZZ=0;
    CH=0;
}
void chwin()
{
    for(int r=1; r<=2; r++)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if((bod[i][0]==r&&bod[i][1]==r&&bod[i][2]==r)||
                        (bod[0][j]==r&&bod[1][j]==r&&bod[2][j]==r)||
                        (bod[0][0]==r&&bod[1][1]==r&&bod[2][2]==r)||
                        (bod[0][2]==r&&bod[1][1]==r&&bod[2][0]==r))
                {
                    //cout<<r<<"P win";
                    PP=r;
                    CH=1;
                    return;
                }
            }
        }
    }
    if(countZZ==9)
    {
        //cout<<"draw";
        CH=1;
        return;
    }
}
void P1()
{
    while(true)
    {
        rd1=rand()%3;
        rd2=rand()%3;
        if(bod[rd1][rd2]==0)
        {
            break;
        }
    }
    ma[rd1*3+rd2]='1';
    bod[rd1][rd2]=1;
    countZZ++;
    his.push_back({ma,countZZ});
    chwin();
}
void P2()
{
    while(true)
    {
        rd1=rand()%3;
        rd2=rand()%3;
        if(bod[rd1][rd2]==0)
        {
            break;
        }
    }
    ma[rd1*3+rd2]='2';
    bod[rd1][rd2]=2;
    countZZ++;
    his.push_back({ma,countZZ});
    chwin();
}
void Datasa()
{
    for(const auto&th:his)
    {
        if(PP == 1)
        {
            His[th.st] -= 50;
        }
        else if(PP == 2)
        {
            His[th.st]+=50;
        }
        else
        {
            His[th.st]+=50;
        }
    }
    ofstream out;
    out.open("C:\\Users\\Genuine\\Desktop\\DATA2.txt");
    // By Al C:\\Users\\Genuine\\Desktop\\DATA2.txt
    if(out.fail())
    {
        //cout<<"DF";
    }
    else
    {
        for(const auto&[st,sc]:His)
        {
            out<<st<<" "<<sc<<endl;
        }
    }
    out.close();
}
void fdata()
{
    ifstream in;
    in.open("C:\\Users\\Genuine\\Desktop\\DATA2.txt");
    if(in.fail())
    {
        //cout<<"fail";
    }
    else
    {
        int sc2;
        string st2;
        while(in>>st2>>sc2)
        {
            His[st2]=sc2;
        }
        in.close();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    while(true)
    {
        fdata();
        srand(time(0));
        memset(bod,0,sizeof(bod));
        memset(C,' ',sizeof(C));
        while(CH==0)
        {
            P1();
            if(CH==1)
            {
                break;
            }
            P2();
            if(CH==1)
            {
                break;
            }
        }
        for(const auto&th:his)
        {
            His[th.st]+=1;
        }
        Datasa();
        clean();
    }
}

