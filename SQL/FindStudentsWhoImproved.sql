# Write your MySQL query statement below
WITH cte AS (
    SELECT *,
            ROW_NUMBER() OVER (PARTITION BY student_id, subject ORDER BY exam_date ASC) AS asc_rank,
            ROW_NUMBER() OVER (PARTITION BY student_id, subject ORDER BY exam_date DESC) AS desc_rank,
            COUNT(*) OVER (PARTITION BY student_id, subject) AS cnt
    FROM Scores
)

SELECT c1.student_id,
        c1.subject,
        c1.score AS first_score,
        c2.score AS latest_score
FROM cte AS c1
INNER JOIN cte AS c2
ON c1.student_id = c2.student_id
    AND c1.subject = c2.subject
WHERE c1.asc_rank = 1
    AND c2.desc_rank = 1
    AND c1.cnt > 1
    AND c2.score > c1.score;