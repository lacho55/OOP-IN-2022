#include <iostream>
#include <string>
#include <vector>

class Animal {
private:
    bool hasFur;
    bool laysEggs;
protected:
    std::string name;
public:
    void eat() const {}
    virtual void greet() const {
        std::cout << "My name is " << name << ".\n";
    }
    void setName(const std::string & newName) {
        this->name = newName;
    }
    virtual void eat() = 0;
};

class Cat : public Animal {
private:
    int lives;
public:
    void setLives(int newLives) {
        this->lives = newLives;
    }
    void greet() const override {
        Animal::greet();
        std::cout << "I have " << lives << " lives left.\n";
    }
    void eat() override {
        std::cout << "The cat " << this->name << " is eating.\n";  
    }
};

void animalsDemo() {
    // Animal traicho;

    // traicho.setName("Traicho");
    //traicho.greet();

    Cat kitten;
    kitten.setName("Marijka");
    kitten.setLives(9);
    //kitten.greet();
    
    // traicho = kitten;
    Animal * pencho = &kitten;
    pencho->greet();
    // pencho->eat();
}

// ------------------------------------------------------------------













class Employable {
public:
    virtual void work() = 0;
};

class Person : public Employable {
private:
    std::string name;
public:
    const std::string & getName() const {
        return this->name;
    }
    Person& setName(const std::string & newName) {
        this->name = newName;
        return *this;
    }

    void work() {

    }
};

class Dog : public Employable {
    void work() override {

    }
};

class Company {
    std::vector<Employable*> employees;
public:
    Company& addEmployee(Employable * newEmployee) {
        this->employees.push_back(newEmployee);
        return *this;
    }
    void work() {
        for(size_t i = 0; i < employees.size(); i++) {
            this->employees[i]->work();
        }
    }
};

void setNames(std::vector<Person> people) { // Liskov substitution principle: replace Person with Employee and see if it makes sense
    for(size_t i = 0; i < people.size(); i++) {
        people[i].setName("NAME_UNKNOWN");
    }
}

void companyDemo() {
    Person *traicho = new Person(), * pencho = new Person();
    traicho->setName("Traicho");
    pencho->setName("Pencho");
    
    Dog * dog = new Dog();


    Company comp;
    comp.addEmployee(traicho).addEmployee(pencho).addEmployee(dog);
    comp.work();
}

int main() {
    animalsDemo();
    companyDemo();
    return 0;
}