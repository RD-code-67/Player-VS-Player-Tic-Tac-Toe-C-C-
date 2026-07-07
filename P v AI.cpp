#include<bits/stdc++.h>
using namespace std;
int x,countZZ=0,CH=0,PP,rd1,rd2,RE=0;
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
    //system("cls");
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
                    //system("cls");
                    cout<<r<<"P win";
                    PP=r;
                    CH=1;
                    return;
                }
            }
        }
    }
    if(countZZ==9)
    {
        //system("cls");
        cout<<"draw";
        CH=1;
        return;
    }
}
void fdata()
{
    ifstream in;
    in.open("C:\\Users\\Genuine\\Desktop\\DATA2.txt",ios::in);
    if(in.fail())
    {
        cout<<"fail";
    }
    else
    {
        int sc2;
        string st2;
        while(in>>st2>>sc2)
        {
            His[st2]=sc2;
        }
    }
}
void P1()
{
    cout<<"P1 turn"<<"\n";
    drawbod();
    while(true)
    {
        cin>>x;
        if(bod[2-(x-1)/3][(x-1)%3]==0)
        {
            break;
        }
        else if(x>9||x<1)
        {
            cout<<"?";
        }
        else
        {
            cout<<"had";
        }
    }
    C[2-(x-1)/3][(x-1)%3]='O';
    ma[(2-(x-1)/3)*3+(x-1)%3]='1';
    bod[2-(x-1)/3][(x-1)%3]=1;
    countZZ++;
    his.push_back({ma,countZZ});
    system("cls");
    chwin();
}
void P2AI()
{
    cout<<"P2 turn"<<"\n";
    drawbod();
    int Max=-100000,bestmo=-1;
    for(int i=0; i<9; i++)
    {
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
        system("cls");
        chwin();
    }
}
int main()
{
    while(RE==0)
    {
        fdata();
        memset(bod,0,sizeof(bod));
        memset(C,' ',sizeof(C));
        while(CH==0)
        {
            P1();
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
        clean();
        cout<<"\nplay again test -100\n";
        if(cin>>x&&x==-100)
        {
            system("cls");
            RE=0;
        }
        else
        {
            RE=1;
        }
    }
    //system("notepad C:\\Users\\Genuine\\Desktop\\DATA2.txt");
}
