#include <iostream>
#include <string>

#ifndef LAB7_STUDENTS_H
#define LAB7_STUDENTS_H

class Students {
public:
    static int count;

    Students(std::string name, int course, int group);

    Students(const Students &copy);

    void SetName(std::string main);

    const std::string GetName() const;

    void SetCourse(int valueCourse);

    const int GetCourse() const;

    void SetGroup(int valueGroup);

    const int GetGroup() const;

    const std::string GetCard_number() const;

    const int GetId() const;

    friend std::ostream &operator<<(std::ostream &fout, Students &copy);

    virtual double AverageScore();

protected:
    std::string name;
    int course;
    int group;
    int id;
private:
    std::string card_number;
};

#endif
