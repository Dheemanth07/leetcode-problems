-- Last updated: 6/22/2026, 6:30:26 PM
# Write your MySQL query statement below
SELECT p.project_id, ROUND(AVG(e.experience_years),2) as average_years
FROM Project as p JOIN Employee as e ON p.employee_id = e.employee_id
GROUP BY p.project_id;