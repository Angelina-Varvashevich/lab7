#include "StudentFirstSession.h"
#include <iostream>

StudentFirstSession::StudentFirstSession(std::string name, int course, int group, int *_marks) : Students(
        (std::string) name, (int) course, (int) group) {
    for (int i = 0; i < 4; ++i) {
        marks_first[i] = _marks[i];
    }

}

StudentFirstSession::StudentFirstSession(const Students &copy, int *_marks) : Students(copy) {
    for (int i = 0; i < 4; ++i) {
        marks_first[i] = _marks[i];
    }

}

StudentFirstSession::StudentFirstSession(const StudentFirstSession &student) : Students(student) {
    for (int i = 0; i < 4; ++i) {
        marks_first[i] = student.marks_first[i];
    }

}

const int *StudentFirstSession::GetMarksFirstSession() const {
    return marks_first;
}

int StudentFirstSession::GetMarkFirstSession(int num_of_mark)  {
    return marks_first[num_of_mark-1];
}



void StudentFirstSession::SetMarksFirstSession(int *_marks) {
    for (int i = 0; i < 4; ++i) {
        marks_first[i] = _marks[i];
    }
}


double StudentFirstSession::AverageScore() {
    double sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += marks_first[i];
    }
    return (double) sum / 4.0;
}

std::ostream &operator<<(std::ostream &fout, StudentFirstSession &copy) {
    fout << "Id: " << copy.GetId() << '\n';
    fout << "Name: " << copy.name << '\n';
    fout << "Course: " << copy.course << '\n';
    fout << "Group: " << copy.group << '\n';
    fout << "Card number: " << copy.GetCard_number() << '\n';
    fout << "First session marks: ";
    for (int i = 0; i < 4; ++i) {
        fout << copy.GetMarksFirstSession()[i] << " ";
    }
    return fout;
}



