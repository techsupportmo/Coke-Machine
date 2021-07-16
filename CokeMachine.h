//Mohammed Ahmed 1001655176

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifndef COKE_MACHINE_H
#define COKE_MACHINE_H

enum ACTION {OK, NOINVENTORY, NOCHANGE, INSUFFICIENTFUNDS, EXACTCHANGE, BOXFULL};

//CokeMachine class
class CokeMachine
{
        
    //Friend function to display machine info
    
    //ostream& operator<<(ostream& output, const PhoneNumber& number)
    
    friend std::ostream& operator<<(std::ostream& output, const CokeMachine& CokeMachine);
        
        
    public:

        //Constructor (with default parameters)
        CokeMachine(std::string name = "New Machine", int cost = 50, int change = 500, int inventory = 100);

        //GetMachineName()
        std::string GetMachineName();

        //buyACoke()
        bool buyACoke(int payment, std::string &change, int &action );

        //getInventoryLevel()
        int getInventoryLevel();

        //getMaxInventoryCapacity()
        int getMaxInventoryCapacity();

        //incrementInventory()
        bool incrementInventory(int amountToAdd);

        //getChangeLevel()
        std::string getChangeLevel() const ;

        //incrementChangeLevel()
        bool incrementChangeLevel(int amountToAdd);

        //getMaxChangeCapacity()
        std::string getMaxChangeCapacity() const ;

        //getCokePrice()
        std::string getCokePrice() const ;

        //displayMoney() - passes int, returns string with money displayed correctly
        std::string displayMoney(int amount) const;
        
        //setMachineName() - Update Machine Name
        void setMachineName(std::string newMachineName);
        
        //setCokePrice() - Update Coke Price
        void setCokePrice(int newCokePrice);
        
        
        

        
    private:
        std::string MachineName;
        int changeLevel;
        int maxChangeCapacity = 5000;
        int CokePrice;
        int inventoryLevel;
        int maxInventoryCapacity = 100;
        


        
};




#endif


