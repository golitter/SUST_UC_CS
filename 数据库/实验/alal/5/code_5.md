```sql
4.1 1)
SELECT pname, eno
FROM PROJ INNER JOIN WORKS
ON PROJ.pno = WORKS.pno;
```



```sql
-- 2)
SELECT ename
FROM EMP INNER JOIN DEPT
ON DEPT.dname = 'information' AND EMP.dno = DEPT.dno;
```



```sql
-- 3)
SELECT pname
FROM PROJ INNER JOIN WORKS ON PROJ.pno = WORKS.pno
INNER JOIN EMP ON WORKS.eno = EMP.eno
WHERE ename = 'pearse';
```



```sql
-- 4)
SELECT ename, dname
FROM EMP INNER JOIN DEPT ON EMP.dno = DEPT.dno;
```



```sql
-- 5)
SELECT ename, dname
FROM EMP INNER JOIN DEPT ON EMP.dno = DEPT.dno
WHERE salary > 25000;
```



```sql
-- 6)
SELECT pname, ename
FROM EMP INNER JOIN WORKS ON EMP.eno = WORKS.eno
INNER JOIN PROJ ON WORKS.pno = PROJ.pno;
```



```sql
-- 4.2 1)
SELECT ename 
FROM EMP
WHERE EMP.dno IN (
	SELECT dno FROM DEPT WHERE dname = 'information'
	);
```



```sql
-- 2)
SELECT pname
FROM PROJ
WHERE PROJ.pno IN (
	SELECT pno FROM WORKS
	WHERE WORKS.eno IN (
		SELECT eno FROM EMP
		WHERE EMP.ename = 'pearse'
		)
	);
```



```sql
-- 3)
SELECT ename
FROM EMP
WHERE salary < (SELECT AVG(salary) FROM EMP);
```



```sql
-- 4)
-- Single Query Block Join:
SELECT COUNT(*)
FROM EMP
JOIN DEPT ON EMP.dno = DEPT.dno
WHERE DEPT.dname = 'information';

-- Nested Query:
SELECT COUNT(ename)
FROM EMP
WHERE EMP.dno IN (
	SELECT dno FROM DEPT
	WHERE dname = 'information'
	);
	

```



```sql
-- 5)
-- Single Query Block Join:
SELECT ename 
FROM EMP INNER JOIN WORKS ON EMP.eno = WORKS.eno
INNER JOIN PROJ ON WORKS.pno = PROJ.pno
WHERE pname IN ( 'payroll', 'database');
-- Nested Query:
SELECT ename 
FROM EMP
WHERE EMP.eno IN (
	SELECT eno FROM WORKS WHERE WORKS.pno IN (
		SELECT pno FROM PROJ WHERE pname IN ('payroll', 'database')
		)
	);
```



```sql
-- 6)
SELECT ename 
FROM EMP
WHERE salary > (SELECT AVG(salary) FROM EMP);
```



```sql
-- 7)
SELECT ename, salary
FROM EMP
WHERE EMP.dno IN (
	SELECT dno FROM DEPT WHERE dname = 'information') AND salary > (
		SELECT AVG(salary) FROM EMP WHERE dno IN (
			SELECT dno FROM DEPT WHERE dname = 'information')
			);
```



```sql
-- 8)
SELECT ename, salary
FROM EMP
WHERE EMP.dno IN (
	SELECT dno FROM DEPT WHERE dname = 'information'
	) AND salary > (
		SELECT MAX(salary) FROM EMP WHERE EMP.dno IN (
			SELECT dno FROM DEPT WHERE dname = 'systems'
			)
		);
```

