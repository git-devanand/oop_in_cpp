#include<iostream>

using namespace std;

class Employee {
    
public:
    string Name;
    string Company;
    int Age;

    void IntroduceYourself() {
        cout << "My name is " << Name << " and I work at " << Company << "." << endl;
        cout << "I am " << Age << " years old." << endl;
    }

    //Constuctor
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

};

int main()
{
    int number;
    Employee employee1 = Employee("Devanand Yadav", "Google", 22);
    /*employee1.Name = "Devanand";
    employee1.Company = "Google";
    employee1.Age = 24;
    */
    employee1.IntroduceYourself();

    Employee employee2 = Employee("Sachin", "Futures First", 21);
    /*employee2.Name = "John";
    employee2.Company = "Apple";
    employee2.Age = 32;
    */
    employee2.IntroduceYourself();
}