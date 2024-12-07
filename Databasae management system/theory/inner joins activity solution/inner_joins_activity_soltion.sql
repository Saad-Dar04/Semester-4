create database innerJoinsActivity2;
use innerJoinsActivity2;

-- Table: salesman
CREATE TABLE salesman (
    salesman_id INT PRIMARY KEY,
    name VARCHAR(50),
    city VARCHAR(50),
    commission DECIMAL(5, 2)
);

-- Insert data into salesman
INSERT INTO salesman (salesman_id, name, city, commission)
VALUES
(5001, 'James Hoog', 'New York', 0.15),
(5002, 'Nail Knite', 'Paris', 0.13),
(5005, 'Pit Alex', 'London', 0.11),
(5006, 'Mc Lyon', 'Paris', 0.14),
(5003, 'Lauson Hen', 'Rome', 0.12),
(5007, 'Paul Adam', 'Rome', 0.13);

-- Table: customer
CREATE TABLE customer (
    customer_id INT PRIMARY KEY,
    cust_name VARCHAR(50),
    city VARCHAR(50),
    grade INT,
    salesman_id INT,
    FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)
);

-- Insert data into customer
INSERT INTO customer (customer_id, cust_name, city, grade, salesman_id)
VALUES
(3002, 'Nick Rimando', 'New York', 100, 5001),
(3005, 'Graham Zusi', 'California', 200, 5002),
(3001, 'Brad Guzan', 'London', NULL, 5005),
(3004, 'Fabian Johns', 'Paris', 300, 5006),
(3007, 'Brad Davis', 'New York', 200, 5001),
(3009, 'Geoff Camero', 'Berlin', 100, 5003),
(3008, 'Julian Green', 'London', 300, 5002);

-- Table: orders
CREATE TABLE orders (
    ord_no INT PRIMARY KEY,
    purch_amt DECIMAL(10, 2),
    ord_date DATE,
    customer_id INT,
    salesman_id INT,
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id),
    FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)
);

-- Insert data into orders
INSERT INTO orders (ord_no, purch_amt, ord_date, customer_id, salesman_id)
VALUES
(70001, 150.5, '2012-10-05', 3005, 5002),
(70009, 270.65, '2012-09-10', 3001, 5005),
(70002, 65.26, '2012-10-05', 3001, 5001),
(70004, 948.5, '2012-08-17', 3002, 5002),
(70007, 2400.6, '2012-07-27', 3007, 5001),
(70005, 5760.0, '2012-09-10', 3002, 5001);

-- query 1
-- 	Write a SQL statement to prepare a list with salesman name,
 -- customer name and their cities for the salesmen and customer who belongs to the same city. 
select s.name as salesman_name , c.cust_name as customer_name , s.city
from salesman as s join customer as c
on s.salesman_id = c.salesman_id 
and s.city = c.city;

-- query 2
-- 1.	Write a SQL statement to make a list with order no, purchase amount, customer name
--   and their cities for those orders which order amount between 500 and 2000.
select o.ord_no as `order no`, o.purch_amt as `purchase amount` , c.cust_name as `customer name` , c.city as `customer city`
from customer as c inner join orders as o
on c.customer_id = o.customer_id and o.purch_amt between 500 and 2000;


-- query 3
-- 3.	Write a SQL statement to know which salesman who are working for some customer. 
select distinct s.name as  salesman_name
from salesman as s inner join customer as c
on s.salesman_id = c.salesman_id;

-- query 4
-- 4.	Write a SQL statement to find the list of customers who appointed a salesman 
-- for their jobs who gets a commission from the company is more than 12%. 
select c.cust_name as customer_name , s.commission , s.name as salesman_name
from salesman as s inner join customer as c
on s.salesman_id = c.salesman_id and commission>0.12;


-- query 5
-- 5.	Write a SQL statement to find the details of an order i.e. order number,
-- order date, amount of order, which customer gives the order and which salesman works
--  for that customer and how much commission he gets for an order.
select  o.ord_no as order_no , o.ord_date as order_date , o.purch_amt as purchase_amount , c.cust_name as customer_name , s.name as salesman_name , s.commission as commission_percentage , s.commission*o.purch_amt as commision_amount
from orders as o inner join customer as c
on o.customer_id = c.customer_id
inner join salesman as s
on o.salesman_id = s.salesman_id ;
-- no and/where clause in this query


-- query 6
-- 6.	Show name of all salesman along with their customers’ name. 
select s.name as salesman_name , c.cust_name as customer_name
from salesman as s inner join customer as c
on s.salesman_id = c.salesman_id
order by s.name asc;


-- query 7
-- 7.	Write a SQL statement to make a list in ascending order for the customer
-- who holds a grade less than 300 and works either through a salesman or by own

