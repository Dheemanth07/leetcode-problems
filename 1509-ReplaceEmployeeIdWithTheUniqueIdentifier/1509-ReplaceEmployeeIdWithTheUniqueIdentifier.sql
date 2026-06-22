-- Last updated: 6/22/2026, 6:30:03 PM
# Write your MySQL query statement below
SELECT unique_id,name
FROM Employees as e LEFT JOIN EmployeeUNI as eu ON e.id = eu.id;