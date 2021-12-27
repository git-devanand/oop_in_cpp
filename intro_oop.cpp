#include<iostream>
using namespace std;

class Employee {

    // public class attibute which can be accessible publicly.
    public:
        // class attributes
        string Name;
        string Company;
        int Age;

    // Methods of this class
     void IntroduceYourself() {
         cout << "Name - " << Name << "\n";
         cout << "Company - " << Company << "\n";
         cout << "Age - " << Age << "\n";
        
             }

             // Consturctor is a method/function which have not any return type
             // constructor has the same name as the class name belongs to
             // Almost always constructors should be use as public

    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;

             }
};

int main()
{
    Employee employee1 = Employee("Devanand", "NASA", 20);
    //employee1.Name = "Devanand";
    //employee1.Company = "DevQubit";
    //employee1.Age = 20;
    employee1.IntroduceYourself();

    Employee employee2 = Employee("Davendra", "Google", 25);
    //employee2.Name = "David";
    //employee2.Company = "Google";
    //employee2.Age = 25;
    employee2.IntroduceYourself();

    Employee employee3 = Employee("Albert", "IBM", 32);
    employee3.IntroduceYourself();
    

}