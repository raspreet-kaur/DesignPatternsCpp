#include <iostream>
#include <string>
#include <map>
using namespace std;
//design a online library, book management 



class Book
{
private:

	int bookId;
	string title;

public:
	Book()
	{}
	Book(int id, string title) :bookId(id), title(title) {}

	//Book(int id, string title) 
	//{
	//	this->bookId = id;
	//	this->title = title; // The a->b notation is usually just a shorthand for (*a).b.		
	//}

	int getId() { return bookId; }
	void setId(int id) { this->bookId = id; }

	void setTitle(string title) { this->title = title; }
	string getTitle() { return title; }
};

class User
{
private:

	int libId;
	string name;

public:
	User()
	{}
	User(int id, string name) :libId(id), name(name) {}

	//Book(int id, string title) 
	//{
	//	this->bookId = id;
	//	this->title = title; // The a->b notation is usually just a shorthand for (*a).b.		
	//}

	int getId() { return libId; }
	void setId(int id) { this->libId = id; }

	void setName(string title) { this->name = title; }
	string getName() { return name; }
};


class Library {
private:
	map<int, Book> books;
public:

	Library() {
		map<int, Book> books;
	}

	bool addBook(Book book)
	{
		if (books.find(book.getId()) != books.end())
			return false;
		books[book.getId()] = book;
		//books.insert(make_pair(book.getId(), book));
		return true;
	}

	bool addBook(int id, string name)
	{
		if (books.find(id) != books.end()) return false;

		books[id] = { id, name };
		return true;
	}

	bool removeBook(Book book)
	{
		return removeBook(book.getId());
	}

	bool removeBook(int id)
	{
		if (books.find(id) != books.end())
			books.erase(id);
		return true;
		return false;
	}

	Book search(int id)
	{
		map<int, Book>::iterator it;
		for (it = books.begin(); it != books.end(); ++it) {
			if (it->first == id) return it->second;
		}

	}
};

class UserRecords {
private:
	map<int, User> users;
public:

	UserRecords() {
		map<int, User> users;
	}

	bool addUser(User user)
	{
		if (users.find(user.getId()) != users.end())
			return false;
		users[user.getId()] = user;
		//books.insert(make_pair(book.getId(), book));
		return true;
	}

	bool addUser(int id, string name)
	{
		if (users.find(id) != users.end()) return false;

		users[id] = { id, name };
		return true;
	}

	bool removeUser(User user)
	{
		return removeUser(user.getId());
	}

	bool removeUser(int id)
	{
		if (users.find(id) != users.end())
			users.erase(id);
		return true;
		return false;
	}

	User search(int id)
	{
		map<int, User>::iterator it;
		for (it = users.begin(); it != users.end(); ++it) {
			if (it->first == id) return it->second;
		}

	}
};

class Display {
private:
	User activeUser;
	Book activeBook;
	 int pageNumber = 0;
public:
	void displayUser(User user)
	{
		activeUser = user;
		setcurrentUserInformation();
	}

	void displayBook(Book book)
	{
		activeBook = book;
		setcurrentBookInformation();
		pageNumber = 0;
		CurrPageInfo();

	}
	void setcurrentUserInformation()
	{
		cout << "active username is: "<< activeUser.getName() << endl;
	}
	void setcurrentBookInformation()
	{
		cout << "book studying right now :" << activeBook.getTitle() << endl;
	}
	void CurrPageInfo()
	{
		cout <<"On page:"<< pageNumber<<endl;
	}
	void clickedOnNextPage()
	{
		pageNumber++;
		CurrPageInfo();

	}
	void clickedOnPrevPage()
	{
		pageNumber--;
		CurrPageInfo();
	}

};

class OnlineReaderSystem {
private:
	Library library;
	User activeUser;
	Book activeBook;
	UserRecords manager;
	Display display;

public:
	 OnlineReaderSystem()
	{
		
	}

	 Library getLibrary()
	 {
		 return library;
	 }

	 UserRecords getUserManager()
	 {
		  return manager;
	 }

	 Display getDisplay()
	 {
		 return display;
	 }

	 Book getActiveBook()
	 {
		 return activeBook;
	 }

	 void setActiveBook(Book book)
	 {
		 activeBook = book;
		 display.displayBook(book);
	 }

	User getActiveUser()
	 {
		 return activeUser;
	 }

	 void setActiveUser(User user)
	 {
		 activeUser = user;
		 display.displayUser(user);
	 }
};


int main()
{
	Book b(12, "CS");
	OnlineReaderSystem onlineReaderSystem;

	Book dsBook(1, "Ds");
	Book algoBook(2, "Algo");

	Library lib = onlineReaderSystem.getLibrary();
	lib.addBook(dsBook);
	lib.addBook(algoBook);

	User user1(1, "Ram");
	User user2(2, "Gopal");

	UserRecords records = onlineReaderSystem.getUserManager();
	records.addUser(user1);
	records.addUser(user2);

	onlineReaderSystem.setActiveBook(algoBook);
	onlineReaderSystem.setActiveUser(user1);

	Display ds = onlineReaderSystem.getDisplay();
	ds.clickedOnNextPage();
	ds.clickedOnNextPage();
	ds.clickedOnNextPage();
	ds.clickedOnNextPage();

	ds.clickedOnPrevPage();

	//cout << "hello" << endl;
	getchar();
	return 0;
}
