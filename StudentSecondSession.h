#include "StudentFirstSession.h"
#include <iostream>
#include <vector>

#ifndef LAB7_STUDENTSECONDSESSION_H
#define LAB7_STUDENTSECONDSESSION_H


class StudentSecondSession : public StudentFirstSession {
public:
    StudentSecondSession(std::string name, int course, int group, int *_marks, int *_marks2);

    StudentSecondSession(const StudentFirstSession &copy, int *_marks2);

    StudentSecondSession(const StudentSecondSession &copy);

    const int *GetMarksSecondSession() const;

    int GetMarkSecondSession(int num_of_mark);

    void SetMarksSecondSession(int *_marks);

    double AverageScore() override;

    friend std::ostream &operator<<(std::ostream &fout, const StudentSecondSession &copy);

private:
    int marks_second[5];
};


#endif //LAB7_STUDENTSECONDSESSION_H
