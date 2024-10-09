# Write your MySQL query statement below
SELECT t1.name,t2.unique_id FROM Employees as t1 left join EmployeeUNI as t2 on t1.id=t2.id;