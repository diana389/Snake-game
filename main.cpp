#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <windows.h>
#include <WinCon.h>
#include <cwchar>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define VK_SPACE	0x20

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void set_cursor(int x = 0, int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition ( handle, coordinates );
}

int main()
{
    int i, j, si, sj, ok=1, runda=1, k=1, fructi, fructj, puncte=0, vi[10000]= {0}, poz=0, vj[10000]= {0}, cs, cj, contor=0;
    int l=1, c=0, x=0, nivel=1, timp=1, colour, directie, keyup, keydown, keyleft, keyright, hearts=3, heartsuse=0, lifei, lifej, vai=-1, verif=1, pause, halfi, halfj;
    char a[25][80];

    set_cursor(49,5);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to white
    cout<<"WELCOME TO SNAKE!";
    set_cursor(30,22);
    cout<<" <- ENDLESS MODE";
    set_cursor(75,22);
    cout<<"LEVELS ->";
    set_cursor(44,7);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); //change text color to white
    cout<<"What would you like to play?";

    for(i=28; i<=88; i++)
    {
        if(i<=49 || i>=67)
        {
            set_cursor(i,10);
            cout<<'x';
            set_cursor(i,20);
            cout<<'x';
        }
    }

    for(i=11; i<=19; i++)
    {
        set_cursor(28,i);
        cout<<'x';
        set_cursor(49,i);
        cout<<'x';
        set_cursor(67,i);
        cout<<'x';
        set_cursor(88,i);
        cout<<'x';
    }

    for(i=67; i<=78; i++)
    {
        set_cursor(i,12);
        cout<<'x';
    }

    for(i=67; i<=74; i++)
    {
        set_cursor(i,15);
        cout<<'x';
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    set_cursor(32,23);
    cout<<"(Press left key)";
    set_cursor(70,23);
    cout<<"(Press right key)";

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for(i=14; i<=17; i++)
    {
        set_cursor(43,i);
        cout<<'o';
    }

    for(i=39; i<=42; i++)
    {
        set_cursor(i,14);
        cout<<'o';
    }

    for(i=12; i<=18; i++)
    {
        set_cursor(83,i);
        cout<<'o';
    }

    set_cursor(82,18);
    cout<<'o';
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    set_cursor(35,17);
    cout<<'M';
    set_cursor(75,18);
    cout<<'M';
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    set_cursor(70,13);
    cout<<'L';
    set_cursor(0,29);
    while(1)
    {
        switch((c=getch()))
        {
        case KEY_RIGHT:
        {
            set_cursor(0,0);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

            for(i=1; i<25; i++)
            {
                cout<<endl;
                Sleep(10); //sleeps for 0.1 seconds
                for(j=0; j<100; j++)
                    cout<<' ';
            }

            for(nivel=1; nivel<=7; nivel++)
            {
                poz=0;
                l=1;

                if(nivel>1)
                {
                    set_cursor(0,0);
                    SetConsoleTextAttribute(hConsole, 0);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

                    for(i=1; i<25; i++)
                    {
                        cout<<endl;
                        Sleep(100); //sleeps for 0.1 seconds
                        for(j=0; j<80; j++)
                            cout<<' ';
                    }
                }

                SetConsoleTextAttribute(hConsole, 0);
                set_cursor(84,15);
                cout<<"             ";
                set_cursor(84,17);
                cout<<"             ";
                set_cursor(84,19);
                cout<<"                ";

                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE); //change text color to white
                set_cursor(96,5);
                cout<<" LEVEL "<<nivel<<" ";

                puncte=0;
                set_cursor(84,15);
                cout<<" SCORE: "<<puncte<<"   ";
                timp=1;
                set_cursor(84,17);
                cout<<" TIME: "<<timp/5<<"s   ";
                set_cursor(84,19);
                cout<<" LIVES: "<<hearts<<"   ";
                set_cursor(84,16);
                cout<<"            ";
                set_cursor(84,18); //move text cursor to particular screen coordinate
                cout<<"            ";
                set_cursor(84,14); //move text cursor to particular screen coordinate
                cout<<"            ";
                set_cursor(84,20); //move text cursor to particular screen coordinate
                cout<<"            ";

                SetConsoleTextAttribute(hConsole, 0);
                set_cursor(105,5);
                cout<<" ";

                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); //change text color to white
                set_cursor(83,7); //move text cursor to particular screen coordinate
                cout<<"                                  ";
                set_cursor(94,8); //move text cursor to particular screen coordinate
                cout<<"                           ";

                if(nivel==4)
                {
                    SetConsoleTextAttribute(hConsole, 0);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

                    set_cursor(84,15); //move text cursor to particular screen coordinate
                    cout<<"               ";
                    set_cursor(84,16);
                    cout<<"               ";
                    set_cursor(84,17);
                    cout<<"               ";
                    set_cursor(84,18);
                    cout<<"               ";
                    set_cursor(84,19);
                    cout<<"               ";
                    set_cursor(84,14);
                    cout<<"            ";
                    set_cursor(84,20);
                    cout<<"            ";
                    set_cursor(96,5);
                    cout<<"                 ";
                    set_cursor(5,27);
                    cout<<"                                                                                                    ";
                    set_cursor(84,10);
                    cout<<"                                           ";

                    set_cursor(0,5);
                    cout<<"CONGRATS! :) You have reached level 4. Now you can choose your snake's colour:"<<endl<<"(1) DARK BLUE"<<endl<<"(2) DARK GREEN"<<endl<<"(3) DARK CYAN"<<endl<<"(4) DARK RED"<<endl<<"(5) DARK MAGENTA"<<endl<<"(6) DARK YELLOW"<<endl<<"(7) DARK GRAY"<<endl<<"(8) GRAY"<<endl<<"(9) BLUE"<<endl<<"(10) GREEN"<<endl<<"(11) CYAN"<<endl<<"(12) RED"<<endl<<"(13) MAGENTA"<<endl<<"(14) YELLOW"<<endl<<"(15) WHITE"<<endl<<"(16) BLACK"<<endl;
                    cin>>colour;
                    while(colour>16 || colour<1)
                    {
                        set_cursor(0,23);
                        cout<<"That is not one of the options! Please try again!";
                        set_cursor(0,22);
                        cout<<"        ";
                        set_cursor(0,22);
                        cin>>colour;
                    }
                    set_cursor(0,23);
                    cout<<"                                                  ";

                    Sleep(500);
                    set_cursor(0,0);

                    for(i=1; i<25; i++)
                    {
                        cout<<endl;
                        Sleep(100); //sleeps for 0.1 seconds
                        for(j=0; j<80; j++)
                            cout<<' ';
                    }

                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE); //change text color to white
                    set_cursor(96,5); //move text cursor to particular screen coordinate
                    cout<<" LEVEL "<<nivel<<" ";
                    set_cursor(84,15);
                    cout<<" SCORE: "<<puncte<<"   ";
                    timp=1;
                    set_cursor(84,17);
                    cout<<" TIME: "<<timp/5<<"s   ";
                    set_cursor(84,19);
                    cout<<" LIVES: "<<hearts<<"   ";
                    set_cursor(84,16);
                    cout<<"            ";
                    set_cursor(84,18);
                    cout<<"            ";
                    set_cursor(84,14);
                    cout<<"            ";
                    set_cursor(84,20);
                    cout<<"            ";
                    SetConsoleTextAttribute(hConsole, 0);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                }

                for(i=0; i<25; i++)
                    for(j=0; j<80; j++)
                        if((j==5 || j==79) && i>1)
                            a[i][j]='x';
                        else
                        {
                            if(j>5 && (i==2 || i==24))
                                a[i][j]='x';
                            else
                                a[i][j]=NULL;
                        }

                if(nivel==2 || nivel==3)
                {
                    for(i=18; i<24; i++)
                        a[i][25]='x';
                    for(i=3; i<=10; i++)
                        a[i][40]='x';

                    if(nivel==3)
                    {
                        for(i=14; i<=17; i++)
                            a[i][25]='x';
                        for(i=3; i<=20; i++)
                            a[i][50]='x';
                        for(i=10; i<24; i++)
                            a[i][60]='x';
                        for(j=6; j<=15; j++)
                            a[9][j]='x';
                    }
                }

                if(nivel==4)
                {
                    for(j=9; j<=75; j++)
                    {
                        a[13][j]='x';
                        a[14][j]='x';
                    }
                    a[6][30]='x';
                    a[6][56]='x';
                    a[7][30]='x';
                    a[7][56]='x';
                    a[6][29]='x';
                    a[6][55]='x';
                    a[7][29]='x';
                    a[7][55]='x';
                    a[19][29]='x';
                    a[19][56]='x';
                    a[20][29]='x';
                    a[20][56]='x';
                    a[19][28]='x';
                    a[19][55]='x';
                    a[20][28]='x';
                    a[20][55]='x';
                }

                if(nivel==5)
                {
                    for(i=7; i<=19; i++)
                    {
                        if(i<12 || i>14)
                        {
                            a[i][30]='x';
                            a[i][56]='x';
                        }
                    }

                    for(j=20; j<=66; j++)
                    {
                        if(j<41 || j>46)
                        {
                            a[9][j]='x';
                            a[17][j]='x';
                        }
                    }
                }

                if(nivel==6)
                {
                    for(j=16; j<=68; j++)
                    {
                        a[8][j]='x';
                        if(j<=38 || j>=46)
                            a[16][j]='x';
                    }

                    for(i=8; i<=16; i++)
                    {
                        a[i][16]='x';
                        a[i][68]='x';
                    }
                }

                if(nivel==7)
                {
                    for(i=15; i<=23; i++)
                        a[i][20]='x';
                    cs=15;
                    cj=23;
                    directie=1;
                }

                SetConsoleTextAttribute(hConsole, 0);
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

                set_cursor(0,0);
                for(j=0; j<80; j++)
                    cout<<a[1][j];
                for(i=1; i<25; i++)
                {
                    cout<<endl;
                    if(nivel>1)
                        Sleep(100); //sleeps for 0.1 seconds
                    for(j=0; j<80; j++)
                        cout<<a[i][j];
                }

                set_cursor(94,7); //move text cursor to particular screen coordinate
                cout<<" PRESS A KEY!";
                set_cursor(90,10);
                cout<<"(Press space to pause)";
                set_cursor(5,27);
                cout<<"INSTRUCTIONS: M = 20 points; P = 40 points; L = 60 points; + = 1 life; H = your snake gets smaller";

                srand(time(0));
                si=rand()%21+3; //generate a random number
                sj=rand()%73+6;

                while(nivel>=2 && a[si][sj]=='x')
                {
                    si=rand()%21+3; //generate a random number
                    sj=rand()%73+6;
                }

                while(nivel==7 && sj==20)
                    sj=rand()%73+6; //generate a random number

                a[si][sj]='o';

                if(nivel>=4)
                {
                    switch (colour)
                    {
                    case 1:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        break;
                    case 2:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        break;
                    case 3:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                        break;
                    case 4:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        break;
                    case 5:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                        break;
                    case 6:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                        break;
                    case 7:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        break;
                    case 8:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
                        break;
                    case 9:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                        break;
                    case 10:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        break;
                    case 11:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        break;
                    case 12:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                        break;
                    case 13:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                        break;
                    case 14:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        break;
                    case 15:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                        break;
                    case 16:
                        SetConsoleTextAttribute(hConsole, 0 | FOREGROUND_INTENSITY);
                        break;
                    }
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to green
                }

                set_cursor(sj,si); //move text cursor to particular screen coordinate
                cout<<a[si][sj];

                x=0;
                k=1;

                while(ok==1 && (timp/5)<180 && puncte<200)
                {
                    keyup=GetAsyncKeyState(VK_UP);
                    keydown=GetAsyncKeyState(VK_DOWN);
                    keyleft=GetAsyncKeyState(VK_LEFT);
                    keyright=GetAsyncKeyState(VK_RIGHT);
                    pause=GetAsyncKeyState(VK_SPACE);

                    if(k==1 || heartsuse==1)
                    {
                        keyup=0;
                        keydown=0;
                        keyleft=0;
                        keyright=0;
                    }

                    if(pause)
                    {
                        set_cursor(89,10); //move text cursor to particular screen coordinate
                        cout<<"(Press space to unpause)";
                        pause=0;
                        contor=0;
                        while(pause==0)
                        {
                            if(contor>100000000)
                                pause=GetAsyncKeyState(VK_SPACE);
                            contor++;
                        }
                        set_cursor(89,10);
                        cout<<"                               ";
                        set_cursor(90,10);
                        cout<<"(Press space to pause)";
                    }

                    if (keyup) //check for a up key press within a while loop
                        x=1;

                    if (keydown) //check for a down key press within a while loop
                        x=2;

                    if (keyleft) //check for a left key press within a while loop
                        x=3;

                    if (keyright) //check for a right key press within a while loop
                        x=4;

                    if(heartsuse==1)
                        heartsuse=0;

                    k++;
                    contor++;
                    ok=0;

                    if(x!=0)
                    {
                        timp++;
                        runda++;
                        if(timp==2)
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                            set_cursor(83,7); //move text cursor to particular screen coordinate
                            cout<<"Survive 180s or collect 200 points";
                            set_cursor(95,8);
                            cout<<"to level up";
                        }

                        if(runda%60==10)
                        {
                            fructi=rand()%21+3; //generate a random number
                            fructj=rand()%73+6;

                            while(a[fructi][fructj]=='o' || a[fructi][fructj]=='x')
                            {
                                fructi=rand()%21+3; //generate a random number
                                fructj=rand()%73+6;
                            }

                            a[fructi][fructj]='M';
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //change text color to red
                            set_cursor(fructj,fructi); //move text cursor to particular screen coordinate
                            cout<<a[fructi][fructj];
                        }

                        if(runda>300 && runda%150==32)
                        {
                            fructi=rand()%21+3; //generate a random number
                            fructj=rand()%73+6;

                            while(a[fructi][fructj]=='o' || a[fructi][fructj]=='x')
                            {
                                fructi=rand()%21+3; //generate a random number
                                fructj=rand()%73+6;
                            }

                            a[fructi][fructj]='P';
                            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //change text color to red
                            set_cursor(fructj,fructi); //move text cursor to particular screen coordinate
                            cout<<a[fructi][fructj];
                        }

                        if(runda>700 && runda%200==4)
                        {
                            fructi=rand()%21+3; //generate a random number
                            fructj=rand()%73+6;

                            while(a[fructi][fructj]=='o' || a[fructi][fructj]=='x')
                            {
                                fructi=rand()%21+3;
                                fructj=rand()%73+6;
                            }

                            a[fructi][fructj]='L';
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to yellow
                            set_cursor(fructj,fructi); //move text cursor to particular screen coordinate
                            cout<<a[fructi][fructj];
                        }

                        if(runda>=600 && runda%200==0)
                        {
                            halfi=rand()%21+3; //generate a random number
                            halfj=rand()%73+6;

                            while(a[halfi][halfj]=='o' || a[halfi][halfj]=='x')
                            {
                                halfi=rand()%21+3; //generate a random number
                                halfj=rand()%73+6;
                            }

                            a[halfi][halfj]='H';
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to red
                            set_cursor(halfj,halfi); //move text cursor to particular screen coordinate
                            cout<<a[halfi][halfj];
                        }

                        if(runda>600 && runda%200==110)
                        {
                            a[halfi][halfj]=' ';
                            set_cursor(halfj,halfi); //move text cursor to particular screen coordinate
                            cout<<a[halfi][halfj];
                        }

                        if(runda>300 && runda%200==23)
                        {
                            lifei=rand()%21+3; //generate a random number
                            lifej=rand()%73+6;

                            while(a[lifei][lifej]=='o' || a[lifei][lifej]=='x')
                            {
                                lifei=rand()%21+3; //generate a random number
                                lifej=rand()%73+6;
                            }

                            a[lifei][lifej]='+';
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //change text color to red
                            set_cursor(lifej,lifei); //move text cursor to particular screen coordinate
                            cout<<a[lifei][lifej];
                        }

                        if(runda>400 && runda%200==130)
                        {
                            a[lifei][lifej]=' ';
                            set_cursor(lifej,lifei); //move text cursor to particular screen coordinate
                            cout<<a[lifei][lifej];
                        }

                        if(nivel>=4)
                        {
                            switch (colour)
                            {
                            case 1:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                break;
                            case 2:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                                break;
                            case 3:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                                break;
                            case 4:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                break;
                            case 5:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                                break;
                            case 6:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                                break;
                            case 7:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                break;
                            case 8:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
                                break;
                            case 9:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                                break;
                            case 10:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                                break;
                            case 11:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                                break;
                            case 12:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                                break;
                            case 13:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                                break;
                            case 14:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                                break;
                            case 15:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                                break;
                            case 16:
                                SetConsoleTextAttribute(hConsole, 0 | FOREGROUND_INTENSITY);
                                break;
                            }
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to green
                        }

                        if (x==1)
                        {
                            if(a[si-1][sj]!='x' && a[si-1][sj]!='o')
                            {
                                ok=1;
                                si--;

                                if(a[si][sj]=='M')
                                    puncte=puncte+20;

                                if(a[si][sj]=='P')
                                    puncte=puncte+40;

                                if(a[si][sj]=='L')
                                    puncte=puncte+60;

                                if(a[si][sj]=='+')
                                    hearts++;

                                if(a[si][sj]=='H')
                                {
                                    for(i=poz-l; i<=poz-l/2; i++)
                                    {
                                        a[vi[i]][vj[i]]=' ';
                                        set_cursor(vj[i],vi[i]);
                                        cout<<' ';
                                    }
                                    l=l/2;
                                }

                                a[si][sj]='o';
                                set_cursor(sj,si);
                                cout<<a[si][sj];
                                vi[poz]=si+1;
                                vj[poz]=sj;
                            }
                            else
                            {
                                vi[poz]=si;
                                vj[poz]=sj;
                            }
                        }

                        if(x==2)
                        {
                            if(a[si+1][sj]!='x' && a[si+1][sj]!='o')
                            {
                                ok=1;
                                si++;

                                if(a[si][sj]=='M')
                                    puncte=puncte+20;

                                if(a[si][sj]=='P')
                                    puncte=puncte+40;

                                if(a[si][sj]=='L')
                                    puncte=puncte+60;

                                if(a[si][sj]=='+')
                                    hearts++;

                                if(a[si][sj]=='H')
                                {
                                    for(i=poz-l; i<=poz-l/2; i++)
                                    {
                                        a[vi[i]][vj[i]]=' ';
                                        set_cursor(vj[i],vi[i]);
                                        cout<<' ';
                                    }
                                    l=l/2;
                                }

                                a[si][sj]='o';
                                set_cursor(sj,si);
                                cout<<a[si][sj];
                                vi[poz]=si-1;
                                vj[poz]=sj;
                            }
                            else
                            {
                                vi[poz]=si;
                                vj[poz]=sj;
                            }
                        }

                        if(x==3)
                        {
                            if(a[si][sj-1]!='x' && a[si][sj-1]!='o')
                            {
                                ok=1;
                                sj--;

                                if(a[si][sj]=='M')
                                    puncte=puncte+20;

                                if(a[si][sj]=='P')
                                    puncte=puncte+40;

                                if(a[si][sj]=='L')
                                    puncte=puncte+60;

                                if(a[si][sj]=='+')
                                    hearts++;

                                if(a[si][sj]=='H')
                                {
                                    for(i=poz-l; i<=poz-l/2; i++)
                                    {
                                        a[vi[i]][vj[i]]=' ';
                                        set_cursor(vj[i],vi[i]);
                                        cout<<' ';
                                    }
                                    l=l/2;
                                }

                                a[si][sj]='o';
                                set_cursor(sj,si);
                                cout<<a[si][sj];
                                vi[poz]=si;
                                vj[poz]=sj+1;
                            }
                            else
                            {
                                vi[poz]=si;
                                vj[poz]=sj;
                            }
                        }

                        if(x==4)
                        {
                            if(a[si][sj+1]!='x' && a[si][sj+1]!='o')
                            {
                                ok=1;
                                sj++;

                                if(a[si][sj]=='M')
                                    puncte=puncte+20;

                                if(a[si][sj]=='P')
                                    puncte=puncte+40;

                                if(a[si][sj]=='L')
                                    puncte=puncte+60;

                                if(a[si][sj]=='+')
                                    hearts++;

                                if(a[si][sj]=='H')
                                {
                                    for(i=poz-l; i<=poz-l/2; i++)
                                    {
                                        a[vi[i]][vj[i]]=' ';
                                        set_cursor(vj[i],vi[i]);
                                        cout<<' ';
                                    }
                                    l=l/2;
                                }

                                a[si][sj]='o';
                                set_cursor(sj,si);
                                cout<<a[si][sj];
                                vi[poz]=si;
                                vj[poz]=sj-1;
                            }
                            else
                            {
                                vi[poz]=si;
                                vj[poz]=sj;
                            }
                        }

                        poz++;

                        if(poz%10!=0)
                        {
                            a[vi[poz-l]][vj[poz-l]]=' ';
                            set_cursor(vj[poz-l],vi[poz-l]);
                            cout<<' ';
                        }
                        else
                            l++;

                        for(i=poz-1; i>=poz-l; i--)
                            if(a[vi[i]][vj[i]]=='x')
                            {
                                ok=0;
                                vai=i;
                                break;
                            }

                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE);
                        set_cursor(84,15); //move text cursor to particular screen coordinate
                        cout<<" SCORE: "<<puncte;

                        set_cursor(84,19);
                        cout<<"            ";
                        set_cursor(84,19);
                        cout<<" LIVES: "<<hearts;

                        if(timp%5==0)
                        {
                            set_cursor(84,17);
                            cout<<" TIME: "<<timp/5<<"s";
                        }
                        SetConsoleTextAttribute(hConsole, 0);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                    }
                    else
                        ok=1;

                    if(nivel==7 && contor%2==0)
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); //change text color to white

                        if(directie==1)
                        {
                            if(a[cs-1][20]!='x')
                            {
                                set_cursor(20,cs-1);
                                a[cs-1][20]='x';
                                cout<<a[cs-1][20];
                                set_cursor(20,cj);
                                a[cj][20]=' ';
                                cout<<a[cj][20];
                                cj--;
                                cs--;
                            }
                            else
                                directie=-1;
                        }
                        else
                        {
                            if(a[cj+1][20]!='x')
                            {
                                set_cursor(20,cj+1);
                                a[cj+1][20]='x';
                                cout<<a[cj+1][20];
                                set_cursor(20,cs);
                                a[cs][20]=' ';
                                cout<<a[cs][20];
                                cj++;
                                cs++;
                            }
                            else
                                directie=1;
                        }
                    }

                    if(ok==0 && hearts>0)
                    {
                        hearts--;
                        ok=1;

                        if(nivel>=4)
                        {
                            switch (colour)
                            {
                            case 1:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                                break;
                            case 2:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                                break;
                            case 3:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                                break;
                            case 4:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                                break;
                            case 5:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                                break;
                            case 6:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                                break;
                            case 7:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                break;
                            case 8:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
                                break;
                            case 9:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                                break;
                            case 10:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                                break;
                            case 11:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                                break;
                            case 12:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                                break;
                            case 13:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                                break;
                            case 14:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                                break;
                            case 15:
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                                break;
                            case 16:
                                SetConsoleTextAttribute(hConsole, 0 | FOREGROUND_INTENSITY);
                                break;
                            }
                        }
                        else
                        {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to green
                        }

                        if(poz<=6)
                        {
                            for(i=poz; i>=1; i--)
                            {
                                if(a[vi[i]][vj[i]]!='x')
                                {
                                    a[vi[i]][vj[i]]=' ';
                                    set_cursor(vj[i],vi[i]);
                                    cout<<' ';
                                    a[vi[i-1]][vj[i-1]]='o';
                                    set_cursor(vj[i-1],vi[i-1]);
                                    cout<<'o';
                                    Sleep(600);
                                }
                            }

                            si=vi[0];
                            sj=vj[0];
                            poz=0;
                        }
                        else
                        {
                            if(nivel==7 && vai!=-1)
                            {
                                verif=0;
                                a[si][sj]=' ';
                                set_cursor(sj,si);
                                cout<<' ';
                                a[vi[poz-l]][vj[poz-l]]='o';
                                set_cursor(vj[poz-l],vi[poz-l]);
                                cout<<'o';
                                Sleep(600);
                                poz--;
                                si=vi[poz];
                                sj=vj[poz];

                                while(verif==0)
                                {
                                    if(a[vi[poz]][vj[poz]]!='x')
                                    {
                                        a[vi[poz]][vj[poz]]=' ';
                                        set_cursor(vj[poz],vi[poz]);
                                        cout<<' ';
                                    }
                                    if(a[vi[poz-l]][vj[poz-l]]!='x')
                                    {
                                        a[vi[poz-l]][vj[poz-l]]='o';
                                        set_cursor(vj[poz-l],vi[poz-l]);
                                        cout<<'o';
                                    }
                                    Sleep(600);

                                    poz--;
                                    si=vi[poz];
                                    sj=vj[poz];
                                    verif=1;

                                    for(i=poz; i>=poz-l; i--)
                                        if(vj[i]==20)
                                            verif=0;
                                }

                                a[vi[poz]][vj[poz]]=' ';
                                set_cursor(vj[poz],vi[poz]);
                                cout<<' ';
                                a[vi[poz-l]][vj[poz-l]]='o';
                                set_cursor(vj[poz-l],vi[poz-l]);
                                cout<<'o';
                                Sleep(600);

                                poz--;
                                si=vi[poz];
                                sj=vj[poz];
                                vai=-1;
                            }
                            else
                            {
                                for(i=poz; i>=poz-4; i--)
                                {
                                    if(a[vi[i]][vj[i]]!='x')
                                    {
                                        a[vi[i]][vj[i]]=' ';
                                        set_cursor(vj[i],vi[i]);
                                        cout<<' ';
                                    }
                                    if(a[vi[i-l]][vj[i-l]]!='x')
                                    {
                                        a[vi[i-l]][vj[i-l]]='o';
                                        set_cursor(vj[i-l],vi[i-l]);
                                        cout<<'o';
                                    }
                                    Sleep(600);
                                }

                                si=vi[poz-5];
                                sj=vj[poz-5];
                                poz=poz-5;

                                if(nivel==7)
                                {
                                    verif=1;
                                    for(i=poz; i>=poz-l; i--)
                                        if(vj[i]==20)
                                            verif=0;
                                    Sleep(600);

                                    while(verif==0)
                                    {
                                        if(a[vi[poz]][vj[poz]]!='x')
                                        {
                                            a[vi[poz]][vj[poz]]=' ';
                                            set_cursor(vj[poz],vi[poz]);
                                            cout<<' ';
                                        }
                                        a[vi[poz-l]][vj[poz-l]]='o';
                                        set_cursor(vj[poz-l],vi[poz-l]);
                                        cout<<'o';
                                        Sleep(600);

                                        poz--;
                                        si=vi[poz];
                                        sj=vj[poz];
                                        verif=1;

                                        for(i=poz; i>=poz-l; i--)
                                            if(vj[i]==20)
                                                verif=0;
                                    }

                                    a[vi[poz]][vj[poz]]=' ';
                                    set_cursor(vj[poz],vi[poz]);
                                    cout<<' ';
                                    a[vi[poz-l]][vj[poz-l]]='o';
                                    set_cursor(vj[poz-l],vi[poz-l]);
                                    cout<<'o';
                                    Sleep(600);

                                    poz--;
                                    si=vi[poz];
                                    sj=vj[poz];
                                }
                            }

                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED);
                            set_cursor(84,19);
                            cout<<"            ";
                            set_cursor(84,19);
                            cout<<" LIVES: "<<hearts;
                            SetConsoleTextAttribute(hConsole, 0);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                        }

                        x=0;
                        heartsuse=1;
                    }

                    if(ok==1)
                        Sleep(200); //sleeps for 0.2 seconds
                }
                if(ok==0)
                {
                    SetConsoleTextAttribute(hConsole, 0);
                    set_cursor(0,0);

                    for(i=1; i<13; i++)
                    {
                        cout<<endl;
                        Sleep(100); //sleeps for 0.1 seconds

                        for(j=0; j<80; j++)
                        {
                            set_cursor(j,i);
                            cout<<' ';
                            set_cursor(j,25-i);
                            cout<<' ';
                        }
                    }

                    Sleep(200);
                    set_cursor(96,5);
                    cout<<"         ";
                    set_cursor(84,15);
                    cout<<"               ";
                    set_cursor(84,16);
                    cout<<"               ";
                    set_cursor(84,17);
                    cout<<"               ";
                    set_cursor(84,18);
                    cout<<"               ";
                    set_cursor(84,19);
                    cout<<"               ";
                    set_cursor(84,14);
                    cout<<"            ";
                    set_cursor(84,20);
                    cout<<"            ";
                    set_cursor(83,7);
                    cout<<"                                             ";
                    set_cursor(94,8);
                    cout<<"                           ";
                    set_cursor(84,10);
                    cout<<"                                           ";
                    set_cursor(5,27);
                    cout<<"                                                                                                    ";

                    while(1)
                    {
                        set_cursor(50,10);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //change text color to red
                        cout<<"YOU LOST!!!";
                        Sleep(150); //sleeps for 0.15 seconds
                        set_cursor(50,10);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); //change text color to white
                        cout<<"YOU LOST!!!";
                        Sleep(150);
                    }

                    return 0;
                }
                else
                    Sleep(1500); //sleeps for 1.5 seconds
            }

            set_cursor(0,0);
            SetConsoleTextAttribute(hConsole, 0);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

            for(i=1; i<25; i++)
            {
                cout<<endl;
                for(j=0; j<80; j++)
                    cout<<' ';
            }

            set_cursor(96,5); //move text cursor to particular screen coordinate
            cout<<"           ";
            set_cursor(83,7);
            cout<<"                                             ";
            set_cursor(94,8);
            cout<<"                           ";
            set_cursor(84,15);
            cout<<"               ";
            set_cursor(84,16);
            cout<<"               ";
            set_cursor(84,17);
            cout<<"               ";
            set_cursor(84,18);
            cout<<"               ";
            set_cursor(84,19);
            cout<<"               ";
            set_cursor(84,14);
            cout<<"            ";
            set_cursor(84,20);
            cout<<"            ";
            set_cursor(84,10);
            cout<<"                                     ";
            set_cursor(5,27);
            cout<<"                                                                                                    ";

            while(1)
            {
                set_cursor(50,10);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //change text color to red
                cout<<"YOU WON!!!";
                Sleep(150); //sleeps for 0.15 seconds
                set_cursor(50,10);
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); //change text color to white
                cout<<"YOU WON!!!";
                Sleep(150);
            }

            return 0;
        }
        case KEY_LEFT:
        {
            set_cursor(0,0);

            for(i=1; i<25; i++)
            {
                cout<<endl;
                Sleep(10); //sleeps for 0.1 seconds
                for(j=0; j<100; j++)
                    cout<<' ';
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); //change text color to white
            poz=0;
            l=1;

            for(i=0; i<25; i++)
                for(j=0; j<80; j++)
                    if((j==5 || j==79) && i>1)
                        a[i][j]='x';
                    else
                    {
                        if(j>5 && (i==2 || i==24))
                            a[i][j]='x';
                        else
                            a[i][j]=NULL;
                    }

            set_cursor(0,0);
            for(j=0; j<80; j++)
                cout<<a[1][j];
            for(i=1; i<25; i++)
            {
                cout<<endl;
                if(nivel>1)
                    Sleep(100); //sleeps for 0.1 seconds
                for(j=0; j<80; j++)
                    cout<<a[i][j];
            }

            set_cursor(95,7);
            cout<<"PRESS A KEY!";
            set_cursor(90,10);
            cout<<"(Press space to pause)";
            set_cursor(5,27);
            cout<<"INSTRUCTIONS: M = 20 points; P = 40 points; L = 60 points; + = 1 life; H = your snake gets smaller";

            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE); //change text color to white
            set_cursor(94,5);
            cout<<" ENDLESS MODE ";
            set_cursor(84,15);
            cout<<" SCORE: "<<puncte<<"   ";
            timp=1;
            set_cursor(84,17);
            cout<<" TIME: "<<timp/5<<"s   ";
            set_cursor(84,19);
            cout<<" LIVES: "<<hearts<<"   ";
            set_cursor(84,16);
            cout<<"            ";
            set_cursor(84,18);
            cout<<"            ";
            set_cursor(84,20);
            cout<<"            ";
            set_cursor(84,14);
            cout<<"            ";

            SetConsoleTextAttribute(hConsole, 0);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

            srand(time(0));
            si=rand()%21+3; //generate a random number
            sj=rand()%73+6;
            a[si][sj]='o';
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to green
            set_cursor(sj,si); //move text cursor to particular screen coordinate
            cout<<a[si][sj];

            while(ok==1)
            {
                keyup=GetAsyncKeyState(VK_UP);
                keydown=GetAsyncKeyState(VK_DOWN);
                keyleft=GetAsyncKeyState(VK_LEFT);
                keyright=GetAsyncKeyState(VK_RIGHT);
                pause=GetAsyncKeyState(VK_SPACE);

                if(k==1 || heartsuse==1)
                {
                    keyup=0;
                    keydown=0;
                    keyleft=0;
                    keyright=0;
                }

                if(pause)
                {
                    pause=0;
                    contor=0;

                    set_cursor(89,10); //move text cursor to particular screen coordinate
                    cout<<"(Press space to unpause)";
                    while(pause==0)
                    {
                        if(contor>100000000)
                            pause=GetAsyncKeyState(VK_SPACE);
                        contor++;
                    }
                    set_cursor(89,10);
                    cout<<"                               ";
                    set_cursor(90,10);
                    cout<<"(Press space to pause)";
                }

                if (keyup) //check for up key press within a while loop
                    x=1;

                if (keydown) //check for down key press within a while loop
                    x=2;

                if (keyleft) //check for left key press within a while loop
                    x=3;

                if (keyright) //check for right key press within a while loop
                    x=4;

                if(heartsuse==1)
                    heartsuse=0;

                k++;
                ok=0;

                if(x!=0)
                {
                    timp++;
                    runda++;
                    if(runda==2)
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                        set_cursor(84,7);
                        cout<<"Collect as many points as you can!";
                    }

                    if(runda%60==10)
                    {
                        fructi=rand()%21+3; //generate a random number
                        fructj=rand()%73+6;

                        while(a[fructi][fructj]=='o' || a[fructi][fructj]=='x')
                        {
                            fructi=rand()%21+3; //generate a random number
                            fructj=rand()%73+6;
                        }

                        a[fructi][fructj]='M';
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //change text color to red
                        set_cursor(fructj,fructi); //move text cursor to particular screen coordinate
                        cout<<a[fructi][fructj];
                    }

                    if(runda>300 && runda%150==33)
                    {
                        fructi=rand()%21+3; //generate a random number
                        fructj=rand()%73+6;

                        while(a[fructi][fructj]=='o' || a[fructi][fructj]=='x')
                        {
                            fructi=rand()%21+3; //generate a random number
                            fructj=rand()%73+6;
                        }

                        a[fructi][fructj]='P';
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //change text color to red
                        set_cursor(fructj,fructi); //move text cursor to particular screen coordinate
                        cout<<a[fructi][fructj];
                    }

                    if(runda>700 && runda%200==6)
                    {
                        fructi=rand()%21+3; //generate a random number
                        fructj=rand()%73+6;

                        while(a[fructi][fructj]=='o' || a[fructi][fructj]=='x')
                        {
                            fructi=rand()%21+3; //generate a random number
                            fructj=rand()%73+6;
                        }

                        a[fructi][fructj]='L';
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to red
                        set_cursor(fructj,fructi);
                        cout<<a[fructi][fructj];
                    }

                    if(runda>=600 && runda%200==23)
                    {
                        halfi=rand()%21+3; //generate a random number
                        halfj=rand()%73+6;

                        while(a[halfi][halfj]=='o' || a[halfi][halfj]=='x')
                        {
                            halfi=rand()%21+3; //generate a random number
                            halfj=rand()%73+6;
                        }

                        a[halfi][halfj]='H';
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to red
                        set_cursor(halfj,halfi);
                        cout<<a[halfi][halfj];
                    }

                    if(runda>600 && runda%200==130)
                    {
                        a[halfi][halfj]=' ';
                        set_cursor(halfj,halfi);
                        cout<<a[halfi][halfj];
                    }

                    if(runda>300 && runda%200==0)
                    {
                        lifei=rand()%21+3; //generate a random number
                        lifej=rand()%73+6;

                        while(a[lifei][lifej]=='o' || a[lifei][lifej]=='x')
                        {
                            lifei=rand()%21+3; //generate a random number
                            lifej=rand()%73+6;
                        }

                        a[lifei][lifej]='+';
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //change text color to red
                        set_cursor(lifej,lifei);
                        cout<<a[lifei][lifej];
                    }

                    if(runda>400 && runda%200==110)
                    {
                        a[lifei][lifej]=' ';
                        set_cursor(lifej,lifei);
                        cout<<a[lifei][lifej];
                    }

                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //change text color to green

                    if (x==1)
                    {
                        if(a[si-1][sj]!='x' && a[si-1][sj]!='o')
                        {
                            ok=1;
                            si--;

                            if(a[si][sj]=='M')
                                puncte=puncte+20;

                            if(a[si][sj]=='P')
                                puncte=puncte+40;

                            if(a[si][sj]=='L')
                                puncte=puncte+60;

                            if(a[si][sj]=='+')
                                hearts++;

                            if(a[si][sj]=='H')
                            {
                                for(i=poz-l; i<=poz-l/2; i++)
                                {
                                    a[vi[i]][vj[i]]=' ';
                                    set_cursor(vj[i],vi[i]);
                                    cout<<' ';
                                }
                                l=l/2;
                            }

                            a[si][sj]='o';
                            set_cursor(sj,si);
                            cout<<a[si][sj];
                            vi[poz]=si+1;
                            vj[poz]=sj;
                        }
                        else
                        {
                            vi[poz]=si;
                            vj[poz]=sj;
                        }
                    }

                    if(x==2)
                    {
                        if(a[si+1][sj]!='x' && a[si+1][sj]!='o')
                        {
                            ok=1;
                            si++;

                            if(a[si][sj]=='M')
                                puncte=puncte+20;

                            if(a[si][sj]=='P')
                                puncte=puncte+40;

                            if(a[si][sj]=='L')
                                puncte=puncte+60;

                            if(a[si][sj]=='+')
                                hearts++;

                            if(a[si][sj]=='H')
                            {
                                for(i=poz-l; i<=poz-l/2; i++)
                                {
                                    a[vi[i]][vj[i]]=' ';
                                    set_cursor(vj[i],vi[i]);
                                    cout<<' ';
                                }
                                l=l/2;
                            }

                            a[si][sj]='o';
                            set_cursor(sj,si);
                            cout<<a[si][sj];
                            vi[poz]=si-1;
                            vj[poz]=sj;
                        }
                        else
                        {
                            vi[poz]=si;
                            vj[poz]=sj;
                        }
                    }

                    if(x==3)
                    {
                        if(a[si][sj-1]!='x' && a[si][sj-1]!='o')
                        {
                            ok=1;
                            sj--;

                            if(a[si][sj]=='M')
                                puncte=puncte+20;

                            if(a[si][sj]=='P')
                                puncte=puncte+40;

                            if(a[si][sj]=='L')
                                puncte=puncte+60;

                            if(a[si][sj]=='+')
                                hearts++;

                            if(a[si][sj]=='H')
                            {
                                for(i=poz-l; i<=poz-l/2; i++)
                                {
                                    a[vi[i]][vj[i]]=' ';
                                    set_cursor(vj[i],vi[i]);
                                    cout<<' ';
                                }
                                l=l/2;
                            }

                            a[si][sj]='o';
                            set_cursor(sj,si); //move text cursor to particular screen coordinate
                            cout<<a[si][sj];
                            vi[poz]=si;
                            vj[poz]=sj+1;
                        }
                        else
                        {
                            vi[poz]=si;
                            vj[poz]=sj;
                        }
                    }

                    if(x==4)
                    {
                        if(a[si][sj+1]!='x' && a[si][sj+1]!='o')
                        {
                            ok=1;
                            sj++;

                            if(a[si][sj]=='M')
                                puncte=puncte+20;

                            if(a[si][sj]=='P')
                                puncte=puncte+40;

                            if(a[si][sj]=='L')
                                puncte=puncte+60;

                            if(a[si][sj]=='+')
                                hearts++;

                            if(a[si][sj]=='H')
                            {
                                for(i=poz-l; i<=poz-l/2; i++)
                                {
                                    a[vi[i]][vj[i]]=' ';
                                    set_cursor(vj[i],vi[i]);
                                    cout<<' ';
                                }
                                l=l/2;
                            }

                            a[si][sj]='o';
                            set_cursor(sj,si);
                            cout<<a[si][sj];
                            vi[poz]=si;
                            vj[poz]=sj-1;
                        }
                        else
                        {
                            vi[poz]=si;
                            vj[poz]=sj;
                        }
                    }

                    poz++;

                    if(poz%10!=0)
                    {
                        a[vi[poz-l]][vj[poz-l]]=' ';
                        set_cursor(vj[poz-l],vi[poz-l]);
                        cout<<' ';
                    }
                    else
                        l++;

                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE); //change text color to white
                    set_cursor(84,15);
                    cout<<" SCORE: "<<puncte;
                    set_cursor(84,19);
                    cout<<" LIVES: "<<hearts;

                    if(timp%5==0)
                    {
                        set_cursor(84,17);
                        cout<<" TIME: "<<timp/5<<"s";
                    }
                    SetConsoleTextAttribute(hConsole, 0);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

                }
                else
                    ok=1;

                if(ok==0 && hearts>0)
                {
                    hearts--;
                    ok=1;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

                    if(poz<=6)
                    {
                        for(i=1; i<=poz; i++)
                        {
                            a[vi[i]][vj[i]]=' ';
                            set_cursor(vj[i],vi[i]);
                            cout<<' ';
                        }

                        si=vi[0];
                        sj=vj[0];
                        poz=0;
                    }
                    else
                    {
                        for(i=poz; i>=poz-4; i--)
                        {
                            a[vi[i]][vj[i]]=' ';
                            set_cursor(vj[i],vi[i]);
                            cout<<' ';
                            a[vi[i-l]][vj[i-l]]='o';
                            set_cursor(vj[i-l],vi[i-l]);
                            cout<<'o';
                            Sleep(600);
                        }

                        si=vi[poz-5];
                        sj=vj[poz-5];
                        poz=poz-5;

                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED);
                        set_cursor(84,19);
                        cout<<" LIVES: "<<hearts;
                        SetConsoleTextAttribute(hConsole, 0);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                    }

                    x=0;
                    heartsuse=1;
                }

                if(ok==1)
                    Sleep(200); //sleeps for 0.2 seconds
            }

            if(ok==0)
            {
                set_cursor(0,0);

                for(i=1; i<13; i++)
                {
                    cout<<endl;
                    Sleep(100);

                    for(j=0; j<80; j++)
                    {
                        set_cursor(j,i);
                        cout<<' ';
                        set_cursor(j,25-i);
                        cout<<' ';
                    }
                }
                Sleep(200); //sleeps for 0.1 seconds
                set_cursor(95,5);
                cout<<"                  ";
                set_cursor(84,15);
                cout<<"               ";
                set_cursor(84,16);
                cout<<"               ";
                set_cursor(84,17);
                cout<<"               ";
                set_cursor(84,18);
                cout<<"               ";
                set_cursor(84,19);
                cout<<"               ";
                set_cursor(84,14);
                cout<<"               ";
                set_cursor(84,20);
                cout<<"               ";
                set_cursor(84,7);
                cout<<"                                   ";
                set_cursor(89,10);
                cout<<"                               ";
                set_cursor(94,5);
                cout<<"                    ";
                set_cursor(5,27);
                cout<<"                                                                                                        ";

                while(1)
                {
                    set_cursor(50,10);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); //change text color to red
                    cout<<"YOU LOST!!!";
                    Sleep(150); //sleeps for 0.15 seconds
                    set_cursor(50,10);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); //change text color to white
                    cout<<"YOU LOST!!!";
                    Sleep(150);
                }

                return 0;
            }
            else
                Sleep(1500); //sleeps for 1.5 seconds
        }
        return 0;
        }
    }
}

