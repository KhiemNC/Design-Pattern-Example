#include<iostream>
#include<string>

using namespace std;
class SchoolType;

// Abstraction
class Staff {
    protected:
    SchoolType* schoolType;

    public:
    virtual void work() = 0;
};

// Implementor
class SchoolType {
    public:
    virtual void addSchoolType() = 0;
};

// RefineAbstraction
class Teacher : public Staff {
    public:
    Teacher(SchoolType* schoolType) { this->schoolType = schoolType; }
    void work() override {
        cout << "Teaching in ";
        schoolType->addSchoolType();
    }
};
class Specialist : public Staff {
    public:
    Specialist(SchoolType* schoolType) { this->schoolType = schoolType; }
    void work() override {
        cout << "Specializing in ";
        schoolType->addSchoolType();
    }
};

// ConcreteImplementor
class PrimarySchool : public SchoolType {
    public:
    void addSchoolType() override {
        cout << "Primary School\n";
    }
};
class SecondarySchool : public SchoolType {
    public:
    void addSchoolType() override {
        cout << "Secondary School\n";
    }
};

int main(int argc, char* argv[]) {
    SchoolType* primarySchool = new PrimarySchool();
    SchoolType* secondarySchool = new SecondarySchool();
    Staff* teacher = new Teacher(primarySchool);
    Staff* specialist = new Specialist(secondarySchool);
    teacher->work();
    specialist->work();

    delete primarySchool;
    delete secondarySchool;
    delete teacher;
    delete specialist;
    return 0;
}

/* Output: */
/*
Teaching in Primary School
Specializing in Secondary School
*/