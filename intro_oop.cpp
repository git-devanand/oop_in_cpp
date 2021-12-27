#include<iostream>
using namespace std;

// Abstraction principal in OOP
class AbstractEmployee {
    virtual void AskForPromotion()=0;

};

class Employee:AbstractEmployee {
    // private access modifier which are only accessible only within the class
    private:
        //Incapsulation principal in OOP
        // Incapsulaiton of class attributes
        // string Name;
        string Company;
        int Age;

    protected:  // protected modifieres
        string Name;

    // public access modefier which can be accessible publicly.
    public:
        void setName(string name) {// setter
            Name = name;
        }

        string getName() {// getter
            return Name;
        }

        void setCompany(string company)
        { // setter
            Company = company;
        }

        string getCompany()
        { // getter
            return Company;
        }

        void setAge(int age)
        { // setter
            if (age >= 18)
                Age = age;
        }

        int getAge()
        { // getter
            return Age;
        }

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
    void AskForPromotion() {
        if(Age > 30)
            cout << Name << " got promoted." << "\n";
        else
            cout << Name << ", sorry NO promotion for you!" <<"\n";

    }

    virtual void Work() {
        cout <<Name<<" is checking email, task backlog, performing tasks..."<<"\n";
    }
};

// Inheritance principal
class Developer:public Employee {// here inherietance is private by default
    public:
        string FavProgrammingLanguage;
        Developer(string name, string company, int age, string favProgrammingLanguage)
            :Employee(name, company, age)
        {
            FavProgrammingLanguage = favProgrammingLanguage;
        }

        void FixBug() {
            cout << Name<<" fixed bug using "<<FavProgrammingLanguage<<"\n";
        }

        void Work()
        {
            cout << Name << " is checking bug, and writting code in "<<FavProgrammingLanguage
                 << "\n";
        }
};

class Teacher:public Employee {
public:
    string Subject;
    void PrepareLesson(){
        cout << Name << " is preparing "<<Subject<<" lesson"<<"\n";
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
        {
            Subject = subject;
        }

        void Work()
        {
            cout << Name << " is teaching "<<Subject
                 << "\n";
        }
};

int main()
    //The most common use of Polymorphism is when 
    // a parent class reference is used to refer to a child class object

{
    /*
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

    employee1.setAge(12);
    cout << employee1.getName() <<" is "<<employee1.getAge()<< " years old."<<"\n";

    employee2.setCompany("Microsoft");
    cout << employee2.getName() << " join to new company named "<<employee2.getCompany()<<"\n";

    employee1.AskForPromotion();
    employee3.AskForPromotion();
    */

    Developer d=Developer("Devanand","NASA", 20, "Python" );
    //d.FixBug();
    //d.AskForPromotion();
    //d.Work();

    Teacher t=Teacher("Linus Torvalds", "LinuxFoundation", 36, "Linux");
    //t.PrepareLesson();
    //t.AskForPromotion();
    //t.Work();

    Employee employee1 = Employee("John", "Apple", 28);
    //employee1.AskForPromotion();
    //employee1.Work();

    Employee* e1 = &d;
    Employee* e2 = &t;
    Employee* e3 = &employee1;

    e1->Work();
    e2->Work();
    e3->Work();



}