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
