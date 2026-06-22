-- Last updated: 6/22/2026, 6:30:25 PM
# Write your MySQL query statement below
WITH FirstLogins AS (
    SELECT player_id,MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
)

SELECT ROUND(COUNT(a.player_id)/COUNT(f.player_id),2) as fraction
FROM FirstLogins as f LEFT JOIN Activity as a ON f.player_id = a.player_id AND a.event_date = DATE_ADD(f.first_login, INTERVAL 1 DAY);