#include "Students.h"
#include <iostream>

#ifndef LAB7_STUDENTFIRSTSESSION_H
#define LAB7_STUDENTFIRSTSESSION_H


class StudentFirstSession : public Students {
public:
    StudentFirstSession(std::string name, int course, int group, int *_marks);

    StudentFirstSession(const Students &copy, int *_marks);

    StudentFirstSession(const StudentFirstSession &copy);

    const int *GetMarksFirstSession() const;

    void SetMarksFirstSession(int *_marks);

    double AverageScore() override;

    friend std::ostream &operator<<(std::ostream &fout, StudentFirstSession &copy);

protected:
    int marks_first[4];
};

#endif //LAB7_STUDENTFIRSTSESSION_H
