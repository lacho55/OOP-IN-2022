const int NAME_SIZE = 128;
const int DESCRIPTION_SIZE = 512;

enum Season {
    Winter,
    Spring,
    Summer,
    Autumn
};

enum Brand {
    VW, 
    Audi,
    BMW,
    Mercedes,
    Seat
};

enum Engine {
    V8,
    V10,
    V12
};

enum Fuel {
    Gasoline,
    Diesel,
    LPG
};

struct Car {
    int km;
    double avgFuelBurn;
    char name[NAME_SIZE], description[DESCRIPTION_SIZE];
    Brand brand;
    Engine engine;
    Fuel fuel;

    void enterCar() {
        cout << "Enter car:";
        cin.ignore();
        cout << "Enter name:";
        cin.getline(name, NAME_SIZE);
        cout << "Enter description";
        cin.getline(description, DESCRIPTION_SIZE);
        cout << "Enter km:";
        cin >> km; cout << endl;
        cout << "Enter average fuel burn";
        cin >> avgFuelBurn; cout << endl;
    }

    // конструктор с параметри
    Car(int _km, double _avgFuelBurn, const char* _name = "Volvo", const char* _description = "The best car") {
        km = _km;
        avgFuelBurn = _avgFuelBurn;
    }

    void getFuel() {
        switch(fuel) {
            case Gasoline: {
                cout << "Na benzin sme" << endl;
                break;
            } 
            case Diesel: {
                cout << "Na dizel sme" << endl;
                break;
            }
            case LPG: {
                cout << "Na gaz sme" << endl;
                break;
            }
        }
    }
};

int main() {

    Season s = Winter;
    cout << s << endl;

    Car* myCar = new Car(120, 7.8);
    
    Car myCar1(150, 7.8);
    Car myCar2(99, 7.8);
    Car myCar3(200, 7.8);
}