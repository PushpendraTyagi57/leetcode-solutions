# Write your MySQL query statement below
SELECT *,
        IF(REGEXP_LIKE(dna_sequence, '^ATG', 'c'), 1, 0) AS has_start,
        IF(REGEXP_LIKE(dna_sequence, '(TAA|TAG|TGA)$', 'c'), 1, 0) AS has_stop,
        IF(REGEXP_LIKE(dna_sequence, 'ATAT', 'c'), 1, 0) AS has_atat,
        IF(REGEXP_LIKE(dna_sequence, '(GGG|GGGG)', 'c'), 1, 0) AS has_ggg
FROM Samples
ORDER BY sample_id ASC;