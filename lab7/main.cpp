#include <iostream>
#include "StudentSecondSession.h"
#include "AverageScore.h"

int main() {
    Students student1("naumov", 4, 3);
    student1.GetCard_number();
    student1.SetName("naumova");
    student1.GetId();
    student1.SetCourse(5);
    std::cout << student1;

    int _marks[4] = {7, 9, 8, 9};
    StudentFirstSession student2(student1, _marks);
    std::cout << student2.GetName();
    std::cout << student2;
    int l[5] = {7, 9, 8, 9, 10};
    StudentSecondSession student3(student2, l);
    student3.SetCourse(5);
    std::cout << student3;
    Students student4("linochka", 1, 4);

    int m[4] = {9, 8, 9, 10};
    int n[5] = {7, 9, 8, 9, 10};
    StudentFirstSession student5(student4, m);
    StudentSecondSession student6(student5, n);
    StudentSecondSession student7("kishkurno", 1, 4, m, n);
    std::cout << student4 << '\n';
    std::cout << student6 << '\n';
    std::cout << student7 << '\n';

    std::cout << student5.AverageScore() << '\n';
    std::cout << student7.AverageScore() << '\n';
    std::cout << student6.AverageScore();
    Students student8("yarik", 1, 4);
    int a[4] = {13, 12, 10, 10};
    StudentFirstSession student9(student8, a);
    int b[5] = {11, 9, 12, 9, 10};
    StudentSecondSession student10(student9, b);
    int c[4] = {9, 9, 8, 9};
    int k[5] = {8, 9, 8, 9, 10};
    StudentSecondSession student11("ann", 4, 2, c, k);
    Students student12("vika", 1, 4);
    int e[4] = {9, 9, 8, 8};
    int d[5] = {8, 9, 8, 9, 10};
    StudentFirstSession student13(student12, e);
    StudentSecondSession student14(student5, d);
    StudentSecondSession student15("tanechka", 1, 4, m, n);

    std::vector<Students *> all_students;
    all_students.push_back(&student3);
    all_students.push_back(&student4);
    all_students.push_back(&student9);
    all_students.push_back(&student10);
    all_students.push_back(&student11);
    all_students.push_back(&student12);
    all_students.push_back(&student13);
    std::cout << AverageScoreAllStudents(all_students);
    return 0;
}
