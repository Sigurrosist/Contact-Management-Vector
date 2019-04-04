#include "hdfile.h"


void main_display()
{
	system("cls");

	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "-                  Contact Management Application                 -" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "-                                                                 -" << endl;
	cout << "-                      Please choose a menu                       -" << endl;
	cout << "-                                                                 -" << endl;
	cout << "-                To CREATE a contact information : 1              -" << endl;
	cout << "-                    To DISPLAY ALL the contacts : 2              -" << endl;
	cout << "-                 To SEARCH for a contacts by ID : 3              -" << endl;
	cout << "-To SEARCH for a contacts by FIRST and LAST NAME : 4              -" << endl;
	cout << "-                     To SORT the contacts by ID : 5              -" << endl;
	cout << "-           To SORT the contacts by company NAME : 6              -" << endl;
	cout << "-            To Remove a contact with contact ID : 7              -" << endl;
	cout << "-                                                                 -" << endl;
	cout << "-                        To Exit the application : 8              -" << endl;
	cout << "-                                                                 -" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Please enter the option : ";
}

void add_contact(vector<Contact> &contacts)
{
	char quit = 'p';
	Contact temp;
	do
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
		contacts.push_back(temp);
		cout << "......................New Contact Information is saved!" << endl;
		cout << "\n\n\nIf you want to add more contact, input 'Y'. Otherwise please input any other letter." << endl;
		cin >> quit;
	} while ((quit == 'Y') || (quit == 'y'));
}
void display_contact(vector<Contact> &contacts)
{
	for_each(contacts.begin(), contacts.end(), Displayer());
}
void sort_contact_id(vector<Contact> &contact)
{
	cout << "\n\n...Sorting (by ID).....\n\n";
	sort(contact.begin(), contact.end(), SortID());
	cout << "Contact Infomation is sorted _Ordered by ID : \n\n\n";
	display_contact(contact);
	cout << "- - END - -" << endl;
}
void sort_contact_name(vector<Contact> &contact)
{
	cout << "\n\n...Sorting (by Name).....\n\n";
	sort(contact.begin(), contact.end(), SortName());
	cout << "Contact Infomation is sorted _Ordered by Name : \n\n\n";
	display_contact(contact);
	cout << "- - END - -" << endl;
}
void search_contact_id(vector<Contact> &contacts, vector<Contact> ::iterator iter)
{
	int id;
	cout << "Please enter the ID to look for : ";
	cin >> id;
	iter = find_if(contacts.begin(), contacts.end(), IsEqualID(id));
	cout << "* ID            : " << iter->id << endl;
	cout << "* Name          : " << iter->fname << " " << iter->lname << endl;
	cout << "* Company       : " << iter->company << endl;
	cout << "* Phone Number  : " << iter->pnumber << endl;
	cout << "* Phone Number  : " << iter->fnumber << "\n\n\n" << endl;
}
void search_contact_name(vector<Contact> &contacts)
{
	bool found = false;
	string target;
	cout << "Please enter the full name to search : ";
	cin.ignore();
	getline(cin, target);

	for (int i = 0; i < contacts.size(); i++)
	{
		string full_name = contacts.at(i).fname + " " + contacts.at(i).lname;
		if (full_name == target)
		{
			cout << endl << "-     Result     -" << endl;
			cout << contacts.at(i);
			found = true;
		}
	}
	if (!found)
	{
		cout << "The list does not have the name : " << target << endl;
	}
}
void remove_contact(vector<Contact>&contacts, vector<Contact> ::iterator iter)
{
	int id;
	cout << "Enter the ID to remove from the vector : ";
	cin >> id;
	iter = find_if(contacts.begin(), contacts.end(), IsEqualID(id));

	if (iter != contacts.end())
	{
		contacts.erase(iter);
		cout << "\nData Removed!" << endl;

	}
	else
	{
		cout << "\nData Not Found!" << endl;
	}

	cout << "Current Contact List" << endl;
	display_contact(contacts);

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
