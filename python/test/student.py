class Student:
    """ Student Class - Maintains the details of a student in a post secondary institution """

    FIRST_NAME_LABEL = "First Name"
    LAST_NAME_LABEL = "Last Name"
    STUDENT_NUM_LABEL = "Student Number"
    PROGRAM_LABEL = "Program"
    COURSE_ID_LABEL = "Course ID"

    def __init__(self, first_name, last_name, student_num, program):
        """ Constructor - Initializes the main attributes of a student """

        Student._validate_string_input(Student.FIRST_NAME_LABEL, first_name)
        self._first_name = first_name

        Student._validate_string_input(Student.LAST_NAME_LABEL, last_name)
        self._last_name = last_name

        Student._validate_string_input(Student.STUDENT_NUM_LABEL, student_num)
        self._student_num = student_num

        Student._validate_string_input(Student.PROGRAM_LABEL, program)
        self._program = program

        self._courses = []

    def get_student_number(self):
        """ Gets the student's student number """
        return self._student_num

    def get_program(self):
        """ Gets the students's program """
        return self._program

    def add_course(self, course_id):
        """ Adds a course to the student. Rejects duplicate courses. """
        Student._validate_string_input("Course ID", course_id)

        if not self.is_enrolled(course_id):
            self._courses.append(course_id)

    def remove_course(self, course_id):
        """ Removes a course from the instructor """

        Student._validate_string_input("Course ID", course_id)

        if self.is_enrolled(course_id):
            self._courses.remove(course_id)

    def is_enrolled(self, course_id):
        """ Checks if the student is enrolled in a given course """

        Student._validate_string_input(Student.COURSE_ID_LABEL, course_id)

        if self._courses.count(course_id) > 0:
            return True

        return False

    def get_full_name(self):
        """ Returns the full name of the instructor """
        return self._first_name + " " + self._last_name

    def get_num_courses(self):
        """ Returns the number of courses an instructor is enrolled in """
        return len(self._courses)

    def get_details(self):
        """ Returns the student details in a printable format """
        course_list = "no courses."

        if len(self._courses) > 0:
            course_list = "the following courses: " + \
                          ", ".join(str(x) for x in self._courses) + \
                          "."

        details = self.get_full_name() + " is an student in the " + self._program + \
                  " program with student number " + self._student_number + \
                  " taking " + course_list

        return details

    @classmethod
    def _validate_string_input(cls, display_name, str_value):
        """ Private helper to validate string values """

        if str_value is None:
            raise ValueError(display_name + " cannot be undefined.")

        if str_value == "":
            raise ValueError(display_name + " cannot be empty.")
