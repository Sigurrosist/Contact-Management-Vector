#include "Header.h"
void add_contact(vector<Contact> contact)
{
	Contact temp;
	char quit = 'p';
	do 
	{
		cin >> temp;
		contact.push_back(temp);
		cout << "......................New Contact Information is saved!" << endl;
		cout << "\n\n\nIf you want to add more contact, input 'Y'. Otherwise please input any other letter." << endl;
		cin >> quit;
	} while ((quit == 'Y') || (quit == 'y'));
}
void display_contact(vector<Contact> contact)
{
	cout << "\n\n\Displaying data......\n\n\n";

	for_each(contact.begin(), contact.end(), myDisplayer1);
	system("pause");
}
void sort_contact_id(vector<Contact> contact)
{
	cout << "Current order of Contact Infomation : \n\n\n";
	display_contact(contact);
	cout << "\n\n...Sorting (by ID).....\n\n";
	sort(contact.begin(), contact.end(), sortID);
	cout << "Contact Infomation is sorted _Ordered by ID : \n\n\n";
	display_contact(contact);
	cout << "- - END - -" << endl;
}
void sort_contact_name(vector<Contact> contact)
{
	cout << "Current order of Contact Infomation : \n\n\n";
	display_contact(contact);
	cout << "\n\n...Sorting (by ID).....\n\n";
	sort(contact.begin(), contact.end(), sortName);
	cout << "Contact Infomation is sorted _Ordered by ID : \n\n\n";
	display_contact(contact);
	cout << "- - END - -" << endl;
}


ostream & operator << (ostream& cout, Contact temp)
{
	cout << "* ID            : " << temp.id << endl;
	cout << "* Name          : " << temp.fname << " " << temp.lname << endl;
	cout << "* Company       : " << temp.company << endl;
	cout << "* Phone Number  : " << temp.pnumber << endl;
	cout << "* Phone Number  : " << temp.fnumber << "\n\n\n" << endl;
	return cout;
}
istream & operator >> (istream& cin, Contact temp)
{
	bool error = false;
	do
	{
		system("cls");
		error = false;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "ID                     : ";
		cin >> temp.id;
		if (cin.fail())
		{
			cout << "* ID should be integer value. *" << endl;
			error = true;
			cin.clear();
			cin.ignore(256, '\n');
			system("pause");
		}
	} while (error);

	do
	{
		system("cls");
		cout << "* * * * * Contact Information * * * * *" << endl;
		cout << "* ID            : " << temp.id << "\n\n\n" << endl;

		error = false;
		regex myR("[a-zA-Z ]+");
		cout << "First Name             : ";
		cin.clear();
		getline(cin, temp.fname);
		if (!regex_match(temp.fname, myR))
		{
			cout << "* First Name should contain only letters." << endl;
			system("pause");
			error = true;
		}
	} while (error);

	do
	{
		system("cls");
		cout << "* * * * * Contact Information * * * * *" << endl;
		cout << "* ID            : " << temp.id << endl;
		cout << "* First Name    : " << temp.fname << "\n\n\n" << endl;
		error = false;
		regex myR("[a-zA-Z ]+");
		cout << "Last Name             : ";
		cin.clear();
		getline(cin, temp.lname);
		if (!regex_match(temp.lname, myR))
		{
			cout << "* Last Name should contain only letters." << endl;
			system("pause");
			error = true;
		}
	} while (error);

	do
	{
		system("cls");
		cout << "* * * * * Contact Information * * * * *" << endl;
		cout << "* ID            : " << temp.id << endl;
		cout << "* Name          : " << temp.fname << " " << temp.lname << "\n\n\n" << endl;
		error = false;
		regex myR("[a-zA-Z ]+");
		cout << "Company              : ";
		cin.clear();
		getline(cin, temp.company);
		if (!regex_match(temp.company, myR))
		{
			cout << "* Company Name should contain only letters." << endl;
			system("pause");
			error = true;
		}
	} while (error);

	do
	{
		system("cls");
		cout << "* * * * * Contact Information * * * * *" << endl;
		cout << "* ID            : " << temp.id << endl;
		cout << "* Name          : " << temp.fname << " " << temp.lname << endl;
		cout << "* Company       : " << temp.company << "\n\n\n" << endl;
		error = false;
		regex myR("\\d{10}");
		cout << "Phone Number    : ";
		cin.clear();
		getline(cin, temp.pnumber);
		string tmp = "";
		for (int i = 0; i < temp.pnumber.size(); ++i)
		{
			if (temp.pnumber[i] >= 48 && temp.pnumber[i] <= 57) // using ascii code for integer values
			{
				tmp += temp.pnumber[i];
			}
		}
		temp.pnumber = tmp;

		if (!regex_match(temp.pnumber, myR))
		{
			cout << "* Phone Number should be composed of 10 digits." << endl;
			system("pause");
			error = true;
		}
	} while (error);

	do
	{
		system("cls");
		cout << "* * * * * Contact Information * * * * *" << endl;
		cout << "* ID            : " << temp.id << endl;
		cout << "* Name          : " << temp.fname << " " << temp.lname << endl;
		cout << "* Company       : " << temp.company << endl;
		cout << "* Phone Number  : " << temp.pnumber << "\n\n\n" << endl;
		error = false;
		regex myR("\\d{10}");
		cout << "Fax Number    : ";
		cin.clear();
		getline(cin, temp.fnumber);
		string tmp = "";
		for (int i = 0; i < temp.fnumber.size(); ++i)
		{
			if (temp.fnumber[i] >= 48 && temp.fnumber[i] <= 57) // using ascii code for integer values
			{
				tmp += temp.fnumber[i];
			}
		}
		temp.fnumber = tmp;

		if (!regex_match(temp.fnumber, myR))
		{
			cout << "* Phone Number should be composed of 10 digits." << endl;
			system("pause");
			error = true;
		}
	} while (error);

	system("cls");
	cout << "* * * * * Contact Information * * * * *" << endl;
	cout << "* ID            : " << temp.id << endl;
	cout << "* Name          : " << temp.fname << " " << temp.lname << endl;
	cout << "* Company       : " << temp.company << endl;
	cout << "* Phone Number  : " << temp.pnumber << endl;
	cout << "* Phone Number  : " << temp.fnumber << "\n\n\n" << endl;

	return cin;
}