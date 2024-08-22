-- Write your PostgreSQL query statement below
SELECT id FROM Weather ww
WHERE temperature>(SELECT temperature from Weather w WHERE w.recordDate= ww.recordDate -1);