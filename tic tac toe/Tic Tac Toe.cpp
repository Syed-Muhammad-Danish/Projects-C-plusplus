#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int box, result = 0, flag = 0;
char square[9] = {'0','1','2','3','4','5','6','7','8'};
void header()
{
	system("cls");
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
cout<<" _________ _________  _______   _________ _______  _______   _________ _______  _______ "<<endl;
cout<<" \\__   __/ \\__   __/ (  ____ \\  \\__   __/(  ___  )(  ____ \\  \\__   __/(  ___  )(  ____ \\"<<endl;
cout<<"    ) (       ) (    | (    \\/     ) (   | (   ) || (    \\/     ) (   | (   ) || (    \\/"<<endl;
cout<<"    | |       | |    | |           | |   | (___) || |           | |   | |   | || (__    "<<endl;
cout<<"    | |       | |    | |           | |   |  ___  || |           | |   | |   | ||  __)   "<<endl;
cout<<"    | |       | |    | |           | |   | (   ) || |           | |   | |   | || (      "<<endl;
cout<<"    | |    ___) (__  | (____/\\     | |   | )   ( || (____/\\     | |   | (___) || (____/\\"<<endl;
cout<<"    )_(    \\_______/ (_______/     )_(   |/     \\|(_______/     )_(   (_______)(_______/"<<endl<<endl<<endl;
}
int checkwin()
{
		if (square[0] == square [1]  && square[1] == square[2] )
		{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}		
		else
		if (square[3] == square [4]  && square[4] == square[5] )
			{	if ( square [3] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[6] == square [7]  && square[7] == square[8] )
			{	if ( square [6] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[0] == square [3]  && square[3] == square[6] )
			{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[1] == square [4]  && square[4] == square[7] )
			{	if ( square [1] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else
		if (square[2] == square [5]  && square[5] == square[8] )
			{	if ( square [2] == 'X' )			
			return 1;
			else
			return 2; 
		}
else
		if (square[0] == square [4]  && square[4] == square[8] )
			{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else
		if (square[2] == square [4]  && square[4] == square[6] )
			{	if ( square [2] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else
		if (square[0] == square [3]  && square[3] == square[6] )
			{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else 
		return 0;
}

void mark(int player, int box)
{
		if (player == 1 )
		{
			square[box] = 'X';
		}
		else
		{
			square[box] = 'Y';
		}
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void grid()
{
		system("cls");
	header();
		    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
	cout<<"    --------------------------"<<endl;
	cout<<"    ||      ||      ||      ||"<<endl;
	cout<<"    ||      ||      ||      ||"<<endl;
	cout<<"    ||      ||      ||      ||"<<endl;
	cout<<"    --------------------------"<<endl;
	cout<<"    ||      ||      ||      ||"<<endl;
	cout<<"    ||      ||      ||      ||"<<endl;
	cout<<"    ||      ||      ||      ||"<<endl;
	cout<<"    --------------------------"<<endl;
	cout<<"    ||      ||      ||      ||"<<endl;
	cout<<"    ||      ||      ||      ||"<<endl;
	cout<<"    ||      ||      ||      ||"<<endl;
	cout<<"    --------------------------"<<endl;

}
void display()
{
	system("cls");
	header();
		grid();
			    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			gotoxy(9,12);
		for(int i=0;i<9;i++)
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout<<square[i];
				if (i == 2 || i== 5 || i ==8)
				{
					if(i == 2 || i == 5)
					{					
						SetConsoleTextAttribute(hConsole, 11);
						cout<<"\n\n\n\n    ||   "; 
					}
					if(i == 8)
					{
						cout<<"\n\n\n\n";
					}
				}
				else
				{
											SetConsoleTextAttribute(hConsole, 11);
					cout<<"  ||   ";
				}
		}
}
void congrats()
{
		system("cls");
	header();
			    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
	cout<<"   )   ___                                           /  "<<endl;
	cout<<"  (__/_____)                     /)      ,          /   "<<endl;
	cout<<"    /       ____  _  __ _ _/_   // _ _/_  ____     /    "<<endl;
	cout<<"   /       (_)/ ((_// ((_((_(_((/_(_((__((_)/ (_  o     "<<endl;
	cout<<"  (______)      .-/                                     "<<endl;
	cout<<"               (_/                                      "<<endl;
    SetConsoleTextAttribute(hConsole, 14);
}
void winner()
{
		if (result == 1 )
		{
			congrats();
			cout<<"\n\n player 1 has Won "<<endl;
			flag = 1;			
		}
		else
		if (result == 2 )
		{
			congrats();
			cout<<"\n\n player 2 has Won "<<endl;
			flag = 1;			
		}
}
int main()
{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	header();
	display();
		int player1 = 1, player2 =2 ;
		
	for(int i=1;i<5;i++)
	{
		int n=0,t=0;
		while(n==0)
		{
			SetConsoleTextAttribute(hConsole, 14);			
			cout<< "\n Player " << player1 << "\n Enter the Box : ";
			cin>> box;
			if((box == 0 || box == 1 || box == 2 || box == 3 || box == 4 || box == 5 || box == 6 || box == 7 || box == 8) && (square[box] != 'X' || square[box] != 'Y'))
			{n=1;}
			else
				n=0;
		}
		mark( player1, box);
		box==9;
		display();

		result =checkwin();	
		winner();
		if(flag ==1)
		{
			break;
		}

		while(t==0)
		{
			SetConsoleTextAttribute(hConsole, 13);			
			cout<< "\n Player " << player2 << " \n Enter the Box : ";
			cin>> box;
			if((box == 0 || box == 1 || box == 2 || box == 3 || box == 4 || box == 5 || box == 6 || box == 7 || box == 8) && (square[box] != 'X' || square[box] != 'Y'))
			{t=1;}
			else
			t=0;
		
		}
		mark ( player2, box);
		box==9;
		display();
		
		result =checkwin();	
		winner();
		if(flag ==1)
		{
			break;
		}
	}
		if (flag == 0 )
						SetConsoleTextAttribute(hConsole, 7);
		cout<<" \n Sorry, The game is a draw \n\n";
	
	return 0;
}