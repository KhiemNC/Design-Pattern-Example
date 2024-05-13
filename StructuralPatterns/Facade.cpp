#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Subsystem
class Student {
    private:
    string id;
    public:
    Student(string id) { this->id = id; }
    void display() { cout << "Student: " << id << endl; }
};
class Teacher {
    private:
    string id;
    public:
    Teacher(string id) { this->id = id; }
    void display() { cout << "Teacher: " << id << endl; }
};
class Course {
    private:
    string name;
    public:
    Course(string name) { this->name = name; }
    void display() { cout << "Course: " << name << endl; }
};
// etc.

// Facade
class UniFacade {
    private:
    vector<Student*> students;
    vector<Teacher*> teachers;
    vector<Course*> courses;
    // etc.
    
    public:
    void addStudent(string id) {
        students.push_back(new Student(id));
    }
    void addTeacher(string id) {
        teachers.push_back(new Teacher(id));
    }
    void addCourse(string name) {
        courses.push_back(new Course(name));
    }
    // etc.

    void display() {
        cout << "Students:\n";
        for (auto student : students) {
            student->display();
        }
        cout << "Teachers:\n";
        for (auto teacher : teachers) {
            teacher->display();
        }
        cout << "Courses:\n";
        for (auto course : courses) {
            course->display();
        }
        // etc.
    }
};

int main(int argc, char* argv[]) {
    UniFacade uni;
    uni.addStudent("2211555");
    uni.addStudent("2211676");
    uni.addTeacher("1025");
    uni.addCourse("Math");

    uni.display();
    return 0;
}