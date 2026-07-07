#include<bits/stdc++.h>
using namespace std;
int bod[3][3]= {};
int x,i,j,r,countZZ=0;
char bodo[3][3]= {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
void drawbod()
{
    cout<<" "<<bodo[0][0]<<" | "<<bodo[0][1]<<" | "<<bodo[0][2]<<"\n"
        <<"---+---+---"<<"\n"
        <<" "<<bodo[1][0]<<" | "<<bodo[1][1]<<" | "<<bodo[1][2]<<"\n"
        <<"---+---+---"<<"\n"
        <<" "<<bodo[2][0]<<" | "<<bodo[2][1]<<" | "<<bodo[2][2]<<"\n";
}
void clean()
{
    memset(bod,0,sizeof(bod));
    memset(bodo,' ',sizeof(bodo));
    system("cls");
    drawbod();
    countZZ=0;
}
bool win()
{
    for(r=1; r<=2; r++)
    {
        for(i=0; i <= 2; i++)
        {
            for(j=0; j <= 2; j++)
            {
                if((bod[0][j] ==r && bod[1][j]==r && bod[2][j]==r)||
                        (bod[i][0] ==r && bod[i][1]==r && bod[i][2]==r)||
                        (bod[0][0]==r && bod[1][1]==r && bod[2][2]==r)||
                        (bod[0][2]==r && bod[1][1]==r && bod[2][0]==r))
                {
                    cout << r<<"p win!"<<"\n";
                    return true;
                }
            }
        }
    }
    if(countZZ==9)
    {
        cout<<"draw"<<"\n";
        return true;
    }
    return false;
}
int main()
{

reg:
    clean();
    while(win()==false)
    {
////////////////////////////////////////////////////////////////////////////1
re1:
        cout<<"player 1 trun"<<"\n";
        cin>>x;
        if(x>9||x<=0)
        {
            system("cls");
            cout<<"what are you doing????????"<<"\n";
            drawbod();
            goto re1;
        }
        else if(bod[2-(x-1)/3][(x-1)%3]==0)
        {
            bod[2-(x-1)/3][(x-1)%3]=1;
            bodo[2-(x-1)/3][(x-1)%3]='O';
            countZZ++;
            system("cls");
            drawbod();
        }
        else if(bod[2-(x-1)/3][(x-1)%3]!=0)
        {
            cout<<"There is already values that cannot be entered."<<"\n";
            goto re1;
        }

        if(win()==true)
        {
            break;
        }
/////////////////////////////////////////////////////////////////////////////////2
re2:
        cout<<"player 2 trun"<<"\n";
        cin>>x;
        if(x>9||x<=0)
        {
            system("cls");
            cout<<"what are you doing????????"<<"\n";
            drawbod();
            goto re2;
        }
        else if(bod[2-(x-1)/3][(x-1)%3]==0)
        {
            bod[2-(x-1)/3][(x-1)%3]=2;
            bodo[2-(x-1)/3][(x-1)%3]='X';
            countZZ++;
            system("cls");
            drawbod();
        }
        else if(bod[2-(x-1)/3][(x-1)%3]!=0)
        {
            cout<<"There is already values that cannot be entered."<<"\n";
            goto re2;
        }
        else
        {
            cout<<"what are you doing????????"<<"\n";
            goto re2;
        }
        if(win()==true)
        {
            break;
        }
    }
    cout<<"play angin? Yes press 0(Zero)"<<"\n";
    cin>>x;
    if(x==0)
    {
        goto reg;
    }
}

    //int win[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}}
