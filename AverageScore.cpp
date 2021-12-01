#include "StudentSecondSession.h"
#include "AverageScore.h"

double AverageScoreForGroup1st(std::vector<StudentFirstSession *> student, int course, int group) {
    double sum = 0;
    int count = 0;
    for (auto &person: student) {
        if (person->GetCourse() == course && person->GetGroup() == group) {
            sum += person->AverageScore();
            count++;
        }
    }
    if (count == 0|| student.size()==0) {
        return 0;
    }
    return sum / count;
}

double AverageScoreForGroup2cd(std::vector<StudentSecondSession *> student, int course, int group) {
    double sum = 0;
    int count = 0;
    for (auto &person: student) {
        if (person->GetCourse() == course && person->GetGroup() == group) {
            sum += person->AverageScore();
            count++;
        }
    }
    if (count == 0|| student.size()==0) {
        return 0;
    }

    return sum / count;
}

double AverageScoreAllStudents(std::vector<Students *> student) {
    double sum = 0;
    for (auto &person: student) {
        sum += person->AverageScore();
    }
    return sum / student.size();
}