
#include<iostream>
#include<vector>
using namespace std;

class Product
{
    public:
    string name;
    double price;

    Product(string name,double price)
    {
        this->name = name;
        this->price = price;
    }
};

class shoppingCart 
{
    private:
    vector<Product*>products;

    public:

    void addProducts(Product* P)
    {
        products.push_back(P);
    }

    const vector<Product*> &getProduct ()
    {
        return products;
    }

    double calcuteTotal ()
    {
        double total = 0;
        for(auto &p : products)
        total += p->price;

        return total;
    }
};

class PrintInvoice
{
    private:
    shoppingCart* cart;

    public:
    PrintInvoice(shoppingCart* cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {
        for(auto &p : cart->getProduct())
        cout<<p->name<<" - "<<p->price<<endl;

        cout<<"Total Price of the cart is: "<<cart->calcuteTotal()<<endl;
    }
};

class SavingToDB
{
    private:
    shoppingCart* cart;

    public:
    SavingToDB(shoppingCart* cart)
    {
        this->cart = cart;
    }

    void SaveToDB()
    {
        cout<<"Saving to the database...."<<endl;
    }
};

int main ()
{
    shoppingCart* cart = new shoppingCart();

    cart->addProducts(new Product("Iphone 15",65000));
    cart->addProducts(new Product("JBL Speaker",2800));

    PrintInvoice* invoice = new PrintInvoice(cart);
    invoice->printInvoice();

    SavingToDB* db = new SavingToDB(cart);
    db->SaveToDB();
}

