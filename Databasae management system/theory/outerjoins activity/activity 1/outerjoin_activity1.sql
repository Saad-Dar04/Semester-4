create database outerjoins;
use outerjoins;

-- outerjoins practice question 1
create table foods(
item_id int primary key,
item_name varchar(255),
item_unit int,
company_id int
);
show columns from foods;

create table  company(
company_id int primary key,
company_name varchar(255),
company_city varchar(255)
);
show columns from company;


alter table foods
add constraint fk_company_foods foreign key(company_id) references company(company_id) on delete set null on update cascade;

insert into company
values(18 , 'order all' , 'boston'),
(15 , 'jack hill ltd' , 'london'),
(16 , 'akas foods' , 'delhi'),
(17 , 'foodies.' , 'london'),
(19 , 'sip-n-bite' ,  'new york');
select* from company;

alter table foods
modify item_unit varchar(255);
show columns from foods;

insert into foods
values
(1 , 'chex mix' , 'pcs' , 16),
(6 , 'cheez-it' , 'pcs' , 15),
(2 , 'bn biscuit' , 'pcs' , 15),
(3 , 'mighty munch' , 'pcs' , 17),
(4 , 'pot rice' , 'pcs' , 15),
(5 , 'jaffa cakes' , 'pcs' , 18),
(7 , 'salt n shake' , 'pcs' , null);
select* from foods;

-- query 1
select f.item_name , c.company_name
from foods as f inner join company as c
on f.company_id = c.company_id; 

-- query 2
select f.item_name , c.company_name
from foods as f left join company as c
on f.company_id = c.company_id;

-- query 3
select f.item_name , c.company_name
from foods as f right join company as c
on f.company_id = c.company_id;

-- query 4
-- select f.item_name , c.company_name
-- from foods as f full outer join company as c
-- on f.company_id = c.company_id;

-- --->> mysql doesnot support full outer join we need a combination of left join and right join and union them both
-- 		 to achieve the effect of full outer join.
select f.item_name , c.company_name
from foods as f left join company as c
on f.company_id = c.company_id
union
select ff.item_name , cc.company_name
from foods as ff right join company as cc
on ff.company_id = cc.company_id;