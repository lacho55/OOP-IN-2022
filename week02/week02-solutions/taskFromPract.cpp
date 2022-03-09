#include <iostream>
#include <fstream>
#include <iomanip>
 
double read(std::ifstream &input) {
    double number = 0;
    input >> number;
    return number;
}
 
void write(std::ofstream &output, double number) {
    output << std::setw(50) << std::fixed << std::showpos << std::setprecision(5) << number << '\n';
}
 
void readWholeFile(std::ifstream &input, std::ofstream &output) {
    //input.eof()== end of file
    while (!input.eof()) {
        double number = read(input);
        write(output, number);
    }
}
 
int main() {
 
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        return 1;
    }
 
    std::ofstream output("output.txt");
    if (!output.is_open()) {
        return 1;
    }
 
    readWholeFile(input, output);
 
    input.close();
    output.close();
}