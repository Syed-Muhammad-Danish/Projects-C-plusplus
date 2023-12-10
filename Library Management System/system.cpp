#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;
// global variables and arrays
string names[100];
string passwords[100];
string books[1000];
string author[1000];
string borrow[1000];
int date[1000];
int month[1000];
string borrowuser[1000];
int borrowcount = 0;
int addsize = 0;
int usercount = 1;
string a = "admin";
string b = "admin";
string name;
string password;
int currentmonth = 0;
int currentdate = 0;
int fines = 0;

// funtion prototype
// major
void header();
void clear();
void signup();
void signin();
string mainpage();

// admin side
void userlist();
void booklist();
void borrowhistory();
void removebook();
void removeuser();
void changeadminpas();
void changepsiduser();
void addbooks();
void addbook(int size);
void PRINTUSERLIST();
bool USERLIST();
void Printbooklist();
bool Booklist();
string admin();
void Adminoptions(string options);
void Printborrowhis();
bool Borrowhis();
bool checkremovebook();
bool CheckRemovebook(string rmbknm, string rmauthor);
bool checkremoveuser(string rmuser);
bool CheckRemoveuser();
bool CheckAdmin(string e, string f);
bool check(string c, string d);
bool changepassiduser();

// userside
void viewfine();
void currenttime();
void changename();
bool chngusname(string x, string y);
void changeboth();
bool chngboth(string x, string y);
bool userrpasswrd(string any);
string userpassword();
void fine(int x);
int Printfines();
void Studentoptions(string option1);
bool checkborrow(string seebknm);
bool Printsearch(string seebknm);
string student();
bool signincheck(string name, string password);
void Returnbook();
void about();
void Borrowedbook();
void borrowbook();
void changepassword();
void searchauthor();
void search();
void loading();
// filehandling functions
void saveuserdata();
void savebooksdata();
void saveborrowdata();
void loaduserdata();
void loadbooksdata();
void loadborrowdata();
string getfield(string record, int field);

// program starting
void loading()
{
	system("cls");
	header();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	char n=219;
	cout<<endl<<endl;
	cout<<"   ||-------------------------------------------------------||"<<endl;
cout<<"   ||.--.    .-._                        .----.             ||"<<endl;
cout<<"   |||==|____| |H|___            .---.___|""""|_____.--.___     ||"<<endl;
cout<<"   |||  |====| | |xxx|_          |+++|=-=|_  _|-=+=-|==|---|||"<<endl;
cout<<"   |||==|    | | |   | \\         |   |   |_\\/_|Black|  | ^ |||"<<endl;
cout<<"   |||  |    | | |   |\\ \\   .--. |   |=-=|_/\\_|-=+=-|  | ^ |||"<<endl;
cout<<"   |||  |    | | |   |_\\ \\_( oo )|   |   |    |Magus|  | ^ |||"<<endl;
cout<<"   |||==|====| |H|xxx|  \\ \\ |''| |+++|=-=|""""|-=+=-|==|---|    ||"<<endl;
cout<<"   ||`--^----'-^-^---'   `-' ""  '---^---^----^-----^--^---^  ||"<<endl;
cout<<"   ||-------------------------------------------------------||"<<endl;
cout<<"   ||-------------------------------------------------------||"<<endl;
cout<<"   ||               ___                   .-.__.-----. .---.||"<<endl;
cout<<"   ||              |===| .---.   __   .---| |XX|<(*)>|_|^^^|||"<<endl;
cout<<"   ||         ,  /(|   |_|III|__|''|__|:x:|=|  |     |=| Q |||"<<endl;
cout<<"   ||      _a'{ / (|===|+|   |++|  |==|   | |  |Illum| | R |||"<<endl;
cout<<"   ||      '/\\/ _(|===|-|   |  |''|  |:x:|=|  |inati| | Y | ||"<<endl;
cout<<"   ||_____  -\\{___(|   |-|   |  |  |  |   | |  |     | | Z |||"<<endl;
cout<<"   ||       _(____)|===|+|[I]|DK|''|==|:x:|=|XX|<(*)>|=|^^^|||"<<endl;
cout<<"   ||              `---^-^---^--^--'--^---^-^--^-----^-^---^||"<<endl;
cout<<"   ||-------------------------------------------------------||"<<endl;
cout<<"   ||_______________________________________________________||"<<endl<< endl;
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
main()
{
	names[0] = "admin";
	passwords[0] = "admin";
	usercount++;
	//saveuserdata();
	loadbooksdata();
	loaduserdata();
loading();
	system("cls");
	string option;
	int n = 1;
	while (n)
	{
		// saveuserdata();
		// savebooksdata();
		// saveborrowdata();
		option = mainpage();
		if (option == "2")
		{
			signup();
		}
		else if (option == "1")
		{
			signin();
		}
		else if (option == "3")
		{
			saveuserdata();
			savebooksdata();
			saveborrowdata();
			n = 0;
		}
	}
	clear();
}

void header()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "*****************************************************************************************************************" << endl;
	cout << "*                                                                                                               *" << endl;
	cout << "*   __    _ _                      _____                                   _      _____         _               *" << endl;
	cout << "*  |  |  |_| |_ ___ __  ___ _ _   |     |___ ___ ___ ___ ___ _____ ___ ___| |_   |   __|_ _ ___| |_ ___ _____   *" << endl;
	cout << "*  |  |__| | . |  _|..'|  _| | |  | | | | .'|   | .'| . | -_|     | -_|   |  _|  |__   | | |_ -|  _| -_|     |  *" << endl;
	cout << "*  |_____|_|___|_| |__,|_| |_  |  |_|_|_|__,|_|_|__,|_  |___|_|_|_|___|_|_|_|    |_____|_  |___|_| |___|_|_|_|  *" << endl;
	cout << "*                          |___|                    |___|                              |___|                    *" << endl;
	cout << "*                                                                                                               *" << endl;
	cout << "*****************************************************************************************************************" << endl
		 << endl;
	// HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
}
void clear()
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	cout << "Press any Key to Continue ";
	getch();
	system("cls");
}
void signup()
{

	system("cls");
	header();
	cout << "Welcome to signup page.............. :) " << endl<<endl;
	string cname, cpass;
	bool at = false;
	while(cpass.length() < 8)
	{
	bool chk =false;
	system("cls");
	header();
	cout << "Enter your Name: ";
	cin >> cname;
	cout << "Enter your Password: ";
	cin >> cpass;
	if(cpass.length() < 8)
	{
		chk = true;
	}
	if(chk == false)
	{
		for (int d = 0; d < usercount; d++)
		{
			if (names[d] == cname || (names[0] == cname && passwords[0] == cpass))
			{
				at = true;
				cout << "user Existed." << endl;
				clear();
				break;
			}
		}
		if (at == false)
		{
			names[usercount] = cname;
			passwords[usercount] = cpass;
			cout << "New id has been created successfully..........." << endl;
			clear();
			usercount++;
			saveuserdata();
			// savebooksdata();
			// saveborrowdata();
			clear();
		}
	}
	if(chk == true)
	{
		cout<<"Password Should be 8 Characters long."<<endl;
		clear();
	}
	}
}

// admin side functions
bool USERLIST()
{
	if (usercount > 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void PRINTUSERLIST()
{
	cout << "   Username       Password" << endl;
	for (int i = 1; i < usercount; i++)
	{
		cout << i << ". " << names[i] << "           " << passwords[i] << endl;
	}
}
void userlist()
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	cout << "User List...." << endl
		 << endl;
	bool t = USERLIST();
	if (t == false)
	{
		cout << "No user existed............." << endl;
	}
	if (t == true)
	{
		PRINTUSERLIST();
	}
	clear();
	header();
}
bool Booklist()
{
	if (addsize > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Printbooklist()
{
	cout << "   Books name      Author name" << endl;
	for (int i = 0; i < addsize; i++)
	{
		cout << i + 1 << ". " << books[i] << "           " << author[i] << endl;
	}
}
void booklist()
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	cout << "Book List...." << endl
		 << endl;
	bool t = Booklist();
	if (t == false)
	{
		cout << "No books existed............." << endl;
	}
	if (t == true)
	{
		Printbooklist();
	}
	clear();
	header();
}
bool Borrowhis()
{
	if (borrowcount > 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Printborrowhis()
{

	cout << "Borrowed books             Users" << endl;
	for (int i = 0; i < borrowcount; i++)
	{
		cout << i + 1 << ". " << borrow[i] << "<<<<<<>>>>>>>" << borrowuser[i] << endl;
	}
}
void borrowhistory()
{
	loadborrowdata();
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	cout << "Borrow History...." << endl
		 << endl;
	bool t = Borrowhis();
	if (t == false)
	{
		cout << endl
			 << "No books has been borrowed yet................." << endl;
	}
	if (t == true)
	{
		Printborrowhis();
	}
	clear();
	header();
}
bool checkremovebook()
{
	if (addsize != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CheckRemovebook(string rmbknm, string rmauthor)
{
	for (int i = 0; i <= addsize; i++)
	{
		if (rmbknm == books[i] && rmauthor == author[i])
		{
			books[i] = " ";
			author[i] = " ";
			for (int x = i; x <= addsize; x++)
			{
				books[x] = books[x + 1];
				author[x] = author[x + 1];
			}
			addsize--;
			return true;
			break;
		}
		else
		{
			continue;
		}
	}
	return false;
}
void removebook()
{
	//saveuserdata();
	//saveborrowdata();
	system("cls");
	header();
	string rmbknm, rmauthor;
	cout << "Remove Book...." << endl
		 << endl;
	bool t = checkremovebook();
	if (t == true)
	{
		cout << "Enter Book name to remove:";
		cin >> rmbknm;
		cout << "Enter name of author of book:";
		cin >> rmauthor;
		bool n = CheckRemovebook(rmbknm, rmauthor);
		if (n == true)
		{
			cout << "Book has been removed sucessfully............." << endl;
		savebooksdata();
		}
		else if (n == false)
		{
			cout << "Book not found. << or >> Enter Correct Name." << endl;
		}
	}
	if (t == false)
	{
		cout << "No book is available in library";
	}
	clear();
	header();
}
bool CheckRemoveuser()
{
	if (usercount > 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool checkremoveuser(string rmuser)
{
	for (int i = 1; i <= usercount; i++)
	{
		if (rmuser == names[i])
		{
			names[i] = " ";
			passwords[i] = " ";
			for (int x = i; x <= usercount; x++)
			{
				names[x] = names[x + 1];
				passwords[x] = passwords[x + 1];
			}
			usercount--;
			return true;
			break;
		}
		else
		{
			continue;
		}
	}
	return false;
}
void removeuser()
{
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	string rmuser;
	cout << "Remove User...." << endl
		 << endl;
	bool t = CheckRemoveuser();
	if (t == true)
	{
		cout << "Enter name of user to remove: ";
		cin >> rmuser;
		bool n = checkremoveuser(rmuser);
		if (n == true)
		{
			cout << "User has been removed sucessfully............." << endl;
			saveuserdata();
		}
		else if (n == true)
		{
			cout << "User not found. << or >> Enter Correct Name." << endl;
		}
	}
	if (t == false)
	{
		cout << "No user existed." << endl;
	}
	clear();
	header();
}
bool CheckAdmin(string e, string f)
{
	if (e == a && f == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool check(string c, string d)
{
	for (int y = 1; y <= usercount; y++)
	{
		if ((c == a && d == b) || (c == names[y] && d == passwords[y]))
		{
			return false;
			break;
		}
		else if (c != names[y] && d != passwords[y])
		{
			continue;
		}
	}
	return true;
}
void changeadminpas()
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	string c, d, e, f;
	cout << "Change Admin id and Password...." << endl
		 << endl;
	cout << "Enter old admin name: ";
	cin >> e;
	cout << "Enter old admin password: ";
	cin >> f;
	bool t = CheckAdmin(e, f);
	if (t == true)
	{
		while(d.length()<8)
		{
		cout << "Enter new admin name: ";
		cin >> c;
		cout << "Enter new admin password: ";
		cin >> d;
		if(d.length() < 8)
		{
		cout<<"Password Should be 8 Characters long."<<endl;
		clear();
		}
		if(d.length() > 8)
		{
		bool n = check(c, d);
		if (n == false)
		{
			cout << "ID and Password Already existed......" << endl;
		}
		if (n == true)
		{
			a = c;
			b = d;
			cout << "Id and Password has been changed.........." << endl;
			names[0] = a;
			names[0] = b;
			saveuserdata();
		}
		}
	}
	}
	if (t == false)
	{
		cout << "Enter correct old Id and password........." << endl;
	}
	clear();
	header();
}
bool changepassiduser()
{

	if (usercount > 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void changepsiduser()
{
	
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	cout << "Change User Id and Password...." << endl
		 << endl;
	string w, x, y, z;
	bool tg = false;
	bool t = changepassiduser();
	if (t == true)
	{
		cout << "Enter Name(Id):";
		cin >> x;
		cout << "Enter Password:";
		cin >> y;
		for (int i = 1; i < usercount; i++)
		{
		while(z.length()<8)
		{
			if ((x == names[i] && y == passwords[i]))
			{
				cout << "Enter New Name (ID):";
				cin >> w;
				cout << "Enter New password:";
				cin >> z;
				if(z.length() < 8)
				{
					cout<<"Password Should be 8 Characters long."<<endl;
					clear();
				}
				if(z.length() > 8)
				{
				tg = check(w, z);
				if (tg == true)
				{
					names[i] = w;
					passwords[i] = z;
					cout << "ID and Password has been updated........." << endl;
					saveuserdata();
					break;
				}
				if (tg == false)
				{
					cout << "Id password has been taken......" << endl;
					break;
				}
				}
			}
				if (i < usercount)
				{
					continue;
				}
				else if (i > usercount)
				{
					cout << "Enter Correct Credentials....." << endl;
					break;
				}
			}
		}
	}
	if (t == false)
	{
		cout << "No user Existed........" << endl;
	}
	clear();
	header();
}
void addbook(int size)
{
	if (addsize == 0)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Enter name of book: ";
			cin >> books[i];
			cout << "Enter author name: ";
			cin >> author[i];
		}
	}
	else if (addsize != 0)
	{
		for (int i = addsize; i < (size + addsize); i++)
		{
			cout << "Enter name of book:";
			cin >> books[i];
			cout << "Enter author name: ";
			cin >> author[i];
		}
	}
}
void addbooks()
{
	// saveuserdata();
	// saveborrowdata();

	system("cls");
	header();
	int size;

	cout << "Add Books...." << endl
		 << endl;
	cout << "Enter no. of books to add :";
	cin >> size;
	addbook(size);
	savebooksdata();
	addsize = addsize + size;
	cout << "Your books has been added" << endl;
	clear();
	header();
}

// user side functions
bool checkborrow(string seebknm)
{
	for (int i = 0; i < borrowcount; i++)
	{
		if (seebknm == borrow[i])
		{

			return true;
			break;
		}
		return false;
	}
}
bool Printsearch(string seebknm)
{
	for (int i = 0; i < addsize; i++)
	{
		if (seebknm == books[i])
		{
			cout << books[i] << " by " << author[i] << endl
				 << "Book is available :)......." << endl;
			return true;
		}
		return false;
	}
}
void search()
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	string seebknm;
	cout << "Search Bar...." << endl
		 << endl;
	bool t = Booklist;
	if (t == true)
	{
		cout << "Enter name exact name of book to search:";
		cin >> seebknm;
		bool ft = false;
		bool ra = false;
		if (ft == true)
		{
			cout << "Book is not available......" << endl;
		}
		if (ft == false)
		{
			ra = Printsearch(seebknm);
			if (ra == false)
			{
				cout << "Enter correct name....." << endl;
			}
		}
	}
	if (t == false)
	{
		cout << "Sorry no book is available uptill now............. :( " << endl;
	}
	clear();
	header();
}
void searchauthor()
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	string seeauth;
	cout << "Author Search Bar...." << endl
		 << endl;
	bool t = Booklist;
	if (t == true)
	{
		cout << "Enter correct name of author:";
		cin >> seeauth;
		bool ta = false;
		cout << "Author        books" << endl;
		for (int i = 0; i < addsize; i++)
		{
			if (seeauth == author[i])
			{
				cout << i + 1 << author[i] << " >>><>>>> " << books[i] << endl;
				ta = true;
			}
		}
		if (ta == false)
		{
			cout << "No book of this author is available in Library............" << endl;
		}
	}
	if (t == false)
	{
		cout << "Sorry no book is available uptill now............. :( " << endl;
	}
	clear();
	header();
}
bool chngusps(string x, string y)
{
	string z;
	for (int i = 1; i < usercount; i++)
	{	while(z.length()<8)
		{
			if ((x == names[i] && y == passwords[i]) && x == name)
			{
				cout << "Enter new password:";
				cin >> z;
				if(z.length()>8)
				{
					passwords[i] = z;
					return true;
					break;
				}
			}
			if ((x != names[i] && y != passwords[i]) && x != name)
			{
				continue;
			}
			if(z.length() < 8)
			{
			cout<<"Password Should be 8 Characters long."<<endl;
			clear();
			}
		}
	}
	return false;
}
void changepassword()
{
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	string x, y;
	cout << "Change Password...." << endl
		 << endl;
	cout << "Enter your old name(id):";
	cin >> x;
	cout << "Enter your old password:";
	cin >> y;
	bool t = chngusps(x, y);
	if (t == true)
	{
		cout << "Password has been updated........." << endl;
	saveuserdata();
	}
	if (t == false)
	{
		cout << "Enter correct credintials......." << endl;
	}
	clear();
	header();
}
void borrowbook()
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	string x, brwbk;
	cout << "Borrow Books...." << endl
		 << endl;
	cout << "Note: You can borrow a single book at a time return old borrow book (If any) to borrow a new book......" << endl
		 << endl;
	bool atd = false;
	bool ras = false;
	bool rf = false;
	bool chk = false;
	int y = 0;
	if (addsize != 0)
	{
		cout << "Please Enter your name(ID):";
		cin >> x;
		for (int i = 0; i < usercount; i++)
		{
			if (x == names[i] && x == name)
			{
				y++;
			}
			if (x == borrowuser[i] && x == name)
			{
				cout << "Return the old book first.........." << endl;
				atd = true;
			}
		}
		if (y == 0)
		{
			cout << "Enter correct name(ID)........" << endl;
		}
		if (y != 0 && borrowcount == 0)
		{
			cout << "Enter name of book to borrow:";
			cin >> brwbk;
			for (int i = 0; i < addsize; i++)
			{
				if (brwbk == books[i])
				{
					chk = true;
				}
			}
			if (chk == true)
			{
				cout << "Book has been borrowed....... :) " << endl;
				borrowuser[borrowcount] = x;
				borrow[borrowcount] = brwbk;
				fine(borrowcount);
				borrowcount++;
			}
			else if (chk == false)
			{
				cout << "Enter correct name of book" << endl;
			}
		}

		else if (y != 0 && borrowcount != 0)
		{
			for (int t = 0; t < borrowcount; t++)
			{
				if (x == borrowuser[t])
				{
					rf = true;
				}
			}
			if (rf == false)
			{
				cout << "Enter name of book to borrow:";
				cin >> brwbk;
				for (int i = 0; i < addsize; i++)
				{
					if (brwbk == books[i])
					{
						chk = true;
					}
				}
				for (int t = 0; t < borrowcount; t++)
				{
					if (borrow[t] == brwbk)
					{
						ras = true;
					}
					else
					{
						ras = false;
					}
					if (ras == true)
					{
						cout << "Book is not available." << endl;
					}
					else if (ras == false && chk == true)
					{
						fine(borrowcount);
						cout << "Book has been borrowed....... :) " << endl;
						borrowuser[borrowcount] = x;
						borrow[borrowcount] = brwbk;
						borrowcount++;
						saveborrowdata;
					}
				}
			}
		}
	}
	else
	{
		cout << "No books are available in Library..... :( " << endl;
	}
	clear();
	header();
}
void Borrowedbook()
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	string bnm;
	bool tas = false;
	int y = 0;
	cout << "List Borrowed Books...." << endl
		 << endl;
	if (borrowcount == 0)
	{
		cout << "No books borrowed" << endl;
	}
	else
	{
		cout << "Enter your name(ID): ";
		cin >> bnm;
		for (int t = 0; t < borrowcount; t++)
		{
			if (bnm == borrowuser[t])
			{
				y++;
				tas = true;
			}
			if (y == 0 && bnm == name)
			{
				cout << "No books are borrowed yet..........." << endl;
				break;
			}
			if (y != 0 && bnm == name)
			{
				cout << borrow[t] << " has been borrowed........" << endl;
			}
		}
		if (name != bnm)
		{
			cout << "Enter your correct id....." << endl;
		}
	}
	clear();
	header();
}
int Printfines(int i)
{	
	int  totaldays=0;
	totaldays = (((currentmonth - month[i]) * 30) + (currentdate - date[i]));
	if (borrowcount !=0)
	{
		if (totaldays>10)
		{
			int sum=0;
			sum = (totaldays-10);
			if (sum <3)
			{
				fines = 1000;
				return fines;
			}
			else
			{
				fines = (1000 + (sum*100));
				return fines;
			}
		}
		if(totaldays<10)
		{
			fines =0;
			return fines;
		}
		else
		{
			cout << "No fine is shown........." << endl;
		}
	}
}
void viewfine()
{
	system("cls");
	header();
	cout << "     View Fine " << endl<< endl;
	cout << "-----------------------." << endl<< endl;
	bool t = false;
	for (int i = 0; i < borrowcount; i++)
	{
		if (name == borrowuser[i])
		{
			currenttime();
			int x = Printfines(i);
			cout << "Fine : " << x << endl;
			t = true;
			break;
		}
	}
	if (t == false)
	{
		cout << "No book Has been borrowed.............." << endl;
	}

	clear();
	header();
}
void fine(int x)
{
	// current date/time based on current system
	time_t now = time(0);

	// cout << "Number of sec since January 1,1970 is:: " << now << endl;

	tm *ltm = localtime(&now);
	date[x] = ltm->tm_mday;
	month[x] = 1 + ltm->tm_mon;
	// print various components of tm structure.
}
void currenttime()
{
	// current date/time based on current system
	time_t now = time(0);

	// cout << "Number of sec since January 1,1970 is:: " << now << endl;

	tm *ltm = localtime(&now);
	currentmonth = 1 + ltm->tm_mon;
	currentdate = ltm->tm_mday;
}
void Returnbook()
{
	// saveuserdata();
	// savebooksdata();
	system("cls");
	header();
	string rbk, rbnm;
	bool et = false;
	cout << "Return Books...." << endl
		 << endl;
	if (borrowcount == 0)
	{
		cout << "No books are borrowed" << endl;
	}
	else
	{
		cout << "Enter your name(ID):";
		cin >> rbnm;
		for (int i = 0; i < borrowcount; i++)
		{
			if (borrowuser[i] == rbnm && rbnm == name)
			{
				et = true;
			}
		}
		if (et == true)
		{
			currenttime();
			cout << "Enter name of book to return:";
			cin >> rbk;
			for (int i = 0; i < borrowcount; i++)
			{
				if (rbk == borrow[i])
				{
					borrow[i] = " ";
					borrowuser[i] = " ";
					month[i] = 0;
					date[i] = 0;
					for (int x = i; x <= borrowcount; x++)
					{
						borrow[x] = borrow[x + 1];
						borrowuser[x] = borrowuser[x + 1];
						month[x] = month[x + 1];
						date[x] = date[x + 1];
					}
					cout << "Fine :" << Printfines(i) << endl;
					cout << "Book Has been returrned.........." << endl;
					borrowcount--;
						saveborrowdata();
				}
			}
			
		}
		if (et == false)
		{
			cout << "No books has been borrowed Yet" << endl;
		}
	}
	clear();
	header();
}
bool chngusname(string x, string y)
{
	string z;
	for (int i = 0; i < usercount; i++)
	{
		if ((x == names[i] && y == passwords[i]) && x == name)
		{
			cout << "Enter new password:";
			cin >> z;
			int x=0;
			while(x<usercount)
			{	
				if(z == names[x])
				{
					cout<<"ID already taken.....";
					break;
				}
				else if(x>=usercount)
				{
					names[i] = z;
					return true;
				}
				x++;
			}
		}
		if ((x != names[i] && y != passwords[i]) && x != name)
		{
			continue;
		}
	}
	return false;
}
void changename()
{
	
	// savebooksdata();
	// saveborrowdata();
	system("cls");
	header();
	string x, y;
	cout << "Change Name(ID)...." << endl
		 << endl;
	cout << "Enter your old name(ID):";
	cin >> x;
	cout << "Enter your old password:";
	cin >> y;
	bool t = chngusname(x, y);
	if (t == true)
	{
		cout << "Name has been updated........." << endl;
	saveuserdata();
	}
	if (t == false)
	{
		cout << "Enter correct credintials......." << endl;
	}
	clear();
	header();
}
bool chngboth(string x, string y)
{
	string z,w;
	for (int i = 0; i < usercount; i++)
	{
		if ((x == names[i] && y == passwords[i]) && x == name)
		{
			cout << "Enter new password: ";
			cin >> z;
			cout<<"Enter new password: ";
			cin>> w;
			int x=0;
			while(x<usercount)
			{	
				if(z == names[x])
				{
					cout<<"ID already taken.....";
					break;
				}
				else if(x>=usercount)
				{
					names[i] = z;
					passwords[i]=w; 
					return true;
				}
				x++;
			}
		}
		if ((x != names[i] && y != passwords[i]) && x != name)
		{
			continue;
		}
	}
	return false;
}
void changeboth()
{
	savebooksdata();
	saveborrowdata();
	system("cls");
	header();
	string x, y;
	cout << "Change Both Name(ID) & Password...." << endl
		 << endl;
	cout << "Enter your old name(ID):";
	cin >> x;
	cout << "Enter your old password:";
	cin >> y;
	bool t = chngboth(x, y);
	if (t == true)
	{
		cout << "credential has been updated........." << endl;
saveuserdata();
	}
	if (t == false)
	{
		cout << "Enter correct credintials......." << endl;
	}
	clear();
	header();
}
bool userrpasswrd(string any)
{
	bool t = true;
	while (t == true)
	{
		any = userpassword();
		if(any == "1")
		{
			changepassword();
		}
		if(any == "2")
		{
			changename();
		}
		if(any == "3")
		{
			changeboth();
		}
		if(any == "4")
		{
			t = false;
		}
	}
}
string userpassword()
{
	system("cls");
	header();
	string any;
	cout<< "Change Name & Password...." << endl<< endl;
	cout<<"Select any option.."<<endl;
	cout<<"1. Change Password"<<endl;
	cout<<"2. Change Name"<<endl;
	cout<<"3. Change Both name and password."<<endl;
	cout<<"4. Return to menu."<<endl;
	cout<<"Select option.. : ";
	cin>>any;
	return any;
}
void about()
{
	system("cls");
	header();
	cout << "About library...." << endl
		 << endl;
	cout << "About Us:" << endl;
	cout << "Our library is dedicated to providing a welcoming and inclusive space for all members of the community. With a collection of books, periodicals, and other resources," << endl
		 << " we aim to be a hub of learning and discovery. Our librarians are knowledgeable and passionate about helping patrons find the information they need, and our" << endl
		 << " facilities are equipped with the latest technology to support research and educational pursuits. Whether you're a student, a lifelong learner, or simply someone" << endl
		 << " looking for a quiet place to read, our library is here to serve you. We believe that access to information and knowledge is a fundamental right, and we work every" << endl
		 << "-day to make that a reality for everyone." << endl
		 << endl;
	cout << "Contact Us:";
	cout << "Email: lib@uet.edu.pk                Website: https://library.uet.edu.pk " << endl;
	clear();
	header();
}
string mainpage()
{
	system("cls");
	header();
	string option;
	cout << "Welcome...." << endl
		 << endl;
	cout << " Enter Any oF The Following: " << endl;
	cout << " 1. Sign In: " << endl;
	cout << " 2. Sign Up: " << endl;
	cout << " 3. Exit: " << endl
		 << endl;

	cout << "Select option: ";
	cin >> option;
	return option;
}
string student()
{
	string option1;
	// while (option1 != 9)
	//{
	system("cls");
	header();
	cout << "Welcome to Student Menu" << endl;
	cout << "__________________________." << endl;
	cout << "Select One Of the Following:" << endl;
	cout << "1.Search Books." << endl;
	cout << "2.Search through author name." << endl;
	cout << "3.View List of All books." << endl;
	cout << "4.Change My Name & Password." << endl;
	cout << "5.Borrow a book." << endl;
	cout << "6.View list of borrowed books." << endl;
	cout << "7.Enter name of book to return." << endl;
	cout << "8.View Fine." << endl;
	cout << "9.About Library." << endl;
	cout << "10.Credentials page." << endl;
	cout << "11.Close Program." << endl
		 << endl;
	cout << "Select the option: ";
	cin >> option1;
	return option1;
}
void Studentoptions(string option1)
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	string any;
	bool t = true;
	while (t == true)
	{
		option1 = student();
		if (option1 == "1")
		{
			search();
		}
		if (option1 == "2")
		{
			searchauthor();
		}
		if (option1 == "3")
		{
			booklist();
		}
		if (option1 == "4")
		{
			userrpasswrd(any);
		}
		if (option1 == "5")
		{
			borrowbook();
		}
		if (option1 == "6")
		{
			Borrowedbook();
		}
		if (option1 == "7")
		{
			Returnbook();
		}
		if (option1 == "8")
		{
			viewfine();
		}
		if (option1 == "9")
		{
			about();
		}
		if (option1 == "11")
		{
			saveuserdata();
			savebooksdata();
			saveborrowdata();
			clear();
			exit(0);
		}
		if (option1 == "10")
		{
			t = false;
		}
	}
	//	clear();
}

void Adminoptions(string options)
{
	// saveuserdata();
	// savebooksdata();
	// saveborrowdata();
	bool t = true;
	while (t == true)
	{
		options = admin();
		if (options == "1")
		{
			addbooks();
		}
		if (options == "2")
		{
			changeadminpas();
		}
		if (options == "3")
		{
			userlist();
		}
		if (options == "4")
		{
			removeuser();
		}
		if (options == "5")
		{
			borrowhistory();
		}
		if (options == "6")
		{
			booklist();
		}
		if (options == "7")
		{
			removebook();
		}
		if (options == "8")
		{
			changepsiduser();
		}
		if (options == "10")
		{
			saveuserdata();
			savebooksdata();
			saveborrowdata();
			clear();
			exit(0);
		}
		if (options == "9")
		{
			t = false;
		}
	}
	//	clear();
}
string admin()
{
	string options;
	// 	while(options != "9")
	// {
	system("cls");
	header();
	cout << "Welcome to Admin menu" << endl;
	cout << "_________________________." << endl;
	cout << "Select One Of the Following:" << endl;
	cout << "1.Add Books." << endl;
	cout << "2.Change Admin Username / Password." << endl;
	cout << "3.See user list." << endl;
	cout << "4.Remove User." << endl;
	cout << "5.See borrow history." << endl;
	cout << "6.View Books List." << endl;
	cout << "7.Remove Book." << endl;
	cout << "8.Change user ID and password." << endl;
	cout << "9.Return to Credentials Page." << endl;
	cout << "10.Close Program." << endl
		 << endl;
	cout << "Select the option: ";
	cin >> options;
	return options;
	// }
}
bool signincheck(string name, string password)
{

	string options, option1;
	bool t = false;
	if (name == a && password == b)
	{
		Adminoptions(options);
		return true;
	}
	for (int y = 1; y < usercount; y++)
	{
		if (name == names[y] && password == passwords[y])
		{
			Studentoptions(option1);
			return true;
		}
		else if (name != names[y] && password != passwords[y])
		{
			continue;
			return false;
		}
	}
	return false;
}
void signin()
{
	system("cls");
	header();
	cout << "Welcome to signin page.............. :) " << endl;
	cout << "Note: If your admin enter only predefined admin id." << endl
		 << endl;
	cout << "Enter your Name: ";
	cin >> name;
	cout << "Enter your Password: ";
	cin >> password;
	bool ty = signincheck(name, password);
	if (ty == false)
	{
		cout << "User not found" << endl
			 << endl;
		cout << "Note: Maybe you have not signedup or your credentials are changed by admin. Contact admin if there is any problem in signing in your existed account." << endl;
		clear();
	}
}

// save and load data
void saveuserdata()
{
	fstream file;
	file.open("useradminrecord.txt", ios::out);
	file << a << ",";
	file << b << endl;
	if (usercount > 1)
	{
		for (int x = 1; x < usercount; x++)
		{
			file << names[x] << ",";
			file << passwords[x] << endl;
		}
		file.close();
	}
}
void savebooksdata()
{
	fstream file;
	file.open("books.txt", ios::out);
	for (int x = 0; x < addsize; x++)
	{
		file << books[x] << ",";
		file << author[x] << endl;
	}
	file.close();
}
void saveborrowdata()
{
	fstream file;
	file.open("borrow.txt", ios::out);
	for (int x = 0; x < borrowcount; x++)
	{
		file << borrow[x] << ",";
		file << borrowuser[x] << ",";
		file << month[x] << ",";
		file << date[x] << endl;
	}
	file.close();
}

void loaduserdata()
{
	string record;
	int x = 0;
	fstream myfile;
	myfile.open("useradminrecord.txt", ios::in);
	while (getline(myfile, record))
	{
		names[x] = getfield(record, 1);
		passwords[x] = getfield(record, 2);
		x++;
	}
	usercount = x;
	myfile.close();
}
void loadbooksdata()
{
	string record;
	int x = 0;
	fstream myfile;
	myfile.open("books.txt", ios::in);
	while (getline(myfile, record))
	{
		books[x] = getfield(record, 1);
		author[x] = getfield(record, 2);
		x++;
	}
	addsize = x;
	myfile.close();
}
void loadborrowdata()
{
	string record;
	fstream myfile;
	myfile.open("borrow.txt", ios::app);
	// borrowcount = x;
	myfile.close();
	int x = 0;
	if (borrowcount != 0)
	{
		myfile.open("borrow.txt", ios::in);
		while (getline(myfile, record))
		{
			borrow[x] = getfield(record, 1);
			borrowuser[x] = getfield(record, 2);
			month[x] = stoi(getfield(record, 3));
			date[x] = stoi(getfield(record, 4));
			x++;
		}
		borrowcount = x;
		myfile.close();
	}
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
