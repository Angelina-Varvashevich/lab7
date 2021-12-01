#include "StudentSecondSession.h"
#include <iostream>

StudentSecondSession::StudentSecondSession(std::string name, int course, int group, int *_marks, int *_marks2)
        : StudentFirstSession((std::string) name, (int) course, (int) group, (int *) _marks) {
    for (int i = 0; i < 5; ++i) {
        marks_second[i] = _marks2[i];
    }
}

StudentSecondSession::StudentSecondSession(const StudentFirstSession &copy, int *_marks2) : StudentFirstSession(copy) {
    for (int i = 0; i < 5; ++i) {
        marks_second[i] = _marks2[i];
    }

}

StudentSecondSession::StudentSecondSession(const StudentSecondSession &copy) : StudentFirstSession(copy) {
    for (int i = 0; i < 5; ++i) {
        marks_second[i] = copy.marks_second[i];
    }

}

const int *StudentSecondSession::GetMarksSecondSession() const {
    return marks_second;
}

int StudentSecondSession::GetMarkSecondSession(int num_of_mark)  {
    return marks_second[num_of_mark-1];
}


void StudentSecondSession::SetMarksSecondSession(int *_marks) {
    for (int i = 0; i < 5; ++i) {
        marks_second[i] = _marks[i];
    }
}

double StudentSecondSession::AverageScore() {
    double sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += GetMarksFirstSession()[i];
    }
    for (int i = 0; i < 5; ++i) {
        sum += GetMarksSecondSession()[i];
    }
    return sum / 9.0;
}

std::ostream &operator<<(std::ostream &fout, const StudentSecondSession &copy) {
    fout << "Id: " << copy.id << '\n';
    fout << "Name: " << copy.name << '\n';
    fout << "Course: " << copy.course << '\n';
    fout << "Group: " << copy.group << '\n';
    fout << "Card number: " << copy.GetCard_number() << '\n';
    fout << "First session marks: ";
    for (int i = 0; i < 4; ++i) {
        fout << copy.GetMarksFirstSession()[i] << " ";
    }
    fout << "Second session marks: ";
    for (int i = 0; i < 5; ++i) {
        fout << copy.GetMarksSecondSession()[i] << " ";
    }
    return fout;
}


