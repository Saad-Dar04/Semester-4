-- create database lecture10_corelatedQuery;
use lecture10_corelatedQuery;

CREATE TABLE EMPLOYEE (
    Fname VARCHAR(50),
    Minit CHAR(1),
    Lname VARCHAR(50),
    Ssn CHAR(9) PRIMARY KEY,
    Bdate DATE,
    Address VARCHAR(100),
    Gender CHAR(1),
    Salary DECIMAL(10, 2),
    Super_ssn CHAR(9),
    Dno INT
);

CREATE TABLE DEPARTMENT (
    Dname VARCHAR(50),
    Dnumber INT PRIMARY KEY,
    Mgr_ssn CHAR(9),
    Mgr_start_date DATE
);

CREATE TABLE DEPT_LOCATIONS (
    Dnumber INT,
    Location VARCHAR(50),
    PRIMARY KEY (Dnumber, Location)
);

CREATE TABLE WORKS_ON (
    Essn CHAR(9),
    Pno INT,
    Hours DECIMAL(5, 2),
    PRIMARY KEY (Essn, Pno)
);

CREATE TABLE PROJECT (
    Pname VARCHAR(50),
    Pnumber INT PRIMARY KEY,
    Plocation VARCHAR(50),
    Dnum INT
);

CREATE TABLE DEPENDENT (
    Essn CHAR(9),
    Dependent_name VARCHAR(50),
    Gender CHAR(1),
    Bdate DATE,
    Relationship VARCHAR(50),
    PRIMARY KEY (Essn, Dependent_name)
);

INSERT INTO EMPLOYEE VALUES 
('John', 'B', 'Smith', '123456789', '1965-01-09', '731 Fondren, Houston, TX', 'M', 30000, '333445555', 5),
('Franklin', 'T', 'Wong', '333445555', '1955-12-08', '638 Voss, Houston, TX', 'M', 40000, '888665555', 5),
('Alicia', 'J', 'Zelaya', '999887777', '1968-01-19', '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4),
('Jennifer', 'S', 'Souza', '987654321', '1941-06-20', '291 Berry, Bellaire, TX', 'F', 43000, '888665555', 4),
('Ramesh', 'K', 'Narayan', '666884444', '1972-09-15', '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5),
('Joyce', 'A', 'English', '453453453', '1962-07-31', '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5),
('Ahmad', 'V', 'Jabbar', '987987987', '1937-11-10', '980 Dallas, Houston, TX', 'M', 25000, '987654321', 4),
('James', 'E', 'Borg', '888665555', '1937-11-10', '450 Stone, Houston, TX', 'M', 55000, NULL, 1);

INSERT INTO DEPARTMENT VALUES
('Research', 5, '333445555', '1988-05-22'),
('Administration', 4, '987654321', '1985-01-01'),
('Headquarters', 1, '888665555', '1981-06-19');

INSERT INTO DEPT_LOCATIONS VALUES
(1, 'Houston'),
(4, 'Stafford'),
(5, 'Bellaire'),
(5, 'Sugarland'),
(5, 'Houston');

INSERT INTO WORKS_ON VALUES
('123456789', 1, 32.5),
('123456789', 2, 7.5),
('666884444', 3, 40.0),
('453453453', 1, 20.0),
('453453453', 2, 20.0),
('333445555', 2, 10.0),
('333445555', 3, 10.0),
('333445555', 10, 10.0),
('987654321', 30, 30.0),
('987987987', 10, 35.0),
('123456789', 30, NULL);


INSERT INTO PROJECT VALUES
('ProductX', 1, 'Bellaire', 5),
('ProductY', 2, 'Sugarland', 5),
('ProductZ', 3, 'Houston', 5),
('Computerization', 10, 'Stafford', 4),
('Reorganization', 20, 'Houston', 1),
('Newbenefits', 30, 'Stafford', 4);

INSERT INTO DEPENDENT VALUES
('333445555', 'Theodore', 'M', '1983-10-25', 'Son'),
('333445555', 'Alice', 'F', '1986-12-30', 'Daughter'),
('333445555', 'Joy', 'F', '1958-05-03', 'Spouse'),
('987654321', 'Abner', 'M', '1942-02-28', 'Son'),
('123456789', 'Michael', 'M', '1988-01-04', 'Son'),
('888665555', 'Elizabeth', 'F', '1967-05-05', 'Spouse');

SELECT * FROM EMPLOYEE;
SELECT * FROM DEPARTMENT;
SELECT * FROM DEPT_LOCATIONS;
SELECT * FROM WORKS_ON;
SELECT * FROM PROJECT;
SELECT * FROM DEPENDENT;

-- 1
select Fname ,  Minit , Lname
from EMPLOYEE as e
where exists ( select 1 from DEPARTMENT as dep where e.Ssn=dep.Mgr_ssn)
and exists(select 1 from DEPENDENT as d where e.Ssn=d.Essn);


-- 2
select Fname , Minit , Lname
from EMPLOYEE as e
where exists ( 
select 1
from DEPARTMENT 
where e.Ssn = DEPARTMENT.Mgr_ssn)
and not exists(
select 1
from DEPENDENT as dep
where e.Ssn = dep.Essn);

-- 3 Show project name on which Aliya is not working
select* from WORKS_ON;
select Pname
from Project as p
where not exists(
			Select 1
			from WORKS_ON as w inner join EMPLOYEE as e
            ON w.Essn = e.Ssn
            where fname='Aliya' and p.Pnumber = w.Pno);
			
-- 4 Show all dependent name of employees working in IT department. 
Select* from DEPENDENT;
SELECT* FROM DEPARTMENT;
SELECT* FROM EMPLOYEE;
select Dependent_name 
From DEPENDENT as dd
where exists(
Select 1
from EMPLOYEE AS e inner join DEPARTMENT AS d
on e.Dno = d.Dnumber and d.Dname = 'IT'
where dd.Essn = e.Ssn);


-- 5 Show employee names who work in research department. 
select Fname , Minit , Lname
from EMPLOYEE as ee
where exists(
Select 1
From EMPLOYEE AS e inner join DEPARTMENT AS d
on e.Dno = d.Dnumber and d.Dname = 'Research'
where ee.Ssn = e.Ssn);

-- 6 Show project names in which an employee ‘John Smith’ works. 
select Pname
from PROJECT AS P
WHERE EXISTS(
select 1
from WORKS_ON AS wo inner join EMPLOYEE AS e
on wo.Essn = e.Ssn and Fname = 'John' and Lname = 'Smith'
where p.Pnumber = wo.Pno);


-- 7 Show all project names which are controlled by a department in which ‘John Smith’ works. 
select Pname
from PROJECT AS p
where exists(
select 1
from EMPLOYEE AS e inner join DEPARTMENT as d
on e.Dno = d.Dnumber and Fname = 'John' and Lname = 'Smith'
where p.Dnum = d.Dnumber);


-- 8 Show employee names who has a supervisor with the same salary as themselves.
select Fname 
from EMPLOYEE AS e
where exists(select 1
from EMPLOYEE AS emp inner join EMPLOYEE AS sup
on emp.Ssn = sup.Super_Ssn and emp.Salary=sup.Salary
where emp.Ssn = e.Ssn);

-- 9 Show employee names who do not work on any project.
select Fname
from EMPLOYEE as e
where not exists(
select 1
from WORKS_ON as wo
where e.Ssn = wo.Essn);

-- practice questions in any all
 -- 1 Show department names in which some workers works with salary> 30,000 or it is located in Stafford. 

 select d.Dname
 from DEPARTMENT as d inner join DEPT_LOCATIONS as dl
 on d.Dnumber = dl.Dnumber
 where dl.location like '%Stafford%'
 union
 select dd.Dname
 from DEPARTMENT as dd inner join EMPLOYEE as e
 on e.Dno = dd.Dnumber
 where e.Salary > 30000;
 
 
 -- 2 Show employee ssn’s who are managers but don’t have any dependents. 
 select distinct mgr.Ssn
 from EMPLOYEE as e inner join EMPLOYEE as mgr
 on mgr.Ssn = e.Super_ssn
 Where mgr.Ssn not in(select distinct ESSN from DEPENDENT);
 
 -- 3 Show manager name who have no dependents. 
 select mgr.Fname
 from EMPLOYEE as e inner join EMPLOYEE as mgr
 on e.Super_ssn = mgr.Ssn
 where mgr.Ssn not in(
 select Essn from DEPENDENT);
 
 -- 4 Make a list of all project numbers for projects that
 -- involve an employee whose last name is smith either as a worker 
 -- or as a manager of dept who controls the project. 
-- smith as a worker
select wo.Pno
from EMPLOYEE as e inner join  WORKS_ON AS wo
on e.Ssn = wo.Essn
where e.Lname = 'Smith'
union all
select p.Pnumber
from DEPARTMENT as d inner join EMPLOYEE as ee
ON d.Mgr_ssn = ee.Ssn and ee.Lname = 'Smith'
inner join PROJECT as p
on p.Dnum = d.Dnumber;
SHOW COLUMNS FROM DEPARTMENT;


-- 5 List names of employees who do not work on any project. 
select Fname
from EMPLOYEE 
where Ssn not in (
select distinct Essn 
from WORKS_ON );
 
 
 -- 6 Fine the names of all employees who work on atleast one project
 -- located in Houston but whose department has not located in Houston. 
