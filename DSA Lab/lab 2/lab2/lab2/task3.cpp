#include<iostream>
#include<string>
using namespace std;

//// template for selection sorting
//template<typename t , int size>
//void selectionSort(t* (arr)[size]) {
//	for (int i = 0; i < size; i++) {
//		for (int j = i; j < size; j++) {
//			if (arr[i] > arr[j]) {
//				swap(arr[i], arr[j]);
//			}
//		}
//	}
//}
//
////template for swap funciton
//template<typename t>
//void swap(t &a, t &b) {
//	t temp = t();
//	temp = a;
//	a = b;
//	b = temp;
//}

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
	int getbookPages() {
		return bookPages;
	}
	string getBookName() {
		return bookName;
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
	string getEdition() {
		return edition;
	}
	string getnewspaperName() {
		return newspaperName;
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

		cout << endl << endl;

		cout << "list of newspaper: " << endl;
		for (int i = 0; i < newspaperCount; i++) {
			newspaper[i].display();
		}
	}
	
	// how will we call the template funciton here?? i will have to revise the previous work and come up with the solution :)
	void sortBooksByPages() {
		for (int i = 0; i < bookCount; i++) {
			for (int j = i; j < bookCount; j++) {
				if (books[i].getbookPages() > books[j].getbookPages()) {
					// swap the objects in the array
					Book temp = books[i];
					// do i need a copy constructor for this?? :(
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}

	void sortNewspapersByEdition() {
		for (int i = 0; i < newspaperCount; i++) {
			for (int j = i; j < newspaperCount; j++) {
				if (newspaper[i].getEdition() > newspaper[j].getEdition()) {
					// swapping the objects :)
					Newspaper temp = newspaper[i];
					newspaper[i] = newspaper[j];
					newspaper[j] = temp;
				}
			}
		}
	}

	Book* searchBookByTitle(const string key) {
		// will will use linear search to traverse through the entire array and find the appropriate book
		for (int i = 0; i < bookCount; i++) {
			
			if (books[i].getBookName() == key) {
				// we would retun a pointer to this object
				Book* temp = &(books[i]);
				return temp;
			}

		}
		return NULL;
	}


	Newspaper* searchNewspaperByName(const string key) {
		for (int i = 0; i < newspaperCount; i++) {

			if (newspaper[i].getnewspaperName() == key) {
				Newspaper* temp = &(newspaper[i]);
				return temp;
			}

		}
		return NULL;
	}
// using selection sort to sort the array O(n^2) time complexity
// i guess i'll have to make this function a friend function inside that so that
// another function to access all the data members associated with that function.

};



int main() {

	// Create book objects
	Book book1("The Catcher in the Rye", "J.D. Salinger", 324);
	Book book2("To Kill a Mockingbird", "Harper Lee", 277);

	// Create newspaper objects
	Newspaper newspaper1("Washington Post", "2024-10-13", "Weekend Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Morning Edition");

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
	
	// Sort books by pages and newspapers by edition
	library.sortBooksByPages();
	library.sortNewspapersByEdition();

	cout << "\nAfter Sorting:\n";
	library.displayCollection();

	// Search for a book by title
	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		cout << "\nFound Book:\n";
		foundBook->display();
	}
	else {
		cout << "\nBook not found.\n";
	}

	// Search for a newspaper by name
	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	}
	else {
		cout << "\nNewspaper not found.\n";
	}

	return 0;
}

