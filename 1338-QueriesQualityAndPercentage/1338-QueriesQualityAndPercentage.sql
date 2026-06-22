-- Last updated: 6/22/2026, 6:30:14 PM
# Write your MySQL query statement below
SELECT query_name, ROUND(AVG(rating * 1.0 /position), 2) AS quality, ROUND(AVG(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100, 2) as poor_query_percentage
FROM Queries
GROUP BY query_name;