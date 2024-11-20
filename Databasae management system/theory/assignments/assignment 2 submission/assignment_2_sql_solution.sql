
create database assignment2;
use assignment2;

create table BOOK(
Book_id int,
Title varchar(255) not null,
Publisher_name varchar(255),
constraint pk_BOOK primary key(Book_id)
);
show columns from BOOK;

/*weak relationship*/
create table BOOK_AUTHORS(
Book_id int,
Author_name varchar(255),
constraint pk_BOOK_AUTHORS primary key(Book_id , Author_name),
constraint fk_BOOK_BOOK_AURHTOS foreign key(Book_id) references BOOK(Book_id) on update cascade on delete cascade
);
show columns from BOOK_AUTHORS;
 /* on deletion of the book pk , in this table the respective tuple having author name will also delete(the entire column will) thus showing
the existance of the book_author entries are entirely reliant on the book id and would cease to exist without them*/

create table PUBLISHER(
Name varchar(255),
Address varchar(255),
Phone varchar(255),
constraint pk_PUBLISHER primary key(Name)
);
SHOW COLUMNS FROM PUBLISHER;

/* creating reference between publisher_name residing in the book relation with the publisher table*/
alter table BOOK
modify Publisher_name varchar(255) DEFAULT 'author not in database';
show columns from BOOK;

alter table BOOK
ADD CONSTRAINT fk_PUBLISHER_BOOK foreign key(Publisher_name) references PUBLISHER(Name) on update cascade on delete set DEFAULT;
show columns FROM BOOK;
SELECT* FROM BOOK;

/* many->many relationship a seperate table will be created.
a book can be in many brances and a branch can have many copies of same book.*/
/* for composite primary key heard about a increment something that is used for cpk , read about it and then implement here*/
create table BOOK_COPIES(
Book_id int,
Branch_id int,
No_of_copies int,
constraint pk_BOOK_COPIES primary key(Book_id , Branch_id),
constraint fk_BOOK_BOOK_COPIES foreign key(Book_id) references BOOK(Book_id) on update cascade on delete cascade
/* if the books get's deleted from our database no need of keeping it's info about it's copies in our database*/
);
show columns from BOOK_COPIES;

create table LIBRARY_BRANCH(
Branch_id int,
Branch_name varchar(255) not null,
Address varchar(255) not null,
constraint pk_LIBRARY_BRANCH primary key(Branch_id)
);
show columns fROM LIBRARY_BRANCH;

/* creating reference of the foreign key of library_branch residing in the book_copies table*/
alter table BOOK_COPIES
ADD CONSTRAINT fk_LIBRARY_BRANCH_BOOK_COPIES foreign key(Branch_id) references LIBRARY_BRANCH(Branch_id) on update cascade on delete cascade;
show columns from BOOK_COPIES;

create table BORROWER(
Card_no int,
Name varchar(255),
Address varchar(255),
Phone int,
constraint pk_BORROWER primary key(Card_no)
);
show columns FROM BORROWER;

/* TERTIARY RELATIONSHIP BETWEEN BOOK_ID , BRANCH_ID , CARD_NO ALL ARE REQUIRED TO KEEP INFO ABOUT THE BOOKS LOANED OUT AND EXTRA INFO LIKE DATE_OUT AND DUE_DATE COMES TO US BECUASE OF THESE RELATIONSHIP ;)
/* I WILL TRY IMPLEMENTING ON DELETE RESTRICT FOR THIS , WHAT THIS QUERY WILL DO IS STOP THE DELETION OF BOOK , BORROWER AND BRANCH INFO IF THE SPECIFIC BOOK IS LOANED OUT ALL THE INFO RELATED TO IT WILL NOT BE ABLE TO BE DELETED. BOOK_LOAN WALEY RELATIONSHIP K PASS IKHTEYAAR AJATA HAE AND
IT DOES NOT ALLOWS FOR IT TO BE DELETED.*/
CREATE TABLE BOOK_LOANS(
Book_id int,
Branch_id int,
Card_id int,
Date_out date not null,
Due_date date not null,
constraint pk_BOOK_LOANS primary key(Book_id , Branch_id , Card_id),
constraint fk_BOOK_BOOK_LOANS foreign key(Book_id) references BOOK(Book_id) on update cascade on delete restrict,
constraint fk_LIBRARY_BRANCH_BOOK_LOANS foreign key(Branch_id) references LIBRARY_BRANCH(Branch_id) on update cascade on delete restrict,
constraint fk_BORROWER_BOOK_LOANS foreign key(Card_id) references BORROWER(Card_no) on update cascade on delete restrict
);


/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Q2 INSERTING VALUES INTO THE DATABASE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
