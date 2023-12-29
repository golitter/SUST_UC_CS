-- Table structure for table `dept`
--
CREATE DATABASE projemp;
go

use projemp;
go

CREATE TABLE  DEPT (
  dno char(3) NOT NULL,
  dname char(12) DEFAULT NULL,
  location char(12) DEFAULT NULL,
  PRIMARY KEY (dno)
) 

--
-- Dumping data for table `dept`
--

INSERT INTO DEPT (dno, dname, location) VALUES
('d1', 'information', 'lisburn'),
('d2', 'systems', 'belfast'),
('d3', 'engineering', 'belfast'),
('d4', 'maintenance', 'bangor');

-- --------------------------------------------------------

--
-- Table structure for table `emp`
--

CREATE TABLE EMP (
  eno char(3) NOT NULL,
  ename char(12) DEFAULT NULL,
  salary decimal(7,2) DEFAULT NULL,
  age tinyint,
  supno char(3) DEFAULT NULL,
  dno char(3),
  PRIMARY KEY (eno),
  foreign KEY (dno) references DEPT(dno)
) 

--
-- Dumping data for table `emp`
--

INSERT INTO EMP (eno, ename, age, salary, supno, dno) VALUES
('e1', 'armstrong', 20, 24000.00, '', 'd1'),
('e10', 'jones', 25, 48000.00, 'e1', 'd3'),
('e11', 'kelly', 22, 28000.00, 'e7', 'd2'),
('e12', 'mccoy', 20, 33000.00, 'e3', 'd1'),
('e13', 'neeson',19, 48000.00, 'e19', 'd1'),
('e14', 'oliver', 30,26000.00, 'e17', 'd3'),
('e15', 'pearse',28, 20000.00, 'e21', 'd1'),
('e16', 'quinn', 26,33000.00, 'e2', 'd1'),
('e17', 'roberts',28, 21000.00, 'e4', 'd3'),
('e18', 'smyth', 27,33000.00, 'e21', 'd3'),
('e19', 'trainor',46, 33000.00, 'e7', 'd1'),
('e2', 'breen', 37,17000.00, 'e4', 'd3'),
('e20', 'urquhart',54, 19000.00, 'e11', 'd3'),
('e21', 'vance', 53,15000.00, 'e10', 'd1'),
('e3', 'carroll',27, 18000.00, 'e10', 'd3'),
('e4', 'deehan', 29,50000.00, 'e1', 'd1'),
('e5', 'evans', 29,38000.00, 'e11', 'd1'),
('e6', 'flynn', 36,24000.00, 'e17', 'd1'),
('e7', 'greer', 28,16000.00, 'e1', 'd2'),
('e8', 'hamill', 47,25000.00, 'e3', 'd1'),
('e9', 'irwin', 37,23000.00, 'e2', 'd2');

-- --------------------------------------------------------

--
-- Table structure for table `proj`
--

CREATE TABLE PROJ (
  pno char(3) NOT NULL,
  pname char(12) DEFAULT NULL,
  ptype char(12) DEFAULT NULL,
  budget decimal(7,2) DEFAULT NULL,
  PRIMARY KEY (pno)
) 

--
-- Dumping data for table `proj`
--

INSERT INTO PROJ (pno, pname, ptype, budget) VALUES
('p13', 'payroll', 'access', 52000.00),
('p15', 'database', 'access', 54000.00),
('p19', 'graphics', 'c', 65000.00),
('p23', 'registration', 'access', 79000.00),
('p26', 'examination', 'c', 69000.00),
('p30', 'information', 'java', 43000.00);

-- --------------------------------------------------------

--
-- Table structure for table `works`
--

CREATE TABLE WORKS (
  eno char(3) NOT NULL,
  pno char(3) NOT NULL,
  role char(15) DEFAULT NULL,
  PRIMARY KEY (eno,pno),
  FOREIGN KEY (eno) REFERENCES EMP(eno),
  FOREIGN KEY (pno) REFERENCES PROJ(pno)
) 

--
-- Dumping data for table `works`
--

INSERT INTO WORKS (eno, pno, role) VALUES
('e1', 'p19', 'consultant'),
('e1', 'p23', 'consultant'),
('e10', 'p15', 'manager'),
('e11', 'p19', 'administrator'),
('e12', 'p23', 'consultant'),
('e12', 'p26', 'administrator'),
('e13', 'p23', 'manager'),
('e14', 'p23', 'engineer'),
('e14', 'p26', 'analyst'),
('e15', 'p13', 'programmer'),
('e15', 'p19', 'programmer'),
('e15', 'p26', 'programmer'),
('e16', 'p19', 'manager'),
('e16', 'p23', 'manager'),
('e17', 'p13', 'analyst'),
('e17', 'p19', 'programmer'),
('e18', 'p13', 'consultant'),
('e18', 'p23', 'analyst'),
('e18', 'p26', 'consultant'),
('e19', 'p15', 'analyst'),
('e19', 'p19', 'consultant'),
('e2', 'p15', 'engineer'),
('e20', 'p15', 'engineer'),
('e20', 'p19', 'engineer'),
('e21', 'p13', 'programmer'),
('e21', 'p23', 'programmer'),
('e21', 'p26', 'programmer'),
('e3', 'p19', 'programmer'),
('e3', 'p26', 'engineer'),
('e4', 'p26', 'manager'),
('e5', 'p13', 'manager'),
('e6', 'p19', 'consultant'),
('e6', 'p26', 'analyst'),
('e7', 'p13', 'administrator'),
('e7', 'p15', 'administrator'),
('e8', 'p13', 'programmer'),
('e8', 'p23', 'analyst'),
('e9', 'p13', 'programmer'),
('e9', 'p19', 'consultant');

--
-- Constraints for dumped tables
--

--
-- Constraints for table `emp`
--
ALTER TABLE EMP
  ADD CONSTRAINT emp_ibfk_1 FOREIGN KEY (dno) REFERENCES DEPT(dno);

--
-- Constraints for table `works`
--
ALTER TABLE WORKS
  ADD CONSTRAINT works_ibfk_1 FOREIGN KEY (eno) REFERENCES EMP (eno);
  
  ALTER TABLE WORKS ADD CONSTRAINT works_ibfk_2 FOREIGN KEY (pno) REFERENCES PROJ (pno);
