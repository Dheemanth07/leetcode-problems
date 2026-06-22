-- Last updated: 6/22/2026, 6:30:31 PM
# Write your MySQL query statement below
SELECT 
    customer_id 
FROM 
    Customer 
GROUP BY 
    customer_id 
HAVING 
    COUNT(DISTINCT product_key) = (
        -- Subquery: Dynamic target for total catalog size
        SELECT COUNT(product_key) 
        FROM Product
    );
