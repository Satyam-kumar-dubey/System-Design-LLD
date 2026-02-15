

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

class SavingInDB

{
    private:
    shoppingCart* cart;

    public:

    virtual void save (shoppingCart* cart) = 0;
};

class SavingToMongo : public SavingInDB
{
    public:
    void save (shoppingCart* cart) override
    {
        cout<<"Saving to MongoDB..."<<endl;
    }
};
class SavingToSQL : public SavingInDB
{
    public:
    void save (shoppingCart* cart) override
    {
        cout<<"Saving to SQL..."<<endl;
    }
};
class SavingToFile : public SavingInDB
{
    public:
    void save (shoppingCart* cart) override
    {
        cout<<"Saving to File..."<<endl;
    }
};

int main ()
{
    shoppingCart* cart = new shoppingCart();

    cart->addProducts(new Product("Iphone 15",65000));
    cart->addProducts(new Product("JBL Speaker",2800));

    PrintInvoice* invoice = new PrintInvoice(cart);
    invoice->printInvoice();

    SavingToMongo* mongo = new SavingToMongo();
    SavingToSQL* SQL = new SavingToSQL();
    SavingToFile* file = new SavingToFile();

    mongo->save(cart);
    SQL->save(cart);
    file->save(cart);
    
}

