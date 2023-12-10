#include <iostream>
using namespace std;
#include <conio.h>
#include <string.h>
#include <process.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>



void color1(int color1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);
		}

class car
{
public:
	int vno;
	float count;
	char dname[15], x, l[50];
	void input()
	{
		system("CLS");
		color1(4);
		int d;
		cout << "\n\n\t\tEnter the name of driver : ";
		cin >> dname;
		cout << "\n\n\t\tEnter the car no : ";
		cin >> vno;
		cout << "\n\n\t\tEnter the no of hours of stay : ";
		cin >> count;
		cout << "\n\n\t\tEnter the time slot : ";
		cin >> l;
		if (d < 20 && count < 8)
		{
			cout << "\n\n\t\tParking Available! You can park your car. ";
		}
		else
			cout << "\n\n\t\t Parking not possible!!";
		cout << "\n\n\t\tCar got parked!!";
		color1(7);
	}
	void cal()
	{

		color1(1);
		cout << "\n\t\n\tAre you a V.I.P: y/n ";
		cin >> x;
		color1(7);
		if (x == 'y')
		{
			color1(2);
			system("CLS");
			cout << "\n\t\n\tThe total expense during parking  ";
			cout << count * 20 << " rupees";
			color1(7);
		}
		else
		{
			color1(2);
			system("CLS");
			cout << "\n\t\n\tThe total expenses during parking  ";
			cout << count * 25 << " rupees";
			color1(7);
		}
	}
	void output()
	{
		color1(4);
		cout << "\n\n\t\tThe Driver Name : " << dname << endl;
		cout << "\n\n\t\tThe Car No : " << vno << endl;
		cout << "\n\n\t\tThe Hours Of Stay : " << count;
		cout << "\n\n\t\tThe Time Slot Of Parking : " << l;
		color1(7);
	}

} a, a1;
// brought to you by code-projects.org
void delete_record()
{
	color1(5);
	int n;
	system("CLS");
	cout << "\n\n\t\tEnter the car no you want to get depart : ";
	cin >> n;
	ifstream inFile;
	inFile.open("parking3.dat", ios::binary);
	ofstream outFile;
	outFile.open("temp.dat", ios::out | ios::binary);
	while (inFile.read((char *)&a, sizeof(a)))
	{
		if (a.vno != n)
		{

			outFile.write((char *)&a, sizeof(a));
		}
	}
	cout << "\n\n\t\t Parking Record Deleted";

	inFile.close();
	outFile.close();

	remove("parking3.dat");
	rename("temp.dat", "parking3.dat");
	color1(7);
}

int main()
{
	int login();
	login();
	int choice, vno1, d;
	while (1)
	{
		color1(4);
		system("CLS");

		cout << "\n\n\t\t ====== CAR PARKING RESERVATION SYSTEM ======";
		cout << "\n\n                                          ";
		cout << " \n\t\t\t======================";
		color1(4);
		cout << "\n\n\t\t\t  1. Arrival of a Car";
		cout << "\n\n\t\t\t  2. Total no of cars Arrived";
		cout << "\n\n\t\t\t  3. Total parking charges of all cars with details";
		cout << "\n\n\t\t\t  4. Departure of the car";
		cout << "\n\n\t\t\t  5. Exit Program";
		cout << " \n\t\t\t======================";
		cout << "\n\n";
		cout << "\t\t\t Select Your Choice ::";
		cin >> choice;
		color1(5);
		switch (choice)
		{
		case 1:
		{
			char f;
			cout << "\n\n\t\t==Do You Want to continue==y/n ";
			cin >> f;
			if (f == 'y')
			{

				ofstream f1("parking3.dat", ios::binary | ios::out | ios::app);
				a.input();
				f1.write((char *)&a, sizeof(a));
			}
			break;
			color1(7);
		}
		case 2:
		{
			color1(8);
			system("CLS");
			cout << "\n\n\t\t=== View the Records in the Parking Database ===";
			cout << "\n";
			ifstream infile("parking3.dat", ios::binary | ios::in);
			int d = 1;
			while (infile.read((char *)&a, sizeof(a)))
			{
				color1(9);
				system("CLS");
				cout << "\n";
				cout << "\n\n\tThe Car position in parking lot : " << d;
				d++;
				a.output();
				cout << "\n";
				cout << "\n\n\n";
				system("PAUSE");
				cout << endl;
			}

			break;
		}
		case 4:
		{

			delete_record();
			break;
		}
		case 3:
		{
			ifstream infile("parking3.dat", ios::binary | ios::in);
			while (infile.read((char *)&a, sizeof(a)))
			{
				cout << "\n";
				a.cal();
				a.output();
				cout << "\n";
				cout << endl;
			}
			break;
		}

		case 5:
		{
			color1(9);
			system("CLS");
			cout << "\n\n\n\t\t\tBrought To You By: code-projects.org \n";
			exit(0);
			break;
		}
		default:
		{
			color1(9);
			cout << "\n\n\t\t Invalid input";
			cout << "\n\n\t\tPress Enter to continue";
		}
		}
		getch();
	}
}
// cpo
int login()
{
	color1(5);
	string pass = "";
	char ch;
	cout << "\n\n\n\n\n\n\n\t\t\t\t\tCar Parking Reservation System Login";
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
	ch = _getch();
	while (ch != 13)
	{ // character 13 is enter
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	if (pass == "pass")
	{
		color1(2);
		cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
		system("PAUSE");
	}
	else
	{
		color1(9);
		cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
		system("PAUSE");
		system("CLS");
		login();
	}
}