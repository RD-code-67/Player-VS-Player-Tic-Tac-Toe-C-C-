#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int x,countZZ=0,CH=0,rd1,rd2,PP,g=0;
int bod[3][3];
char C[3][3];
map<string,int>His;
struct Hh
{
    string st;
    int sc;
};
string ma= {"000000000"};
string tmap;
vector<Hh>his;
void drawbod()
{
    cout<<" "<<C[0][0]<<"  |"<<" "<<C[0][1]<<"  |"<<" "<<C[0][2]<<"\n"
        <<"----+----+----"<<"\n"
        <<" "<<C[1][0]<<"  |"<<" "<<C[1][1]<<"  |"<<" "<<C[1][2]<<"\n"
        <<"----+----+----"<<"\n"
        <<" "<<C[2][0]<<"  |"<<" "<<C[2][1]<<"  |"<<" "<<C[2][2]<<"\n";
}
void clean()
{
    ma= {"000000000"};
    memset(bod,0,sizeof(bod));
    memset(C,' ',sizeof(C));
    his.clear();
    countZZ=0;
    CH=0;
    PP=0;
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
        PP=0;
        return;
    }
}
void P1AI()
{
    //cout<<"P1 turn"<<"\n";
    //drawbod();
    int Max=-100000,bestmo=-1;
    for(int i=0; i<9; i++)
    {
        if (rand() % 100 < 5)
        {
            bestmo = -1;
        }
        else if(ma[i]=='0')
        {
            tmap=ma;
            tmap[i]='1';
            if(His[tmap]>Max)
            {
                Max=His[tmap];
                bestmo=i;
            }
        }
    }
    if(bestmo==-1)
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
        C[rd1][rd2]='O';
        ma[rd1*3+rd2]='1';
        bod[rd1][rd2]=1;
        countZZ++;
        his.push_back({ma,countZZ});
        //system("cls");
        chwin();
    }
    else
    {
        bod[bestmo/3][bestmo%3]=1;
        C[bestmo/3][bestmo%3]='O';
        ma[bestmo]='1';
        countZZ++;
        his.push_back({ma,countZZ});
        //system("cls");
        chwin();
    }
}
void P2AI()
{
    //cout<<"P2 turn"<<"\n";
    //drawbod();
    int Max=-100000,bestmo=-1;
    for(int i=0; i<9; i++)
    {
        if (rand() % 100 < 5)
        {
            bestmo = -1;
        }
        if(ma[i]=='0')
        {
            tmap=ma;
            tmap[i]='2';
            if(His[tmap]>Max)
            {
                Max=His[tmap];
                bestmo=i;
            }
        }
    }
    if(bestmo==-1)
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
        C[rd1][rd2]='X';
        ma[rd1*3+rd2]='2';
        bod[rd1][rd2]=2;
        countZZ++;
        his.push_back({ma,countZZ});
        system("cls");
        chwin();
    }
    else
    {
        bod[bestmo/3][bestmo%3]=2;
        C[bestmo/3][bestmo%3]='X';
        ma[bestmo]='2';
        countZZ++;
        his.push_back({ma,countZZ});
        //system("cls");
        chwin();
    }
}
void Datasa()
{
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
void SC()
{
    for(const auto&th:his)
    {
        if(PP == 1)
        {
            His[th.st]-=100;
        }
        else if(PP == 2)
        {
            His[th.st]+=100;
        }
        else
        {
            His[th.st]+=20;
        }
    }
}
int main()
{
    fdata();
    srand(time(0));
    while(g<=100000)
    {
        memset(bod,0,sizeof(bod));
        memset(C,' ',sizeof(C));
        while(CH==0)
        {
            P1AI();
            if(CH==1)
            {
                break;
            }
            P2AI();
            if(CH==1)
            {
                break;
            }
        }
        for(const auto&th:his)
        {
            His[th.st]+=1;
        }
        SC();
        //Fcout<<His.size()<<"\n";
        clean();
        g++;
    }
    Datasa();
}

