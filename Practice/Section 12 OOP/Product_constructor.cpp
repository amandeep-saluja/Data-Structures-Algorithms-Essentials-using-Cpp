#include <iostream>
#include <cstring>
using namespace std;

class Product
{
private:
    int id;
    char name[100];
    int mrp;
    int selling_price;

public:
    // Constructor
    Product()
    {
        cout << "Inside constructor" << endl;
    }
    Product(int id, char name[], int mrp, int selling_price)
    {
        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;
        // Due to shallow copy/ deep copy
        strcpy(this->name, name);
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
        // Due to shallow copy/ deep copy
        strcpy(this->name, X.getName());
        // cout << "Copied all values\n"
        //      << endl;
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
    char *getName()
    {
        return this->name;
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

    // Product camera;
    // camera.setMRP(100);
    // camera.setSellingPrice(200);
    // cout << sizeof(camera) << endl;
    // cout << "MRP: " << camera.getMRP() << endl;
    // cout << "Selling Price: " << camera.getSellingPrice() << endl;

    Product camera2(101, "GoProHEro2", 28000, 26000);

    Product webCam(camera2); // copy constructor is called

    Product handyCam = camera2; // copy constructor is called

    camera2.showDetails();
    webCam.showDetails();
    handyCam.showDetails();

    return 0;
}