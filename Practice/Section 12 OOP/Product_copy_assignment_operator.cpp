#include <iostream>
#include <cstring>
using namespace std;

class Product
{
private:
    int id;
    char *name;
    int mrp;
    int selling_price;

public:
    // Constructor
    Product()
    {
        cout << "Inside constructor" << endl;
    }
    Product(int id, char *n, int mrp, int selling_price)
    {
        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;
        this->name = new char[strlen(n) + 1];
        // Due to shallow copy/ deep copy
        strcpy(name, n);
    }
    /*
        we have a default copy constructor provided by cpp compiler
        we can override it's implementation and for that we need the param to be passed as reference/address
        bcoz to copy the args(passes at the time of function call) to params(received values at function def) will
        be copied iff we have a copy constructor, so to overcome this we abide to pass the param as pass by ref.
    */
    Product(Product &X)
    {
        // cout << "\nCopying all values" << endl;
        this->id = X.getId();
        this->selling_price = X.getSellingPrice();
        this->mrp = X.getMRP();
        this->name = new char[strlen(X.getName()) + 1];
        // Due to shallow copy/ deep copy
        strcpy(this->name, X.getName());
        // cout << "Copied all values\n"
        //      << endl;
    }

    // we have to define our own/override copy assignment operator
    void operator=(Product &X)
    {
        cout << "Inside copy assignment operator" << endl;
        this->id = X.getId();
        this->selling_price = X.getSellingPrice();
        this->mrp = X.getMRP();
        this->name = new char[strlen(X.getName()) + 1];
        // Due to shallow copy/ deep copy
        strcpy(this->name, X.getName());
    }

    int getMRP()
    {
        return mrp;
    }
    void setMRP(int price)
    {
        mrp = price;
    }
    int getSellingPrice()
    {
        return selling_price;
    }
    void setSellingPrice(int price)
    {
        if (price > mrp)
        {
            selling_price = mrp;
        }
        else
        {
            selling_price = price;
        }
    }
    int getId()
    {
        return this->id;
    }
    void setId(int id)
    {
        this->id = id;
    }
    char *getName()
    {
        return this->name;
    }
    void setName(char *name)
    {
        strcpy(this->name, name);
    }
    void showDetails()
    {
        cout << "-----------------------" << endl;
        cout << "MRP: " << this->mrp << endl;
        cout << "Selling Price: " << this->selling_price << endl;
        cout << "Name: " << this->name << endl;
        cout << "Id: " << this->id << endl;
    }
};

int main()
{

    Product camera(101, "GoProHero8", 28000, 26000);

    Product old_cam; // copy constructor is called

    old_cam = camera; // copy assignment operator will be called

    old_cam.setName("Hero2");

    camera.showDetails();
    old_cam.showDetails();

    return 0;
}