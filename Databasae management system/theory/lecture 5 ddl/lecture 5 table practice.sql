create database companyName;
drop database companyName;
create database companyName;

use companyName;
DROP TABLE Employee;
DROP TABLE Department;

CREATE TABLE Department(
Dname VARCHAR(255) NOT NULL,
Dnumber INT CHECK(Dnumber>0 AND Dnumber<21),
Mgr_ssn INT ,
Mgr_start_date DATE,
CONSTRAINT PK_Department PRIMARY KEY(Dnumber)
);
SELECT* FROM Department;

CREATE TABLE Employee(
Fname VARCHAR(255) NOT NULL,
Minit CHAR(2) , 
Lname VARCHAR(255) NOT NULL,
SSN INT ,
Bdate DATE NOT NULL,
Address VARCHAR(255) NOT NULL,
Gender CHAR(1),
Salary int,
Super_SSN int,
Dno int,
CONSTRAINT PK_Employee PRIMARY KEY(SSN),
CONSTRAINT FK_DepEmp FOREIGN KEY(Dno) REFERENCES Department(Dnumber) ON DELETE SET NULL ON UPDATE CASCADE
);
SELECT* FROM EMPLOYEE;

ALTER TABLE Department
ADD CONSTRAINT FK_Table FOREIGN KEY(Mgr_ssn) REFERENCES Employee(SSN) ON DELETE SET NULL ON UPDATE CASCADE;

ALTER TABLE Employee
ADD CONSTRAINT FK_ManEmp FOREIGN KEY(Super_SSN) REFERENCES Employee(SSN) ON DELETE SET NULL ON UPDATE CASCADE;

SELECT* FROM Employee;
SELECT* FROM Department;


/* adding table for dept_location*/
/* it is an weak entity , for that reason dept_location k andar partial key and dlocation ki key both will be used to make compoiste primary key*/

CREATE TABLE DEPT_LOCATIONS(
Dnumber INT,
Dlocation VARCHAR(255),
CONSTRAINT PK_DEP_LOCATIONS PRIMARY KEY(Dlocation , Dnumber), /*both are forming a composite primary key , (partial key , foreign key ) , both make up a composite primary key*/
/* as Dlocation is a  foreign key in this table it needs to be defined over here*/
CONSTRAINT FK_DepLoc FOREIGN KEY(Dnumber) REFERENCES Department(Dnumber) ON DELETE  CASCADE ON UPDATE CASCADE
);

SELECT* FROM DEPT_LOCATIONS;

drop table project;
create table project(
pname varchar(255) not null , 
pnumber int,
plocation varchar(255) not null,
dnum int,
constraint pk_project primary key(pnumber),
constraint fk_project_department foreign key(dnum) references Department(dnumber) on delete set null on update cascade
);

select* from project;

create table depedent(
essn int,
dependent_name varchar(255) not null,
gen char(1) ,
bdate date ,
relationship varchar(10) not null,
/*composite primary key , dependent name(partial key) & essn(foreign key)*/
constraint pk_dependent primary key(essn , dependent_name),
constraint fk_dependent_employee foreign key(essn) references Employee(SSN) on delete cascade on update cascade
);
select* from depedent;
alter table depedent rename to dependent;
select* from dependent;
show tables;

/* on delete cascade is okay in this circumstance because agar employee hi nhi rha tou usky corresponding jou info about dependednt
hae ukou b rkhny ki koi zaroorat NHI :0 */


create table works_on(
/* two strong entites having many to many relationship , so a seperate table works_on has been made for it
where both the foreign keys will be united to make up a primary key*/
essn int,
pno int,
hours numeric(3,1),
constraint pk_works_on primary key(essn , pno),
constraint fk_works_on_employee foreign key(essn) references Employee(SSN) on delete restrict on update cascade,
constraint fk_works_on_project foreign key(pno) references Project(pnumber) on delete restrict on update cascade
);
/* for now i've selected on delete restrict , this will not let the primary tables(having the primary key) delete the row of employee and pno ,this table of works_on would be restricting them to do so  :) */

select* from works_on;
show tables;
select* from department;




