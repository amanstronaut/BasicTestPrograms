#include<iostream>
#include<vector>
#include<string>

class Vehicle
{
    private:
        std::string brand;
        std::string model;
        int year;
    public:
        Vehicle(const std::string& b, const std::string& m, int y):
            brand(b), model(m), year(y){}
        virtual int calculateCost() = 0;
        virtual void displayInfo() const
        {
            std::cout<<"Brand: "<<brand<<"\nModel:"<<model<<std::endl;
        }
};

class Car : public Vehicle
{
    private:
        bool isElectric;
        int numDoors;
    public:
        Car(const std::string& b, const std::string& m, int y, bool elec, int door):
            Vehicle(b, m, y), isElectric(elec), numDoors(door){}
        int calculateCost() override
        {
            return (isElectric ? 30000:25000);
        }
        void displayInfo() const override
        {
            Vehicle::displayInfo();
            std::cout<<"Electric: "<<(isElectric?"Yes":"No")<<"\nDoors:"<<numDoors<<std::endl;
        }
};

class Motorcycle : public Vehicle
{
    private:
        std::string type;
        int cc;
    public:
        Motorcycle(const std::string& b, const std::string& m, int y, const std::string& t, int c):
            Vehicle(b, m, y), type(t), cc(c){}
        int calculateCost() override
        {
            return 20000;
        }
        void displayInfo() const override
        {
            Vehicle::displayInfo();
            std::cout<<"Type: "<<type<<"\nCC: "<<cc<<std::endl;
        }
};

class Dealership
{
    private:
        std::string dealerName;
        std::vector <Vehicle*> inventory;
    public:
        Dealership(const std::string& dealer):
            dealerName(dealer){}
        void addVehicle(Vehicle *vehicle)
        {
            inventory.push_back(vehicle);
        }
        void displayInventory()
        {
            std::cout<<"Dealership name: "<<dealerName<<std::endl;
            for(auto trans:inventory)
            {
                std::cout<<"-------------"<<std::endl;
                trans->displayInfo();
            }
        }
};

