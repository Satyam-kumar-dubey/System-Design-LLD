
#include<iostream>
#include<vector>
using namespace std;

class Product
{
    public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart 
{
    private:
    vector<Product*>products;

    public:

    // add the products in the product vector
    void addProduct (Product* P)
    {
        products.push_back(P);
    }

    // Calculate the total of the cart values
    double calculateTotal ()
    {
        double total = 0;
        for(auto &p : products)
        total += p->price;

        return total;
    }

    // It will print the invoice of the cart along with the total price
    void PrintInvoice ()
    {
        for(auto &p : products)
        {
            cout<<p->name<<" "<<p->price<<endl;
        }
        cout<<"Total Price : "<<calculateTotal()<<endl;
    }

    // It will save the information in the database
    void saveToDB ()
    {
        cout<<"Saving data in the database.... "<<endl;
    }
};

int main ()
{
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Iphone 15",65000));
    cart->addProduct(new Product("JBL tune",2800));

    cart->PrintInvoice();
    cart->calculateTotal();
    cart->saveToDB();
}

