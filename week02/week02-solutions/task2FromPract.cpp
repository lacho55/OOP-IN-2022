#include <iostream>
#include <fstream>
 
struct Student {
    double avgGrade;
    char fn[11];
    char name[31];
};
 
 
void read(std::ifstream &input, Student &st) {
    input >> st.avgGrade;
    input >> st.fn;
    input >> st.name;
}
 
void write(std::ofstream &output, Student &st) {
    output << st.name << '\n';
    output << st.fn << '\n';
    output << st.avgGrade << '\n' << '\n';
}
 
void readStudents(std::ifstream &input, Student *students, size_t size) {
    for (size_t i = 0; i < size; i++) {
        read(input, students[i]);
    }
}
 
void writeStudents(std::ofstream &output, Student *students, size_t size) {
    for (size_t i = 0; i < size; i++) {
        write(output, students[i]);
    }
}
 
 
int main() {
    Student st[5] = {};
 
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        return -1;
    }
 
    std::ofstream output("output.txt");
    if (!output.is_open()) {
        return -1;
    }
 
    readStudents(input, st, 3);
    writeStudents(output, st, 3);
 
    input.close();
    output.close();
}