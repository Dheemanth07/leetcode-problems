-- Last updated: 6/22/2026, 6:29:17 PM
# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT subject_id) as cnt
FROM Teacher
GROUP BY teacher_id;