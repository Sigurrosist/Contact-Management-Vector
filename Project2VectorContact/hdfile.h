#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<regex>
using namespace std;

struct Contact
{
	int id;
	string fname, lname;
	string company;
	string pnumber;
	string fnumber;
	Contact() {}
	Contact(int _id, string _fname, string _lname, string _company, string _pnumber, string _fnumber)
	{
		id = _id; fname = _fname; lname = _lname; company = _company; pnumber = _pnumber; fnumber = _fnumber;
	}
};
ostream & operator << (ostream& cout, Contact temp);
struct SortID
{
	bool operator()(Contact a1, Contact a2)
	{
		return a1.id < a2.id;
	}
};
struct SortName
{
	bool operator()(Contact a1, Contact a2)
	{
		return a1.fname < a2.fname;
	}
};
struct Displayer
{
	void operator() (Contact c)
	{
		cout << c;
	}
};
struct IsEqualID
{
	int key;
	IsEqualID() {}
	IsEqualID(int _key)
	{
		key = _key;
	}
	bool operator () (Contact &c)
	{
		return c.id == key;
	}
};
void add_contact(vector<Contact>&);
void display_contact(vector<Contact>&);
void search_contact_id(vector<Contact>&, vector<Contact> ::iterator);
void search_contact_name(vector<Contact>&);
void remove_contact(vector<Contact>&, vector<Contact> ::iterator);
void sort_contact_id(vector<Contact>&);
void sort_contact_name(vector<Contact>&);
void main_display();
