#include<bits/stdc++.h>
using namespace std;
int x,countZZ=0,CH=0;
int bod[3][3];
void drawbod()
{
    cout<<bod[0][0]<<"|"<<bod[0][1]<<"|"<<bod[0][2]<<"\n"
        <<"-+-+-"<<"\n"
        <<bod[1][0]<<"|"<<bod[1][1]<<"|"<<bod[1][2]<<"\n"
        <<"-+-+-"<<"\n"
        <<bod[2][0]<<"|"<<bod[2][1]<<"|"<<bod[2][2]<<"\n";
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
                    system("cls");
                    cout<<r<<"P win";
                    CH=1;
                    return;
                }
            }
        }
    }
    if(countZZ==9)
    {
        system("cls");
        cout<<"draw";
        CH=1;
        return;
    }
}
int main()
{
    memset(bod,0,sizeof(bod));
    //////////////////////p1
    while(CH==0)
    {
re1:
        cout<<"P1 turn"<<"\n";
        drawbod();
        cin>>x;
        if(x>9||x<1)
        {
            cout<<"?";
            goto re1;
        }
        else if(bod[2-(x-1)/3][(x-1)%3]!=0)
        {
            cout<<"had";
            goto re1;
        }
        else
        {
            bod[2-(x-1)/3][(x-1)%3]=1;
            countZZ++;
            system("cls");
        }
        chwin();
        if(CH==1)
        {
            break;
        }
        ////////////////////////////2P
re2:
        cout<<"P2 turn"<<"\n";
        drawbod();
        cin>>x;
        if(x>9||x<1)
        {
            goto re2;
            cout<<"?";
        }
        else if(bod[2-(x-1)/3][(x-1)%3]!=0)
        {
            goto re2;
            cout<<"had";
        }
        else
        {
            bod[2-(x-1)/3][(x-1)%3]=2;
            countZZ++;
            system("cls");
        }
        chwin();
        if(CH==1)
        {
            break;
        }
    }
}
