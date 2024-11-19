create database cp2;
use cp2;



create table Staff_Member(
F_Name varchar(255) not null,
L_name varchar(255),
User_No varchar(255),
constraint pk_Staff_Member primary key(User_No)
);



create table Student(
F_Name varchar(255) not null,
L_Name varchar(255),
User_No varchar(255),
Project_No varchar(255),
Super_No varchar(255),
Assessor1 varchar(255),
Assessor2 varchar(255),
constraint pk_Student primary key(User_No),
constraint fk_StaffMember_Student foreign key(Super_No) references Staff_Member(User_No) on delete set null on update cascade
);

create table Project(
Proj_No varchar(255),
Project_Name varchar(255) not null,
Levels int not null check(Levels>0 and Levels<10),
Keywords varchar(255),
Description varchar(255), 
constraint pk_Project primary key(Proj_No)
);

/* adding foreign key to student table by altering the table */
alter table Student
add constraint fk_Project_Student foreign key(Project_No) references Project(Proj_No) on delete set null on update cascade;

/* composite primary key both stud user no and exam no(partial key) are together making up the composite primary key for this table.*/
create table Exam(
Stud_User_No varchar(255),
Exam_No varchar(255),
`Time` TIME ,
`Day` DATE,
Room_No int check(Room_No>0 and Room_No<20),
constraint pk_Exam primary key(Exam_No , Stud_User_No),
constraint fk_Student_Exam foreign key(Stud_User_No)  references Student(User_NO) on update cascade on delete cascade
);


/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   		not related >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*changing datatype of user_no from and avoiding referntial integrity*/
alter table Student
drop foreign key fk_StaffMember_Student;

alter table Staff_Member 
modify User_NO int;

alter table Student
modify Super_No int;

alter table Student
add constraint foreign key(Super_No) references Staff_Member(User_No) on delete set null on update cascade;

show columns from Staff_Member;
show columns from Student;




/* doing the same for project */
alter table Student
drop foreign key fk_Project_Student;

alter table Student
modify Project_No int;

alter table Project
modify Proj_No int;

alter table Student
add constraint fk_Project_Student foreign key(Project_No) references Project(Proj_No) on delete cascade on update cascade;

show columns from Student;
show columns from Project;




/* altering the last remaining stud_user_no inside exam*/
alter table Exam
drop foreign key fk_Student_Exam;

alter table Exam
modify Stud_User_No int;

alter table Student
modify User_No int;

alter table Exam
add constraint fk_Exam_Student foreign key(Stud_User_No) references Student(User_No) on delete cascade on update cascade;

show columns from Exam;
show columns from Student;

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< not related >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 2 . POPULATE SENSIBLE DATA INTO THE RELATIIONS >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
show columns from Staff_Member;
insert into Staff_Member
values
('Naeem' , 'Sabir' , 2001),
('Orangzaib' , 'Khan' , 2002),
('Mohsin' , 'Ghaffar Ghouri' , 2003 ) ,
('Waqas' , 'Ahmed' , 2004),
('Ayesha' , 'Zaheer' , 2005);
select* from Staff_Member;

show columns from Student;
insert into Student
values
('Saad' , 'Salman' , 1010 , null , 2001 , 'ali' , 'abbas' ) ,
('Abdul' , 'Muiz' , 1011 , null , 2002 , 'ali' , 'abbas' ),
('Muqaddas' , 'Hussain' , 1012 , null , 2003 , 'ali' , 'abbas' ),
('Kaun' , 'Talha' , 1013 , null , 2004 , 'ali' , 'abbas' ) ,
('Fahad' , 'Rizvi' , 1014 , null , 2005 , 'ali' , 'abbas' ) ;
select* from Student;

show columns from Project;
insert into Project
values
(10 , 'Web' , 3 , 'web_dev' , 'project related to web development'),
(1 , 'IOS' , 5 , 'ios_dev' , 'project related to ios app development'),
(2 , 'Andriod' , 4 , 'andriod_dev' , 'project realted to android app development'),
(3 , 'Ai' , 7 , 'AI_ML' , 'project realted to machine learning and artifical intelligence'),
(4 , 'Cyber Security' , 6 , 'Security' , 'project related to cyber securtiy' );

select Proj_No,Project_Name,Levels,Keywords,Description
from Project;


/* adding values where we left null, previous time */
show columns from Student;
select* from Student;

update Student
set Project_No = 10  
where User_No = 1010;

update Student
set Project_No = 1
where User_No = 1011;

update Student
set Project_No = 2
where User_No = 1012;

update Student
set Project_No = 3
where User_No = 1013;

update Student
set Project_No = 4
where User_No = 1014;


/* inserting values into the final table exam*/
alter table Exam
modify Exam_No int;		/* converted the datatpye for exam to int */

show columns from Exam;
insert into Exam
values
(1010 , 1 , '12:30:00' , '2024-12-01' , 005),
(1011 , 2 , '12:30:00' , '2024-12-01' , 006),
(1012 , 3 , '12:30:00' , '2024-12-01' , 007),
(1013 , 4 , '12:30:00' , '2024-12-01' , 008 ),
(1014 , 5 , '12:30:00' , '2024-12-01' , 009);
select* from Exam;

/* <<<<<<<<<<<<<<<<<<<<<<<<<<      3       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
select* from Student; 
delete
from Student
where Project_No = 10;  /* deleted the entire info of the student saad :( */
select* from Student;
select* from Exam;     /* as i has choosen on delete cascade , it also deleted the entire tuple in the exam relation where the user id 1011(saad) resided */


/* <<<<<<<<<<<<<<<<<<<<<<<<<<  4 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
select* from Project;
update Project
set Levels = 5
where Project_Name ='Andriod';   /* updated the android level from 4 to 5 */
select* from Project;      


/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 5(1.) >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
select* from student;
insert into Student
values
('Saad' , 'Salman' , 1010 , 10 , 2001 , 'ali' , 'abbas' );

insert into Exam
values
(1010 , 1 , '12:30:00' , '2024-12-01' , 005);

select* from Exam;

select `Time`,day
from Exam
where Stud_User_No = 1010 and Room_No = 5;

/* as this was previously deleted so i readded the data and then displayed it */


/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 5(2.) >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
select Project_Name
from Project
order by Project_Name;

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 5(3.) >>>>>>>>>>>>>>>>>>>>>>>>>>>*/
select F_Name , L_Name 
from Staff_Member
where F_Name like 'a%a' and 
L_Name like '%a%';  


/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 5(4.) >>>>>>>>>>>>>>>>>>>>>>>>>>*/
select* from Student;

select F_name , L_Name
from Student
/*where Super_No  = null;   NOT THE CORRECT WAY TO CHECK NULL    */   
where Super_no is NULL;



/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<< 5(5.) >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

select Stud_User_No
from Exam
where Room_No>=5 and Room_No<=9;

