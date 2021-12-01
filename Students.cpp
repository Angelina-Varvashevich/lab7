#include "Students.h"
#include <iostream>

int Students::count = 0;

Students::Students(std::string _name, int course, int group) {

    this->name = _name;
    this->course = course;
    this->group = group;
    count++;
    id = count;
    card_number = std::to_string(group) + "0" + std::to_string(course) + "1" + std::to_string(id);
}

Students::Students(const Students &copy) {
    this->name = copy.name;
    this->course = copy.course;
    this->group = copy.group;
    this->card_number = copy.card_number;
    count++;
    id = count;
}

void Students::SetName(std::string newname) {
    name = newname;
}

const std::string Students::GetName() const {
    return name;
}

void Students::SetCourse(int valueCourse) {
    course = valueCourse;
}

const int Students::GetCourse() const {
    return course;
}

void Students::SetGroup(int valueGroup) {
    group = valueGroup;
}

const int Students::GetGroup() const {
    return group;
}

const std::string Students::GetCard_number() const {
    return card_number;
}

const int Students::GetId() const {
    return id;
}

double Students::AverageScore() {
    return 0;
}

std::ostream &operator<<(std::ostream &fout, Students &copy) {
    fout << "Id: " << copy.GetId() << '\n';
    fout << "Name: " << copy.name << '\n';
    fout << "Course: " << copy.course << '\n';
    fout << "Group: " << copy.group << '\n';
    fout << "Card number: " << copy.card_number << '\n';
    return fout;
}





