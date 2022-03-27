#include <iostream>
using namespace std;

class Product
{
private:
    int id;
    char name[100];
    int mrp;
    int selling_price;

public:
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
};

int main()
{

    Product camera;
    camera.setMRP(100);
    camera.setSellingPrice(200);
    cout << sizeof(camera) << endl;
    cout << "MRP: " << camera.getMRP() << endl;
    cout << "Selling Price: " << camera.getSellingPrice() << endl;

    return 0;
}