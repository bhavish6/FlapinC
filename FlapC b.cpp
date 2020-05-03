#include <iostream>
#include <conio.h>
#include <time.h>
#include<dos.h>
#include<stdlib.h>
#include <stdio.h>
using namespace std;
string map[20][30];  //global variable declared
int startgame(int start ,int xob[3],int yob[3],int score,int x,bool wasit,char mv) //func called to start game
{


 while (wasit == true)                //This loop runs until the bird is alive
    {
        for (int i =0;i<3;i++)
        {
            for (int j=1;j<19;j++)
            {
                map[j][xob[i]]="  "; //clearing the obstacle
            }
        }
        for (int i=0;i<3;i++) //make the obstacle move from right to left
        {
            xob[i]--;
        }
        for (int i =0;i<3;i++) //make the obstacle
        {
            for (int j=1;j<19;j++)
            {
                map[j][xob[i]]="* ";
            }
        }
        for (int i=0;i<3;i++) //to make a hole at the obstacle
        {
            map[yob[i]][xob[i]]="  ";
            map[yob[i]+1][xob[i]]="  ";
            map[yob[i]+2][xob[i]]="  ";
            map[yob[i]+3][xob[i]]="  ";
            map[yob[i]+4][xob[i]]="  ";
        }
        for (int i=0;i<3;i++)
        {
            if (xob[i]==1)                  //to take obstacle again to right after it reaches left
                {xob[i]=28;
                yob[i]=(rand()-1)%14;     //Range of 14 randomize
                }
        }
        map[x][3]="  ";            //clear the position for bird

        if (_kbhit())            //if keyboard hit this loop runs
        {
            mv=_getch();
            x=x-3;                    //the bird flies up on the negative y axis
        }
        x++;                        //effect of gravity which pulls bird down
        if(x<1)
            x=1;                //boundary condition
        for (int i=0;i<3;i++)
        {
            if (xob[i]==3)    //when the obstacle reaches the position of the bird ,checking
            {


                if (map[x][3]=="  ")  //bird flies succesfully thru hole
                    score=score+1;     //score increases
                if (map[x][3]=="* ")
                    wasit=false;      //crashes ,game over
            }
        }
        map[x][3]=" $ ";                //initialize the bird
        for (int i=1;i<19;i++)
        {
            map[i][1]="  ";
        }
        for (int i=0;i<20;i++)
        {
            for (int j=0;j<30;j++)    //print the map of the game
            {
                cout<<map[i][j];
            }
        printf("\n");
        }
         printf("Score = %d",score);

    system ("cls");         //clear screen
    }
    return score;
}
int main()
{    int start =0;

    srand(time(0));//to make the program randomize(for rand func)
    char mv;
    char repeat='y';
    int highscore=0;
    while (repeat=='y'){
    int score=0;

    int x=9;
    int yob[3]; // the y-axis of obstacle
    int xob[3]; // the x-axis of obstacle
    xob[0]=10;
    xob[1]=18;
    xob[2]=27; // the starting x-asis of obstacle


    bool wasit=true;



    for (int i=0;i<3;i++)
    {
        yob[i]=(rand()-1)%14;//Random y in range of 14
    }
    //initialize the map as a graph of x axis and negative y axis
    for (int i=0;i<20;i++)
    {
        for (int j=0;j<30;j++)
        {
            if ( i==0 || i==19|| j==29 || j==0)//making a rectangle

                map[i][j]="* ";
            else
                map[i][j]="  ";

        }

    }
    score =startgame(start ,xob,yob,score,x,wasit,mv);             //startgame function is called
    printf( "\nScore = %d",score);
    if (highscore<score)
        highscore=score;
     printf("\nHighscore= %d" ,highscore);
    printf( "\nPress y to begin game and n to exit = ");
    scanf("%s",&repeat);
    }
    return 0;
}
