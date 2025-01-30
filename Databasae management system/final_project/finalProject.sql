create database final_project;
use final_project;
drop database final_project;

create table Customer(
CustomerID int primary key,
CustomerName varchar(255),
Email varchar(255),
Phone varchar(255),
AccountType varchar(255),
MembershipStatus varchar(255),
AddressID int
);
select* from Customer;

create table Employee(
EmployeeID int primary key,
EmployeeName varchar(255),
Role varchar(255)
);
select* from Employee;


create table Address(
AddressID int primary key,
HouseNumber int,
Block  varchar(255),
Street int,
City varchar(255),
PostalCode int,
Country varchar(255)
);
select* from Address;

create table Shipment(
ShipmentID int primary key,
ShipmentDate date,
ExpectedDeliveryDate date,
Status varchar(255),
ShippingCost int,
TotalWeight varchar(255),
CustomerID int,
CarrierID int,
PickupAddressID int,
DeliveryAddressID int
);
Select* from Shipment;

create table Payment(
PaymentID int primary key,
Amount int,
PaymentMethod varchar(255),
PaymentStatus varchar(255),
PaymentDate date,
ShipmentID int
);
select* from Payment;

create table Tracking(
TrackingID int primary key,
ShipmentID int,
CurrentLocation varchar(255),
Status varchar(255),
LastUpdate date
);
select* from Tracking;

create table Carrier(
CarrierID int primary key,
CarrierName varchar(255),
ContactNumber varchar(255),
ServiceType varchar(255)
);
select* from Carrier;

create table Product(
ProductID int primary key,
Name varchar(255),
Category varchar(255),
Weight varchar(255),
Dimensions varchar(255),
Descripton varchar(255),
DeclaredValue int,
PackagingID int
);
Select* from Product;

create table Packaging(
PackagingID int primary key,
Type varchar(255),
Cost int,
Dimensions varchar(255)
);
Select* from Packaging;



select* from Product;
alter table Product
add ShipmentID int;

-- making relationships..
select* from Customer;
select* from Address;
alter table Customer
add constraint fk_address foreign key(AddressID) references Address(AddressID) on delete cascade on update cascade;


select* from Carrier;
select* from Shipment;
Alter table Shipment
add constraint fk_carrier foreign key(CarrierID) references Carrier(CarrierID) on delete cascade on update cascade;
show columns from Shipment;


select* from payment;
select* from Shipment;
alter table payment
add constraint fk_shipment foreign key(ShipmentID) references Shipment(ShipmentID) on delete cascade on update cascade;
Show columns from payment;

select* from Shipment;
alter table Shipment
add constraint fk_customer foreign key(CustomerID) references Customer(CustomerID) on delete cascade on update cascade;
show columns from Shipment;

select* from Shipment;
select* from Address;
alter table Shipment
add constraint fk_pickupaddress foreign key(PickupAddressID) references Address(AddressID) on delete cascade on update cascade;
show columns from Shipment;


alter table Shipment
add constraint fk_deliveryaddress foreign key(DeliveryAddressID) references Address(AddressID) on delete cascade on update cascade;
show columns from Shipment;


select* from Tracking;
select* from Shipment;
alter table Tracking
add constraint fk_shipmentTracking foreign key(ShipmentID) references Shipment(ShipmentID) on delete cascade on update cascade; 
show columns from Tracking;


select* from Product;
select* from Packaging;
alter table Product
add constraint fk_packingproduct foreign key(PackagingID) references Packaging(PackagingID) on delete cascade on update cascade;
show columns from Product;

select* from Employee;
select* from shipment;
create table EmployeeShipment(
EmployeeID int,
ShipmentID int,
constraint pk_employeeshipment primary key(EmployeeID , ShipmentID),
constraint fk_employee1 foreign key(EmployeeID) references Employee(EmployeeID),
constraint fk_shipment1 foreign key(ShipmentID) references Shipment(ShipmentID)
);
select* from EmployeeShipment;

select* from Product;
select* from Shipment;
create table ProductShipment(
`Product Name` varchar(255),
ShipmentID int,
constraint pk_productShipment primary key(`Product Name` , ShipmentID)
);
select* from ProductShipment;

select* from ProductShipment;
show columns from ProductShipment;
alter table ProductShipment
modify `Product Name` int;
show columns from ProductShipment;


alter table ProductShipment
add constraint fk_product1 foreign key(`Product Name`) references Product(ProductID) on delete cascade on update cascade;
show columns from ProductShipment;

alter table ProductShipment
add constraint fk_shipment2 foreign key(ShipmentID) references Shipment(ShipmentID) on delete cascade on update cascade;
show columns from ProductShipment;

alter table Product
drop column ShipmentID;
select* from Product;

ALTER TABLE ProductShipment
CHANGE `Product Name` ProductID int;
show columns from ProductShipment;






INSERT INTO Address (AddressID, HouseNumber, Block, Street, City, PostalCode, Country) VALUES
(1, 123, 'A', 1, 'Karachi', 75200, 'Pakistan'),
(2, 124, 'B', 2, 'Lahore', 54000, 'Pakistan'),
(3, 125, 'C', 3, 'Islamabad', 44000, 'Pakistan'),
(4, 126, 'D', 4, 'Karachi', 75000, 'Pakistan'),
(5, 127, 'E', 5, 'Peshawar', 25000, 'Pakistan'),
(6, 128, 'F', 6, 'Quetta', 87300, 'Pakistan'),
(7, 129, 'G', 7, 'Rawalpindi', 46000, 'Pakistan'),
(8, 130, 'H', 8, 'Faisalabad', 38000, 'Pakistan'),
(9, 131, 'I', 9, 'Multan', 60000, 'Pakistan'),
(10, 132, 'J', 10, 'Sialkot', 51300, 'Pakistan'),
(11, 133, 'K', 11, 'Karachi', 74400, 'Pakistan'),
(12, 134, 'L', 12, 'Lahore', 54010, 'Pakistan'),
(13, 135, 'M', 13, 'Islamabad', 44010, 'Pakistan'),
(14, 136, 'N', 14, 'Karachi', 75210, 'Pakistan'),
(15, 137, 'O', 15, 'Peshawar', 25100, 'Pakistan'),
(16, 138, 'P', 16, 'Quetta', 87400, 'Pakistan'),
(17, 139, 'Q', 17, 'Rawalpindi', 46100, 'Pakistan'),
(18, 140, 'R', 18, 'Faisalabad', 38100, 'Pakistan'),
(19, 141, 'S', 19, 'Multan', 60100, 'Pakistan'),
(20, 142, 'T', 20, 'Sialkot', 51400, 'Pakistan');
select* from Address;

INSERT INTO Carrier (CarrierID, CarrierName, ContactNumber, ServiceType) VALUES
(1, 'PakPost', '03001234567', 'Standard'),
(2, 'TCS', '03201234567', 'Express'),
(3, 'Leopards', '03301234567', 'Standard'),
(4, 'Daewoo', '03401234567', 'Express'),
(5, 'M&P', '03501234567', 'Standard'),
(6, 'Flash', '03601234567', 'Express'),
(7, 'G4S', '03701234567', 'Standard'),
(8, 'Postex', '03801234567', 'Standard'),
(9, 'Pinnacle', '03901234567', 'Express'),
(10, 'Shahi', '04001234567', 'Express'),
(11, 'Bahria Express', '04101234567', 'Standard'),
(12, 'Pakistan Cargo', '04201234567', 'Standard'),
(13, 'Ship Express', '04301234567', 'Express'),
(14, 'Sundar', '04401234567', 'Standard'),
(15, 'Xpress', '04501234567', 'Express'),
(16, 'Swift', '04601234567', 'Standard'),
(17, 'Sky Courier', '04701234567', 'Express'),
(18, 'Redex', '04801234567', 'Standard'),
(19, 'Blue Star', '04901234567', 'Express'),
(20, 'Ufone Delivery', '05001234567', 'Standard');
select* from Carrier;

INSERT INTO Customer (CustomerID, CustomerName, Email, Phone, AccountType, MembershipStatus, AddressID) VALUES
(1, 'Ali Khan', 'ali@gmail.com', '03001234567', 'Basic', 'Active', 1),
(2, 'Fatima Bibi', 'fatima@gmail.com', '03001234568', 'Premium', 'Active', 2),
(3, 'Ahmed Ali', 'ahmed@gmail.com', '03001234569', 'Basic', 'Inactive', 3),
(4, 'Sara Ali', 'sara@gmail.com', '03001234570', 'Premium', 'Active', 4),
(5, 'Kashan Ahmed', 'kashan@gmail.com', '03001234571', 'Basic', 'Active', 5),
(6, 'Ayesha Shah', 'ayesha@gmail.com', '03001234572', 'Premium', 'Inactive', 6),
(7, 'Omar Farooq', 'omar@gmail.com', '03001234573', 'Basic', 'Active', 7),
(8, 'Nida Khan', 'nida@gmail.com', '03001234574', 'Premium', 'Active', 8),
(9, 'Rehman Shah', 'rehman@gmail.com', '03001234575', 'Basic', 'Inactive', 9),
(10, 'Tariq Mehmood', 'tariq@gmail.com', '03001234576', 'Premium', 'Active', 10),
(11, 'Sana Javed', 'sana@gmail.com', '03001234577', 'Basic', 'Inactive', 11),
(12, 'Zohaib Khan', 'zohaib@gmail.com', '03001234578', 'Premium', 'Active', 12),
(13, 'Hassan Raza', 'hassan@gmail.com', '03001234579', 'Basic', 'Inactive', 13),
(14, 'Mahira Khan', 'mahira@gmail.com', '03001234580', 'Premium', 'Active', 14),
(15, 'Usman Malik', 'usman@gmail.com', '03001234581', 'Basic', 'Inactive', 15),
(16, 'Imran Ahmed', 'imran@gmail.com', '03001234582', 'Premium', 'Active', 16),
(17, 'Mariam Shah', 'mariam@gmail.com', '03001234583', 'Basic', 'Inactive', 17),
(18, 'Farhan Siddique', 'farhan@gmail.com', '03001234584', 'Premium', 'Active', 18),
(19, 'Nashit Mehmood', 'nashit@gmail.com', '03001234585', 'Basic', 'Inactive', 19),
(20, 'Kiran Iqbal', 'kiran@gmail.com', '03001234586', 'Premium', 'Active', 20);
select* from Customer;


INSERT INTO Employee (EmployeeID, EmployeeName, Role) VALUES
(1, 'John Doe', 'Manager'),
(2, 'Jane Smith', 'Salesperson'),
(3, 'Ali Raza', 'Driver'),
(4, 'Sara Riaz', 'Warehouse Staff'),
(5, 'Hassan Javed', 'Delivery Coordinator'),
(6, 'Nadia Farooq', 'Customer Support'),
(7, 'Omar Khan', 'Driver'),
(8, 'Sana Mir', 'HR Manager'),
(9, 'Ali Mustafa', 'Manager'),
(10, 'Fatima Ali', 'Customer Service'),
(11, 'Ahmed Shah', 'Logistics Manager'),
(12, 'Tariq Khan', 'Salesperson'),
(13, 'Usman Raza', 'Warehouse Staff'),
(14, 'Mariam Zahra', 'HR Assistant'),
(15, 'Zohaib Ali', 'Manager'),
(16, 'Ali Ahmed', 'Driver'),
(17, 'Nashit Mehmood', 'Customer Support'),
(18, 'Imran Iqbal', 'Salesperson'),
(19, 'Kashan Mehmood', 'Warehouse Staff'),
(20, 'Murtaza Ali', 'Delivery Coordinator');
select* from Employee;


INSERT INTO Shipment (ShipmentID, ShipmentDate, ExpectedDeliveryDate, Status, ShippingCost, TotalWeight, CustomerID, CarrierID, PickupAddressID, DeliveryAddressID) VALUES
(1, '2025-01-01', '2025-01-05', 'In Transit', 500, '10kg', 1, 1, 1, 2),
(2, '2025-01-02', '2025-01-06', 'Delivered', 600, '12kg', 2, 2, 3, 4),
(3, '2025-01-03', '2025-01-07', 'Pending', 400, '8kg', 3, 3, 5, 6),
(4, '2025-01-04', '2025-01-08', 'In Transit', 700, '15kg', 4, 4, 7, 8),
(5, '2025-01-05', '2025-01-09', 'Delivered', 300, '7kg', 5, 5, 9, 10),
(6, '2025-01-06', '2025-01-10', 'In Transit', 650, '11kg', 6, 6, 11, 12),
(7, '2025-01-07', '2025-01-11', 'Delivered', 550, '9kg', 7, 7, 13, 14),
(8, '2025-01-08', '2025-01-12', 'In Transit', 400, '10kg', 8, 8, 15, 16),
(9, '2025-01-09', '2025-01-13', 'Delivered', 750, '20kg', 9, 9, 17, 18),
(10, '2025-01-10', '2025-01-14', 'Pending', 500, '13kg', 10, 10, 19, 20),
(11, '2025-01-11', '2025-01-15', 'In Transit', 450, '11kg', 11, 11, 2, 3),
(12, '2025-01-12', '2025-01-16', 'Delivered', 550, '9kg', 12, 12, 4, 5),
(13, '2025-01-13', '2025-01-17', 'Pending', 600, '14kg', 13, 13, 6, 7),
(14, '2025-01-14', '2025-01-18', 'In Transit', 700, '16kg', 14, 14, 8, 9),
(15, '2025-01-15', '2025-01-19', 'Delivered', 800, '17kg', 15, 15, 10, 11),
(16, '2025-01-16', '2025-01-20', 'In Transit', 550, '12kg', 16, 16, 12, 13),
(17, '2025-01-17', '2025-01-21', 'Delivered', 400, '9kg', 17, 17, 14, 15),
(18, '2025-01-18', '2025-01-22', 'Pending', 750, '18kg', 18, 18, 16, 17),
(19, '2025-01-19', '2025-01-23', 'In Transit', 600, '11kg', 19, 19, 18, 19),
(20, '2025-01-20', '2025-01-24', 'Delivered', 450, '10kg', 20, 20, 20, 1);
select* from Shipment;

INSERT INTO Payment (PaymentID, Amount, PaymentMethod, PaymentStatus, PaymentDate, ShipmentID) VALUES
(1, 500, 'Credit Card', 'Completed', '2025-01-02', 1),
(2, 600, 'Cash', 'Completed', '2025-01-03', 2),
(3, 400, 'Credit Card', 'Pending', '2025-01-04', 3),
(4, 700, 'Debit Card', 'Completed', '2025-01-05', 4),
(5, 300, 'Cash', 'Completed', '2025-01-06', 5),
(6, 650, 'Credit Card', 'Pending', '2025-01-07', 6),
(7, 550, 'Debit Card', 'Completed', '2025-01-08', 7),
(8, 400, 'Cash', 'Completed', '2025-01-09', 8),
(9, 750, 'Credit Card', 'Completed', '2025-01-10', 9),
(10, 500, 'Cash', 'Pending', '2025-01-11', 10),
(11, 450, 'Credit Card', 'Completed', '2025-01-12', 11),
(12, 550, 'Debit Card', 'Completed', '2025-01-13', 12),
(13, 600, 'Credit Card', 'Pending', '2025-01-14', 13),
(14, 700, 'Debit Card', 'Completed', '2025-01-15', 14),
(15, 800, 'Cash', 'Completed', '2025-01-16', 15),
(16, 550, 'Credit Card', 'Pending', '2025-01-17', 16),
(17, 400, 'Debit Card', 'Completed', '2025-01-18', 17),
(18, 750, 'Credit Card', 'Pending', '2025-01-19', 18),
(19, 600, 'Cash', 'Completed', '2025-01-20', 19),
(20, 450, 'Debit Card', 'Completed', '2025-01-21', 20);
select* from Payment;	

INSERT INTO Tracking (TrackingID, ShipmentID, CurrentLocation, Status, LastUpdate) VALUES
(1, 1, 'Karachi Warehouse', 'In Transit', '2025-01-02'),
(2, 2, 'Lahore Hub', 'Delivered', '2025-01-03'),
(3, 3, 'Islamabad Hub', 'Pending', '2025-01-04'),
(4, 4, 'Karachi Warehouse', 'In Transit', '2025-01-05'),
(5, 5, 'Peshawar Hub', 'Delivered', '2025-01-06'),
(6, 6, 'Quetta Warehouse', 'In Transit', '2025-01-07'),
(7, 7, 'Rawalpindi Warehouse', 'Delivered', '2025-01-08'),
(8, 8, 'Faisalabad Warehouse', 'In Transit', '2025-01-09'),
(9, 9, 'Multan Hub', 'Delivered', '2025-01-10'),
(10, 10, 'Sialkot Warehouse', 'Pending', '2025-01-11'),
(11, 11, 'Karachi Hub', 'In Transit', '2025-01-12'),
(12, 12, 'Lahore Warehouse', 'Delivered', '2025-01-13'),
(13, 13, 'Islamabad Hub', 'Pending', '2025-01-14'),
(14, 14, 'Karachi Hub', 'In Transit', '2025-01-15'),
(15, 15, 'Peshawar Warehouse', 'Delivered', '2025-01-16'),
(16, 16, 'Quetta Hub', 'In Transit', '2025-01-17'),
(17, 17, 'Rawalpindi Hub', 'Delivered', '2025-01-18'),
(18, 18, 'Faisalabad Warehouse', 'Pending', '2025-01-19'),
(19, 19, 'Multan Warehouse', 'In Transit', '2025-01-20'),
(20, 20, 'Sialkot Hub', 'Delivered', '2025-01-21');
select* from Tracking;

INSERT INTO Packaging (PackagingID, Type, Cost, Dimensions) VALUES
(1, 'Box', 50, '10x10x10 cm'),
(2, 'Envelope', 20, '5x10 cm'),
(3, 'Crate', 150, '20x20x20 cm'),
(4, 'Bag', 30, '15x10 cm'),
(5, 'Pallet', 200, '100x100x50 cm'),
(6, 'Box', 50, '15x15x15 cm'),
(7, 'Envelope', 25, '8x15 cm'),
(8, 'Crate', 175, '25x25x25 cm'),
(9, 'Bag', 35, '20x15 cm'),
(10, 'Pallet', 250, '120x120x80 cm'),
(11, 'Box', 60, '20x20x20 cm'),
(12, 'Envelope', 15, '6x12 cm'),
(13, 'Crate', 100, '18x18x18 cm'),
(14, 'Bag', 45, '25x20 cm'),
(15, 'Pallet', 300, '130x130x90 cm'),
(16, 'Box', 70, '25x25x25 cm'),
(17, 'Envelope', 18, '7x14 cm'),
(18, 'Crate', 130, '22x22x22 cm'),
(19, 'Bag', 40, '18x15 cm'),
(20, 'Pallet', 220, '110x110x60 cm');
select* from Packaging;

INSERT INTO Product (ProductID, Name, Category, Weight, Dimensions, Descripton, DeclaredValue, PackagingID) VALUES
(1, 'Laptop', 'Electronics', '2kg', '30x20x2 cm', '15-inch laptop, Intel i5, 8GB RAM, 512GB SSD', 50000, 1),
(2, 'Smartphone', 'Electronics', '0.2kg', '15x7x1 cm', '6-inch smartphone, 128GB storage, 6GB RAM', 30000, 2),
(3, 'Coffee Maker', 'Home Appliances', '1.5kg', '25x25x35 cm', 'Electric coffee maker, 1.5L capacity', 15000, 3),
(4, 'Washing Machine', 'Home Appliances', '8kg', '60x60x85 cm', 'Fully automatic washing machine, 7kg load capacity', 40000, 4),
(5, 'Refrigerator', 'Home Appliances', '50kg', '70x60x180 cm', 'Double-door refrigerator, 400L capacity', 60000, 5),
(6, 'Headphones', 'Electronics', '0.3kg', '15x15x10 cm', 'Wireless over-ear headphones with noise cancellation', 10000, 6),
(7, 'Microwave Oven', 'Home Appliances', '12kg', '50x40x35 cm', '800W microwave with grill function', 25000, 7),
(8, 'Gaming Console', 'Electronics', '3kg', '30x20x10 cm', 'PlayStation 5, 1TB storage, includes controller', 100000, 8),
(9, 'Vacuum Cleaner', 'Home Appliances', '4kg', '35x25x15 cm', 'Cordless vacuum cleaner with rechargeable battery', 12000, 9),
(10, 'Smart Watch', 'Electronics', '0.4kg', '10x10x2 cm', 'Fitness tracker with heart rate monitor and GPS', 8000, 10),
(11, 'Tablet', 'Electronics', '0.5kg', '24x16x1 cm', '10-inch tablet with 64GB storage and 4GB RAM', 20000, 11),
(12, 'Air Conditioner', 'Home Appliances', '30kg', '80x80x40 cm', 'Split AC, 1.5 ton capacity, energy efficient', 35000, 12),
(13, 'Electric Kettle', 'Home Appliances', '1kg', '20x20x30 cm', '1.5L electric kettle with auto shut-off', 2000, 13),
(14, 'Bluetooth Speaker', 'Electronics', '0.6kg', '20x10x10 cm', 'Portable Bluetooth speaker with 360-degree sound', 5000, 14),
(15, 'Camera', 'Electronics', '1.2kg', '15x12x7 cm', 'DSLR camera with 24MP resolution and 18-55mm lens', 40000, 15),
(16, 'Electric Heater', 'Home Appliances', '3kg', '30x30x20 cm', 'Portable electric heater with adjustable temperature', 8000, 16),
(17, 'Fitness Tracker', 'Electronics', '0.1kg', '5x5x1 cm', 'Compact fitness tracker with step counting and sleep tracking', 3000, 17),
(18, 'Blender', 'Home Appliances', '2kg', '20x20x40 cm', 'High-speed blender with multiple speed settings', 7000, 18),
(19, 'LED TV', 'Electronics', '8kg', '110x65x8 cm', '55-inch 4K LED TV with smart features', 45000, 19),
(20, 'Digital Camera', 'Electronics', '0.9kg', '12x10x6 cm', 'Compact digital camera with 20MP resolution and 10x zoom', 25000, 20);
select* from Product;


INSERT INTO EmployeeShipment (EmployeeID, ShipmentID) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5),
(6, 6),
(7, 7),
(8, 8),
(9, 9),
(10, 10),
(11, 11),
(12, 12),
(13, 13),
(14, 14),
(15, 15),
(16, 16),
(17, 17),
(18, 18),
(19, 19),
(20, 20);
Select* from EmployeeShipment;

INSERT INTO ProductShipment (ProductID, ShipmentID) VALUES
(1, 1),
(2, 1),
(3, 2),
(4, 2),
(5, 3),
(6, 3),
(7, 4),
(8, 4),
(9, 5),
(10, 5),
(11, 6),
(12, 6),
(13, 7),
(14, 7),
(15, 8),
(16, 8),
(17, 9),
(18, 9),
(19, 10),
(20, 10);
select* from ProductShipment;


-- inner join between employee and shipment to see
-- which employees were involved in which shipments.
select* from Employee;
select* from Shipment;
select* from EmployeeShipment;

select e.EmployeeName , es.EmployeeID , es.ShipmentID
from EmployeeShipment as es inner join Employee as e
on es.EmployeeID = e.EmployeeID;

-- inner join between product and shipment
select* from Product;
select* from ProductShipment;
select p.Name , ps.ProductID , ps.ShipmentID
from ProductShipment as ps inner join product as p
on ps.ProductID = p.ProductID;


-- Displaying all of the tables.
SELECT * FROM Customer;
SELECT * FROM Employee;
SELECT * FROM Address;
SELECT * FROM Shipment;
SELECT * FROM Payment;
SELECT * FROM Tracking;
SELECT * FROM Carrier;
SELECT * FROM Product;
SELECT * FROM Packaging;
SELECT * FROM EmployeeShipment;
SELECT * FROM ProductShipment;

show columns from Customer;

