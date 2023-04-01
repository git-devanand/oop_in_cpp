#include<iostream>
using namespace std;

class Dev{
private:
    string gf;
	friend class P;
protected:
    string response;
public:
    Dev(){
        gf = "Sonali Verma";
        response = "Loves";
    }
    
};

class P{
public:
    void secretinfo(Dev& d){
        cout<<"Name of Girlfriend is "<<d.gf<<".\n";
        cout<<"She "<<d.response<<" Dev.\n";
    }
};

// C++ Program to demonstrate the
// fucntioning of a friend class
#include <iostream>
using namespace std;

class GFG {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	GFG()
	{
		private_variable = 10;
		protected_variable = 99;
	}

	// friend class declaration
	friend class F;
};

// Here, class F is declared as a
// friend inside class GFG. Therefore,
// F is a friend of class GFG. Class F
// can access the private members of
// class GFG.
class F {
public:
	void display(GFG& t)
	{
		cout << "The value of Private Variable = "
			<< t.private_variable << endl;
		cout << "The value of Protected Variable = "
			<< t.protected_variable<<"\n";
	}
};

// Driver Code
int main()
{
    GFG g;
	F fri;
	fri.display(g);
    Dev d;
    P p;
    p.secretinfo(d);

    return 0;
}
