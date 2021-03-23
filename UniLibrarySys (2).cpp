#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
using namespace std;
const int NBIS = 10 ;
int nob = 0;
string CorrPassword = "NYUADlib";

void printmenu();
void enterpassword();
void addbook();
void removebook();
void rearrange();
void booksOnShelf();

class Book;
class Shelf;
class Bookcase;


int totalbooks = 0;

int Atotalbooks = 0;
int Btotalbooks = 0;
int Ctotalbooks = 0;

int Ashelfcount = 0;
int Bshelfcount = 0;
int Cshelfcount = 0;



void printmenu();
void addbook();
void SearchBook();
void LoadBooks(string fileName);


class Bookcase {
public:
	vector<Shelf> Library; //declare vector of type shelf
	Bookcase() {};

	void addBookcase(vector<Shelf> bookcasie, int nobc) { //add vector of all shelves to a vector which links all bookcases
		Library.push_back(bookcasie[nobc]);
	};

};

class Shelf {

private:
	int nob;
public:
	vector<Book> books; //declare vector of type book
	Shelf() {};

	void addBook(vector<Book> bookie, int nob) //add vector of all books to a vector which links all the books in a shelf
	{
		books.push_back(bookie[nob]);
	};
	int size(int a) //returns size of books vector
	{
		int x = 0;
		x = books.size();
		return x;
	}

};

class Book {
private:
	string title;
	string author;
	string ISBN;
	string year;
	int Num_of_Copies;

public:
	Book() //constructor of book class
	{
		title = "";
		author = "";
		ISBN = "";
		year = "";
		Num_of_Copies = 0;
	};

	Book(string tit, string aut, string isbn, string yr, int noc) { //5 argument constructor of book class
		title = tit;
		author = aut;
		ISBN = isbn;
		year = yr;
		Num_of_Copies = noc;
	};

	~Book() {}; //destructor of class
	//setters and getters of class: 
	const string getTitle() {
		return this->title;
	}

	void setTitle(string tit) {
		title = tit;

	};

	void setAuthor(string aut) {
		author = aut;           
	};
	string getAuthor(){
		return this->author;           
	};
	void setISBN(string isbn) {
		ISBN = isbn;
	};
	string getISBN() {
		return this->ISBN;
	};

	void setYear(string YEAR) {
		year = YEAR;
	};
	string getYear() {
		return this->year;
	};

	void setNum_of_Copies(int NoCopies) {
		Num_of_Copies = NoCopies;
	};
	int getNum_of_Copies() {
		return Num_of_Copies;
	};
	void print() {
		cout << title << endl;
		cout << author << endl;
		cout << ISBN << endl;
		cout << year << endl;
		cout << Num_of_Copies << endl;
	};

};
//declare vectors of bookcases,shelves and books
vector<Bookcase> bookcases;

vector<Book> Abook;
vector<Shelf> Ashelf;

vector<Book> Bbook;
vector<Shelf>Bshelf;

vector<Book> Cbook;
vector<Shelf> Cshelf;

int main() {
	string title1;
	string author1;
	string ISBN1;
	string year1;
	string value = " ";
	int noc = 0;
	int Num_of_Copies1;
	int booksinshelf = 0;
	//open file
	ifstream AFile("BookcaseA.csv", ios::in);

	if (AFile.fail()) {
		cerr << "Error opening file.\n";
		exit(1);
	}
	getline(AFile, value);//read header line of file
	//omcrease vector size by adding a new object
	Ashelf.push_back(Shelf());

	while (!AFile.eof())
	{
		if (Ashelfcount > 5) //check if limit of shelves reached
			break;
		//read attributes of books:
		getline(AFile, value, ',');
		title1 = value;
		//cout << "title" << title1 << endl;

		getline(AFile, value, ',');
		author1 = value;
		//cout << "Author" << author1 << endl;

		getline(AFile, value, ',');
		ISBN1 = value;
		//cout << "ISBN" << ISBN1 << endl;

		getline(AFile, value, ',');
		year1 = value;
		//cout << "Year" << year1 << endl;

		getline(AFile, value);
		noc = stoi(value);
		Num_of_Copies1 = noc;
		//cout << "NOC" << noc << endl;

		Abook.push_back(Book(title1, author1, ISBN1, year1, noc));//add book to respective vector
		Atotalbooks++; //increment books in bookcase
		booksinshelf++; //increment books in shelf
		totalbooks++; //increment total books in library

		if (noc > 1) { //if no. of copies is greater than 1
			for (int i = 0; i < noc - 1; i++) {
				Abook.push_back(Book(title1, author1, ISBN1, year1, noc));
				Atotalbooks++;
				booksinshelf++;
				totalbooks++;
			}
		}
		if (booksinshelf >= 10) { //if books in a shelf is equal to or greater than 10
			Ashelf.push_back(Shelf());
			Ashelfcount++;
			booksinshelf = 0;
		}

	}
	//add books on to a vector of shelf from a vector of books
	booksinshelf = 0;
	for (int i = 0; i < Ashelfcount; i++) {
		for (int j = 0; j < 10; j++) {
			Ashelf[i].addBook(Abook, j);
			booksinshelf++;
			if (booksinshelf == Atotalbooks) //if books are equal to total books in bookcase
				break;
		}
	}

	for (int j = 0; j < Ashelfcount; j++) {
		bookcases.push_back(Bookcase()); //increase size of vector to add a bookcase to a vector of bookcases
		bookcases[0].addBookcase(Ashelf, j); //add A bookCase on position 0
	}

  //REPEAT ABOVE PROCESS FOR THE REST OF BOOKCASES (FILES)
	
	int addshelf = 0;
	addshelf = 5 - shelfcount;
	for (int i = 0; i < addshelf; i++)
		Ashelf.push_back(Book());

	AFile.close();
	booksinshelf=0;
	ifstream BFile("BookcaseB.csv", ios::in);

	if (BFile.fail()) {
		cerr << "Error opening file.\n";
		exit(1);
	}
	getline(BFile, value);

	Bshelfcount++;
	Bshelf.push_back(Shelf());
	
	while (!BFile.eof())
	{
		if (Bshelfcount > 5)
			break;

		getline(BFile, value, ',');
		title1 = value;
		//cout << "title" << title1 << endl;

		getline(BFile, value, ',');
		author1 = value;
		//cout << "Author" << author1 << endl;

		getline(BFile, value, ',');
		ISBN1 = value;
		//cout << "ISBN" << ISBN1 << endl;

		getline(BFile, value, ',');
		year1 = value;
		//cout << "Year" << year1 << endl;

		getline(BFile, value);
		noc = stoi(value);
		Num_of_Copies1 = noc;
		//cout << "NOC" << noc << endl;

		Bbook.push_back(Book(title1, author1, ISBN1, year1, noc));
		Btotalbooks++;
		booksinshelf++;
		totalbooks++;

		if (noc > 1) {
			for (int i = 0; i < noc - 1; i++) {
				Bbook.push_back(Book(title1, author1, ISBN1, year1, noc));
				Btotalbooks++;
				booksinshelf++;
				totalbooks++;
			}
		}
		if (booksinshelf >= 10) {
			Bshelf.push_back(Shelf());
			Bshelfcount++;
			booksinshelf = 0;
		}

	}

	booksinshelf = 0;
	for (int i = 0; i < Bshelfcount; i++) {
		for (int j = 0; j < 10; j++) {
			Bshelf[i].addBook(Bbook, j);
			booksinshelf++;
			if (booksinshelf == Btotalbooks)
				break;
		}
	}

	for (int j = 0; j < Bshelfcount; j++) {
		bookcases.push_back(Bookcase());
		bookcases[1].addBookcase(Bshelf, j);
	}

	int addshelf = 0;
	addshelf = 5 - shelfcount;
	for (int i = 0; i < addshelf; i++)
		Bshelf.push_back(Book());

	BFile.close();
	booksinshelf = 0;
	ifstream CFile("BookcaseC.csv", ios::in);

	if (CFile.fail()) {
		cerr << "Error opening file.\n";
		exit(1);
	}
	getline(CFile, value);

	
	Cshelf.push_back(Shelf());
	
	char quote,dump;
	Cshelfcount++;
	while (!CFile.eof())
	{
		if (Cshelfcount > 5)
			break;

		CFile >> noskipws >> quote;
		if (quote == '"') {
			getline(CFile, value, '"');
			CFile >> noskipws >> dump;
			title1 = quote + value + quote;
		}
		else
		{
			getline(CFile, value, ',');
			title1 = quote + value;
		}
		//cout << "title" << title1 << endl;

		getline(CFile, value, ',');
		author1 = value;
		//cout << "Author" << author1 << endl;

		getline(CFile, value, ',');
		ISBN1 = value;
		//cout << "ISBN" << ISBN1 << endl;

		getline(CFile, value, ',');
		year1 = value;
		//cout << "Year" << year1 << endl;

		getline(CFile, value);
		//cout << "last value: " << value << endl;
		if (value != ",,,"){
			noc = stoi(value);
			Ctotalbooks++;
			booksinshelf++;
			totalbooks++;
		}
		else{
			noc = 0;
		}
		Num_of_Copies1 = noc;
		//cout << "NOC" << noc << endl;

		Cbook.push_back(Book(title1, author1, ISBN1, year1, noc));
		

		if (noc > 1) {
			for (int i = 0; i < noc - 1; i++) {
				Cbook.push_back(Book(title1, author1, ISBN1, year1, noc));
				Ctotalbooks++;
				booksinshelf++;
				totalbooks++;
			}
		}
		if (booksinshelf>= 10 ) {
			Cshelf.push_back(Shelf());
			Cshelfcount++;
			booksinshelf = 0;
		}
	}

	booksinshelf = 0;
	for (int i = 0; i < Cshelfcount; i++) {
		for (int j = 0; j < 10; j++) {
			Cshelf[i].addBook(Cbook, j);
			booksinshelf++;
			if (booksinshelf == Ctotalbooks)
				break;
		}
	}

	for (int j = 0; j < Cshelfcount; j++) {
		bookcases.push_back(Bookcase());
		bookcases[2].addBookcase(Cshelf, j);
	}

	int addshelf = 0;
	addshelf = 5 - shelfcount;
	for (int i = 0; i < addshelf; i++)
		Cshelf.push_back(Book());

	CFile.close();

	int choice;
	cout << "Welcome to the Library System!" << endl;
	cout << "There are " << totalbooks << " books in the library" << endl;
	//call print menu
	printmenu();
	
	system("pause");
	return 0;
}

void SearchBook()
{
	vector<Book> Search;
	int bookNo(0);
	string dump;
	//string stitle;
	string storedTitle,stitle;
	char caseIs('\n'), shelfIs('\n');
	int noInShelf(-1);
	int ind(-1);
	cout << "Enter the Book to Search" << endl;

	getline(cin, dump);
	getline(cin, stitle, '\n');
	transform(stitle.begin(), stitle.end(), stitle.begin(), toupper);
	for (int i = 0; i < Atotalbooks; i++)
	{
		Search.push_back(Abook[i]);
	}
	for (int j = 0; j < Btotalbooks; j++)
	{
		Search.push_back(Bbook[j]);
	}
	for (int k = 0; k < Ctotalbooks; k++)
	{
		Search.push_back(Cbook[k]);
	}
	for (int l = 0; l < totalbooks; l++)
	{
		storedTitle = Search[l].getTitle();//search if title of book exists in vectors of book
		transform(storedTitle.begin(), storedTitle.end(), storedTitle.begin(), toupper);
		if (storedTitle == stitle) {
			ind = l;
			break;
		}
	}
	bookNo = ind + 1;
	//if book exists then find its identifier or position
	if (ind != -1) {
		if (bookNo <= Atotalbooks) {
			caseIs = 'A';
		}
		else if (bookNo <= Atotalbooks+Btotalbooks) {
			caseIs = 'B';
		}
		else if (bookNo <= Atotalbooks + Btotalbooks+ Ctotalbooks) {
			caseIs = 'C';
		}
		if (caseIs == 'B') {
			bookNo = bookNo - Atotalbooks;
		}
	
		if (caseIs == 'C') {
			bookNo = bookNo - (Atotalbooks+Btotalbooks);
		}
		
		if (bookNo > 0 && bookNo <= 10) {
			shelfIs = '1';
		}
		if (bookNo > 10 && bookNo <= 20) {
			shelfIs = '2';
		}
		if (bookNo > 20 && bookNo <= 30) {
			shelfIs = '3';
		}
		if (bookNo > 30 && bookNo <= 40) {
			shelfIs = '4';
		}
		if (bookNo > 40 && bookNo <= 50) {
			shelfIs = '5';
		}
		if (shelfIs == '1') {
			noInShelf = bookNo;
		}
		if (shelfIs == '2') {
			bookNo=bookNo-10;
			noInShelf = bookNo;
		}
		if (shelfIs == '3') {
			bookNo = bookNo - 20;
			noInShelf = bookNo;
		}
		if (shelfIs == '4') {
			bookNo = bookNo - 30;
			noInShelf = bookNo;
		}
		if (shelfIs == '5') {
			bookNo = bookNo - 40;
			noInShelf = bookNo;
		}
		cout << "book identifier: " << caseIs << shelfIs << '.' << noInShelf<<endl;
	}
	else { cout << "Book not found\n"; }
}

void addbook(){

	string title;
	string author;
	string ISBN;
	string year;
	int Num_of_Copies;
	string location;
	int shelfindex;
	int bookindex;
	//ask for book's attributes
	cout << "Enter the book title." << endl;
	cin >> title;

	cout << "Enter the book author." << endl;
	cin >> author;

	cout << "Enter the book ISBN." << endl;
	cin >> ISBN;

	cout << "Enter the publishing year of the book." << endl;
	cin >> year;

	cout << "Enter the number of copies to be added." << endl;
	cin >> Num_of_Copies;

	cout << "Enter the location to add the book." << endl;
	cin >> location;

	char si = location[1];
	char bi = location[3];

	bookindex = (bi)-'0';
	shelfindex = (si)-'0';
	//store book at the location specified using case of bookcase
	switch (location[0])
	{
	case 'A':
		cout << Ashelf[shelfindex].size(shelfindex);
		if (Ashelf[shelfindex].size(shelfindex) < 10 - Num_of_Copies){
			
			for (int i = 0; i < Atotalbooks; i++) {
				if (Abook[i].getTitle() == title) {
					Abook[i].setNum_of_Copies((Abook[i].getNum_of_Copies()) + Num_of_Copies);
					break;
				}
			}
		
			Abook.insert((Abook.begin() + bi), Book(title, author, ISBN, year, Num_of_Copies));

			LoadBooks("BookcaseA.csv");

		}
		else
			cout << "Error! Not enough space on shelf." << endl;
	case 'B':
		if (Bshelf[shelfindex].size(shelfindex) < 10 - Num_of_Copies){
			for (int i = 0; i < Btotalbooks; i++) {
				if (Bbook[i].getTitle() == title) {
					Bbook[i].setNum_of_Copies((Bbook[i].getNum_of_Copies()) + Num_of_Copies);
					break;
				}
			}
			Bbook.insert((Bbook.begin() + bi), Book(title, author, ISBN, year, Num_of_Copies));
			LoadBooks("BookcaseB.csv");
		}
		else
			cout << "Error! Not enough space on shelf." << endl;
	case 'C':
		if (Cshelf[shelfindex].size(shelfindex) < 10 - Num_of_Copies) {	
			for (int i = 0; i < Ctotalbooks; i++) {
				if (Cbook[i].getTitle() == title) {
					Cbook[i].setNum_of_Copies((Cbook[i].getNum_of_Copies()) + Num_of_Copies);
					break;
				}
			}
			Cbook.insert((Cbook.begin() + bi), Book(title, author, ISBN, year, Num_of_Copies));
			LoadBooks("BookcaseC.csv");
		}
		else
			cout << "Error! Not enough space on shelf." << endl;
	}
}

void booksOnShelf(){

	string location;
	int nob;
	int shelfindex;

	cout << "Enter the shelf identifier." << endl;
	cin >> location;

	char si = location[1];
	//find shelf index based on the shelf input
	shelfindex = si-'0';

	nob = Ashelf[shelfindex].size(shelfindex);
	//check number of books on the particular shelf
	switch (location[0]){
	case 'A':
		nob = Ashelf[shelfindex].size(shelfindex);
	case 'B':
		nob = Bshelf[shelfindex].size(shelfindex);
	case 'C':
		nob = Cshelf[shelfindex].size(shelfindex);
	}

	cout << "There are " << nob << "books on the shelf." << endl;

}

void LoadBooks(string filename) {
	ofstream outFile(filename);
	
	bool found(false);
	//if book has not been written already, write the book to the respective file
	if (filename == "BookcaseA.csv") {
		string * title = new string[Atotalbooks];
		for (int i = 0; i < Atotalbooks; i++) {
			if (i > 0) {
				for (int j = 0; j < i; j++) {
					if (title[j] == Abook[i].getTitle()) {
						found = true;
					}
				}
			}
			if (!found) {
				outFile << Abook[i].getTitle() << ',' << Abook[i].getAuthor() << ',' << Abook[i].getISBN() << ',' << Abook[i].getYear() << ',' << Abook[i].getNum_of_Copies() << endl;
			}
			title[i] = Abook[i].getTitle();
			found = false;
		}
		delete[] title;
	}
	else if (filename == "BookcaseB.csv") {
		string* title = new string[Btotalbooks];
		for (int i = 0; i < Btotalbooks; i++) {
			if (i > 0) {
				for (int j = 0; j < i; j++) {
					if (title[j] == Bbook[i].getTitle()) {
						found = true;
					}
				}
			}
			if (!found) {
				outFile << Bbook[i].getTitle() << ',' << Bbook[i].getAuthor() << ',' << Bbook[i].getISBN() << ',' << Bbook[i].getYear() << ',' << Bbook[i].getNum_of_Copies() << endl;
			}
			title[i] = Bbook[i].getTitle();
			found = false;
		}
		delete[] title;
	}
	if (filename == "BookcaseC.csv") {
		string* title = new string[Ctotalbooks];
		for (int i = 0; i < Ctotalbooks; i++) {
			if (i > 0) {
				for (int j = 0; j < i; j++) {
					if (title[j] == Cbook[i].getTitle()) {
						found = true;
					}
				}
			}
			if (!found) {
				outFile << Cbook[i].getTitle() << ',' << Cbook[i].getAuthor() << ',' << Cbook[i].getISBN() << ',' << Cbook[i].getYear() << ',' << Cbook[i].getNum_of_Copies() << endl;
			}
			title[i] = Cbook[i].getTitle();
			found = false;
		}
		delete[] title;
	}

	
}

void printmenu()
{
	int choice;
	//present options to user
	cout << "Please choose one of the following options: " << endl;

	cout << "1: Search for a book." << endl;
	cout << "2: Add a new book." << endl;
	cout << "3: Remove an existing book." << endl;
	cout << "4: Rearrange books." << endl;
	cout << "5: Access number of books on a shelf." << endl;
	cout << "6: Access number of bookcases in the library." << endl;
	cout << "7: Exit the system." << endl;
	//ask for user choice
	cin >> choice;

	switch (choice)
	{
	case 1:
		SearchBook();
		break;
	case 2:
		enterpassword();
		addbook();
		break;
	case 3:
		enterpassword();
		removebook();
		break;
	case 4:
		enterpassword();
		rearrange();
		break;
	case 5:
		enterpassword();
		booksOnShelf();
		break;
	case 6:
		enterpassword();
		cout << "There are " << "3" << " book cases in the library" << endl;
		break;
	case 7:
		exit(0);
	}
}

void enterpassword()
{
	string password;
	int choice;
	//ask for password
	cout << "Please enter the password." << endl;
	cin >> password;
	
	if (password != CorrPassword)
	{	//give 2 more attempts for password
		for (int i = 0; i < 2; i++)
		{

			cout << "Incorrect password. Please re-enter." << endl;
			cin >> password;

			if (password == CorrPassword)
				break;

			if (i == 1 && password != CorrPassword)
			{
				cout << "Sorry you do not have access to the database. " << endl;
				cout << "Press 1 to return to main menu or 2 to exit the system." << endl;
				cin >> choice;

				if (choice == 1)
					main();
				else
					exit(0);

			}
		}
	}

}

void removebook(){

	string location;
	int shelfindex;
	int bookindex;
	//ask for the book to be removed
	cout << "Enter the book identifier of the book to be removed." << endl;
	cin >> location;
	int vari(-1);
	char si = location[1];
	char bi = location[3];
	//calculate position of book in the book's vector
	bookindex = bi-'0';
	shelfindex = si-'0';

	//remove book from its location based on bookcase
	switch (location[0]){
	case 'A':
		vari = (Abook[bookindex].getNum_of_Copies()) - 1;
		Abook[bookindex].setNum_of_Copies(vari);
		Abook.erase((Abook.begin()+bookindex));
		LoadBooks("BookcaseA.csv");
		cout << "book removed";
		break;
	case 'B':
		vari = (Bbook[bookindex].getNum_of_Copies()) - 1;
		Bbook[bookindex].setNum_of_Copies(vari);
		Bbook.erase(Bbook.begin() + bi - 1);
		LoadBooks("BookcaseB.csv");
		cout << "book removed";
		break;
	case 'C':
		vari = (Cbook[bookindex].getNum_of_Copies()) - 1;
		Cbook[bookindex].setNum_of_Copies(vari);
		Cbook.erase(Cbook.begin() + bi-1);
		LoadBooks("BookcaseC.csv");
		cout << "book removed";
		break;
	}

}

void rearrange(){

	string removebookID, addbookID;
	int shelfindex;
	int bookindex;
	string t, a, i, y;
	int n;
	//ask for book to be rearranged
	cout << "Enter the location identifier of the book you would like to rearrange." << endl;
	cin >> removebookID;

	char si = removebookID[1];
	char bi = removebookID[3];
	//calculate position of the book in vector
	bookindex = bi-'0';
	shelfindex = si-'0';
	//store attributes of the book in variables and then delete the book
	switch (removebookID[0]){
	case 'A':
		t = Abook[((shelfindex - 1) * 10 + bookindex)].getTitle();
		a = Abook[((shelfindex - 1) * 10 + bookindex)].getAuthor();
		i = Abook[((shelfindex - 1) * 10 + bookindex)].getISBN();
		y = Abook[((shelfindex - 1) * 10 + bookindex)].getYear();
		n = Abook[((shelfindex - 1) * 10 + bookindex)].getNum_of_Copies();
		Abook.erase(Abook.begin() + ((shelfindex - 1) * 10 + bookindex));
		LoadBooks("BookcaseA.csv");
	case 'B':
		
		t = Bbook[((shelfindex - 1) * 10 + bookindex)].getTitle();
		a = Bbook[((shelfindex - 1) * 10 + bookindex)].getAuthor();
		i = Bbook[((shelfindex - 1) * 10 + bookindex)].getISBN();
		y = Bbook[((shelfindex - 1) * 10 + bookindex)].getYear();
		n = Bbook[((shelfindex - 1) * 10 + bookindex)].getNum_of_Copies();
		Bbook.erase(Bbook.begin() + ((shelfindex - 1) * 10 + bookindex));
		LoadBooks("BookcaseB.csv");
	case 'C':
		
		t = Cbook[((shelfindex - 1) * 10 + bookindex)].getTitle();
		a = Cbook[((shelfindex - 1) * 10 + bookindex)].getAuthor();
		i = Cbook[((shelfindex - 1) * 10 + bookindex)].getISBN();
		y = Cbook[((shelfindex - 1) * 10 + bookindex)].getYear();
		n = Cbook[((shelfindex - 1) * 10 + bookindex)].getNum_of_Copies();
		Cbook.erase(Cbook.begin() + ((shelfindex - 1) * 10 + bookindex));
		LoadBooks("BookcaseC.csv");
	}
	//ask for location to add the book
	cout << "Where would you like to place this book?" << endl;
	cin >> addbookID;
	//calculate location to add the new book to
	bookindex = bi-'0';
	shelfindex = si-'0';
	//add the book using the stored attributes to respective location
	switch (addbookID[0])
	{
	case 'A':
		if (Ashelf[shelfindex].size(shelfindex) < 10) {
			Abook.insert((Abook.begin() + bookindex), Book(t, a, i, y, n));
			LoadBooks("BookcaseA.csv");
			cout << "rearranged" << endl;
		}
		else
			cout << "Error! Not enough space on shelf." << endl;
	case 'B':
		if (Bshelf[shelfindex].size(shelfindex) < 10) {
			Bbook.insert((Bbook.begin() + bookindex), Book(t, a, i, y, n));
			LoadBooks("BookcaseB.csv");
			cout << "rearranged" << endl;
		}
		else
			cout << "Error! Not enough space on shelf." << endl;
	case 'C':
		if (Cshelf[shelfindex].size(shelfindex) < 10){
			Cbook.insert((Cbook.begin() + bookindex), Book(t, a, i, y, n));
		LoadBooks("BookcaseC.csv");
		cout << "rearranged" << endl;
	}
		else
			cout << "Error! Not enough space on shelf." << endl;

	}

}

