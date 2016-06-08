#1
select EmployeeName from Employee;

#1.1
select EmployeeName from Employee WHERE DepartmentID = 1;

#2
SELECT DISTINCT ItemID FROM Sale INNER JOIN Department ON Sale.DepartmentID = Department.DepartmentID WHERE DepartmentFloor = 2;

SELECT DISTINCT ItemID FROM Sale INNER JOIN Department ON Sale.DepartmentID = Department.DepartmentID  WHERE DepartmentFloor <> 2;

SELECT DISTINCT ItemID FROM Sale natural JOIN Department WHERE DepartmentFloor <> 2;

SELECT ItemID FROM Sale NATURAl JOIN Department 
WHERE DepartmentFloor = 2 
GROUP BY ItemID 
HAVING COUNT(DISTINCT Department.DepartmentID) > 1;

#3
SELECT DISTINCT Supplier.SupplierID, SupplierName   FROM Supplier INNER JOIN Delivery INNER JOIN Item  ON Supplier.SupplierID = Delivery.SupplierID   AND Item.ItemID = Delivery.ItemID  WHERE ItemName = 'Compass'; 

#4
SELECT Item.ItemName, ItemType,  Department.DepartmentID, DepartmentFloor  FROM Item INNER JOIN Sale INNER JOIN Department  ON Sale.ItemID = Item.ItemID  AND Sale.DepartmentID =     Department.DepartmentID;

#5
SELECT Supplier.SupplierID, SupplierName FROM Supplier  INNER JOIN Delivery INNER JOIN Item  ON Supplier.SupplierID = Delivery.SupplierID  AND Item.ItemID = Delivery.ItemID  WHERE (ItemType = 'C' OR ItemType = 'N')  GROUP BY Delivery.SupplierID, SupplierName   HAVING SUM(DeliveryQTY) > 40;

#6
SELECT emp.EmployeeID, emp.EmployeeName  FROM Employee emp INNER JOIN Employee boss ON emp.BossID = boss.EmployeeID WHERE boss.EmployeeSalary < emp.EmployeeSalary;

#7
SELECT wrk.EmployeeName, wrk.DepartmentID,  boss.EmployeeName  FROM Employee wrk INNER JOIN Employee boss  ON wrk.BossID = boss.EmployeeID  WHERE wrk.DepartmentID = boss.DepartmentID;

#8!!!
SELECT wrk.EmployeeName, wrk.EmployeeSalary, 
boss.EmployeeName 
FROM Employee wrk INNER JOIN Employee boss 
ON wrk.BossID = boss.EmployeeID 
WHERE wrk.DepartmentID = 11
AND wrk.EmployeeSalary > 25000; 

#9~~~
SELECT EmployeeName, EmployeeSalary FROM Employee 
WHERE EmployeeSalary > 
(SELECT MAX(EmployeeSalary)  
FROM Employee NATURAL JOIN Department 
WHERE DepartmentName = "Marketing "); 

#10!!!
SELECT EmployeeName, EmployeeSalary FROM Employee 
WHERE EmployeeID IN 
(SELECT BossID FROM Employee 
GROUP BY BossID  
HAVING COUNT(*) > 2); 

#11!!!
SELECT SupplierID, SupplierName FROM Supplier 
WHERE SupplierID NOT IN 
(SELECT SupplierID FROM Delivery  
NATURAL JOIN Item  
WHERE ItemName = 'Compass'); 

#12!!!
SELECT Supplier.SupplierID, SupplierName FROM Delivery 
NATURAL JOIN Supplier NATURAL JOIN Item 
WHERE ItemType = 'N' 
GROUP BY Supplier.SupplierID, SupplierName 
HAVING COUNT(DISTINCT Delivery.ItemID) > 1; 
 
SELECT Supplier.SupplierID, SupplierName, count(Distinct Delivery.ItemID) as NumItems  
FROM Delivery NATURAL JOIN Supplier NATURAL JOIN Item 
WHERE ItemType = 'N' 
GROUP BY Supplier.SupplierID, SupplierName 
HAVING NumItems > 1; 

#13
SELECT ItemName FROM Delivery NATURAL JOIN Item 
GROUP BY ItemName  
HAVING COUNT(DISTINCT SupplierID) = 1; 

#14
SELECT Supplier.SupplierID, SupplierName  
FROM Delivery NATURAL JOIN Supplier 
GROUP BY Supplier.SupplierID, SupplierName 
HAVING COUNT(DISTINCT Delivery.ItemID) >= 10; 

#15
SELECT DISTINCT ItemName FROM Item 
WHERE ItemID IN 
(SELECT ItemID FROM Delivery NATURAL JOIN Supplier 
WHERE SupplierName = 'Nepalese corp.') 
AND ItemID IN 
(SELECT ItemID FROM Sale NATURAL JOIN Department 
WHERE DepartmentName = 'Navigation'); 

#16
SELECT DISTINCT ItemName FROM Item 
WHERE ItemID IN 
(SELECT ItemID FROM Delivery NATURAL JOIN Supplier 
WHERE SupplierName = 'Nepalese corp.') 
OR ItemID IN 
(SELECT ItemID FROM Sale NATURAL JOIN Department 
WHERE DepartmentName = 'Navigation'); 

#17
SELECT FORMAT(AVG(EmployeeSalary),2) AS AverageSalary 
FROM Employee INNER JOIN Department 
ON Department.DepartmentID = Employee.DepartmentID 
WHERE DepartmentName = 'Clothes'; 

#18
SELECT DepartmentName, FORMAT(AVG(EmployeeSalary),2) AS AverageSalary 
FROM Employee INNER JOIN Department 
ON Department.DepartmentID = Employee.DepartmentID 
GROUP BY DepartmentName; 

#19
SELECT Department.DepartmentName,  
FORMAT(AVG(EmployeeSalary),2) AS AverageSalary 
FROM Employee NATURAL JOIN Department 
WHERE DepartmentFloor = 2 
GROUP BY Department.DepartmentName; 

#20
SELECT Department.DepartmentName,  
FORMAT(AVG(EmployeeSalary),2) AS AverageSalary 
FROM Employee INNER JOIN Department INNER JOIN Sale INNER JOIN Item 
ON Employee.DepartmentID = Department.DepartmentID 
AND Department.DepartmentID = Sale.DepartmentID 
AND Sale.ItemID = Item.ItemID 
WHERE ItemType = 'E' 
GROUP BY Department.DepartmentName; 


#21 no

#22
SELECT SUM(SaleQTY) FROM Item INNER JOIN Sale INNER JOIN Department 
ON Item.ItemID = Sale.ItemID 
AND Department.DepartmentID = Sale.DepartmentID 
WHERE ItemType = 'E' 
AND DepartmentFloor = 2; 

#23
SELECT Item.ItemName, SUM(SaleQTY) FROM Item  
INNER JOIN Sale INNER JOIN Department 
ON Item.ItemID = Sale.ItemID 
AND Department.DepartmentID = Sale.DepartmentID 
WHERE DepartmentFloor = 2 
GROUP BY Item.ItemName; 

#24
SELECT DepartmentID,  
FORMAT(lower(EmployeeSalary),2) AS AverageSalary  
FROM Employee 
GROUP BY DepartmentID 
HAVING AVG(EmployeeSalary) > 25000; 

#25??????????????????????????????
CREATE VIEW vAvgSalaryDept (DepartmentID, dpavgsal) AS 
SELECT DepartmentID, AVG(EmployeeSalary) FROM Employee 
GROUP BY DepartmentID; 
SELECT dpavgsal from vAvgSalaryDept;
SELECT EmployeeName,FORMAT((EmployeeSalary-dpavgsal),2) as 
Salary_DeptAvgSalary
from vAvgSalaryDept natural JOIN Employee NATURAL JOIN Department
WHERE Department.DepartmentName = 'Accounting';

#26
SELECT EmployeeName, EmployeeSalary, FORMAT(dpavgsal,2) AS DeptAvSal,
FORMAT(EmployeeSalary - dpavgsal,2) AS DiffEAvgDSal 
FROM vAvgSalaryDept NATURAL JOIN Employee 
WHERE vAvgSalaryDept.DepartmentID =  Employee.DepartmentID; 

#27~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#use view
##create a view
CREATE VIEW vDeptFloor2ItemB AS 
(SELECT DepartmentID FROM Department 
WHERE DepartmentFloor = 2 AND NOT EXISTS  
(SELECT * FROM Item WHERE ItemType = 'R' AND NOT EXISTS  
(SELECT * FROM Sale WHERE Sale.ItemID = Item.ItemID 
AND Sale.DepartmentID = Department.DepartmentID))); 
##take advantage of the view
SELECT SupplierName FROM Supplier WHERE NOT EXISTS  
(SELECT * FROM Item WHERE ItemType = 'B' AND NOT EXISTS  
(SELECT * FROM Delivery WHERE Delivery.ItemID = Item.ItemID 
AND Delivery.SupplierID = Supplier.SupplierID 
AND DepartmentID IN  
(SELECT DepartmentID FROM vDeptFloor2ItemB))); 
#don't use  a  view

#28!!!!!!!!!!!!!!!!!!!!
#29
CREATE VIEW vAvgSalary(allavgsal) AS 
SELECT AVG(EmployeeSalary) FROM Employee;  
select EmployeeName,(EmployeeSalary - allavgsal) from vAvgSalary natural JOIN Employee
WHERE DepartmentID IN
(select DepartmentID from Department
WHERE DepartmentName = 'Accounting'); 

select EmployeeName,(EmployeeSalary - allavgsal) from vAvgSalary natural JOIN Employee natural JOIN Department
WHERE DepartmentName = 'Accounting';

#30
SELECT count(*) FROM 
(SELECT DISTINCT SupplierID, DepartmentID FROM Delivery NATURAL JOIN Item 
WHERE ItemType = 'E' ) AS tempname; 

SELECT count( DISTINCT SupplierName, DepartmentName )
FROM Delivery NATURAL JOIN Item NATURAL JOIN Department NATURAL JOIN Supplier 
WHERE ItemType = 'E'; 

SELECT count(*) FROM 
(SELECT DISTINCT SupplierName, DepartmentName FROM Delivery NATURAL JOIN Item NATURAL JOIN Department NATURAL JOIN Supplier
WHERE ItemType = 'E' ) AS tempname; 

##seems unsafe distinct. it's ok but we have to use distinct for multi-column
SELECT count( DISTINCT SupplierName, DepartmentName) FROM Delivery NATURAL JOIN Item NATURAL JOIN Department NATURAL JOIN Supplier
WHERE ItemType = 'E'; 


#31
SELECT AVG(EmployeeSalary) FROM Employee; 
#why the pdf talk about the rounding, I believe it's because of weight
select * from vAvgSalaryDept;
select dpavgsal from vAvgSalaryDept;
SELECT AVG(dpavgsal) FROM vAvgSalaryDept;

#32???

#33???

#34
SELECT DISTINCT ItemID FROM Sale INNER JOIN Department 
ON Department.DepartmentID = Sale.DepartmentID 
WHERE DepartmentFloor = 2; 

SELECT DISTINCT ItemID FROM Sale 
WHERE DepartmentID IN 
(SELECT DepartmentID FROM Department  
WHERE DepartmentFloor = 2); 

SELECT DISTINCT ItemID FROM Sale 
WHERE DepartmentID IN 
(SELECT DepartmentID FROM Department 
WHERE Department.DepartmentID = Sale.DepartmentID 
AND DepartmentFloor = 2); 

SELECT Count(DepartmentID )FROM Department  
WHERE DepartmentFloor = 2;

SELECT Count(distinct DepartmentID )FROM Department NATURAL JOIN Sale
WHERE DepartmentFloor = 2;

#35
SELECT DISTINCT ItemID FROM Sale 
WHERE ItemID NOT IN 
(SELECT DISTINCT ItemID FROM Sale NATURAL JOIN Department 
WHERE DepartmentFloor = 2); 

#36???????????

#37
SELECT DISTINCT DepartmentName FROM Sale  
NATURAL JOIN Department D  
WHERE ItemID = 17 
AND D.DepartmentID IN  
(SELECT DepartmentID FROM Employee 
GROUP BY DepartmentID  
HAVING SUM(EmployeeSalary) > 25000) ;

#38
SELECT EmployeeID,EmployeeName, EmployeeSalary FROM Employee 
WHERE EmployeeID IN 
(SELECT BossID FROM Employee  
WHERE EmployeeName = 'Clare'); 

SELECT BossID FROM Employee  
where EmployeeName = 'Clare'; 

#39!!!!
SELECT boss.EmployeeID, boss.EmployeeName, COUNT(*) 
FROM Employee wrk INNER JOIN Employee boss 
ON wrk.BossID = boss.EmployeeID 
GROUP BY boss.EmployeeID, boss.EmployeeName; 

#40???????????
-- SELECT DISTINCT DepartmentID FROM Employee 
-- WHERE DepartmentID <> 1 
-- AND DepartmentID NOT IN 
-- (SELECT wrk.DepartmentID FROM Employee wrk INNER JOIN Employee boss 
-- ON wrk.BossID = boss.EmployeeID 
-- WHERE wrk.EmployeeSalary >= boss.EmployeeSalary); 

#41???????????
-- SELECT DISTINCT DepartmentName FROM Sale NATURAL JOIN Department 
-- WHERE ItemID IN 
-- (SELECT Item.ItemID FROM Item INNER JOIN Delivery  
-- INNER JOIN Supplier 
-- ON Item.ItemID = Delivery.ItemID  
-- AND Delivery.SupplierID = Supplier.SupplierID 
-- WHERE SupplierName = 'Nepalese Corp.' 
-- AND ItemType = 'E') 
-- OR ItemID IN 
-- (SELECT ItemID FROM Sale NATURAL JOIN Department 
-- WHERE DepartmentName = 'Navigation'); 

#42??????
-- SELECT COUNT(*) > 0 FROM Department 
-- WHERE DepartmentFloor <> 3 
-- AND EXISTS 
-- (SELECT * FROM Sale NATURAL JOIN Item 
-- WHERE Sale.DepartmentID = Department.DepartmentID 
-- AND ItemType = 'C'); 

#43 amazing
SELECT DISTINCT Supplier.SupplierID, SupplierName, ItemID 
FROM Supplier NATURAL JOIN Delivery del1 
WHERE ItemID NOT IN 
(SELECT ItemID FROM Delivery 
WHERE Delivery.SupplierID <> del1.SupplierID); 
#how about this? distinct is neccessary.2 also uses this approach 
##???????????????wierd, why I have to put group by beforeward? may not be good.
SELECT DISTINCT Supplier.SupplierID, SupplierName, ItemID 
FROM Supplier NATURAL JOIN Delivery
Group  by ItemID
HAVING count(distinct SupplierID)=1
;

#44???

#45

#46

#47

#48

#49

#50

#51

#52

#54

#55

#56

#57

#58

#59

#60

##################################################################
#part 4
#1
SELECT ItemName FROM Item  
WHERE ItemType = "C" 
AND ItemColour = "Green"; 

#2 but ...lab's solu1 and solu1 don't match with each other?!
SELECT DepartmentName FROM Department 
WHERE DepartmentID IN 
(SELECT DepartmentID FROM Sale  
GROUP BY DepartmentID  
HAVING COUNT(DISTINCT ItemID) > 3); 
#I believe the answer is wrong and I've corrected it
#merely says 4 items, didnt say 4 kinds of items as below
SELECT DepartmentName FROM Department NATURAL JOIN Sale 
GROUP BY DepartmentID
HAVING COUNT(SaleID) > 3;# for 4 kinds of items we will do: HAVING COUNT(ItemID) > 3 

#3 I believe the answer is wrong again
SELECT DepartmentName, COUNT(SaleID) FROM Department NATURAL JOIN Sale #for 4 kinds of items we will do: COUNT(ItemID) 
GROUP BY DepartmentID
HAVING COUNT(SaleID) > 3; # for 4 kinds of items we will do: HAVING COUNT(ItemID) > 3 

#4
SELECT Emp.EmployeeName FROM Employee AS Emp INNER JOIN Employee AS Boss 
ON Emp.BossID = Boss.EmployeeID 
WHERE Emp.DepartmentID = Boss.DepartmentID; 
#so da si nie, we can use without alias
SELECT Emp.EmployeeName FROM Employee Emp INNER JOIN Employee Boss 
ON Emp.BossID = Boss.EmployeeID 
WHERE Emp.DepartmentID = Boss.DepartmentID; 

#5
SELECT ItemName FROM Item NATURAL JOIN Sale NATURAL JOIN Department  
WHERE DepartmentName = "Recreation" AND ItemColour = "Brown";  

#6
SELECT Emp.EmployeeName FROM Employee AS Emp INNER JOIN Employee AS Boss  
ON Boss.EmployeeID = Emp.BossID 
WHERE Emp.EmployeeSalary <= (Boss.EmployeeSalary /2); 

#7 could I use count??????????????????????
SELECT DepartmentName FROM Department
WHERE DepartmentID NOT IN 
(SELECT DepartmentID FROM Sale NATURAL JOIN Item 
WHERE ItemName = "Geo Positioning System"); 

#8?????I cant focus
-- SELECT ItemName FROM SALE NATURAL JOIN Item 
-- GROUP BY ItemName 
-- HAVING COUNT(DepartmentID) >= 2; 

#9
SELECT EmployeeName FROM Employee 
WHERE EmployeeSalary =  
(SELECT MAX(EmployeeSalary) FROM Employee NATURAL JOIN Department 
WHERE DepartmentName = "Marketing"); 

#10
SELECT EmployeeName, EmployeeSalary FROM Employee 
WHERE EmployeeSalary < 
(SELECT AVG(EmployeeSalary)*0.60 FROM Employee); 

#11
SELECT COUNT(EmployeeID) FROM Employee 
WHERE EmployeeSalary < 15000; 

#12
SELECT ItemName, COUNT(SaleQTY) AS UnitsSold  
FROM Sale NATURAL JOIN Item 
GROUP BY ItemName; 

#13
#wth? how come??? so many times doing this weird logic, how come???
SELECT SupplierName, COUNT(Supplier.SupplierID) FROM Delivery INNER JOIN Supplier 
ON Supplier.SupplierID = Delivery.SupplierID 
GROUP BY SupplierName 
HAVING COUNT(Supplier.SupplierID) <= 2; 
#mine
SELECT SupplierName, COUNT(Delivery.DeliveryID) FROM Delivery INNER JOIN Supplier 
ON Supplier.SupplierID = Delivery.SupplierID 
GROUP BY SupplierName 
HAVING COUNT(Delivery.DeliveryID) <= 2; 

#14 why error? could I use count??????
-- WHERE Delivery.SupplierID NOT IN 
-- (SELECT SupplierID FROM Delivery NATURAL JOIN Item 
-- WHERE Itemname = 'Compass'); 

#15
#dont need join?
SELECT Department.DepartmentName, Department.DepartmentFloor, AVG(EmployeeSalary) 
FROM Employee, Department 
WHERE Department.DepartmentID = Employee.DepartmentID 
GROUP BY Department.DepartmentName, Department.DepartmentFloor; 

SELECT Department.DepartmentName, Department.DepartmentFloor, AVG(EmployeeSalary) 
FROM Employee inner join Department 
WHERE Department.DepartmentID = Employee.DepartmentID 
GROUP BY Department.DepartmentName, Department.DepartmentFloor; 

#16
SELECT DepartmentName FROM Department 
WHERE DepartmentFloor = 2; 

#17
SELECT DISTINCT SupplierName, ItemName FROM Supplier INNER JOIN Delivery INNER JOIN Item 
ON Delivery.SupplierID = Supplier.SupplierID 
AND Item.ItemID = Delivery.ItemID  
ORDER BY SupplierName, ItemName; 
#test ascend?
SELECT DISTINCT SupplierName, ItemName FROM Supplier INNER JOIN Delivery INNER JOIN Item 
ON Delivery.SupplierID = Supplier.SupplierID 
AND Item.ItemID = Delivery.ItemID  
ORDER BY SupplierName desc, ItemName asc; 

#18
# still weird, but also make sense?
SELECT DepartmentName, COUNT(DepartmentName)  
FROM Employee NATURAL JOIN Department 
GROUP BY DepartmentName;
#mine
SELECT DepartmentName, COUNT(EmployeeID)  
FROM Employee NATURAL JOIN Department 
GROUP BY DepartmentName;

#19
SELECT EmployeeName FROM Employee 
WHERE BossID IN  
(SELECT EmployeeID FROM Employee 
WHERE EmployeeName = "Todd"); 

#ok let me use a self join. wth, I tried several times
SELECT emp.EmployeeName FROM Employee as emp inner join Employee as boss
on boss.EmployeeID = emp.BossID
WHERE boss.EmployeeName = "Todd"; 

#20
SELECT EmployeeName FROM Employee 
WHERE EmployeeID IN  
(SELECT BossID FROM Employee  
WHERE EmployeeName = 'Sophie'); 

#ok let me use a self join. wth, I tried several times
SELECT boss.EmployeeName FROM Employee as emp inner join Employee as boss
on boss.EmployeeID = emp.BossID
WHERE emp.EmployeeName = "Sophie"; 

#21
SELECT boss.EmployeeName AS Manager, emp.EmployeeName AS Employee 
FROM Employee AS emp, Employee AS boss 
WHERE emp.BossID = boss.EmployeeID 
ORDER BY boss.EmployeeName, emp.EmployeeName; 

#22
SELECT EmployeeName FROM Employee 
WHERE EmployeeSalary = (SELECT MIN(EmployeeSalary) FROM Employee); 

#23 could I use count?
SELECT DISTINCT ItemName FROM Delivery NATURAL JOIN Item 
WHERE Delivery.ItemID NOT IN 
(SELECT DISTINCT ItemID FROM Delivery NATURAL JOIN Department 
 WHERE DepartmentName = 'Books'); 

#24

#25

#26

#27
SELECT DISTINCT ItemName FROM Item WHERE ItemID NOT IN 
(SELECT ItemID FROM Delivery NATURAL JOIN Supplier 
WHERE SupplierName = "Nepalese Corp."); 

#28

#29

#30

#31

#32

#33

#34

#35

#36

#37

#38

#39

#40

#41

#42


