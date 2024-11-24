create database practice_on_delete;
use practice_on_delete;

create table BOOK(
Book_id int,
Title varchar(255),
Publisher_name varchar(255) DEFAULT 'NO PUBLISHER', 
constraint pk_BOOK primary key(Book_id)
);
DROP TABLE BOOK;
DROP TABLE PUBLISHERS;

create table PUBLISHERS(
Name varchar(255),  
Address varchar(255),
phone int,
constraint pk_PUBLISHER primary key(Name) /* SINCE THIS IS A PRIMARY KEY THIS CANNOT BE SET TO DEFAULT  , AND USING A DEFAULT WITH PRIMARY KEY WILL NOT WORK BECAUSE PRIMARY KEY'S CANNOT REPEAT THEY ARE UNIQUE VALUES WITHIN A TABLE*/
);
/*INSERTING THE DEFAULT VALUE IN PUBLISHERS TO AVOID REFERENTIAL INTEGRITY*/
INSERT INTO PUBLISHERS(Name)
value('NO PUBLISHER');
SELECT* 
from PUBLISHERS;
/* INSERTED THE VALUE 'NO PUBLISHER' INTO PUBLISHER TO AVOID REFERNTIAL INTEGRITY , IN CASE THE VALUES IN PUBLISHER TABLE ARE DELETED THE BOOK AUTHOR WILL BE SET TO DEFAULT VALUE 'NO PUBLISHER' AND THAT NO PUBLISHER ALREADY EXISTS in publisher hence referential integrity/foreign key constraint error wont show up*/
/* and since it's a foreign key it can be repeated multiple times*/

alter table BOOK
add constraint fk_BOOK_PUBLISHER FOREIGN KEY(Publisher_name) references PUBLISHERS(Name) on update cascade on delete set default;

INSERT INTO BOOK
value
(8000 , 'Don Quixote' , default ),
(8001 , 'A Tale of Two Cities' , default ),
(8002 , 'The Lord of Rings' , default ),
(8003 , 'And Then There Were None' , default ),
(8004 , 'The Hobbit' , default);

SELECT* FROM BOOK;

INSERT INTO PUBLISHER
value
(

