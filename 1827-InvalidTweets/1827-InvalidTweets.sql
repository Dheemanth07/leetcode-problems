-- Last updated: 6/22/2026, 6:29:43 PM
# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;