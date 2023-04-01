#include<iostream>
using namespace std;

class Car {
    private:
    string make;
    string model;
    

    public:
    int year;
    string getMake() {
        return make;
    }
    void setMake(string _make) {
        make = _make;
    }
    string getModel() {
        return model;
    }
    void setModel(string _model) {
        model = _model;
    }

    // Default Constructor
    Car () {
        cout << "Default Constructor called!\n";
        make = "TATA";
        model = "Safari";
        year = 2023;
    }

    // Parameterized Constructor 
    Car (string make, string model) {
        cout << "Parameterized Constructor1 called!\n";
        this->make = make;
        this->model = model;
    }

    Car (string make, string model, int year) {
        cout << "Parameterized Constructor1 called!\n";
        this->make = make;
        this->model = model;
        this->year = year;
    }

    void engineStart() {
        cout << "Car Engine started...\n";
    }

    void engineStart(string typesound) {
        cout << "Car Engine started with sound..." << typesound <<"...\n";
    }


    void summary () {
        cout << "Parameterized Constructor2 called!\n";
        cout << "Manufacturer: " << make << "\n";
        cout << "Model: " << model << "\n";
        cout << "Year: " << year <<"\n";
    }

    ~Car() {
        cout << "Destructor called!\n";
    }
};

class Audi : public Car {
    public:
    void engineStart() {
        cout << "Audi Engine started...\n";
    }
};

class QSpostback : public Audi{
    public:
    void engineStart() {
        cout << "Q Sportback Engine started...\n";
    }
};


int main()
{
    Audi c1 = Audi();
    c1.engineStart();
    QSpostback c2 = QSpostback();
    c2.engineStart();
}