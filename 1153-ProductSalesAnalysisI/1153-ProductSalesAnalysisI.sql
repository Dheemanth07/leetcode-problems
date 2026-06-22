-- Last updated: 6/22/2026, 6:30:29 PM
# Write your MySQL query statement below
SELECT p.product_name, s.year, s.price
FROM Sales as s LEFT JOIN Product as p ON s.product_id = p.product_id;