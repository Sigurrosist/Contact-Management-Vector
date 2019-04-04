/* 

	Project 2 - Vector of Contacts

	Author : Jooyeon Mok
	2018-04-02
	Version 1.3

	Objective:
	Create a vector of contacts and implement the necessary functions to :
	1 - add a contact - ok
	2 - display all contacts - ok
	3 - remove a contact from the vector
	4 - search for a contact : use 2 kinds of keys(one should be int value and the other should be string value) - ok
	5 - sort contacts : use 2 kinds of keys(one should be int value and the other should be string value) - ok

*/
#include "hdfile.h"

int main()
{
	vector<Contact> contacts;
	vector<Contact> ::iterator iter;
	contacts.push_back(Contact(311, "Joo yeon", "Mok", "LaSalle College", "5145495016", "1234567890"));
	contacts.push_back(Contact(2, "Sally Kat", "Sayuri", "Tawasaki", "1234567897", "1234567895"));
	contacts.push_back(Contact(31, "Kong Kat", "Totoro", "CAT.com", "7977977979", "1311311313"));
	contacts.push_back(Contact(64, "Leonard", "Haruki", "Bird Watcher", "5959595959", "1941919419"));
	int choice = 0;
	char quit = 'n';
	
	while ((quit != 'Q') || (quit != 'q'))
	{
		main_display();
		cin >> choice;

		if ((choice > 0) || (choice < 9))
		{
			switch (choice)
			{
			case 1:
				add_contact(contacts);
				system("pause");

				break;
			case 2:
				display_contact(contacts);
				system("pause");

				break;
			case 3:
				search_contact_id(contacts, iter);
				system("pause");

				break;
			case 4:
				search_contact_name(contacts);
				system("pause");

				break;
			case 5:
				sort_contact_id(contacts);
				system("pause");

				break;
			case 6:
				sort_contact_name(contacts);
				system("pause");

				break;
			case 7:
				remove_contact(contacts, iter);
				system("pause");

				break;
			case 8:
				cout << "Do you really want to exit the program?" << endl;
				cin >> quit;
			}
		}
		else
		{
			if ((choice < 1) || (choice > 8) || cin.fail())
			{
				cout << "\n\nPlease choose the correct option.\n\n" << endl;
			}
		}
	}

	cout << "\n\n\nEnd of Testing\n\n\n";
	system("pause");
	return 0;
}

/*
1) ADD
* * * * * Contact Information * * * * *
* ID            : 266
* Name          : Jason Lee
* Company       : Head
* Phone Number  : 2322322323
* Phone Number  : 3233233232



......................New Contact Information is saved!



If you want to add more contact, input 'Y'. Otherwise please input any other letter.

2) Display
* ID            : 311
* Name          : Joo yeon Mok
* Company       : LaSalle College
* Phone Number  : 5145495016
* Phone Number  : 1234567890



* ID            : 2
* Name          : Sally Kat Sayuri
* Company       : Tawasaki
* Phone Number  : 1234567897
* Phone Number  : 1234567895



* ID            : 31
* Name          : Kong Kat Totoro
* Company       : CAT.com
* Phone Number  : 7977977979
* Phone Number  : 1311311313



* ID            : 64
* Name          : Leonard Haruki
* Company       : Bird Watcher
* Phone Number  : 5959595959
* Phone Number  : 1941919419


3) Search by ID
Please enter the ID to look for : 31
* ID            : 31
* Name          : Kong Kat Totoro
* Company       : CAT.com
* Phone Number  : 7977977979
* Phone Number  : 1311311313

4) Search by Name
Please enter the full name to search : Joo yeon Mok

-     Result     -
* ID            : 311
* Name          : Joo yeon Mok
* Company       : LaSalle College
* Phone Number  : 5145495016
* Phone Number  : 1234567890

5) Sort by ID
Contact Infomation is sorted _Ordered by ID :


* ID            : 2
* Name          : Sally Kat Sayuri
* Company       : Tawasaki
* Phone Number  : 1234567897
* Phone Number  : 1234567895



* ID            : 31
* Name          : Kong Kat Totoro
* Company       : CAT.com
* Phone Number  : 7977977979
* Phone Number  : 1311311313



* ID            : 64
* Name          : Leonard Haruki
* Company       : Bird Watcher
* Phone Number  : 5959595959
* Phone Number  : 1941919419



* ID            : 311
* Name          : Joo yeon Mok
* Company       : LaSalle College
* Phone Number  : 5145495016
* Phone Number  : 1234567890


6) Sort by Name
* ID            : 311
* Name          : Joo yeon Mok
* Company       : LaSalle College
* Phone Number  : 5145495016
* Phone Number  : 1234567890



* ID            : 31
* Name          : Kong Kat Totoro
* Company       : CAT.com
* Phone Number  : 7977977979
* Phone Number  : 1311311313



* ID            : 64
* Name          : Leonard Haruki
* Company       : Bird Watcher
* Phone Number  : 5959595959
* Phone Number  : 1941919419



* ID            : 2
* Name          : Sally Kat Sayuri
* Company       : Tawasaki
* Phone Number  : 1234567897
* Phone Number  : 1234567895

7) Remove a Contact
Enter the ID to remove from the vector : 64

Data Removed!
Current Contact List
* ID            : 311
* Name          : Joo yeon Mok
* Company       : LaSalle College
* Phone Number  : 5145495016
* Phone Number  : 1234567890



* ID            : 31
* Name          : Kong Kat Totoro
* Company       : CAT.com
* Phone Number  : 7977977979
* Phone Number  : 1311311313



* ID            : 2
* Name          : Sally Kat Sayuri
* Company       : Tawasaki
* Phone Number  : 1234567897
* Phone Number  : 1234567895



*/