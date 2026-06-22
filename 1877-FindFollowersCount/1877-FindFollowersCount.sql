-- Last updated: 6/22/2026, 6:29:42 PM
# Write your MySQL query statement below
SELECT user_id, COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;