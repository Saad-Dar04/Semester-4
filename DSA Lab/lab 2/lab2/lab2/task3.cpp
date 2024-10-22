#include<iostream>
#include<string>
using namespace std;

class Book {
private:
	string bookName;
	string authorName;
	int bookPages;
public:
	Book(string bookName = "", string authorName = "", int bookPages = 0) : bookName(bookName), authorName(authorName), bookPages(bookPages) {}
	void display() {
		cout << bookName << "  " << authorName << "  " << bookPages << endl;
	}
};


class Newspaper {
private:
	string newspaperName;
	string date;
	string edition;
public:
	Newspaper(string name = "", string date = "", string edition = "") :newspaperName(name), date(date), edition(edition) {}
	void display() {
		cout << newspaperName << "  " << date << "   " << edition << endl;
	}
};

class Library : public Book, public Newspaper {
private:
	Book* books;
	int bookCount;
	Newspaper* newspaper;
	int newspaperCount;
public:
	Library() {
		bookCount = 0;
		newspaperCount = 0;
		books = nullptr;
		newspaper = nullptr;
	}

	void addBook(const Book& newBook) {
		// it will allocate new memory with each book added , new memory will be
		// allocated and the books will be moved to that new memory location.
		// if firstBook is added we dont need to transfer the old books to the new memory location
		// but if their already exists a book we need to 
		if (bookCount == 0) {
			bookCount++;
			books = new Book[bookCount];
			books[bookCount-1] = newBook;
		}
		else {
			// allocating new memory
			bookCount++;
			Book* ptr = new Book[bookCount];
			// transferring the previous objects to this newly allocated memory
			for (int i = 0; i < bookCount-1; i++) {
				ptr[i] = books[i];
			}
			ptr[bookCount-1] = newBook;
			delete[] books;
			books = ptr;
		}
	}

	void addNewspaper(const Newspaper& addition) {
		if (newspaperCount == 0) {
			newspaperCount++;
			newspaper = new Newspaper[newspaperCount ];
			newspaper[newspaperCount-1] = addition;
		}
		else {
			newspaperCount++;
			Newspaper* ptr = new Newspaper[newspaperCount];
			for (int i = 0; i < newspaperCount-1; i++) {
				ptr[i] = newspaper[i];
			}
			ptr[newspaperCount - 1] = addition;
			delete[] newspaper;
			newspaper = ptr;
		}
	}

	void displayCollection() {
		cout << "list of books: " << endl;
		for (int i = 0; i < bookCount; i++) {
			 books[i].display();
		}

		cout << endl << endl << endl;

		cout << "list of newspaper: " << endl;
		for (int i = 0; i < newspaperCount; i++) {
			newspaper[i].display();
		}
	}


};

int main() {

	// Create book objects
	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);

	// Create newspaper objects
	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

	// Create a library object
	Library library;

	// Add books and newspapers to the library
	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);

	// Display the entire collection
	cout << "Before Sorting:\n";
	library.displayCollection();
	



	return 0;
}