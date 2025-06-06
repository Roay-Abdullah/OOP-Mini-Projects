#include <iostream>
#include <cstdlib>
#include<windows.h>
#include <ctime>
using namespace std;
bool moveTortoise(char*& TorPos);
bool moveHare(char*& HarePos);
static int Torposition = 1;
static int Hareposition = 1;
int main()
{
    char Tarr[100], Harr[100];
    for (int i = 0; i < 90; i++)  //Empty both Arrays
    {
        Tarr[i] = Harr[i] = ' ';
    }
    char* HarePos = Harr;   //Point to Arrays
    char* TorPos = Tarr;


    for (int i = 0; i < 1000; i++)  //Run until one Win or Tie
    {
        system("CLS");   //Clear screen before every output
        for (int i = 0; i < 90; i++) //Empty both Arrays before output 
        {
            Tarr[i] = Harr[i] = ' ';
        }

        if (Torposition >= 80 && Hareposition >= 80)  //on Tie
        {
            cout << "It's a tie." << endl;
            return 0;
        }


        if (Hareposition == Torposition && Torposition != 1)  //when both at same position
        {
            cout << "------------OUCH!!!------------";
            Sleep(1500);
            system("CLS");
        }
        if (!moveHare(HarePos))   //Hare movement Function call
        {
            *HarePos = 'H';
            for (int i = 0; i < 80; i++)
            {
                cout << Harr[i];
            }
            cout << '|' << endl;
        }
        else              //if Hare wins
        {
            cout << "Hare wins. Yuck!!!" << endl;
            cout << "Wins a pail of fresh carrots and lettuce" << endl;
            return 0;
        }


        if (!moveTortoise(TorPos))  //Tortoise movement Function call
        {
            *TorPos = 'T';
            for (int i = 0; i < 80; i++)
            {
                cout << Tarr[i];
            }
            cout << '|' << endl;
        }
        else           //if Tortoise wins
        {
            cout << "TORTOISE WINS!!! YAY!!!" << endl;
            cout << "Wins a pail of fresh carrots and lettuce" << endl;
            return 0;
        }

        Sleep(500);  //Wait for next output or execution

    }

}
bool moveTortoise(char*& TorPos)  //MoveTortoise Function
{
    srand(time(0));                 //Seed random time
    int Tnum = rand() % 100 + 1;    //random percentages

    if (Tnum <= 50)
    {
        Torposition = Torposition + 4;  //Fast Plod (50%)
        TorPos = TorPos + 4;   
    }
    else if (Tnum <= 70)
    {
        Torposition = Torposition - 5;  //Slip (20%)
        TorPos = TorPos - 5;  
    }
    else
    {
        Torposition = Torposition + 1;   //Slow Plod (30%)
        TorPos = TorPos + 1;   
    }

    if (Torposition < 1)        //if Tortoise moves backward and reaches below 1
    {
        while (Torposition != 1)
        {
            Torposition++;
            TorPos++;
        }
    }
    if (Torposition > 80)     //if tortoise reaches 80 or further next and wins
    {
        return 1;
    }
    else                     //if Tortoise doesn't reach until 80 
    {
        return 0;
    }

}
bool moveHare(char*& HarePos)  //moveHare Function
{
    srand(time(0));                  //Seed random time
    int Hnum = rand() % 100 + 1;     //random percentages

    if (Hnum <= 38)
    {
        Hareposition = Hareposition + 0;   //Sleep (38%)
        HarePos = HarePos + 0;   
    }
    else if (Hnum <= 58)
    {
        Hareposition = Hareposition + 11;   //Big Hop (20%)
        HarePos = HarePos + 11;  
    }
    else if (Hnum <= 78)
    {
        Hareposition = Hareposition - 9;  //Big Slip (20%)
        HarePos = HarePos - 9;  
    }
    else
    {
        Hareposition = Hareposition + 1;   //Small Hop (22%)
        HarePos = HarePos + 1;   
    }

    if (Hareposition < 1)      //if Hare moves backward and reaches below 1
    {
        while (Hareposition != 1)
        {
            Hareposition++;
            HarePos++;
        }
    }
    if (Hareposition > 80)     //if Hare reaches 80 or further next and wins
    {
        return 1;
    }
    else                       //if Hare doesn't reach until 80 
    {
        return 0;
    }
}
