#1
select EmployeeName from Employee;

#1.1
select EmployeeName from Employee WHERE DepartmentID = 1;

#2
SELECT DISTINCT ItemID FROM Sale INNER JOIN Department ON Sale.DepartmentID = Department.DepartmentID WHERE DepartmentFloor = 2;

SELECT DISTINCT ItemID FROM Sale INNER JOIN Department ON Sale.DepartmentID = Department.DepartmentID  WHERE DepartmentFloor <> 2;

SELECT DISTINCT ItemID FROM Sale natural JOIN Department WHERE DepartmentFloor <> 2;

#!!!
SELECT ItemID FROM Sale NATURAl JOIN Department WHERE DepartmentFloor = 2 GROUP BY ItemID HAVING COUNT(DISTINCT Department.DepartmentID) > 1;

#3
SELECT DISTINCT Supplier.SupplierID, SupplierName   FROM Supplier INNER JOIN Delivery INNER JOIN Item  ON Supplier.SupplierID = Delivery.SupplierID   AND Item.ItemID = Delivery.ItemID  WHERE ItemName = 'Compass'; 

#4
SELECT Item.ItemName, ItemType,  Department.DepartmentID, DepartmentFloor  FROM Item INNER JOIN Sale INNER JOIN Department  ON Sale.ItemID = Item.ItemID  AND Sale.DepartmentID =     Department.DepartmentID;

#5
SELECT Supplier.SupplierID, SupplierName FROM Supplier  INNER JOIN Delivery INNER JOIN Item  ON Supplier.SupplierID = Delivery.SupplierID  AND Item.ItemID = Delivery.ItemID  WHERE (ItemType = 'C' OR ItemType = 'N')  GROUP BY Delivery.SupplierID, SupplierName   HAVING SUM(DeliveryQTY) > 40;

#6!!!
SELECT emp.EmployeeID, emp.EmployeeName  FROM Employee emp INNER JOIN Employee boss ON emp.BossID = boss.EmployeeID WHERE boss.EmployeeSalary < emp.EmployeeSalary;

#7!!!
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
#SELECT EmployeeName, FORMAT((EmployeeSalary ‐ dpavgsal),2) AS Salary_DeptAvgSalary
#FROM vAvgSalaryDept NATURAL JOIN Employee NATURAL JOIN Department 
#WHERE Department.DepartmentName = 'Accounting'; 

#26
SELECT EmployeeName, EmployeeSalary, FORMAT(dpavgsal,2) AS DeptAvSal,
FORMAT(EmployeeSalary - dpavgsal,2) AS DiffEAvgDSal 
FROM vAvgSalaryDept NATURAL JOIN Employee 
WHERE vAvgSalaryDept.DepartmentID =  Employee.DepartmentID; 

#27
