#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global variables
char inletter[1000] = "\0";
char hang[1000] = "\0";
char allguess[1000] = "\0";
char used[1000] = "\0";
int score = 10;

// Prototyping all functions
int checkAlpha();
int alreadyUsed();
int guessed();
int counter(char a[]);
int lower();
int occurrence();
int prihan();


int main()

{
    int n=0;
    srand(time(NULL));
    n = rand()%5;
    switch(n)
    {
    case 0:
        strcpy(hang,"misunderstanding\0");
        break;
    case 1:
        strcpy(hang,"computer\0");
        break;
    case 2:
        strcpy(hang,"acknowledgement\0");
        break;
    case 3:
        strcpy(hang,"chair\0");
        break;
    case 4:
        strcpy(hang,"blabber\0");
        break;

    }
    int ep;
    for(ep=0; hang[ep]!='\0'; ep++)
    {
        allguess[ep] = '0';
    }
    allguess[ep] ='\0';


    prihan();
    printf("\t%d incorrect attempts left\n",score);

    while( score>0 && guessed() == 0)
    {
        gets(inletter);
        lower();
        if (counter(inletter) == 1)
        {
            if (checkAlpha()==1)
            {
                if (alreadyUsed() == 0)
                {
                    int p=counter(used);
                    used[p] = inletter[0];
                    used[p+1] = '\0';
                    if (occurrence()==1)
                    {
                        int j=0;
                        for(j=0; hang[j]!='\0'; j++)
                        {
                            if (hang[j] == inletter[0])
                            {
                                allguess[j] = '1';
                            }
                        }
                        prihan();
                        printf("\n");


                    }
                    else if (occurrence()==0)
                    {
                        score--;
                        prihan();
                        if (score >0){
                        printf("\t%d incorrect attempts left\n",score);
                        }
                        else if (score==0){
                            printf("\tNo attempt left\n");
                        }
                    }

                }


                else if (alreadyUsed() == 1)
                {
                    printf("Character already entered earlier. Please enter a new character.\n");
                    prihan();
                    printf("\n");
                }

            }
            else if (checkAlpha() == 0)
            {
                printf("Only alphabets are allowed. Please try again.\n");
                prihan();
                printf("\n");

            }
        }
        else if(counter(inletter) > 1)
        {
            printf("Multiple characters are not allowed. Please try again.\n");
            prihan();
            printf("\n");
        }
        else if(counter(inletter) == 0)
        {
            printf("No character entered. Please try again.\n");
            prihan();
            printf("\n");
        }
    }
    if (guessed() == 1)
    {
        printf("You win by a score of %d!!!\n",score);
    }
    else if (guessed() == 0)
    {
        printf("You lose!!!\nThe answer was %s\n",hang);
    }

    return 0;
}

int counter(char a[])
{
    int i=0;
    for(i=0; a[i]!='\0'; i++);
    return i;
}


int checkAlpha()
{

    switch (inletter[0])
    {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
        return 1;
    }

    return 0;
};

int alreadyUsed()
{
    int k=0;
    for (k=0; used[k] != '\0'; k++)
    {
        if (inletter[0] == used[k])
        {
            return 1;
        }
    }

    return 0;

}

int guessed()
{
    int i=0;
    for (i=0; hang[i]!='\0'; i++)
    {
        if (allguess[i] != '1')
        {
            return 0;
        }
    }
    return 1;
}

int lower()
{
    int i=0;
    for (i=0; inletter[i] != '\0'; i++)
    {
        if (inletter[i] >='A' && inletter[i] <='Z')
        {
            inletter[i] = inletter[i] + 'a' - 'A';
        }
    }

    return 0;
}

int occurrence()
{

    int i=0;
    for(i=0; hang[i]!='\0'; i++)
    {
        if (hang[i] == inletter[0])
        {
            return 1;
        }
    }
    return 0;
}

int prihan()
{
    int i=0;
    for (i=0; hang[i] !='\0'; i++)
    {
        if (allguess[i] != '1')
        {
            printf("_ ");
        }
        else if (allguess[i] == '1')
        {
            printf("%c ",hang[i]);
        }
    }

    return 0;
}
