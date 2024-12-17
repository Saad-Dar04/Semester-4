create database union_practice;
use union_practice;

create table Student(
cnic int primary key,
name varchar(255),
address varchar(255),
gpa double(3,2),
did int
);

create table Teacher(
cnic int primary key,
name varchar(255),
address varchar(255),
salary int,
did int
);

create table Department(
id int primary key,
name varchar(255),
location varchar(255)
);

alter table Student
add constraint fk_dept_stud foreign key(did) references Department(id) on delete set null on update cascade;

alter table Teacher
add constraint fk_dept_teacher foreign key(did) references Department(id) on delete set null on update cascade;

-- Insert data into the Department table
INSERT INTO Department (id, name, location)
VALUES 
(1, 'Computer Science', 'Building A'),
(2, 'Mathematics', 'Building B'),
(3, 'Physics', 'Building C');

-- Insert data into the Student table
-- Adding students, including teachers who are also students
INSERT INTO Student (cnic, name, address, gpa, did)
VALUES
(12345, 'Ali Khan', '123 Main St', 3.80, 1),
(67890, 'Sara Ahmed', '456 Elm St', 3.50, 2),
(11223, 'Dr. Ayesha', '321 Maple Ave', 4.00, 1), -- A teacher who is also a student
(33445, 'Dr. Faisal', '654 Cedar Blvd', 3.75, 2); -- Another teacher who is also a student

-- Insert data into the Teacher table
-- Adding teachers, including those who are also students
INSERT INTO Teacher (cnic, name, address, salary, did)
VALUES
(54321, 'Dr. Hamid', '987 Pine Lane', 95000, 3),
(11223, 'Dr. Ayesha', '321 Maple Ave', 90000, 1), -- A teacher who is also a student
(33445, 'Dr. Faisal', '654 Cedar Blvd', 85000, 2); -- Another teacher who is also a student

-- Insert additional departments
INSERT INTO Department (id, name, location)
VALUES
(4, 'Electrical Engineering', 'Building D'),
(5, 'Business Administration', 'Building E');

-- Insert more students, including those from Lahore
INSERT INTO Student (cnic, name, address, gpa, did)
VALUES
(22334, 'Hassan Ali', 'Gulberg, Lahore', 3.70, 1), -- Student from Lahore
(33456, 'Ayesha Malik', 'Model Town, Lahore', 3.85, 2), -- Student from Lahore
(44567, 'Dr. Salman', 'DHA, Lahore', 3.95, 4), -- Teacher from Lahore also a student
(55678, 'Dr. Nida', 'Johar Town, Lahore', 3.90, 5), -- Teacher from Lahore also a student
(66789, 'Zara Khan', 'Cantt, Lahore', 3.80, 3), -- Student from Lahore
(77890, 'Farhan Sheikh', 'Shadman, Lahore', 3.65, 2); -- Student from Lahore

-- Insert more teachers, including those from Lahore
INSERT INTO Teacher (cnic, name, address, salary, did)
VALUES
(99887, 'Dr. Hasan', 'Gulberg, Lahore', 92000, 1), -- Teacher from Lahore
(44567, 'Dr. Salman', 'DHA, Lahore', 94000, 4), -- Teacher from Lahore also a student
(55678, 'Dr. Nida', 'Johar Town, Lahore', 96000, 5), -- Teacher from Lahore also a student
(11234, 'Dr. Fatima', 'Cantt, Lahore', 89000, 3), -- Teacher from Lahore
(22445, 'Dr. Zain', 'Model Town, Lahore', 87000, 2); -- Teacher from Lahore

-- Add an entry to the Student table
INSERT INTO Student (cnic, name, address, gpa, did)
VALUES
(88990, 'Sameer Khan', 'Wapda Town, Lahore', 3.60, 1); -- Student with unique CNIC

-- Add an entry to the Teacher table
INSERT INTO Teacher (cnic, name, address, salary, did)
VALUES
(99112, 'Sameer Khan', 'Wapda Town, Lahore', 88000, 1); -- Teacher with unique CNIC but same name


select* from Student;
select* from Teacher;

select name
from Student
where address like '%Lahore%';

select name , cnic
from Student
where address like '%Lahore%' 
union
select name , cnic
from Teacher
 where address like '%Lahore%' ;


