//Mohammed Ahmed
//1001655176

#include "CokeMachine.h"

//Constructor
CokeMachine::CokeMachine(std::string name, int cost, int change, int inventory)
{
    //sets machine name
    MachineName = name;

    //price of a single coke
    CokePrice = cost;

    //The amount of change in the machine
    changeLevel = change;

    //The number of items (inventory level) in the machine
    inventoryLevel = inventory;

}

//GetMachineName()
std::string CokeMachine::GetMachineName()
{
    //returns name of machine
    return MachineName;
}

//buyACoke()
bool CokeMachine::buyACoke(int payment, std::string &change, int &action )
{
    bool result = false;

    //checks if inventory is empty
    if(inventoryLevel <= 0)
    {
        
        action = ACTION::NOINVENTORY;
        result = false;
        
    }
    else if(payment - CokePrice == 0) //paying with exact change
    {
        //purchase pencil
        result = true;
        inventoryLevel--; //reduced inventory by one (buying one coke)
        changeLevel += CokePrice; //adds amount paid to change level
        action = ACTION::EXACTCHANGE;
        
    }
    else if(payment - CokePrice > 0) //if change is needed
    {
        
        //reduces amount of change
        //changeLevel = changeLevel - (payment - CokePrice);
        
        //checks if not enough change, OR changebox is full
        if(changeLevel < 0 || changeLevel >= maxChangeCapacity)
        {
            
            //checks if changebox is full
            if(changeLevel >= maxChangeCapacity)
            {
                action = ACTION::BOXFULL;
            }
            else
            {
                action = ACTION::NOCHANGE;
            }

            
            changeLevel = changeLevel + CokePrice;//adds back change
            result = false;
            
            
        }
        else
        {
            //purchase pencil
            result = true;
            inventoryLevel--; //reduced inventory by one (buying one coke)
            changeLevel += CokePrice; //adds amount paid to change level
            action = ACTION::OK;
            
            //output change
            change = displayMoney(payment - CokePrice);
            
        }
        
        
    }
    
    
    //if user pays with insufficient funds
    if(payment < CokePrice)
    {
        result = false;
        action = ACTION::INSUFFICIENTFUNDS;
    }
    

    
    return result;
}

//getInventoryLevel()
int CokeMachine::getInventoryLevel()
{
    return inventoryLevel;
}

//getMaxInventoryCapacity()
int CokeMachine::getMaxInventoryCapacity()
{
    return maxInventoryCapacity;
}

//incrementInventory()
bool CokeMachine::incrementInventory(int amountToAdd)
{

    int newAmount = inventoryLevel + amountToAdd;
    bool outcome = false;
    
    //if the new amount exceeds max inventory capacity
    if(newAmount > maxInventoryCapacity)
    {
        outcome = false;
    }
    else if (amountToAdd < 0)
    {
        outcome = false;
    }
    else
    {
        outcome = true;
        
        //adds amount to inventory level
        inventoryLevel = newAmount;
    }
    
    
    
    return outcome;


}


//getChangeLevel()
std::string CokeMachine::getChangeLevel() const 
{
    return displayMoney(changeLevel);;
}

//incrementChangeLevel()
bool CokeMachine::incrementChangeLevel(int amountToAdd)
{
    int newAmount = changeLevel + amountToAdd;
    bool outcome = false;
    
    //if the new amount exceeds max inventory capacity
    if(newAmount > maxChangeCapacity)
    {
        outcome = false;
    }
    else if (amountToAdd < 0)
    {
        outcome = false;
    }
    else
    {
        outcome = true;
        
        //adds amount to inventory level
        changeLevel = newAmount;
    }
    
    
    
    return outcome;
}


//getMaxChangeCapacity()
std::string CokeMachine::getMaxChangeCapacity() const
{
    //returns maxChangeCapacity as a formatted string
    return displayMoney(maxChangeCapacity);
}

//getCokePrice()
std::string CokeMachine::getCokePrice() const
{
    //returns CokePrice as a formatted string
    return displayMoney(CokePrice);
}

//displayMoney() - passes in int and returns string with money displayed correctly
std::string CokeMachine::displayMoney(int amount) const
{
    //dollars
    std::string dollars{std::to_string(amount/100)};
    
    //cents
    std::string cents{std::to_string(amount%100)};
    
    //output
    std::string output{"$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents};
    
    
    
    return output;
}



//setMachineName() - Update Machine Name
void CokeMachine::setMachineName(std::string newMachineName)
{
    
    //sets the new machine name
    MachineName = newMachineName;

    
}

//setCokePrice() - Update Coke Price
void CokeMachine::setCokePrice(int newCokePrice)
{
    //sets the new coke price
    CokePrice = newCokePrice;
}

