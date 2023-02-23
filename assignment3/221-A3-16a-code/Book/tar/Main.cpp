#include "std_lib_facilities_3.h"
#include "Record.h"
#include "TemplateDoublyLinkedList.h"
#include <fstream>
#include <iomanip>
void display(vector<DoublyLinkedList<Record>> & v)
{
	for (int i = 0; i<v.size(); ++i)
	{
		cout << "LIST:" << i << "\n" << v[i];
		cout << endl << endl;
	}
}

void insert_record(vector<DoublyLinkedList<Record>>& v, Record r)
{
	char temp = '0';
	stringstream ss;
	ss << r.title;
	ss >> temp; //get first letter
	int index = temp - 65;//shift index for ascill
	if (index<0)
	{
		cout << "\n";
		throw "Range error, check capital letter on name input";
	}
	v[index].insert(r); //insert into sorted list
}

Record* search(vector<DoublyLinkedList<Record>>& v, Record r)
{
	Record* result = new Record;
	char temp = '0';
	stringstream ss;
	ss << r.title;
	ss >> temp; //get first letter
	int index = temp - 65;//shift index for ascill
	if (index<0)
	{
		throw "Range error, check capital letter on name input";
	}
	DoublyLinkedList<Record> temp_list1, temp_list2; //create two temp lists to narrow down into a new list

	DListNode<Record>* it = v[index].getFirst();
	int counter = 0;
	while (it != v[index].getAfterLast())
	{
		if ((it->getElem().title).substr(0, (r.title).size()) == r.title)
		{
			*result = it->getElem();
			temp_list1.insert(*result);
			++counter;
		}
		it = it->getNext();
	}
	if (counter == 0)
		return NULL;
	if (counter == 1)
		return result;
	cout << "Sorry there are " << counter << " books that have the title starting with "
		<< r.title << ".\nPlease input the author's name, first letter must be CAPS:\n";
	getline(cin, r.author);
	cin.clear();
	string author = r.author;
	counter = 0;

	it = temp_list1.getFirst();
	while (it != temp_list1.getAfterLast())
	{
		if ((it->getElem().author).substr(0, (r.author).size()) == r.author)
		{
			*result = it->getElem();
			temp_list2.insert(*result);
			++counter;
		}
		it = it->getNext();
	}
	if (counter == 0)
		return NULL;
	if (counter == 1)
		return result;
	cout << "Sorry there are " << counter << " books that have the title starting with "
		<< r.title << " and the author " << r.author << ". Please input its ISBN:\n";
	getline(cin, r.ISBN);
	cin.clear();
	counter = 0;

	it = temp_list2.getFirst();
	while (it != temp_list2.getAfterLast())
	{
		if ((it->getElem().ISBN).substr(0, (r.ISBN).size()) == r.ISBN)
		{
			*result = it->getElem();
			++counter;
		}
		it = it->getNext();
	}
	if (counter == 0)
		return NULL;
	if (counter == 1)
		return result;

	return  result;
}
void Output() {
	string titleOut, authorOut, ISBNOut, editionOut;
	int yearOut;
	ofstream Out;
	Out.open("books.txt", ios::out | ios::app);
	if (Out.is_open()) {
		cin.ignore();
		cout << "Enter the book title: " << "\r\n";
		getline(cin, titleOut);
		cin.clear();
		Out << fixed << showpoint << setprecision(2) << endl << "P" << titleOut << endl;

		cout << "Enter the book author: " << "\r\n";
		getline(cin, authorOut);
		cin.clear();
		Out << fixed << showpoint << setprecision(2) << authorOut << endl;

		cout << "Enter the book ISBN: " << "\r\n";
		getline(cin, ISBNOut);
		cin.clear();
		Out << fixed << showpoint << setprecision(2) << ISBNOut << endl;

		cout << "Enter the book year: " << "\r\n";
		cin >> yearOut;
		cin.ignore();
		Out << fixed << showpoint << setprecision(2) << yearOut << endl;

		cout << "Enter the book edition: " << "\r\n";
		getline(cin, editionOut);
		cin.clear();
		Out << fixed << showpoint << setprecision(2) << editionOut;

		Out.close();
	}
	else cout << "could not open file." << endl;
	return;
}
int main()
try

{
	Record temp;
	vector<DoublyLinkedList<Record>> Books(26);
	cout << "Do you want to insert a book? Type 1 to insert a book, 2 for searching, or anything else to exit:" << endl;
	int x;
	cin >> x;
	do {
		if (x == 1) Output();
		else if (x == 2){
			ifstream in("books.txt");
			if (!in.is_open())
				throw 1;
			cin.ignore();
			while (!in.eof())
			{
				in >> temp;
				insert_record(Books, temp);
			}
			display(Books);
			string title;
			cout << "Please input title, first letter must be CAPS:\n";
			getline(cin, title);
			Record input;
			input.title = title;
			Record* result = search(Books, input);
			if (result == NULL)
				cout << "Sorry match not found in database\n";
			else
				cout << "Match found!:\n" << *result;
			in.close();

			if (cin.fail())
				throw 2;
		}
		cout << "Would you like to enter another book or search for a book? Type 1 for book, 2 for search: " << endl;
		cin >> x;
	} while (x == 1 || x == 2);
	return 0;

}

catch (int & e)
{
	if (e == 1)
		cout << "Error could not open file\n";
	if (e == 2)
		cout << "Error input fail, check ISBN for correct input\n";
	if (e != 1 || e != 2)
		cout << "Integer exception, error unknown\n";
}
catch (string & s)
{
	cout << s;
}

catch (...)
{

	cout << "Range error on vector check capital letter on name input\n";
}
