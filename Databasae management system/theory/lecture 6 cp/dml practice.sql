create database dml;
use dml;

create table student(
fname varchar(255) not null,
lname char(2)
);

-- it is trying to keep the value of student to null but it is not allowed
insert into student(lname)
values
('c');

alter table student
alter fname set default 'unknown';
show columns from student;

alter table student
add address varchar(255);

show columns from student;

insert into student(lname)
values('d');

select*
from student;

insert into student
values( '' , 'a' , '' );
select* from student;

-- not specifying the where clause will delete the entire table/relation
delete 
from student;
select* from student;

alter table student
add roll_number int,
add constraint pk_student primary key(roll_number);

show columns from student;

create table department(
name varchar(255),
dno int,
constraint pk_department primary key(dno)
);

insert into department
values('cs' , 1),
('accounting and finance' , 2),
('biology' , 3);

select* from department;

alter table student
add dno int,
add constraint pk_student_department foreign key(dno) references department(dno) on delete cascade on update cascade;

show columns from student;
insert into student
values
('saad' , 'da' , 'usman block' , 1234 , 1);

select*
from student
where dno = 1;

-- on deleting the primary key dno from the department the info of saad would also be lost
delete
from department
where dno = 1;

select* from department;
select* from student;


delete
from department;

insert into department
values
('Computer Science', 1),
('Accounting and Finance', 2),
('Biology', 3),
('Mathematics', 4),
('Physics', 5),
('Chemistry', 6),
('Engineering', 7),
('History', 8),
('Psychology', 9),
('Philosophy', 10);


insert into student
values
('Saad', 'A', 'Usman Block', 1234, 1),
('Mia', 'B', 'Lahore Road', 1235, 2),
('Ahmed', 'C', 'Karachi Street', 1236, 3),
('Sana', 'D', 'Peshawar Avenue', 1237, 4),
('Ali', 'E', 'Multan Lane', 1238, 5),
('Sara', 'F', 'Faisal Town', 1239, 6),
('Zain', 'G', 'Gulberg Road', 1240, 7),
('Nina', 'H', 'Liberty Market', 1241, 8),
('Omar', 'I', 'Model Town', 1242, 9),
('Rida', 'J', 'Johar Town', 1243, 10);

select* from department;
select* from student;

-- deleting the foreign key and then adding the same one again.
alter table student
drop foreign key pk_student_department;

alter table student
add constraint fk_student_department foreign key(dno) references department(dno) on update cascade on delete cascade;

show columns from student;

-- now i will see the working of on update cascade
-- updating the dno primary key would also update the foreign key residing in the student table
 update department
 set dno=11
 where dno=1;
 
 select* from student;
 select* from department;

select*
from department
order by dno;

select*
from student 
order by fname;

alter table student
add fine int;
select* from student;

update student
set fine = 100; -- since no where condition all will be updated

-- updating fine by 10% of only those students who belong to dno=5
update student
set fine = fine*1.10
where dno>=5 and dno<=10;
select* from student order by fine;

-- this query is not working properly..
select fname , name
from student , department;


-- order by within select->from->while->order by asc/desc
select fname , lname , dno
from student
order by dno desc;

select fname , lname ,dno
from student
order by fname desc;

-- between operator select->from->while between
select*
from student
where dno between 7 and 9;

select*
from student
where dno>=7 and dno<=9;

select* 
from student
where dno between 7 and 9 and fine = 110;

-- arithmetic operators
select* from student;

select fname , lname , fine+100
from student;

select fname , lname , fine/10
from student
where fine = 100;

update student
set fine = fine/10
where fine = 100;
select* from student;







-- practice operators
-- 1
select fname
from student;

-- 2 
select fname , ssn
from employee;

-- 3
select fname , ssn , salary
from employee
where salary = 40000;

-- 4
select fname , ssn , salary
from employee
where salary > 40000 and dno = 5; 

-- 5
select fname
from employee
where salary = 30000 or gender = 'f';

-- 6
select*
from employee
where supervisor is null;  -- agar koi supervisor nhi houga tou uskey agey null likha aye ga ;)
-- is and is not is used with null , boolean values

-- 7 
select fname
from employee
where address is not null;

-- 8 distinct keyword doesnot repeat the words that have already appeard in a row/tuple
-- agar 2 employees ka naam saad hae tou bss aik show houga.
select distinct fname
from employee;

-- 9
select*
from employee
where salary between 20000 and 40000 and dno = 5;

-- 10
select* 
from employee
order by salary desc;




