create database task6;

use task6;

create table EMPLOYEE(
Fname varchar(255) not null,
Minit char(2),
Lname varchar(255),
Ssn int,
Bdate date not null,
Address varchar(255) not null,
Sex char(1) not null,
Salary int,
Super_ssn int ,  /* referencing to the ssn of this employee table , we would reference after table has been created*/
Dno int, /* reference will be created after the creation of the department table */
constraint pk_employee primary key(Ssn)
);


/* first thing i'll do is reference the super_ssn to the employee ka ssn , and make reference between them two.*/
alter table EMPLOYEE
add constraint foreign key(Super_ssn) references EMPLOYEE(Ssn) on update cascade on delete cascade;

select* from EMPLOYEE;

create table DEPARTMENT(
Dname varchar(255) not null,
Dnumber int,
Mgr_ssn int,
Mgr_start_date date not null,
constraint pk_DEPARTMENT primary key(Dnumber),
constraint fk_Mgr_ssn_DEPARTMENT foreign key(Mgr_ssn) references EMPLOYEE(Ssn) on delete cascade on update cascade
);

alter table EMPLOYEE
add constraint fk_Dno_EMPLOYEE foreign key(Dno) references DEPARTMENT(Dnumber) on delete cascade on update cascade;

select* from DEPARTMENT;

/* MULTI VALUED ATTRIBUTES */
create table DEPT_LOCATIONS(
Dnumber int,
Dlocation varchar(255),
/* this table will have a composite primary key , which will be combination of both the keys:)*/
constraint pk_dept_locations primary key(Dnumber , Dlocation),
constraint pk_Dnumber_dept_locations foreign key(Dnumber) references DEPARTMENT(Dnumber) on delete cascade on update cascade
);

select* from DEPT_LOCATIONS;

create table PROJECT(
Pname varchar(255) not null,
Pnumber int,
Plocation varchar(255),
Dnum int,
constraint pk_project primary key(Pnumber),
constraint fk_Dnum_project foreign key(Dnum) references DEPARTMENT(Dnumber) on delete cascade on update cascade
);

select* from PROJECT;

/* many to many relatiionship , a seperate table will be created and a composite primary key will be formed meaning that both keys would work together to give reference*/
create table WORKS_ON (
Essn int,
Pno int,
Hours int,
constraint pk_works_on primary key(Essn , Pno),
constraint fk_Essn_works_on foreign key(Essn) references EMPLOYEE(Ssn) on delete cascade on update cascade,
constraint fk_Pno_works_on foreign key(Pno) references PROJECT(Pnumber) on delete cascade on update cascade
);

select* from WORKS_ON;

/* dependents have partial key and we need foreign key from another table to form an reference with that table*/
create table DEPENDENT (
Essn int,
Dependent_name varchar(255),
Sex char(1),
Bdate date,
Relationship varchar(255) not null,
constraint pk_dependent primary key(Essn , Dependent_name),
constraint pk_Essn_dependent foreign key(Essn ) references EMPLOYEE(Ssn) on delete cascade on update cascade
);

select* from DEPENDENT;

insert into EMPLOYEE(Fname , Minit , Lname , Ssn , Bdate , Address , Sex , Salary , Super_ssn)
values
('muhammad' , 'm.' , 'ali' , 101 , '2000-10-01' , 'ucp' , 'm' , 120000, null ),
('saad' , 's.' ,'dar' , 102 , '2005-12-04' , 'ucp' , 'm' , 2000 , 101),
('muqaddas' ,'m.' , 'hussain' , 103 , '2004-01-04' , 'umt' , 'm' , 20000 , 101),
('abdul' , null, 'mooez' , 104 , '2004-01-04' , 'uol' , 'm',35000 , 101),
('kaun' , 't.' , 'talha' , 105 , '2004-01-04' , 'sharakpur' ,'m', 500000 , 101);

SELECT* FROM EMPLOYEE;

insert into DEPARTMENT
values
('Research' , 5 , 101 , '1998-05-22'),
('Administration' , 4 , 102 , '1995-01-01'),
('Headquaters' , 1 , 103 , '1981-06-19');

select* from DEPARTMENT;

insert into DEPT_LOCATIONS
values
(1 , 'houstan'),
(4 , 'Stafford'),
(5 , 'Bellaire'),
(5 , 'Sugarland'),
(5 , 'Houstan');

select* from DEPT_LOCATIONS;

insert into PROJECT
VALUES
('ProductX' , 1 , 'Bellaire' , 5),
('ProductY' , 2 , 'Sugarland' , 5),
('ProductZ' , 3 , 'Houstan' , 5),
('Computerization' , 10 , 'Stafford' , 4),
('Reorganiztion' , 20 , 'Houstan' , 1);

select* from PROJECT;

INSERT INTO WORKS_ON
VALUES
(101 , 1 , 32),
(102 , 2 , 50 ),
(103 , 3 , 100 ),
(104 , 20 , 22),
(101 , 20 , 22),
(105 , 10 , 100);

SELECT* FROM WORKS_ON ;

insert into DEPENDENT
VALUES
(101 , 'alice' , 'f' , '1986-04-05' , 'daughter'),
(105 , 'theodore' , 'm' , '1983-10-25' , 'son'),
(103 , 'joy' , 'f' , '1958-05-03' , 'spouse'),
(104 , 'malayka' , 'f' , '1999-10-29' , 'daughter');

SELECT* FROM DEPENDENT;

/* UPDAING RECORDS FOR EACH TABLE :) */



UPDATE EMPLOYEE
SET Dno = 4
WHERE Super_ssn = 101;

UPDATE EMPLOYEE 
SET Dno = 5
WHERE SSN=101;
SELECT* FROM EMPLOYEE;

select* from DEPARTMENT;
update DEPARTMENT
SET Dnumber =2
where Dnumber = 4;

select* from DEPT_LOCATIONS;

update DEPT_LOCATIONS
SET Dlocation = 'bahria town'
where Dnumber = 2;

update DEPT_LOCATIONS
SET Dlocation = 'maanga mandi'
where Dnumber = 1;

SELECT* FROM DEPT_LOCATIONS;





 
