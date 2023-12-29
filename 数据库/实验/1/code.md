```sql

CREATE TABLE XSQK (
	stu_id CHAR(6) NOT NULL PRIMARY KEY,
	sname CHAR(8) NOT NULL UNIQUE,
	gender CHAR(1) NOT NULL DEFAULT('1') CHECK(gender IN ('0', '1') ),
	birthday DATETIME	NOT NULL,
	department CHAR(10) NOT NULL,
	major CHAR(10) NOT NULL,
	phone CHAR(11) CHECK( phone >= '10000000000'),
	total_credits TINYINT CHECK( total_credits >= 0 AND total_credits <= 200),
	remarks TEXT
	);
```

```sql
CREATE TABLE KC (
	serial_num INT IDENTITY(1,1),
	course_id CHAR(3) NOT NULL PRIMARY KEY,
	cname CHAR(20) NOT NULL,
	teacher CHAR(8),
	semester TINYINT NOT NULL DEFAULT(1) CHECK( semester > 0 AND semester < 7),
	class_hour TINYINT,
	credit TINYINT
	);
```

```sql
CREATE TABLE XS_KC (
	stu_id CHAR(6) NOT NULL REFERENCES XSQK(stu_id),
	course_id CHAR(3) NOT NULL REFERENCES KC(course_id),
	score TINYINT CHECK( score >= 0 AND score < 101),
	credit TINYINT,
	PRIMARY KEY (stu_id, course_id)
);
```

