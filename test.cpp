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

    // Copy Constructor 
    Car (const Car &other) {
        cout << "Copy Constructor called!\n";
        this->make = other.make;
        this->model = other.model;
        this->year = other.year;
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

int main()
{
    Car car1;
    // Car * car2 = Car ("BMW", "XM40"); // Dynamically declaration of object with new keyword
    Car car2 = Car ("Mercedes", "AMG COPE", 2023);
    car1.summary();
    car2.summary();
    Car car3 = Car(car2);
    car3.setModel("GLS MAYBAG");
    car3.summary();


    // cout << sizeof(car1)<<"\n";




    // cout << "Size of INT: " << sizeof (int) << " byte\n";
    // cout << "Size of LONG LONG: " << sizeof (long long) << " byte\n";
    // cout << "Size of CHAR: " << sizeof (char) << " byte\n";
    // cout << "Size of BOOL: " << sizeof (bool) << " byte\n";
    // cout << "Size of DOUBLE: " << sizeof (double) << " byte\n";
    // cout << "Size of FLOAT: " << sizeof (float) << " byte\n";
    // cout << "Size of STRING: " << sizeof (string) << " byte\n";
}





// Size of INT: 4 byte
// Size of LONG LONG: 8 byte
// Size of CHAR: 1 byte
// Size of BOOL: 1 byte
// Size of DOUBLE: 8 byte
// Size of FLOAT: 4 byte
// Size of STRING: 24 byte