```sql
SELECT * FROM EMP;
```



```sql
SELECT ename, age
FROM EMP
WHERE dno = 'd1';
```



```sql
SELECT eno, ename
FROM EMP
WHERE dno = 'd2' AND age >= 30;
```



```sql
SELECT ename
FROM EMP
WHERE salary < 20000 OR salary > 30000;
```



```sql
SELECT COUNT(*)
FROM EMP
WHERE dno = 'd3';
```



```sql
SELECT SUM(salary)
FROM EMP
WHERE dno = 'd1';
```



```sql
SELECT ename, salary
FROM EMP
ORDER BY salary ASC;
```



```sql
-- 8)
SELECT *
FROM EMP
WHERE salary IN (18000, 20000);
```



```sql
-- 9)
SELECT ename
FROM EMP
GROUP BY ename
HAVING SUM(salary) > 25000;
```



```sql
-- 10)
SELECT ename
FROM EMP
WHERE salary > 25000 AND dno = 'd1';
```



```sql
-- 11)
SELECT AVG(age)
FROM EMP
WHERE dno = 'd2';
```



```sql
-- 12)
SELECT ename, salary, age
FROM EMP
WHERE dno = 'd1'
ORDER BY age;
```



```sql
-- 13)
SELECT COUNT(*)
FROM EMP
WHERE salary > 20000 AND dno = 'd1';
```

