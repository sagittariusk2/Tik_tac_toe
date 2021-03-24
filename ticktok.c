#include <stdio.h>

#include <stdlib.h>

int main()
{
    printf("WELCOME TO THE \"TICK_TAK_TOE\" GAME\n");
    printf("PRESS THE NUMBER ACCORDING TO KEYPAD TO FILL \'X\' AND \'O\'.\n");
    printf("7 8 9\n4 5 6\n1 2 3\n");
    printf("TO PLAY PRESS 1 AND TO FINISH PRESS 0\n-> ");



    int t;
    scanf("%d",&t);


    while(t==1)
    {
        char a[3][3];
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                a[i][j]='-';
                printf("- ");
            }
            printf("\n");
        }
        static int win[2];
        int playTime=0, n;
        char playKey;
        while(win[0]==0 && win[1]==0 && playTime<9) {
                lavel:
            if(playTime%2==0)
                playKey='X';
            else
                playKey='O';

            printf("-------------------\nPlayer (\'%c\')\n",playKey);
            printf("ENTER THE NUMBER\n-> ");
            scanf("%d",&n);
            playTime++;

            if(n==0)
                exit(0);
            else if(n>=7&&n<=9&&a[0][n-7]=='-')
                a[0][n-7]=playKey;
            else if(n>=4&&n<=6&&a[1][n-4]=='-')
                a[1][n-4]=playKey;
            else if(n>=1&&n<=3&&a[2][n-1]=='-')
                a[2][n-1]=playKey;
            else{
                printf("PLAYER : \'%c\'. YOU HAVE ENTERED WORNG NUMBER.\n",playKey);
                playTime--;
                goto lavel;
            }

            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    printf("%c ",a[i][j]);
                }
                printf("\n");
            }

            if(a[0][0]==a[0][1]&&a[0][1]==a[0][2]&&a[0][2]==playKey)
                win[playTime%2]++;
            if(a[1][0]==a[1][1]&&a[1][1]==a[1][2]&&a[1][2]==playKey)
                win[playTime%2]++;
            if(a[2][0]==a[2][1]&&a[2][1]==a[2][2]&&a[2][2]==playKey)
                win[playTime%2]++;
            if(a[0][0]==a[1][0]&&a[1][0]==a[2][0]&&a[2][0]==playKey)
                win[playTime%2]++;
            if(a[0][1]==a[1][1]&&a[1][1]==a[2][1]&&a[2][1]==playKey)
                win[playTime%2]++;
            if(a[0][2]==a[1][2]&&a[1][2]==a[2][2]&&a[2][2]==playKey)
                win[playTime%2]++;
            if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[2][0]==playKey)
                win[playTime%2]++;
            if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[2][2]==playKey)
                win[playTime%2]++;
            if(win[playTime%2]==1)
            {
                printf("Player \'%c\' won\n",playKey);
                win[playTime%2]=0;
                break;
            }
        }
        if(playTime>=9)
            printf("MATCH DRAW\nTRY NEXT");
        printf("\n\n");
        printf("TO REPLAY PRESS 1 AND TO FINISH PRESS 0\n");
        int t;
        scanf("%d",&t);
        if(t==0)
                exit(0);
    }

}
