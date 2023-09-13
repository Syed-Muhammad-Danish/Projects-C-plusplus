#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>

using namespace std;


void header();
string options();
string Mainpg();
void keys();
void clear();
void instruction();
void startgame();
void ready();
void submenu();
bool gameRunning = true;
void starting();
void ending();
void moveLeft();
void moveRight();
void moveUp();
void moveDown();
void tankp();
void erase();
int count = 0;
bool isActive[10000];
char heart = 3;
int bulletXl[2000];
int bulletYl[2000];
bool isbulletActivel[10000];
int bulletcountl = 0;
void generatebulletl();
void movebulletl();
void makebulletInactivel(int index);

// bullet functions
int bulletX[2000];
int bulletY[2000];
int bulletCount = 0;

void generatebullet();
void erasebullet(int x, int y);
void printbullet(int x, int y);
void makebulletinactive(int index);
void movebullet();
void printPlayerHealth();
void collisionPlayer();

// Player Character
char box1 = 16;
char box3 = 17;
char box2 = 178;
char box = 219;
char tank[3][3] = {{box2, box2, box1},{'0', '0', ' '}};
int playerHealth=0;
int bulletSpeed;

// Player Coordinates
int tankX=0;
int tankY=0;

// resetbullet
void bulletcountreset();

// variables of e1
int bulletCountE1 = 0;
int bulletE1X[10000];
int bulletE1Y[10000];
bool isActiveE1[10000];
int bulletE1Speed;

// Cordinated of enemy1
int enemyX=0;
int enemyY=0;

// Functions of Enemy1

string enemydirection = "left";
void moveenemy();
void erEnemy1(int x, int y);
void printE1(int x, int y);
void colision();
void generatebulletE1();
void movebulletE1();
void printbulletE1(int x, int y);
void erasebulletE1(int x, int y);

// variables of e2
int bulletCountE2 = 0;
int bulletE2X[10000];
int bulletE2Y[10000];
bool isActiveE2[10000];
int bulletE2Speed;


// Cordinated of enemy2
int enemy2X=0;
int enemy2Y=0;
int randomSpeed2 = 0;
int random;
int e2Speed;

// Functions of enemy2

void moveEnemy2();
void erEnemy2(int x, int y);
void printE2(int x, int y);
void colisionE2();
void generatebulletE2();
void movebulletE2();
void printbulletE2(int x, int y);
void erasebulletE2(int x, int y);

// variables of e3
int bulletCountE3 = 0;
int bulletE3X[10000];
int bulletE3Y[10000];
bool isActiveE3[10000];
int bulletE3Speed;


					
// Cordinated of enemy3
int enemy3X=0;
int enemy3Y=0;
int e3Speed;

// Functions of enemy3

void moveenemy3();
void erenemy3(int x, int y);
void printE3(int x, int y);
void colisionE3();
void generatebulletE3();
void movebulletE3();
void printbulletE3(int x, int y);
void erasebulletE3(int x, int y);

// variables of e4
int bulletCountE4 = 0;
int bulletE4X[10000];
int bulletE4Y[10000];
bool isActiveE4[10000];
int bulletE4Speed;

// Cordinated of enemy4
int enemy4X=0;
int enemy4Y=0;

// Functions of Enemy4

string enemy4direction = "down";
void moveenemy4();
void erEnemy4(int x, int y);
void printE4(int x, int y);
void colisionE4();
void generatebulletE4();
void movebulletE4();
void printbulletE4(int x, int y);
void erasebulletE4(int x, int y);

// Score
void Printscore();
int Score=0;

//enemyhealth
int e1health=0;
int e2health=0;
int e3health=0;
int e4health=0;
void Printe1health();
void Printe2health();
void Printe3health();
void Printe4health();
void Printplayerhealth();
// pre defined function
char getCharAtxy(short int x, short int y);
void gotoxy(int x, int y);

//file handling
string getfield(string record, int field);
void loadmaze();
void loadgamedata();
void storemaze();
void savegamedata();
void printmaze();

//maze
char maze[30][76];
void asking();
string menu();
void newcordinates();

//starting of game code
string menu()
{
		string option;
			    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
		cout<<" Select any Option....."<<endl<<endl;
		cout<<" 1. New Game."<<endl;
		cout<<" 2. Load saved Game."<<endl;
		cout<<" 3. Exit."<<endl;
		cout<<" Select: ";
		cin>>option;
		return option;
}
void submenu()
{

	string option;
	while(option != "3")
	{
		system("cls");
		header();
	
		option = menu();
		if(option == "1")
		{
			newcordinates();
			system("cls");
			startgame();
			break;
		}
		if(option == "2")
		{
			clear();
			loadgamedata();
			if(tankX==0)
			{
				cout<<"Nothing Has Been Saved Yet...."<<endl;
				continue;
			}
			else
			{
				gameRunning = true;
				startgame();
				break;
			}
		}
	}
}
void newcordinates()
{
				tankX = 5;
			tankY = 5;
			enemyX = 4;
			enemyY = 2;
			enemy2X = 35;
			enemy2Y = 17;
			enemy3X = 35;
			enemy3Y = 9;
			enemy4X = 70;
			enemy4Y = 4;
			Score = 0;
			e1health =100;
			e2health =100;
			e3health =100;
			e4health =100;
			count = 2;
			playerHealth =50;
			gameRunning = true;
}
main()
{
    system("cls");
    header();
    starting();
    string option;
    while (option != "3")
    {
        system("cls");
        header();
        option = Mainpg();
        if (option == "1")
        {
			submenu();
        }
        if (option == "2")
        {
            options();
        }
    }
    clear();
}

string Mainpg()
{
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    string option;
    cout << " Select any of the following option............." << endl<< endl;
    cout << " 1. START" << endl;
    cout << " 2. OPTION" << endl;
    cout << " 3. EXIT" << endl;
    cout << " Select: ";
    cin >> option;
    return option;
}
string options()
{
    string option1;
    clear();
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    while (option1 != "3")
    {
        // system("cls");
        header();
        cout << " Select any of the following option...................." << endl<< endl;
        cout << " 1. KEYS" << endl;
        cout << " 2. INSTRUCTION" << endl;
        cout << " 3. Main Menu" << endl;
        cout << " 4. Exit" << endl;
        cout << " Select :";
        cin >> option1;
        if (option1 == "1")
        {
            keys();
        }
        if (option1 == "2")
        {
            instruction();
        }
        if (option1 == "4")
        {
            clear();
            exit(0);
        }
        clear();
    }
}
void keys()
{
    system("cls");
    header();
    cout << "             " << endl;
    cout << "*********       KEYS        *********" << endl;
    cout << "_____________________________________" << endl<< endl;
    cout << "1. UP                    GO UP " << endl;
    cout << "2. Down                  Go down" << endl;
    cout << "3. Left                  GO left " << endl;
    cout << "4. Right                 GO right " << endl;
    cout << "5. Space                 Right Shoot Fire " << endl;
    cout << "6. Shift                 Left Shoot Fire " << endl;
    cout << "7. Esc                   End game" << endl<< endl;
}
void instruction()
{
    system("cls");
    header();
    cout << "*******    INSTRUCTION    *********" << endl;
    cout << "_____________________________________" << endl <<endl;
	cout << " 1. Kill All enemies to win."<<endl;
	cout << " 2. If player health become zero game will be over."<< endl<< endl;
}
void clear()
{
    cout << "Press any key to continue..........";
    getch();
    system("cls");
}
void header()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    cout << "$$$$$$$$\\                  $$\\          $$$$$$$\\                        $$\\                             $$$$$$\\                                    " << endl;
    cout << "\\__$$  __|                 $$ |         $$  __$$\\                       $$ |                           $$  __$$\\                                   " << endl;
    cout << "   $$ | $$$$$$\\  $$$$$$$\\  $$ |  $$\\    $$ |  $$ |$$\\   $$\\  $$$$$$$\\ $$$$$$\\    $$$$$$\\   $$$$$$\\     $$ //  \\_|$$\\   $$\\ $$$$$$\\$$$$\\   $$$$$$\\  " << endl;
    cout << "   $$ | \\____$$\\ $$  __$$\\ $$ | $$  |   $$$$$$$\\ |$$ |  $$ |$$  _____|\\_$$  _|  $$  __$$\\ $$  __$$\\    \\$$$$$$\\  $$ |  $$ |$$  _$$  _$$\\  \\____$$\\ " << endl;
    cout << "   $$ | $$$$$$$ |$$ |  $$ |$$$$$$  /    $$  __$$\\ $$ |  $$ |\\$$$$$$\\    $$ |    $$$$$$$$ |$$ |  \\__|    \\____$$\\ $$ |  $$ |$$ / $$ / $$ | $$$$$$$ |" << endl;
    cout << "   $$ |$$  __$$ |$$ |  $$ |$$  _$$<     $$ |  $$ |$$ |  $$ | \\____$$\\   $$ |$$\\ $$   ____|$$ |         $$\\   $$ |$$ |  $$ |$$ | $$ | $$ |$$  __$$ |" << endl;
    cout << "   $$ |\\$$$$$$$ |$$ |  $$ |$$ | \\$$\\    $$$$$$$  |\\$$$$$$  |$$$$$$$ |   \\$$$$  |\\$$$$$$$\\ $$ |         \\$$$$$$  |\\$$$$$$  |$$ | $$ | $$ |\\$$$$$$$ |" << endl;
    cout << "   \\__| \\_______|\\__|  \\__|\\__|  \\__|   \\_______// \\______/ \\_______/    \\____/  \\_______|\\__|          \\______/  \\______/ \\__| \\__| \\__| \\_______|" << endl;
    cout << endl
         << endl;
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 8);
}
void startgame()
{
    system("cls");
    header();
    ready();
	bulletcountreset();
    storemaze();
	loadmaze();
	printmaze();
    tankp();
    printE1(enemyX, enemyY);
    printE2(enemy2X, enemy2Y);
    while (gameRunning == true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generatebullet();
        }
		if (GetAsyncKeyState(VK_SHIFT))
        {
            generatebulletl();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
			asking();
            gameRunning = false;
        }
		 if (playerHealth <= 0)
		{
		    Printplayerhealth();
		}
        Printscore();
        Printplayerhealth();
	

        if(e1health >0)
		{
			moveenemy();
        	generatebulletE1();
			Printe1health();
		}
		else
		{
			e1health =0;
			Printe1health();
			erEnemy1(enemyX,enemyY);
			enemyX = 80;
			enemyY = 40;
			
		}
        if(e2health >0)
		{        
			moveEnemy2();
			generatebulletE2();
			Printe2health();
		}
		else
		{
			e2health =0;
			Printe2health();
			erEnemy2(enemy2X,enemy2Y);
			enemy2X = 80;
			enemy2Y = 40;
		}
		if(e1health <= 0 && e2health <=0)
		{
			printE3(enemy3X, enemy3Y);
			printE4(enemy4X, enemy4Y);
			if(e3health > 0)
			{
				moveenemy3();
				generatebulletE3();
				Printe3health();
			}
			else
			{
							e3health =0;
			Printe3health();
				erenemy3(enemy3X,enemy3Y);
				enemy3X = 80;
				enemy3Y = 40;
			}
			if(e4health >0)
			{
				moveenemy4();
				generatebulletE4();
				Printe4health();
			}
			else
			{
							e4health =0;
			Printe4health();
				erEnemy4(enemy4X,enemy4Y);
				enemy4X = 80;
				enemy4Y = 40;				
			}
		}
		if(e1health == 0 && e2health == 0 && e3health ==0 && e4health ==0)
		{
			ending();
			gameRunning = false;
		}
		        Printplayerhealth();
        movebullet();
		movebulletl();
        collisionPlayer();
        colision();
        colisionE2();
        colisionE3();
        colisionE4();
			movebulletE3();
			movebulletE2();
			movebulletE1();
			movebulletE4();

        Sleep(50);
    }
}
void asking()
{
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    system("cls");
    header();
	string opt;
	cout<<" Select Any Option....."<<endl<<endl;
	cout<<" 1. Save Game."<<endl;
	cout<<" 2. Continue without saving."<<endl;
	cout<<" Select: "<<endl;
	cin>>opt;
	if(opt == "1")
	{
		savegamedata();
		clear();
	}
	else if(opt == "2")
	{
		clear();
	}
	else
	{
		asking();
	}
}
void erase()
{
    for (int x = 0; x < 3; x++)
    {

        gotoxy(tankX + x, tankY);
        cout << " ";
    }
    cout << endl;
    for (int x = 0; x < 3; x++)
    {

        gotoxy(tankX + x, tankY + 1);
        cout << " ";
    }
}
void Printscore()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    gotoxy(10, 0);
    cout << "Score = " << Score;
}
void tankp()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    gotoxy(tankX, tankY);
	for (int index = 0; index < 2; index++)
	{
		gotoxy(tankX, tankY+index);
		for (int x = 0; x < 3; x++)
		{
			cout << tank[index][x];
		}
    }
}
// moving
void moveLeft()
{
    char next1 = getCharAtxy(tankX - 1, tankY + 1);
    char nextLocation = getCharAtxy(tankX - 1, tankY);
    if (nextLocation == ' ' && next1 == ' ')
    {
        erase();
        tankX = tankX - 1;
        tankp();
    }
	

}
void moveRight()
{
    char next2 = getCharAtxy(tankX + 3, tankY + 1);
    char nextLocation = getCharAtxy(tankX + 3, tankY);
    if (nextLocation == ' ' && next2 == ' ')
    {
        erase();
        tankX = tankX + 1;
        tankp();
    }
}
void moveUp()
{

    char next1 = getCharAtxy(tankX + 1, tankY - 1);
    char next2 = getCharAtxy(tankX + 2, tankY - 1);
    char nextLocation = getCharAtxy(tankX, tankY - 1);
    if (nextLocation == ' ' && next1 == ' ' && next2 == ' ')
    {
        erase();
        tankY = tankY - 1;
        tankp();
    }
}
void moveDown()
{
    char next1 = getCharAtxy(tankX + 1, tankY + 2);
    char next2 = getCharAtxy(tankX + 2, tankY + 2);
    char nextLocation = getCharAtxy(tankX, tankY + 2);
    if (nextLocation == ' ' && next1 == ' ' && next2 == ' ')
    {
        erase();
        tankY = tankY + 1;
        tankp();
    }
}
// Print Health of Player
void Printplayerhealth()
{
    if (playerHealth <= 0 && count > 0)
    {
        count--;
        playerHealth = 50;
    }
    if (count <= 0 && playerHealth <= 0)
    {
		ending();
		gameRunning = false;
		clear();
    }
    gotoxy(77, 2);
    cout << "LIVES OF PLAYER ARE = ";
    for (int x = 0; x < count+1; x++)
    {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
        gotoxy(99 + 2 * x, 2);
        cout << heart << "  ";
    }
    gotoxy(50, 0);
    cout << "HEALTH OF PLAYER IS = " << playerHealth << " " << endl;
}
void ready()
{
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    cout << "    ___                    __  __     ____                        " << endl;
    cout << "   /   |  ____ ___        / / / /    / __ \\___   ____ ______/ _   __" << endl;
    cout << "  / /| | / ___/ _ \\      / / / /    / /_/ / _ \\/ __ `/ __  / / / / /" << endl;
    cout << " / ___ |/ /  /  __/     / /_/ /    / _, _/  __/ /_/ / /_/ / / /_/_/  " << endl;
    cout << "/_/  |_/_/   \\___/      \\____/    /_/ |_|\\___/\\__,_/\\__,_/  \\__,_/  " << endl;
    cout << "                                                         /____/   " << endl;
    Sleep(1000);
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void starting()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    char n = 219;
    cout << "                                                     _..----.._                                   " << endl;
    cout << "                                                    ]_.--._____[                                  " << endl;
    cout << "                                                  ___|'--'__..|--._                               " << endl;
    cout << "                              __               '''    ;            :                              " << endl;
    cout << "                            ()_ ''''---...__.'''!':  /    ___       :                             " << endl;
    cout << "                               '''---..._\\]..__] | /    [ 0 ]      :                             " << endl;
    cout << "                                          '''!--./ /      '''        :                            " << endl;
    cout << "                                   __  ...._____;'''.__________..--..:_                           " << endl;
    cout << "                                  /  !'''''''!''''''''''|''''/' ' ' '\\'--..__  __..              " << endl;
    cout << "                                 /  /.--.    |          |  .'         \\' ' '.''--.{'.            " << endl;
    cout << "             _...__            >=7 //.-.:    |          |.'            \\ ._.__  ' ''''.          " << endl;
    cout << "          .-' /    ''''----..../ ''>==7-.....:______    |               \\| |  '';.;-'>\\         " << endl;
    cout << "          '''';           __..'   .--'/'''''----....'''''----.....H______\\_!....'----'''']       " << endl;
    cout << "        _..---|._ __..--''       _!.-=_.            '''''''''''''''                   ;'''        " << endl;
    cout << "       /   .-';-.'--...___     .' .-''; ';''-''-...^..__...-v.^___,  ,__v.__..--^'--''-v.^v,      " << endl;
    cout << "      ;   ;   |'.         '''-/ /;  ;   ;\\P.        ;   ;        ''''____;  ;.--''''// '''<,     " << endl;
    cout << "      ;   ;   | 1            ;  ;  '.: .'  ;<   ___.-'._.'------''''''____'..'.--''';;'  o ';     " << endl;
    cout << "      '.  \\__:/__           ;  ;--''()_   ;'  /___ .-' ____---''''''' __.._ __._   '>.,  ,/;     " << endl;
    cout << "        \\  \\    /'''<--...__;  '_.-'/; ''; ;.'.'  '-..'    '-.      /'/    `__. '.   '---';      " << endl;
    cout << "         '.  'v ; ;     ;;   \\ \\ .' \\ ; ////    _.-' '-._   ;    : ;   .-'__ '. ;   .^'.'      " << endl;
    cout << "           '.  '; '.   .'/     '. `-.__.' /;;;   .o__.---.__o. ;    : ;   ';;;;;;' ;v^; .^        " << endl;
    cout << "             '-. '-.___.'<__v.^,v'.  '-.-' ;|:   '    :      ` ;v^v^'.'.    .;'.__/_..-'          " << endl;
    cout << "                '-...__.___...---'''-.   '-'.;\\    'WW\\    .'_____..>.'^'-''''''''              " << endl;
    cout << "                                      '--..__ ''._..'  ''-;;;;;                                   " << endl;
    cout << "                                             ------'------                                        " << endl
         << endl;
    cout << "              LOADING   ";
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(500);
    cout << n;
    Sleep(2000);
}

// right side firing
void generatebullet()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
	if (bulletSpeed % 1 == 0)
    {
    bulletX[bulletCount] = tankX + 3;
    bulletY[bulletCount] = tankY;
    char next = getCharAtxy(bulletX[bulletCount], bulletY[bulletCount]);
    if (next == ' ')
    {
        gotoxy(bulletX[bulletCount], bulletY[bulletCount]);
        cout << "*";
        isActive[bulletCount] = true;
        bulletCount++;
    }
	}
	bulletSpeed++;
}
void movebullet()
{
		for (int x = 0; x < bulletCount; x++)
		{
			if (isActive[x] == true)
			{
				char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);

				if (next != ' ' || next == '*')
				{
					erasebullet(bulletX[x], bulletY[x]);
					isActive[x] = false;
				}
				else if (next == ' ')
				{
					erasebullet(bulletX[x], bulletY[x]);
					bulletX[x] = bulletX[x] + 1;
					printbullet(bulletX[x], bulletY[x]);
				}
			}
		}
}
void printbullet(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    gotoxy(x, y);
    cout << "*";
}
void erasebullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
// leftbullet
void generatebulletl()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    bulletXl[bulletcountl] = tankX - 1;
    bulletYl[bulletcountl] = tankY;
    char next = getCharAtxy(bulletXl[bulletCount], bulletYl[bulletCount]);
    if (next == ' ')
    {
		isbulletActivel[bulletcountl] = true;
		gotoxy(tankX-1, tankY);
		cout << "*";
		bulletcountl++;
	}
}
void makebulletInactivel(int index)
{
    isbulletActivel[index] = false;
}
void movebulletl()
{
    for (int x = 0; x < bulletcountl; x++)
    {
        if (isbulletActivel[x] == true)
        {
            char next = getCharAtxy(bulletXl[x] - 1, bulletYl[x]);
            if (next != ' ')
            {
                erasebullet(bulletXl[x], bulletYl[x]);
                makebulletInactivel(x);
            }
            else
            {
                erasebullet(bulletXl[x], bulletYl[x]);
                bulletXl[x] = bulletXl[x] - 1;
                printbullet(bulletXl[x], bulletYl[x]);
            }
        }
    }
}
void collisionPlayer()
{
    for (int x = 0; x < bulletCountE1; x++)
    {
        if (isActiveE1[x] == true)
        {
            if ((bulletE1X[x] == tankX + 3 && bulletE1Y[x] == tankY))
            {
                playerHealth = playerHealth-5;
            }
            if ((bulletE1X[x] == tankX + 3 && bulletE1Y[x] == tankY + 1))
            {
                playerHealth = playerHealth-5;
            }
        }
    }
    for (int x = 0; x < bulletCountE2; x++)
    {
        if (isActiveE2[x] == true)
        {
            if ((bulletE2X[x] == tankX + 3 && bulletE2Y[x] == tankY))
            {
                playerHealth = playerHealth-5;
            }
            if ((bulletE2X[x] == tankX + 3 && bulletE2Y[x] == tankY + 1))
            {
                playerHealth = playerHealth-5;
            }
        }
    }
    for (int x = 0; x < bulletCountE3; x++)
    {
        if (isActiveE3[x] == true)
        {
            if ((bulletE3X[x] == tankX + 3 && bulletE3Y[x] == tankY))
            {
                playerHealth = playerHealth-5;
            }
            if ((bulletE3X[x] == tankX + 3 && bulletE3Y[x] == tankY + 1))
            {
                playerHealth = playerHealth-5;
            }
        }
    }
	for (int x = 0; x < bulletCountE4; x++)
    {
        if (isActiveE4[x] == true)
        {
            if ((bulletE4X[x] == tankX + 3 && bulletE4Y[x] == tankY))
            {
                playerHealth = playerHealth-5;
            }
            if ((bulletE4X[x] == tankX + 3 && bulletE4Y[x] == tankY + 1))
            {
                playerHealth = playerHealth-5;
            }
        }
    }
}



// E1

void bulletcountreset()
{
	bulletCount=0;
	bulletCountE1=0;
	bulletCountE2=0;
	bulletCountE3=0;
	bulletCountE4=0;
}
void moveenemy()
{
    if (enemydirection == "left")
    {
        char next = getCharAtxy(enemyX - 1, enemyY);
        char next2 = getCharAtxy(enemyX - 1, enemyY + 1);
        if ((next == ' ' && next2 == ' ') || (next == '*' && next2 == '*') )
        {
            erEnemy1(enemyX, enemyY);
            enemyX--;
            printE1(enemyX, enemyY);
        }
        if (next == '|' || next2 == '|')
        {
            enemydirection = "right";
        }
		if (next == box1 || next2 == box1 || next == box || next2 == box)
        {
            enemydirection = "right";
		}
		if (next == box1 || next2 == box1 || next == '0' || next2 == '0')
        {
			playerHealth = playerHealth -5;
		}
    }
    if (enemydirection == "right")
    {
        char next = getCharAtxy(enemyX + 3, enemyY);
        char next2 = getCharAtxy(enemyX + 3, enemyY + 1);
        if (next == ' ' && next2 == ' ')
        {
            erEnemy1(enemyX, enemyY);
            enemyX++;
            printE1(enemyX, enemyY);
        }
        if (next == '|' || next2 == '|')
        {
            enemydirection = "left";
        }
		if(next == box2 || next2 == box2 || next == box3 || next2 == box3)
		{
            enemydirection = "left";
		}
		if (next == box2 || next2 == box2 || next == '0' || next2 == '0')
        {
			playerHealth = playerHealth -5;
		}
    }
}

void erEnemy1(int x, int y)
{
    for (int x = 0; x < 3; x++)
    {
        gotoxy(enemyX + x, enemyY);
        cout << " ";
    }
    for (int x = 0; x < 3; x++)
    {

        gotoxy(enemyX + x, enemyY + 1);
        cout << " ";
    }
}

void printE1(int x, int y)
{
	// Enemy1 Character
char enemy1[3][3] = {{box3 , box , box},
					{'\\', '0', '/'}};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);	
    gotoxy(x,y);
	for (int index = 0; index < 2; index++)
	{
		gotoxy(x,y+index);
		for (int x = 0; x < 3; x++)
		{
			cout << enemy1[index][x];
		}
    }
}

void colision()
{
if(e1health > 0)
{	
    for (int x = 0; x < bulletCount; x++)
    {
        if (isActive[x] == true)
        {
            if ((bulletX[x] == enemyX - 1 && bulletY[x] == enemyY))
            {
                Score++;
				e1health = e1health-2;
            }
            if ((bulletX[x] == enemyX - 1 && bulletY[x] == enemyY + 1))
            {
                Score++;
				e1health = e1health-2;
            }
        }
    }
		
		//left side collision
    for (int x = 0; x < bulletcountl; x++)
    {		
		if (isbulletActivel[x] == true)
        {
            if ((bulletXl[x] == enemyX +3 && bulletYl[x] == enemyY))
            {
                Score++;
				e1health = e1health-2;
            }
            if ((bulletXl[x] == enemyX +3 && bulletYl[x] == enemyY + 1))
            {
                Score++;
				e1health = e1health-2;
            }
        }
	}
}
}
void generatebulletE1()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    if (bulletE1Speed % 2 == 0)
    {
        bulletE1X[bulletCountE1] = enemyX - 1;
        bulletE1Y[bulletCountE1] = enemyY;
        char next = getCharAtxy(bulletE1X[bulletCountE1], bulletE1Y[bulletCountE1]);
        if (next == ' ')
        {
            gotoxy(bulletE1X[bulletCountE1], bulletE1Y[bulletCountE1]);
            cout << "+";
            isActiveE1[bulletCountE1] = true;
            bulletCountE1++;
        }
    }
    bulletE1Speed++;
}

void movebulletE1()
{
    for (int x = 0; x < bulletCountE1; x++)
    {
        if (isActiveE1[x] == true)
        {
            char next = getCharAtxy(bulletE1X[x] - 1, bulletE1Y[x]);

            if (next != ' ')
            {
                erasebulletE1(bulletE1X[x], bulletE1Y[x]);
                isActiveE1[x] = false;
            }
            else if (next == ' ' || next == '*' || next == '+')
            {
                erasebulletE1(bulletE1X[x], bulletE1Y[x]);
                bulletE1X[x] = bulletE1X[x] - 1;
                printbulletE1(bulletE1X[x], bulletE1Y[x]);
            }
        }
    }
}
void printbulletE1(int x, int y)
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    gotoxy(x, y);
    cout << "+";
}
void erasebulletE1(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

// e2
void moveEnemy2()
{
    if (randomSpeed2 % 12 == 0)
    {
        random = rand() % 4;
    }
    if (e2Speed % 3 == 0)
    {
        if (random == 0)
        {
            char next = getCharAtxy(enemy2X - 1, enemy2Y);
            char next2 = getCharAtxy(enemy2X - 1, enemy2Y + 1);
            if (next == ' ' && next2 == ' ')
            {
                erEnemy2(enemy2X, enemy2Y);
                enemy2X--;
                printE2(enemy2X, enemy2Y);
            }
			if (next == box1 || next2 == box1 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -5;
			}
			if (next == box2 || next2 == box2 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -5;
			}	
        }

        if (random == 1)
        {
            char next = getCharAtxy(enemy2X + 3, enemy2Y);
            char next2 = getCharAtxy(enemy2X + 3, enemy2Y + 1);
            if (next == ' ' && next2 == ' ')
            {
                erEnemy2(enemy2X, enemy2Y);
                enemy2X++;
                printE2(enemy2X, enemy2Y);
            }
			if (next == box1 || next2 == box1 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -5;
			}
			if (next == box2 || next2 == box2 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -5;
			}	
        }
        if (random == 2)
        {
            char next = getCharAtxy(enemy2X, enemy2Y - 1);
            char next2 = getCharAtxy(enemy2X + 1, enemy2Y - 1);
            char next3 = getCharAtxy(enemy2X + 2, enemy2Y - 1);
            if (next == ' ' && next2 == ' ' && next3 == ' ')
            {
                erEnemy2(enemy2X, enemy2Y);
                enemy2Y--;
                printE2(enemy2X, enemy2Y);
            }
			if (next == box1 || next2 == box1 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -5;
			}
			if (next == box2 || next2 == box2 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -5;
			}				
        }
        if (random == 3)
        {
            char next = getCharAtxy(enemy2X, enemy2Y + 2);
            char next2 = getCharAtxy(enemy2X + 1, enemy2Y + 2);
            char next3 = getCharAtxy(enemy2X + 2, enemy2Y + 2);
            if (next == ' ' && next2 == ' ' && next3 == ' ')
            {
                erEnemy2(enemy2X, enemy2Y);
                enemy2Y++;
                printE2(enemy2X, enemy2Y);
            }
			if (next == box1 || next2 == box1 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -5;
			}
			if (next == box2 || next2 == box2 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -5;
			}				
        }
    }
    e2Speed++;
    randomSpeed2++;
}

void erEnemy2(int x, int y)
{
    for (int x = 0; x < 3; x++)
    {
        gotoxy(enemy2X + x, enemy2Y);
        cout << " ";
    }
    for (int x = 0; x < 3; x++)
    {

        gotoxy(enemy2X + x, enemy2Y + 1);
        cout << " ";
    }
}

void printE2(int x, int y)
{
	// enemy2 Character
char enemy2[3][3] = {{box3 , box , box},
					{'<', '0', '/'}};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);	
    gotoxy(x,y);
	for (int index = 0; index < 2; index++)
	{
		gotoxy(x,y+index);
		for (int x = 0; x < 3; x++)
		{
			cout << enemy2[index][x];
		}
    }
}

void colisionE2()
{
	if(e2health > 0)
	{
		for (int x = 0; x < bulletCount; x++)
		{
			if (isActive[x] == true)
			{
				if ((bulletX[x] == enemy2X - 1 && bulletY[x] == enemy2Y))
				{
					Score++;
					e2health = e2health-2;
				}
				if ((bulletX[x] == enemy2X - 1 && bulletY[x] == enemy2Y + 1))
				{
					Score++;
					e2health = e2health-2;
				}
			}
		}
		
		//left side collision
		for (int x = 0; x < bulletcountl; x++)
		{		
			if (isbulletActivel[x] == true)
			{
				if ((bulletXl[x] == enemy2X +3 && bulletYl[x] == enemy2Y))
				{
					Score++;
					e2health = e2health-2;
				}
				if ((bulletXl[x] == enemy2X +3 && bulletYl[x] == enemy2Y + 1))
				{
					Score++;
					e2health = e2health-2;
				}
			}
		}
	}
}
void generatebulletE2()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    if (bulletE2Speed % 10 == 0)
    {
        bulletE2X[bulletCountE2] = enemy2X - 1;
        bulletE2Y[bulletCountE2] = enemy2Y;
        char next = getCharAtxy(bulletE2X[bulletCountE2], bulletE2Y[bulletCountE2]);
        if (next == ' ')
        {
            gotoxy(bulletE2X[bulletCountE2], bulletE2Y[bulletCountE2]);
            cout << "+";
            isActiveE2[bulletCountE2] = true;
            bulletCountE2++;
        }
    }
    bulletE2Speed++;
}

void movebulletE2()
{
    for (int x = 0; x < bulletCountE2; x++)
    {
        if (isActiveE2[x] == true)
        {
            char next = getCharAtxy(bulletE2X[x] - 1, bulletE2Y[x]);

            if (next != ' ')
            {
                erasebulletE2(bulletE2X[x], bulletE2Y[x]);
                isActiveE2[x] = false;
            }
            else if (next == ' ')
            {
                erasebulletE2(bulletE2X[x], bulletE2Y[x]);
                bulletE2X[x] = bulletE2X[x] - 1;
                printbulletE2(bulletE2X[x], bulletE2Y[x]);
            }
        }
    }
}
void printbulletE2(int x, int y)
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);;
    gotoxy(x, y);
    cout << "+";
}
void erasebulletE2(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

// E3

void moveenemy3()
{

    if (e3Speed % 4 == 0)
    {
        if (enemy3X > tankX)
        {
            char next = getCharAtxy(enemy3X - 1, enemy3Y);
            char next2 = getCharAtxy(enemy3X - 1, enemy3Y + 1);
            if (next == ' ' && next2 == ' ')
            {
                erenemy3(enemy3X, enemy3Y);
                enemy3X--;
                printE3(enemy3X, enemy3Y);
            }
			if (next == box1 || next2 == box1 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -1;
			}
			if (next == box2 || next2 == box2 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -1;
			}				
        }

        if (enemy3X < tankX)
        {
            char next = getCharAtxy(enemy3X + 3, enemy3Y);
            char next2 = getCharAtxy(enemy3X + 3, enemy3Y + 1);
            if (next == ' ' && next2 == ' ')
            {
                erenemy3(enemy3X, enemy3Y);
                enemy3X++;
                printE3(enemy3X, enemy3Y);
            }
			if (next == box1 || next2 == box1 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -1;
			}
			if (next == box2 || next2 == box2 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -1;
			}				
        }
        if (enemy3Y > tankY)
        {
            char next = getCharAtxy(enemy3X, enemy3Y - 1);
            char next2 = getCharAtxy(enemy3X + 1, enemy3Y - 1);
            char next3 = getCharAtxy(enemy3X + 2, enemy3Y - 1);
            if (next == ' ' && next2 == ' ' && next3 == ' ')
            {
                erenemy3(enemy3X, enemy3Y);
                enemy3Y--;
                printE3(enemy3X, enemy3Y);
            }
			if (next == box1 || next2 == box1 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -1;
			}
			if (next == box2 || next2 == box2 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -1;
			}	
        }
        if (enemy3Y < tankY)
        {
            char next = getCharAtxy(enemy3X, enemy3Y + 2);
            char next2 = getCharAtxy(enemy3X + 1, enemy3Y + 2);
            char next3 = getCharAtxy(enemy3X + 2, enemy3Y + 2);
            if (next == ' ' && next2 == ' ' && next3 == ' ')
            {
                erenemy3(enemy3X, enemy3Y);
                enemy3Y++;
                printE3(enemy3X, enemy3Y);
            }
			if (next == box1 || next2 == box1 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -1;
			}
			if (next == box2 || next2 == box2 || next == '0' || next2 == '0')
			{
				playerHealth = playerHealth -1;
			}	
        }
    }
    e3Speed++;
}

void erenemy3(int x, int y)
{
    for (int x = 0; x < 3; x++)
    {
        gotoxy(enemy3X + x, enemy3Y);
        cout << " ";
    }
    for (int x = 0; x < 3; x++)
    {

        gotoxy(enemy3X + x, enemy3Y + 1);
        cout << " ";
    }
}

void printE3(int x, int y)
{
	// enemy3 Character
char enemy3[3][3] = {{box3 , box , box},
					{'<', '=', ']'}};
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,11);	
    gotoxy(x,y);
	for (int index = 0; index < 2; index++)
	{
		gotoxy(x,y+index);
		for (int x = 0; x < 3; x++)
		{
			cout << enemy3[index][x];
		}
    }
}

void colisionE3()
{
if(e3health > 0)
{	
    for (int x = 0; x < bulletCount; x++)
    {
        if (isActive[x] == true)
        {
            if ((bulletX[x] == enemy3X - 1 && bulletY[x] == enemy3Y))
            {
                Score++;
				e3health = e3health-2;
            }
            if ((bulletX[x] == enemy3X - 1 && bulletY[x] == enemy3Y + 1))
            {
                Score++;
				e3health = e3health-2;
            }
        }
		
				//left side collision
		for (int x = 0; x < bulletcountl; x++)
		{		
			if (isbulletActivel[x] == true)
			{
				if ((bulletXl[x] == enemy3X +3 && bulletYl[x] == enemy3Y))
				{
					Score++;
					e3health = e3health-2;
				}
				if ((bulletXl[x] == enemy3X +3 && bulletYl[x] == enemy3Y + 1))
				{
					Score++;
					e3health = e3health-2;
				}
			}
		}
    }
}
}
void generatebulletE3()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    if (bulletE3Speed % 10 == 0)
    {
        bulletE3X[bulletCountE3] = enemy3X - 1;
        bulletE3Y[bulletCountE3] = enemy3Y;
        char next = getCharAtxy(bulletE3X[bulletCountE3], bulletE3Y[bulletCountE3]);
        if (next == ' ')
        {
            gotoxy(bulletE3X[bulletCountE3], bulletE3Y[bulletCountE3]);
            cout << "+";
            isActiveE3[bulletCountE3] = true;
            bulletCountE3++;
        }
    }
    bulletE3Speed++;
}

void movebulletE3()
{
    for (int x = 0; x < bulletCountE3; x++)
    {
        if (isActiveE3[x] == true)
        {
            char next = getCharAtxy(bulletE3X[x] - 1, bulletE3Y[x]);

            if (next != ' ')
            {
                erasebulletE3(bulletE3X[x], bulletE3Y[x]);
                isActiveE3[x] = false;
            }
            else if (next == ' ')
            {
                erasebulletE3(bulletE3X[x], bulletE3Y[x]);
                bulletE3X[x] = bulletE3X[x] - 1;
                printbulletE3(bulletE3X[x], bulletE3Y[x]);
            }
        }
    }
}
void printbulletE3(int x, int y)
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    gotoxy(x, y);
    cout << "+";
}
void erasebulletE3(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}


// E4

void moveenemy4()
{
    if (enemy4direction == "down")
    {
        char next = getCharAtxy(enemy4X, enemy4Y+2);
        char next1 = getCharAtxy(enemy4X+1, enemy4Y + 2);
        char next2 = getCharAtxy(enemy4X+2, enemy4Y + 2);
        if ((next == ' ' && next2 == ' ' && next1 == ' ')||(next == '*' && next2 == '*' && next1 == '*'))
        {
            erEnemy4(enemy4X, enemy4Y);
            enemy4Y++;
            printE4(enemy4X, enemy4Y);
        }
        if (next == '#' || next2 == '#'|| next2 == '#')
        {
            enemy4direction = "up";
        }
		if (next == box2 || next2 == box1 || next1 == box2)
        {
            enemy4direction = "up";
		}
		if (next == box2 || next2 == box1 || next1 == box2)
        {
			playerHealth = playerHealth -5;
		}
    }
    if (enemy4direction == "up")
    {
        char next = getCharAtxy(enemy4X , enemy4Y-1);
        char next1 = getCharAtxy(enemy4X +1, enemy4Y -1);
        char next2 = getCharAtxy(enemy4X + 2, enemy4Y - 1);
        if ((next == ' ' && next2 == ' ' && next1 == ' ') || (next == '*' && next2 == '*' && next1 == '*'))
        {
            erEnemy4(enemy4X, enemy4Y);
            enemy4Y--;
            printE4(enemy4X, enemy4Y);
        }
        if (next == '#' || next2 == '#'|| next2 == '#')
        {
            enemy4direction = "down";
        }
		if (next == '0' || next1 == '0' || next == box1)
        {
            enemy4direction = "down";
		}
		if (next == '0' || next1 == '0' || next == box1)
        {
			playerHealth = playerHealth -5;
		}
    }
}

void erEnemy4(int x, int y)
{
    for (int x = 0; x < 3; x++)
    {
        gotoxy(enemy4X + x, enemy4Y);
        cout << " ";
    }
    for (int x = 0; x < 3; x++)
    {

        gotoxy(enemy4X + x, enemy4Y + 1);
        cout << " ";
    }
}

void printE4(int x, int y)
{
	// Enemy1 Character
char enemy4[3][3] = {{box3 , box , box},
					{'0', '0', '0'}};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);	
    gotoxy(x,y);
	for (int index = 0; index < 2; index++)
	{
		gotoxy(x,y+index);
		for (int x = 0; x < 3; x++)
		{
			cout << enemy4[index][x];
		}
    }
}

void colisionE4()
{
if(e4health > 0)
{	
    for (int x = 0; x < bulletCount; x++)
    {
        if (isActive[x] == true)
        {
            if ((bulletX[x] == enemy4X - 1 && bulletY[x] == enemy4Y))
            {
                Score++;
				e4health = e4health-2;
            }
            if ((bulletX[x] == enemy4X - 1 && bulletY[x] == enemy4Y + 1))
            {
                Score++;
				e4health = e4health-2;
            }
        }
    }
		
}
}
void generatebulletE4()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    if (bulletE4Speed % 2 == 0)
    {
        bulletE4X[bulletCountE4] = enemy4X - 1;
        bulletE4Y[bulletCountE4] = enemy4Y;
        char next = getCharAtxy(bulletE4X[bulletCountE4], bulletE4Y[bulletCountE4]);
        if (next == ' ')
        {
            gotoxy(bulletE4X[bulletCountE4], bulletE4Y[bulletCountE4]);
            cout << "+";
            isActiveE4[bulletCountE4] = true;
            bulletCountE4++;
        }
    }
    bulletE4Speed++;
}

void movebulletE4()
{
    for (int x = 0; x < bulletCountE4; x++)
    {
        if (isActiveE4[x] == true)
        {
            char next = getCharAtxy(bulletE4X[x] - 1, bulletE4Y[x]);

            if (next != ' ')
            {
                erasebulletE4(bulletE4X[x], bulletE4Y[x]);
                isActiveE4[x] = false;
            }
            else if (next == ' ' || next == '*' || next == '+')
            {
                erasebulletE4(bulletE4X[x], bulletE4Y[x]);
                bulletE4X[x] = bulletE4X[x] - 1;
                printbulletE4(bulletE4X[x], bulletE4Y[x]);
            }
        }
    }
}
void printbulletE4(int x, int y)
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    gotoxy(x, y);
    cout << "+";
}
void erasebulletE4(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void Printe1health()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    gotoxy(77, 4);
    cout << "Health 1 = " << e1health<<" ";
	if(e1health <= 0)
	{
		gotoxy(77, 4);
		cout<<"Health 1 is finished";
	}
}
void Printe2health()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    gotoxy(77, 6);
    cout << "Health 2 = " << e2health<<" ";
		if(e2health <= 0)
	{
		gotoxy(77, 6);
		cout<<"Health 2 is finished";
	}
}
void Printe3health()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    gotoxy(77, 8);
    cout << "Health 3 = " << e3health<<" ";
	if(e3health <= 0)
	{
		gotoxy(77, 8);
		cout<<"Health 3 is finished";
	}
}
void Printe4health()
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    gotoxy(77, 10);
    cout << "Health 4 = " << e4health<<" ";
		if(e4health <= 0)
	{
		gotoxy(77, 10);
		cout<<"Health $ is finished";
	}
}
void ending()
{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
	system("cls");
	header();
			tankX = 0;
			tankY = 0;
			enemyX = 0;
			enemyY = 0;
			enemy2X = 0;
			enemy2Y = 0;
			enemy3X = 0;
			enemy3Y = 0;
			Score = 0;
			e1health = 0;
			e2health = 0;
			e3health = 0;
			playerHealth = 0;
			savegamedata();
cout<<endl<<endl<<endl<<endl<<"                 /$$$$$$                                           /$$$$$$                               "<<endl;
cout<<"                /$$__  $$                                         /$$__  $$                              "<<endl;
cout<<"               | $$  \\__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$       | $$  \\ $$ /$$    /$$ /$$$$$$   /$$$$$$ "<<endl;
cout<<"               | $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$      | $$  | $$|  $$  /$$//$$__  $$ /$$__  $$"<<endl;
cout<<"               | $$|_  $$  /$$$$$$$| $$ \\ $$ \\ $$| $$$$$$$$      | $$  | $$ \\  $$/$$/| $$$$$$$$| $$  \\__/"<<endl;
cout<<"               | $$  \\ $$ /$$__  $$| $$ | $$ | $$| $$_____/      | $$  | $$  \\  $$$/ | $$_____/| $$      "<<endl;
cout<<"               |  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$      |  $$$$$$/   \\  $/  |  $$$$$$$| $$      "<<endl;
cout<<"                \\______/  \\_______/|__/ |__/ |__/ \\_______/       \\______/     \\_/    \\_______/|__/      "<<endl;
Sleep(2000);
//clear();
}

void loadmaze()
{
    fstream myfile;
    string line;
    int row = 0;
    myfile.open("maze.txt", ios::in);
    while (getline(myfile, line))
    {
        for (int colom = 0; colom < 76; colom++)
        {
            maze[row][colom] = line[colom];
        }
        cout << endl;
        row++;
    }
    myfile.close();
}
void storemaze()
{
    fstream file;
    string line;
    file.open("maze.txt", ios::out);
    {
    file << "###########################################################################  " << endl;
    file << "||                                                                       ||          " << endl;
    file << "||                                                                       ||          " << endl;
    file << "||    %%%%%%%%%%%%%%%                 %%%%%%%%%%%%%%    |%|     %%%%     ||     " << endl;
    file << "||          |%|   |%|     |%|         |%|        |%|    |%|      |%|     ||         " << endl;
    file << "||          |%|   |%|       |%|       |%|        |%|    |%|      |%|     ||          " << endl;
    file << "||          %%%%%%%%      |%|         %%%%%%%%%%%%%%           %%%%      ||     " << endl;
    file << "||          |%|          |%|                         |%|                 ||        " << endl;
    file << "||          |%|              |%|                     |%|                 ||        " << endl;
    file << "||          %%%%%%%%%%    |%|        %%%%%%%%%%%%    |%|       %%%       ||        " << endl;
    file << "||                 |%|               |%|              |%|      |%|       ||       " << endl;
    file << "||                 |%|               |%|      |%|                |%|     ||      " << endl;
    file << "||    |%|  |%|%%%|%| |%|    |%|                 |%|          |%|  |%|    ||        " << endl;
    file << "||    |%|  |%|%%%|%| |%|    |%|                 |%|          |%|  |%|    ||        " << endl;
    file << "||   |%|  |%|   |%|         %%%%%%%%%%%       |%|            |%|         ||       " << endl;
    file << "||    |%|  |%|   |%|                 |%|     %%%%%%          |%|         ||       " << endl;
    file << "||   |%|                            |%|                |%|     |%|       ||      " << endl;
    file << "||      |%|                        |%|                |%|     |%|        ||      " << endl;
    file << "||    |%|  %%%%%%%%%%%%%%            |%|%%%%%%%%%%     |%|    |%|%%%%%   ||   " << endl;
    file << "||                                                    |%|                ||    " << endl;
    file << "||                                                                       ||    " << endl;
    file << "||                                                                       ||    " << endl;
    file << "||    |%|    |%|   |%|      %%%%%%%%%%%%%       |%|                      ||    " << endl;
    file << "||    |%|    |%|   |%|                |%|     %%%%%%     |%|   |%|       ||    " << endl;
    file << "||    |%|                             |%|                |%|   |%|       ||     " << endl;
    file << "||    |%|                             |%|                |%|   |%|       ||     " << endl;
    file << "||    |%|    %%%%%%%%%%%%%%           |%|%%%%%%%%%%      |%|   |%|       ||  " << endl;
    file << "||                                                                       ||    " << endl;
    file << "||                                                                       ||   " << endl;
    file << "###########################################################################";
    }
    file.close();
}
void printmaze()
{
	    system("cls");
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
		cout<<endl;
	    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 76; j++)
        {
            cout<< maze[i][j];
        }
        cout << endl;
    }
}
void savegamedata()
{
	fstream file;
	file.open("gamedata.txt", ios::out);
		file << tankX << ",";
		file << tankY << ",";
		file << enemyX << ",";
		file << enemyY << ",";
		file << enemy2X << ",";
		file << enemy2Y << ",";
		file << enemy3X << ",";
		file << enemy3Y << ",";
		file << enemy4X << ",";
		file << enemy4Y << ",";
		file << Score << ",";
		file << e1health << ",";
		file << e2health << ",";
		file << e3health << ",";
		file << e4health << ",";
		file << count << ",";
		file << playerHealth << endl;
	file.close();
}
void loadgamedata()
{
	string record;
	fstream myfile;
		myfile.open("gamedata.txt", ios::in);
		while (getline(myfile, record))
		{
			tankX = stoi(getfield(record, 1));
			tankY = stoi(getfield(record, 2));
			enemyX = stoi(getfield(record, 3));
			enemyY = stoi(getfield(record, 4));
			enemy2X = stoi(getfield(record, 5));
			enemy2Y = stoi(getfield(record, 6));
			enemy3X = stoi(getfield(record, 7));
			enemy3Y = stoi(getfield(record, 8));
			enemy4X = stoi(getfield(record, 9));
			enemy4Y = stoi(getfield(record, 10));
			Score = stoi(getfield(record, 11));
			e1health = stoi(getfield(record, 12));
			e2health = stoi(getfield(record, 13));
			e3health = stoi(getfield(record, 14));
			e4health = stoi(getfield(record, 15));
			count = stoi(getfield(record, 16));
			playerHealth = stoi(getfield(record, 17));
		}
		myfile.close();
}
string getfield(string record, int field)
{
	int commacount = 1;
	string item;
	for (int x = 0; x < record.length(); x++)
	{
		if (record[x] == ',')
		{
			commacount++;
		}
		else if (commacount == field)
		{
			item = item + record[x];
		}
	}
	return item;
}