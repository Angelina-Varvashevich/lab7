#include "gtest/gtest.h"
#include "StudentSecondSession.h"
#include "AverageScore.h"
#include <vector>

TEST(fractionTrue, Students) {
    ASSERT_EQ (5, 5);
}

TEST(Students, getStudents) {
    Students student("lina", 1, 4);
    ASSERT_EQ (student.GetName(), "lina");
    ASSERT_EQ (student.GetCourse(), 1);
    ASSERT_EQ (student.GetGroup(), 4);
    ASSERT_EQ(student.GetCard_number(), "40111");
    ASSERT_EQ(student.GetId(), 1);
}

TEST(Students, setStudents) {
    Students student("lina", 1, 4);
    student.SetName("angelina");
    student.SetCourse(2);
    student.SetGroup(1);
    ASSERT_EQ (student.GetName(), "angelina");
    ASSERT_EQ (student.GetCourse(), 2);
    ASSERT_EQ (student.GetGroup(), 1);
}

TEST(Students, immutableFieldStudents) {
    Students student("vika", 1, 4);
    student.SetName("victoria");
    ASSERT_EQ(student.GetId(), 3);
    student.SetCourse(2);
    student.SetGroup(1);
    ASSERT_EQ(student.GetCard_number(), "40113");
    ASSERT_EQ(student.GetId(), 3);
}

TEST(Students, averageScore) {
    Students student("vika", 1, 4);
    ASSERT_EQ(student.AverageScore(), 0);
}

TEST(StudentsStudentFirstSession, gettersWithStudents) {
    Students student("lina", 1, 4);
    int m[4] = {9, 8, 9, 10};
    StudentFirstSession student1(student, m);
    ASSERT_EQ (student1.GetName(), "lina");
    ASSERT_EQ (student1.GetCourse(), 1);
    ASSERT_EQ (student1.GetGroup(), 4);
    ASSERT_EQ(student1.GetCard_number(), "40115");
    ASSERT_EQ(student1.GetMarkFirstSession(3), 9);
    ASSERT_EQ(student1.GetId(), 6);
}

TEST(StudentsStudentFirstSession, getters) {
    int m[4] = {9, 8, 9, 10};
    StudentFirstSession student("lina", 1, 4, m);
    ASSERT_EQ (student.GetName(), "lina");
    ASSERT_EQ (student.GetCourse(), 1);
    ASSERT_EQ (student.GetGroup(), 4);
    ASSERT_EQ(student.GetCard_number(), "40117");
    ASSERT_EQ(student.GetId(), 7);
}

TEST(StudentFirstSession, setStudents) {
    Students student("lina", 1, 4);
    int m[4] = {9, 8, 9, 10};
    StudentFirstSession student1(student, m);
    student1.SetName("angelina");
    student1.SetCourse(2);
    student1.SetGroup(1);
    int n[4] = {9, 9, 9, 10};
    student1.SetMarksFirstSession(n);
    ASSERT_EQ (student1.GetName(), "angelina");
    ASSERT_EQ (student1.GetCourse(), 2);
    ASSERT_EQ (student1.GetGroup(), 1);
    ASSERT_EQ (student1.GetMarkFirstSession(2), 9);
}

TEST(StudentFirstSession, immutableField) {
    Students student("lina", 1, 4);
    int m[4] = {9, 8, 9, 10};
    StudentFirstSession student1(student, m);
    student1.SetCourse(2);
    student1.SetGroup(1);
    ASSERT_EQ(student1.GetCard_number(), "401110");
    ASSERT_EQ(student.GetId(), 10);
}

TEST(StudentFirstSession, averageScore) {
    int m[4] = {9, 8, 9, 10};
    StudentFirstSession student("dasha", 1, 4, m);
    ASSERT_EQ(student.AverageScore(), 9);

    int n[4] = {10, 7, 7, 3};
    StudentFirstSession student1("dasha", 1, 4, n);
    ASSERT_EQ(student1.AverageScore(), 6.75);

    int r[4] = {0, 0, 0, 0};
    StudentFirstSession student2("dasha", 1, 4, r);
    ASSERT_EQ(student2.AverageScore(), 0);
}

TEST(StudentSecondSession, gettersAndCardNumber) {
    Students student("dasha", 1, 4);
    int m[4] = {9, 8, 9, 10};
    StudentFirstSession student1(student, m);
    int d[5] = {9, 8, 9, 10, 10};
    StudentSecondSession student2(student1, d);
    ASSERT_EQ (student2.GetName(), "dasha");
    ASSERT_EQ (student2.GetCourse(), 1);
    ASSERT_EQ (student2.GetGroup(), 4);
    ASSERT_EQ(student2.GetCard_number(), "401115");
    ASSERT_EQ(student2.GetId(), 17);
    ASSERT_EQ (student2.GetMarkFirstSession(2), 8);
    ASSERT_EQ (student2.GetMarkSecondSession(4), 10);
}

TEST(StudentSecondSession, averageScore) {
    int m[4] = {9, 9, 9, 9};
    int f[5] = {9, 9, 9, 9, 9};
    StudentSecondSession student("dasha", 1, 4, m, f);
    ASSERT_EQ(student.AverageScore(), 9);

    int n[4] = {10, 7, 7, 3};
    int e[5] = {5, 3, 2, 9, 4};
    StudentSecondSession student1("dasha", 1, 4, n, e);
    ASSERT_NEAR(student1.AverageScore(), 5.5556, 0.0001);

    int r[4] = {10, 2, 8, 10};
    int g[5] = {8, 7, 7, 10, 10};
    StudentSecondSession student2("dasha", 1, 4, r, g);
    ASSERT_EQ(student2.AverageScore(), 8);
}

TEST(AverageScore, AverageScoreForGroup2cd) {
    int m[4] = {9, 9, 9, 9};
    int f[5] = {9, 9, 9, 9, 9};
    StudentSecondSession student("dasha", 1, 3, m, f);
    int n[4] = {10, 7, 7, 3};
    int e[5] = {5, 3, 2, 4, 4};
    StudentSecondSession student1("dasha", 1, 4, n, e);
    StudentSecondSession student3("dasha", 2, 4, m, f);
    StudentFirstSession student4("dasha", 1, 3, m);
    int r[4] = {10, 2, 8, 10};
    int g[5] = {8, 7, 7, 10, 10};
    StudentSecondSession student2("dasha", 1, 4, r, g);
    std::vector<StudentSecondSession *> students;
    students.push_back(&student);
    students.push_back(&student1);
    students.push_back(&student2);
    students.push_back(&student3);
    ASSERT_NEAR(AverageScoreForGroup2cd(students, 1, 4), 6.5, 0.00001);
}

TEST(AverageScore, AverageScoreForGroup1st) {
    int m[4] = {6, 6, 6, 6};
    int f[5] = {9, 9, 9, 9, 9};
    StudentFirstSession student("dasha", 1, 3, m);
    int n[4] = {5, 7, 7, 3};
    int e[5] = {5, 3, 2, 4, 4};
    StudentFirstSession student1("dasha", 1, 4, n);
    StudentSecondSession student3("dasha", 2, 4, m, f);
    StudentFirstSession student4("dasha", 1, 4, m);
    int r[4] = {1, 2, 8, 3};
    int g[5] = {8, 7, 7, 10, 10};
    StudentSecondSession student2("dasha", 1, 4, r, g);
    std::vector<StudentFirstSession *> students;
    students.push_back(&student);
    students.push_back(&student1);
    students.push_back(&student4);
    ASSERT_NEAR(AverageScoreForGroup1st(students, 1, 4), 5.75, 0.01);
}

TEST(AverageScore, AverageScoreForGroup2cdEmpty) {
    int m[4] = {6, 6, 6, 6};
    int f[5] = {9, 9, 9, 9, 9};
    StudentSecondSession student("dasha", 1, 3, m, f);
    int n[4] = {5, 7, 7, 3};
    StudentSecondSession student3("dasha", 2, 4, n, f);
    std::vector<StudentSecondSession *> students;
    students.push_back(&student);
    students.push_back(&student3);
    ASSERT_NEAR(AverageScoreForGroup2cd(students, 1, 4), 0, 0.01);
}

TEST(AverageScore, AverageScoreForGroup1stEmpty) {
    int m[4] = {6, 6, 6, 6};
    int f[5] = {9, 9, 9, 9, 9};
    StudentFirstSession student("dasha", 1, 3, m);
    int n[4] = {5, 7, 7, 3};
    StudentFirstSession student1("dasha", 1, 5, n);
    StudentSecondSession student3("dasha", 2, 4, m, f);
    std::vector<StudentFirstSession *> students;
    students.push_back(&student);
    students.push_back(&student1);
    students.push_back(&student3);
    ASSERT_NEAR(AverageScoreForGroup1st(students, 1, 4), 0, 0.01);
}

TEST(AverageScore, AverageScoreForAllWithStudentsClass) {
    int m[4] = {9, 9, 9, 9};
    int f[5] = {9, 9, 9, 9, 9};
    StudentSecondSession student("dasha", 1, 3, m, f);
    int n[4] = {10, 7, 7, 3};
    int e[5] = {5, 3, 2, 4, 4};
    StudentSecondSession student1("dasha", 1, 4, n, e);
    StudentSecondSession student3("dasha", 2, 4, m, f);
    StudentFirstSession student4("dasha", 1, 3, m);
    int r[4] = {10, 2, 8, 10};
    int g[5] = {8, 7, 7, 10, 10};
    StudentSecondSession student2("dasha", 1, 4, r, g);
    Students student5("lina", 4, 2);
    Students student6("lina", 3, 2);
    std::vector<Students *> studentss;
    studentss.push_back(&student);
    studentss.push_back(&student1);
    studentss.push_back(&student2);
    studentss.push_back(&student3);
    studentss.push_back(&student4);
    studentss.push_back(&student5);
    studentss.push_back(&student6);
    ASSERT_NEAR(AverageScoreAllStudents(studentss), 5.714, 0.01);
}


















/*TEST(StudentsStudentFirstSession, averageScore) {
    Students student("lina", 1, 4);
    int m[4] = {9, 8, 9, 10};
    StudentFirstSession student1 (student,m);
    ASSERT_EQ ( student1.GetName(), "lina");
    ASSERT_EQ ( student1.GetCourse(), 1);
    ASSERT_EQ ( student1.GetGroup(), 4);
    ASSERT_EQ(student1.GetCard_number(), "40115");
    /// ASSERT_EQ( student1.GetMarksFirstSession(), m); оценочки достать
    ASSERT_EQ(student1.GetId(), 5);

    ///ASSERT_EQ(student.AverageScore(), 0);
}
*/






