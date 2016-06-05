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