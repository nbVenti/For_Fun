from unittest import TestCase
from school import School
from student import Student


class TestSchool(TestCase):
    """ Unit Tests for the School Class """

    def test_school(self):
        """ 010A - Valid Construction """

        test_school = School("Computing and Academic Studies")
        self.assertIsNotNone(test_school, "School must be defined")

    def test_school_invalid_parameters(self):
        """ 010B - Invalid Construction Parameters """

        # Must reject an undefined school name
        undefined_school = None
        self.assertRaisesRegex(ValueError, "School Name cannot be undefined", School, undefined_school)

        # Must reject an empty school name
        empty_school = ""
        self.assertRaisesRegex(ValueError, "School Name cannot be empty.", School, empty_school)

    def test_add_student(self):
        """ 020A - Valid Add student """
        test_student_1 = Student("Bill", "Smith", "A0100000000", "CIT")
        test_student_1.add_course("ACIT2515")

        test_student_2 = Student("Ken", "Rodgers", "A0100000001", "CIT")
        test_student_2.add_course("ACIT2515")
        test_student_2.add_course("COMP1409")

        test_school = School("Computing and Academic Studies")
        self.assertEqual(test_school.get_num_students(), 0, "School must have no students")

        test_school.add_student(test_student_1)
        self.assertEqual(test_school.get_num_students(), 1, "School must have 1 student")

        test_school.add_student(test_student_2)
        self.assertEqual(test_school.get_num_students(), 2, "School must have 2 students")

    def test_add_student_undefined(self):
        """ 020B - Invalid Add invalid student """

        test_school = School("Computing and Academic Studies")

        invalid_student = None
        self.assertRaisesRegex(ValueError, "Student must be defined.", test_school.add_student, invalid_student)

    def test_add_student_already_exists(self):
        """ 020C - student already exists """

        test_student_1 = Student("Bill", "Smith", "A0100000000", "CIT")
        test_student_1.add_course("ACIT2515")

        test_school = School("Computing and Academic Studies")
        self.assertEqual(test_school.get_num_students(), 0, "School must have no students")

        test_school.add_student(test_student_1)
        self.assertEqual(test_school.get_num_students(), 1, "School must have 1 student")

        # Add the same student again
        test_school.add_student(test_student_1)
        self.assertEqual(test_school.get_num_students(), 1, "School must have 1 students")

    def test_student_exists(self):
        """ 030A - Valid student exists """

        test_student_1 = Student("Bill", "Smith", "A0100000000", "CIT")
        test_student_1.add_course("ACIT2515")

        test_student_2 = Student("Ken", "Rodgers", "A0100000001", "CIT")
        test_student_2.add_course("ACIT2515")
        test_student_2.add_course("COMP1409")

        test_school = School("Computing and Academic Studies")
        test_school.add_student(test_student_1)
        test_school.add_student(test_student_2)

        self.assertTrue(test_school.student_exists("A0100000000"), "Student A0100000000 must exist")
        self.assertTrue(test_school.student_exists("A0100000001"), "Student A0100000001 must exist")

    def test_student_exists_invalid_student_id(self):
        """ 030B - Invalid student Exists Parameters """

        test_school = School("Computing and Academic Studies")

        student_id_undef = None
        self.assertRaisesRegex(ValueError, "Student Number cannot be undefined.", test_school.student_exists, student_id_undef)

        student_id_empty = ""
        self.assertRaisesRegex(ValueError, "Student Number cannot be empty.", test_school.student_exists, student_id_empty)

    def test_student_exists_not_existent_student(self):
        """ 030C - Valid student Does Not Exist """

        test_student_1 = Student("Bill", "Smith", "A0100000000", "CIT")
        test_student_1.add_course("ACIT2515")

        test_student_2 = Student("Ken", "Rodgers", "A0100000001", "CIT")
        test_student_2.add_course("ACIT2515")
        test_student_2.add_course("COMP1409")

        test_school = School("Computing and Academic Studies")
        test_school.add_student(test_student_1)
        test_school.add_student(test_student_2)

        self.assertFalse(test_school.student_exists("B0100000000"), "student B0100000000 must NOT exist")
        self.assertFalse(test_school.student_exists("A0100000002"), "student A0100000002 must NOT exist")

    def test_remove_student(self):
        """ 040A - Valid Remove Student """

        test_student_1 = Student("Bill", "Smith", "A0100000000", "CIT")
        test_student_1.add_course("ACIT2515")

        test_student_2 = Student("Ken", "Rodgers", "A0100000001", "CIT")
        test_student_2.add_course("ACIT2515")
        test_student_2.add_course("COMP1409")

        test_school = School("Computing and Academic Studies")
        test_school.add_student(test_student_1)
        test_school.add_student(test_student_2)

        self.assertEqual(test_school.get_num_students(), 2, "School must have 2 students")
        self.assertTrue(test_school.student_exists("A0100000000"))
        self.assertTrue(test_school.student_exists("A0100000001"))

        test_school.remove_student("A0100000001")
        self.assertEqual(test_school.get_num_students(), 1, "School must have 1 student")
        self.assertFalse(test_school.student_exists("A0100000001"))

    def test_remove_student_invalid_student_id(self):
        """ 040B - Invalid Remove student Parameters """

        test_school = School("Computing and Academic Studies")

        student_id_undef = None
        self.assertRaisesRegex(ValueError, "Student Number cannot be undefined.", test_school.remove_student, student_id_undef)

        student_id_empty = ""
        self.assertRaisesRegex(ValueError, "Student Number cannot be empty.", test_school.remove_student, student_id_empty)

    def test_remove_non_existent_student(self):
        """ 040C - Invalid Remove student Non-Existent """

        test_student_1 = Student("Bill", "Smith", "A0100000000", "CIT")
        test_student_1.add_course("ACIT2515")

        test_student_2 = Student("Ken", "Rodgers", "A0100000001", "CIT")
        test_student_2.add_course("ACIT2515")
        test_student_2.add_course("COMP1409")

        test_school = School("Computing and Academic Studies")
        test_school.add_student(test_student_1)
        test_school.add_student(test_student_2)

        self.assertEqual(test_school.get_num_students(), 2, "School must have 2 students")
        self.assertTrue(test_school.student_exists("A0100000000"))
        self.assertTrue(test_school.student_exists("A0100000001"))

        test_school.remove_student("B0100000001")
        self.assertEqual(test_school.get_num_students(), 2, "School must have 2 students")

    def test_get_student(self):
        """ 050A - Valid Get student """
        test_student_1 = Student("Bill", "Smith", "A0100000000", "CIT")
        test_student_1.add_course("ACIT2515")

        test_student_2 = Student("Ken", "Rodgers", "A0100000001", "CIT")
        test_student_2.add_course("ACIT2515")
        test_student_2.add_course("COMP1409")

        test_school = School("Computing and Academic Studies")
        test_school.add_student(test_student_1)
        test_school.add_student(test_student_2)

        retrieved_student = test_school.get_student("A0100000001")
        self.assertEqual(retrieved_student.get_student_number(), "A0100000001", "student must have student number A0100000001")
        self.assertEqual(retrieved_student.get_program(), "CIT", "student must be in CIT program")

    def test_get_student_invalid_employee_num(self):
        """ 050B - Invalid Get student Parameters """

        test_school = School("Computing and Academic Studies")

        student_num_undef = None
        self.assertRaisesRegex(ValueError, "Student Number cannot be undefined.", test_school.get_student, student_num_undef)

        student_num_empty = ""
        self.assertRaisesRegex(ValueError, "Student Number cannot be empty.", test_school.get_student, student_num_empty)

    def test_get_non_existent_student(self):
        """ 050C - Invalid Get student Non-Existent """

        test_student_1 = Student("Bill", "Smith", "A0100000000", "CIT")
        test_student_1.add_course("ACIT2515")

        test_student_2 = Student("Ken", "Rodgers", "A0100000001", "CIT")
        test_student_2.add_course("ACIT2515")
        test_student_2.add_course("COMP1409")

        test_school = School("Computing and Academic Studies")
        test_school.add_student(test_student_1)
        test_school.add_student(test_student_2)

        self.assertIsNone(test_school.get_student("AXXXYYYZZZ"), "No student should exists for AXXXYYYZZZ")

    def test_get_num_students_in_program(self):
        """ 060A - Valid Get Number of student in Program """

        test_student_1 = Student("Bill", "Smith", "A0100000000", "CIT")
        test_student_1.add_course("ACIT2515")

        test_student_2 = Student("Ken", "Rodgers", "A0100000001", "CST")
        test_student_2.add_course("COMP1510")

        test_student_3 = Student("Sally", "Jones", "A0100000002", "CST")
        test_student_3.add_course("COMP1510")

        test_student_4 = Student("Julie", "Wong", "A0100000003", "CST")
        test_student_4.add_course("COMP1510")

        test_school = School("Computing and Academic Studies")
        test_school.add_student(test_student_1)
        test_school.add_student(test_student_2)
        test_school.add_student(test_student_3)
        test_school.add_student(test_student_4)

        self.assertEqual(test_school.get_num_students_in_program("CIT"), 1, "Must be only 1 CIT student")
        self.assertEqual(test_school.get_num_students_in_program("CST"), 3, "Must be 3 CST students")
        self.assertEqual(test_school.get_num_students_in_program("SSD"), 0, "Must be no SSD students")

    def test_get_num_students_in_program_invalid_program_name(self):
        """ 060B - Invalid Get Num students in Program Parameters """

        test_school = School("Computing and Academic Studies")

        program_name_undef = None
        self.assertRaisesRegex(ValueError, "Program cannot be undefined.", test_school.get_num_students_in_program, program_name_undef)

        program_name_empty = ""
        self.assertRaisesRegex(ValueError, "Program cannot be empty.", test_school.get_num_students_in_program, program_name_empty)

