#include<iostream>
#include<string.h>
using namespace std;

class DeepCopyExample {
public:
    DeepCopyExample(int* pData) {
        m_pData = new int[1];
        *m_pData = *pData;
    }
    // Deep Copy Constructor
    DeepCopyExample(const DeepCopyExample& other) {
        m_pData = new int[1];
        *m_pData = *(other.m_pData);
    }
    // Destructor
    ~DeepCopyExample() {
        delete[] m_pData;
    }
private:
    int* m_pData;
};

class Car {
public:
    Car(const char* brand, int year) {
        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);
        m_year = year;
    }
    
    // Shallow copy constructor
    Car(const Car& other) {
        m_brand = other.m_brand;
        m_year = other.m_year;
    }
    
    // Deep copy constructor
    Car(const Car& other) {
        m_brand = new char[strlen(other.m_brand) + 1];
        strcpy(m_brand, other.m_brand);
        m_year = other.m_year;
    }
    
    // Destructor
    ~Car() {
        delete[] m_brand;
    }
    
    // Getter methods
    const char* getBrand() const { return m_brand; }
    int getYear() const { return m_year; }
    
private:
    char* m_brand;
    int m_year;
};

int main() {
    Car car1("Toyota", 2022);
    
    // Create a shallow copy of car1
    Car car2 = car1;
    
    // Modify the brand name of car1
    car1.setBrand("Honda");
    
    // Print the brand names of both cars
    std::cout << car1.getBrand() << " " << car1.getYear() << std::endl;  // Output: "Honda 2022"
    std::cout << car2.getBrand() << " " << car2.getYear() << std::endl;  // Output: "Honda 2022" (due to shallow copy)
    
    // Create a deep copy of car1
    Car car3(car1);
    
    // Modify the brand name of car1 again
    car1.setBrand("Tesla");
    
    // Print the brand names of all three cars
    std::cout << car1.getBrand() << " " << car1.getYear() << std::endl;  // Output: "Tesla 2022"
    std::cout << car2.getBrand() << " " << car2.getYear() << std::endl;  // Output: "Tesla 2022" (due to shallow copy)
    std::cout << car3.getBrand() << " " << car3.getYear() << std::endl;  // Output: "Honda 2022" (due to deep copy)
    
    return 0;
}
