create database outerjoin_activity2;
use outerjoin_activity2;

create table employee(
ssn int primary key,
fname varchar(255),
lname varchar(255),
salary varchar(255),
gender char(1),
dep_no int
);
show columns from employee;

create table department(
dnumber int primary key,
name varchar(255),
mgr_ssn int,
mgr_start_date date,
constraint fk_department_employee foreign key(mgr_ssn) references employee(ssn) on delete set null on update cascade
);
show columns from employee;

alter table employee
add constraint fk_dep_emp foreign key(dep_no) references department(dnumber) on delete set null on update cascade;
show columns from employee;

insert into employee
values
(10 , 'a' , 'b' , '10,000' , 'm' , null),
(11 , 'c' , 'd' , '11,000' , 'm' , null),
(12 , 'e' , 'f' , '10,000' , 'f' , null),
(13 , 'g' , 'h' , '11,000' , 'f' , null),
(14 , 'i' , 'j' , '12,000' , 'm' , null);
select* from employee;

insert into department
values
(5 , 'foit' , 10 , '2016-05-30'),
(4 , 'management' , 12 , '2016-04-25'),
(3 , 'engineering' , 13 , '2018-03-20'),
(8 , 'administration' , null , null),
(9 , 'social sciences' , null , null);
select* from department;

update employee
set dep_no = 5
where ssn in(10,11);
select* from employee;

update employee
set dep_no = 4
where ssn in(12 , 14);
select* from employee;

update employee
set dep_no = 3
where dep_no is null;
select* from employee;


-- query 1
select e.fname , e.lname , d.name
from department as d inner join employee as e
on d.mgr_ssn = e.ssn
order by fname asc;


-- query 2
select e.fname , e.lname , d.name
from department as d right join employee as e
on d.mgr_ssn = e.ssn
order by d.name desc;

-- query 3
select e.fname , e.lname , d.name
from department as d left join employee as e
on d.mgr_ssn = e.ssn;


-- query 4
select e.fname , e.lname , d.name
from department as d right join employee as e
on d.mgr_ssn = e.ssn

union

select e.fname , e.lname , d.name
from department as d left join employee as e
on d.mgr_ssn = e.ssn;


