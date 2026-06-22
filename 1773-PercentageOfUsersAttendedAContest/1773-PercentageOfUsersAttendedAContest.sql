-- Last updated: 6/22/2026, 6:29:52 PM
# Write your MySQL query statement below
SELECT r.contest_id, ROUND(COUNT(r.user_id) * 100.0 / u.total_users, 2) AS percentage
FROM Register r
CROSS JOIN (SELECT COUNT(*) AS total_users FROM Users) u
GROUP BY r.contest_id, u.total_users
ORDER BY percentage DESC, contest_id ASC;