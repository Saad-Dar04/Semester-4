CREATE DATABASE DDL_PRACTICE;
USE DDL_PRACTICE;

create table student(
fname varchar(255) not null,
lname varchar(255) default 'cheddah talli',
email_address varchar(255) default 'unknown@gmail.com',
s_id int
);

show columns from student;

-- adding an attribute
alter table student
add height numeric(2,1) default 4.0;

show columns from student;

-- removing an attribute
alter table student
add attribute_to_be_deleted varchar(255);  -- adding an extra attribute to test qery
show columns from student;
alter table student
drop attribute_to_be_deleted;				-- deleting that attribute
show columns from student;



-- setting position for newly added attribute
			
            -- to be added first
			alter table student
			add first_attribute varchar(255)
			first;	

			show columns from student;

		-- adding an attribute after some attribute
			alter table student
			add attribute_after int
			after email_address;

show columns from student;



-- changing the name and datatype of a column
show columns from student;
		
        -- modify can change the only datatype of an attribute
        alter table student
        modify first_attribute int;
        
        -- change can change both the name and datatype of the attribute
		alter table student
        change attribute_after Father_name varchar(255) ;
        

-- adding/droping constraints

	show columns from student;
			
		-- primary key
			
					-- primary key
					alter table student
					add primary key(s_id);
					
					-- drop primary key
					alter table student
					drop primary key;
		
					-- adding primary key with a constraint name
					alter table student
					add constraint pk_student primary key(s_id);
					
					-- droping primary key with the constraint name
					alter table student
					drop primary key;
		
        
					show columns from student;
        
					show columns from student;
        
	     -- foreign key
			alter table student
			add CR varchar(255);
			alter table student
            modify CR int;
					
                    -- adding foreign key
                    alter table student
                    add constraint fk_student_cr foreign key(CR) references student(s_id) on update cascade on delete set null;
                    
                    -- removing an foreign key
                    alter table student
                    drop  foreign key fk_student_cr;
                    
                    
		-- NULL
        SHOW COLUMNS FROM student;
        
					-- ADDING THE NULL CONSTRAINT
                    ALTER TABLE student
                    modify ADDRESS TEXT NOT NULL;
        
        
					-- drop NULL CONSTRAINT TO AN ALREADY EXISTING ATTRIBUTE
                    -- JUST USE THE MODFIY AND DONT WRITE NOT NULL AGAIN AND IT WOULD REMOVE
					ALTER TABLE student
                    modify Address TEXT ;
                    -- OR YOU COULD USE THE OTHER APPROACH WHICH IS ALSO APPLICABLE IN OTHER DATABASES
                    ALTER TABLE student
                    alter Address
                    drop default;
					
                    
			-- DEFAULT
            
            show columns from student;
            
            
					-- ADDING THE DEFAULT USING MODIFY
					ALTER TABLE student
                    modify Address  varchar(255) default 'lahore';
        
					-- removing the default using modify and drop default
								-- method 1
                                alter table student
                                alter Address
                                drop default;
                                
                                -- method 2
                                alter table student
                                modify Address varchar(255);

					-- changing the default value stored using set default 'karachi'
						alter table student
                        alter Address
                        set default 'karachi';
                        
                        
                        
                        
          -- check
          
          show columns from student;
          
						-- adding the check
                        alter table student
                        modify height numeric(2,1) check(height>=3.0 and height<=6.5);
                        
                        -- removing the check constraint
                        alter table student
                        modify height numeric(2,1);
                        insert into student(fname , s_id , height)
                        values
                        ('saad' , 1234 , 7.0);
                        
                        -- this didnot remove the check constraint.
                        


-- renaming the table
alter table student
rename to baby_girl;
show columns from baby_girl;
alter table baby_girl
rename to student;

