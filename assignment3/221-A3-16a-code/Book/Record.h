#include "std_lib_facilities_3.h"

class Record {

public:
	string title;
	string author;
	string ISBN;
	int year;
	string edition;

	Record& operator =(const Record& r) {
		title = r.title;
		author = r.author;
		ISBN = r.ISBN;
		year = r.year;
		edition = r.edition;

	}

	friend bool operator <(const Record& r1, const Record& r2) {
		if (r1.title<r2.title)
			return true;
		if (r1.title == r2.title&&r1.author<r2.author)
			return true;
		if (r1.title == r2.title&&r1.author == r2.author&&r1.ISBN<r2.ISBN)
			return true;
		return false;
	}

};



ostream& operator <<(ostream& os, Record& r) {
	os << r.title << ", Author: "
		<< r.author << "\nISBN: "
		<< r.ISBN<< ", Year: "
		<< r.year << ", "
		<< r.edition << endl;
	return os;
}

istream& operator >>(istream& is, Record& r) {
	string temp;
	getline(is, temp);
	r.title = temp;
	getline(is, temp);
	r.author = temp;
	getline(is, temp);
	r.ISBN = temp;
	getline(is, temp);
	r.year = atoi(temp.c_str());
	getline(is, temp);
	r.edition = temp;
	is.ignore();
	return is;
}
