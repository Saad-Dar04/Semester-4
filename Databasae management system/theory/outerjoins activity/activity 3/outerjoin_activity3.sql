create database outerjoin_activity3;
use outerjoin_activity3;

create table salesman(
salesman_id int primary key,
name varchar(255),
city varchar(255),
commission double(3,2)
);
show columns from salesman;

create table customer(
customer_id int primary key,
cust_name varchar(255),
city varchar(255),
grade int ,
salesman_id int,
constraint fk_salesman_customer foreign key(salesman_id) references salesman(salesman_id) on delete set null on update cascade
);
show columns from customer;

INSERT INTO salesman (salesman_id, name, city, commission)
VALUES
(5001, 'James Hoog', 'New York', 0.15),
(5002, 'Nail Knite', 'Paris', 0.13),
(5005, 'Pit Alex', 'London', 0.11),
(5006, 'Mc Lyon', 'Paris', 0.14),
(5007, 'Paul Adam', 'Rome', 0.13),
(5003, 'Lauson Hen', 'San Jose', 0.12);


INSERT INTO customer (customer_id, cust_name, city, grade, salesman_id)
VALUES
(3002, 'Nick Rimando', 'New York', 100, 5001),
(3007, 'Brad Davis', 'New York', 200, 5001),
(3005, 'Graham Zusi', 'California', 200, 5002),
(3008, 'Julian Green', 'London', 300, 5002),
(3004, 'Fabian Johnson', 'Paris', 300, 5006),
(3009, 'Geoff Cameron', 'Berlin', 100, 5003),
(3003, 'Jozy Altidor', 'Moscow', 200, 5007);



-- query 1
select s.name as `salesman name` , c.cust_name as `customer name`
from salesman as s left join customer as c
on s.salesman_id = c.salesman_id
order by c.cust_name desc;


-- query 2
select s.name as `salesman name` , c.cust_name as `customer name`
from salesman as s right join customer as c
on s.salesman_id = c.salesman_id
order by c.cust_name desc;

-- query 3
select s.name as `salesman name` , c.cust_name as `customer name`
from salesman as s inner join customer as c
on s.salesman_id = c.salesman_id
order by s.salesman_id asc;


-- query 4
select s.name as `salesman name` , c.cust_name as `customer name`
from salesman as s left join customer as c
on s.salesman_id = c.salesman_id

union

select s.name as `salesman name` , c.cust_name as `customer name`
from salesman as s right join customer as c
on s.salesman_id = c.salesman_id;


