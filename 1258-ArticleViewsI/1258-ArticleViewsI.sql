-- Last updated: 6/22/2026, 6:30:21 PM
# Write your MySQL query statement below
SELECT DISTINCT author_id as id
FROM Views
WHERE author_id = viewer_id
ORDER BY id ASC;