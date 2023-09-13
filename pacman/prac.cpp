#include <iostream>
#include <windows.h>
using namespace std;

void printmaze();
void gotoxy(int x , int y);
void clear(int x , int y, char previous);
void erase(int x, int y);
void printPacman(int x, int y);
void printghost1(int x, int y);
void printghost2(int x, int y);
char getCharAtxy(short int x, short int y);
void gamestop();
int score = 0;
int scoreincrease();

main()
{
	system("color 05");
	int pacmanX = 4; 
        int pacmanY = 4; 
	int gx = 30;
	int gy = 6;
	int ga = 8;
	int gb = 5;
	string direction = "right";
	string direction1 = "down";
  string direction2 = "left";
	string direction3 = "up";
  string direction4 = "jump";
	char previous = ' ';
	char previous1 = ' ';
	bool gameRunning = true;
	
	score = scoreincrease();
        system("cls");
        cout << endl;
	printmaze();
	printPacman(pacmanX, pacmanY);
	printghost1(gx , gy);
	printghost2(ga, gb);


  while(gameRunning)
   {
	Sleep(200);
	
	 if (GetAsyncKeyState(VK_LEFT))
        {
            char nextLocation = getCharAtxy(pacmanX - 1, pacmanY);
            if (nextLocation == ' ')
            {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX - 1;
                printPacman(pacmanX, pacmanY);
            }
            if (nextLocation == '.')
            {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX - 1;
                printPacman(pacmanX, pacmanY);
                scoreincrease();
            }
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            char nextLocation = getCharAtxy(pacmanX + 1, pacmanY);
            if (nextLocation == ' ')
            {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX + 1;
                printPacman(pacmanX, pacmanY);
            }
            if (nextLocation == '.')
            {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX + 1;
                printPacman(pacmanX, pacmanY);
                scoreincrease();
            }
        }

        if (GetAsyncKeyState(VK_UP))
        {
            char nextLocation = getCharAtxy(pacmanX, pacmanY - 1);
            if (nextLocation == ' ')
            {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY - 1;
                printPacman(pacmanX, pacmanY);
            }
            if (nextLocation == '.')
            {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY - 1;
                printPacman(pacmanX, pacmanY);
                scoreincrease();
            }
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            char nextLocation = getCharAtxy(pacmanX, pacmanY + 1);
            if (nextLocation == ' ')
            {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY + 1;
                printPacman(pacmanX, pacmanY);
            }
            if (nextLocation == '.')
            {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY + 1;
                printPacman(pacmanX, pacmanY);
                scoreincrease();
            }
        }

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameRunning = false;
        }
	
	if(direction == "right")
	{
	  char nextlocation =  getCharAtxy(gx + 1, gy);
	  if(nextlocation == '|'|| nextlocation == '%')
	  {
	       direction ="left";
	  }
	  else if(nextlocation == ' ' || nextlocation == '.')
	  {
		clear(gx , gy , previous);
		gx = gx + 1;
		previous = nextlocation;
		printghost1(gx , gy);
	  }
	  else if(nextlocation == 'P')
	  {
		Sleep(500);
		system("cls");
		gamestop();
		
		gameRunning = false;
          }

        }
	if(direction == "left")
	{
	  char nextlocation =  getCharAtxy(gx - 1, gy);
	  if(nextlocation == '|'|| nextlocation == '%')
	  {
	       direction ="right";
	  }
	  else if(nextlocation == ' ' || nextlocation == '.')
	  {
		clear(gx , gy , previous);
		gx = gx - 1;
		previous = nextlocation;
		printghost1(gx , gy);
	  }
	  else if(nextlocation == 'P')
	  {
		Sleep(500);
		system("cls");
		gamestop();
		
		gameRunning = false;
          }
        
         }
	if(direction1 == "down")
	{
	  char nextlocation =  getCharAtxy(ga, gb + 1);
	  if(nextlocation == '#' || nextlocation == '%' )
	  {
	       direction1 ="up";
	  }
	  else if(nextlocation == ' ' || nextlocation == '.')
	  {
		clear(ga , gb , previous1);
		gb = gb + 1;
		previous1 = nextlocation;
		printghost2(ga , gb);
	  }
            else if(nextlocation == 'P')
	  {
		Sleep(500);
		system("cls");
		
              gamestop();
		
		gameRunning = false;
          }	 

        }
	if(direction1 == "up")
	{
	  char nextlocation =  getCharAtxy(ga, gb -1);
	  if(nextlocation == '#'|| nextlocation == '%')
	  {
	       direction1 ="down";
	  }
	  else if(nextlocation == ' ' || nextlocation == '.')
	  {
		clear(ga , gb , previous1);
		gb = gb - 1;
		previous1 = nextlocation;
		printghost2(ga , gb);
	  }
	  else if(nextlocation == 'P')
	  {
		Sleep(500);
		system("cls");
		 gamestop();
		
		gameRunning = false;
          }

         }
     }
 }

void printmaze()
{

	  cout << " #######################################################################      " << endl;
    cout << " ||.. ......................................................  ......  ||          " << endl;
    cout << " ||.. %%%%%%%%%%%%%%%%        ...      %%%%%%%%%%%%%%  |%|..   %%%%   ||     " << endl;
    cout << " ||..        |%|   |%|     |%|...      |%|        |%|  |%|..    |%|   ||         " << endl;
    cout << " ||..        |%|   |%|     |%|...      |%|        |%|  |%|..    |%|   ||          " << endl;
    cout << " ||..        %%%%%%%%  . . |%|...      %%%%%%%%%%%%%%     ..   %%%%.  ||     " << endl;
    cout << " ||..        |%|       . . |%|...     ............... |%| ..       .  ||        " << endl;
    cout << " ||..        %%%%%%%%%%. . |%|...     %%%%%%%%%%%%    |%| ..   %%%%.  ||        " << endl;
    cout << " ||..               |%|.              |%|......       |%| ..    |%|.  ||       " << endl;
    cout << " ||..     ......... |%|.              |%|......|%|        ..    |%|.  ||      " << endl;
    cout << " ||..|%|  |%|%%%|%|.|%|.  |%|            ......|%|        ..|%| |%|.  ||        " << endl;
    cout << " ||..|%|  |%|   |%|..     %%%%%%%%%%%%%  ......|%|         .|%|.      ||       " << endl;
    cout << " ||..|%|  |%|   |%|..            ...|%|     %%%%%%        . |%|.      ||       " << endl;
    cout << " ||..|%|           .             ...|%|               |%| ..|%|.      ||      " << endl;
    cout << " ||..|%|  %%%%%%%%%%%%%%         ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||   " << endl;
    cout << " ||................................................   |%| ..........  ||    " << endl;
    cout << " ||   .............................................          .......  ||    " << endl;
    cout << " ||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|     |%| ..|%|.      ||    " << endl;
    cout << " ||..|%|  |%|   |%|..           ...|%|     %%%%%%     |%| ..|%|.      ||    " << endl;
    cout << " ||..|%|            .           ...|%|                |%| ..|%|.      ||     " << endl;
    cout << " ||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%      |%| ..|%|%%%%%  ||  " << endl;
    cout << " ||...............................................    |%| ..........  ||    " << endl;
    cout << " ||...............................................           .......  ||   " << endl;
    cout << " #######################################################################      " << endl;
}

void printPacman(int x, int y)
{
    gotoxy(x, y);
    cout << "P";
}
void gamestop()
{
    gotoxy(15,20);
                cout << " ______________" << endl;
     gotoxy(15,21);                     
		cout << "#              #" << endl;
    gotoxy(15,22);
		cout << "#  GAME OVER   # "<< endl;
     gotoxy(15,23);
		cout << "#              #" << endl;
     gotoxy(15,24);
		cout << "#              #" << endl;
      gotoxy(15,24);
		cout << "#______________#" << endl;

}

int scoreincrease()
{

    score = score + 1;
    gotoxy(0, 0);
    cout << "		 Score: " << score << endl;
    return score;
   
}
void printghost1(int x, int y)
{
	gotoxy(x , y);
	cout << "G";
}
void printghost2(int x, int y)
{
	gotoxy(x , y);
	cout << "V";
}

void clear(int x, int y ,char previous)
{
	gotoxy(x , y);
	cout << previous;
}
void erase(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void gotoxy(int x , int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
	CHAR_INFO ci;
	COORD xy = {0 , 0};
	SMALL_RECT rect = {x, y, x, y};
	COORD coordBufSize;
	coordBufSize.X = 1;
	coordBufSize.Y = 1;
	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), & ci, coordBufSize, xy, & rect) ? ci.Char.AsciiChar : ' ';
}