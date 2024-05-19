class Student:
    def __init__(self, first_name, last_name, student_number, program_name):
        self.first_name = first_name
        self.last_name = last_name
        self.student_number = student_number
        self.program_name = program_name
        self.courses = []

    def add_course(self, course):
        self.courses.append(course)

    def get_student_number(self):
        return self.student_number

    def get_program_name(self):
        return self.program_name


class School:
    def __init__(self, name):
        if name is None:
            raise ValueError("School Name cannot be undefined.")
        if name == "":
            raise ValueError("School Name cannot be empty.")
        self.name = name
        self.students = []

    def add_student(self, student):
        if student is None:
            raise ValueError("Student must be defined.")
        if any(s.get_student_number() == student.get_student_number() for s in self.students):
            print(student.get_student_number())
            return False
            # Not testing for errors
            # raise ValueError("Student already exists.")
        else:
            self.students.append(student)

    def remove_student(self, student_id):
        print(student_id)
        if student_id is None:
            raise ValueError("Student Number cannot be undefined.")
        if student_id == "":
            raise ValueError("Student Number cannot be empty.")
        for student in self.students:
            if student.get_student_number() == student_id:
                self.students.remove(student)
        
                
        

    def get_student(self, student_id):
        if student_id is None:
            raise ValueError("Student Number cannot be undefined.")
        if student_id == "":
            raise ValueError("Student Number cannot be empty.")
        for student in self.students:
            if student.get_student_number() == student_id:
                return student
        return None

    def get_num_students(self):
        return len(self.students)

    def student_exists(self, student_id):
        if student_id is None:
            raise ValueError("Student Number cannot be undefined.")
        if student_id == "":
            raise ValueError("Student Number cannot be empty.")
        for student in self.students:
            if student.get_student_number() == student_id:
                return True
        return False

    def get_num_students_in_program(self, program_name):
        if program_name is None:
            raise ValueError("Program cannot be undefined.")
        if program_name == "":
            raise ValueError("Program cannot be empty.")
        count = 0
        for student in self.students:
            if student.get_program() == program_name:
                count += 1
        return count
