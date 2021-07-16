//Mohammed Ahmed
//1001655176
//Coding Assignment 4


#include "CokeMachine.h"

using namespace std;

ostream& operator<<(ostream& output, const CokeMachine& MyCokeMachine)
{
    //output << "\n\n\n--------------------NEW OUTPUT------------------\n";
    
    //int change = MyCokeMachine.getChangeLevel();

    //old code -----
    
    output << "\n\n" << endl;//space
    
    //Current Inventory Level
    output << "Current Inventory Level: ";
    output << MyCokeMachine.inventoryLevel << endl;
    
    //Max Inventory Capacity
    output << "\nMax Inventory Capacity: ";
    output << MyCokeMachine.maxInventoryCapacity << endl;
    
    output << "\n\n" << endl;//space
    
    //Current Change Level
    output << "Current Change Level: ";
    output << MyCokeMachine.getChangeLevel() << endl;
    //output << MyCokeMachine.changeLevel << endl;
    
    //Max Change Capacity
    output << "\nMax Change Capacity: ";
    output << MyCokeMachine.getMaxChangeCapacity() << endl;
    //output << MyCokeMachine.maxChangeCapacity << endl;
    
    output << "\n\n" << endl;//space
    
    //Current Coke Price
    output << "Current Coke Price is: ";
    //output << MyCokeMachine.CokePrice << endl;
    output << MyCokeMachine.getCokePrice() << endl;
    
    //---------------
    
    return output;
}



int main(int argc, const char * argv[])
{
    
    int choice;
    bool outcome = false;
    int payment;
    string change;
    int action;
    
    string newMachineName;
    int newCokePrice;
    
    int product;
    bool restockStatus = false;
    
    int changeInput;
    bool changeStatus = false;
    
    

    
    //initalize Coke Machine
    CokeMachine MyCokeMachine{"CSE 1325 Coke Machine", 50, 500, 100};
    
    //initialize Coke Machine with Default Parameters
    //CokeMachine MyCokeMachine{};
    
    

    
    do
    {
        //print the name of machine
        cout << "\n\n\n\n";
        cout << MyCokeMachine.GetMachineName() << endl;
        cout << "\n\n";
        
        
        
        //DISPLAYS MENU
        cout << "0. Walk Away" << endl;
        cout << "1. Buy a Coke" << endl;
        cout << "2. Restock Machine" << endl;
        cout << "3. Add Change" << endl;
        cout << "4. Display Machine Info" << endl;
        cout << "5. Update Machine Name" << endl;
        cout << "6. Update Coke Price" << endl;
        
        //user inputs choice
        cout <<"\nChoice: ";
        cin >> choice;
        
        //checks for wrong input
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "incorrect input. Please enter a number from 0 - 4" << endl;
            cin >> choice;
        }
        
        //switch statement for options
        switch (choice)
        {
            //0 - Walk away
            case 0:
                cout << "\nAre you sure you aren't really THIRSTY and need a Coke?\n" << endl;
                break;
                
            //1 - Buy a coke
            case 1:
                cout << "\n\n" << endl;
                
                //prompt for payment
                cout << "Insert Payment: ";
                cin >> payment;
                
                //checks for wrong input
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout << "\nincorrect input. Please enter a numeric value" << endl;
                    cin >> payment;
                }
                
                //buy the coke and change inventory/change
                outcome = MyCokeMachine.buyACoke(payment, change, action);
                
                //output result based on buyACoke()
                if(outcome)
                {
                    
                    //exact change
                    if(action == ACTION::EXACTCHANGE)
                    {
                        cout << "\nThank you for exact change\n" << endl;
                        cout << "Here's your Coke\n\n" << endl;
                    }
                    else if(action == ACTION::OK)//bought coke and needs change
                    {
                        cout << "\n\nHere's your Coke and your change of " << change << endl;
                    }
                    else
                    {
                        cout << "\nSomething unknown occured\n" << endl;
                    }
                    
                    
                }
                else
                {
                    //cout << "\nIt didn't work :( unable to buy a coke\n" << endl;
                    
                    //no inventory
                    if(action == ACTION::NOINVENTORY)
                    {
                        cout << "\nNo more Cokes available...sorry :(" << endl;
                    }
                    else if(action == ACTION::NOCHANGE) //no change
                    {

                        
                        cout << "\nUnable to give change at this time...returning your payment\n" << endl;
                    }
                    else if(action == ACTION::INSUFFICIENTFUNDS) //insufficient funds
                    {
                        cout << "\nInsufficent payment...returning your payment\n" << endl;
                    }
                    else if(action == ACTION::BOXFULL)
                    {
                        cout << "\nChange box is full - call 1800IMFULL to get change removed...\n" << endl;
                    }
                    else
                    {
                        cout << "\nSomething unknown occured\n" << endl;
                    }
                    
                }
            

                
                
                
                break;
                
            //2 - Restock Machine
            case 2:
                cout << "\n\n" << endl;
                
                //prompt for input
                cout << "How much product are you adding to the machine:  ";
                cin >> product;
                
                //checks for wrong input
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout << "\nincorrect input. Please enter a numeric value" << endl;
                    cin >> product;
                }
                
                
                //adds product to inventory
                restockStatus = MyCokeMachine.incrementInventory(product);
                
                //checks if restock was successful
                if(restockStatus)
                {
        
                    cout << "\n\nYour machine has been restocked.\n" << endl;
                    
                    //prints inventory level
                    cout << "\nYour inventory level is now " << MyCokeMachine.getInventoryLevel() << endl;
                    
                }
                else
                {
                    cout << "\n\nYou have exceeded your machine's max capacity\n" << endl;
                    
                    //prints inventory level
                    cout << "\nYour inventory level is now " << MyCokeMachine.getInventoryLevel() << endl;
                    
                }
                
                
                
                break;
                
            //3 - Add change
            case 3:
                cout << "\n\n" << endl;
                
                //prompt for input
                cout << "How much change are you adding to the machine?  ";
                cin >> changeInput;
                
                //checks for wrong input
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout << "\nincorrect input. Please enter a numeric value" << endl;
                    cin >> changeInput;
                }
                
                
                //adds change to changeLevel
                changeStatus = MyCokeMachine.incrementChangeLevel(changeInput);
                
                //checks if adding change was successfull
                if(changeStatus)
                {
                    cout << "\n\nYour change has been updated\n" << endl;
                    
                    //prints current change level
                    cout << "Your change level is now " << MyCokeMachine.getChangeLevel() << endl;
                }
                else
                {
                    cout << "\n\nYou have exceeded your machine's max change capacity\n" << endl;
                    
                    //prints current change level
                    cout << "Your change level is now " << MyCokeMachine.getChangeLevel() << endl;
                }
                
                
                break;
                
            //4 - Display Machine Info
            case 4:

                
                //Display Machine Info
                cout << MyCokeMachine;
                
                break;
                
                
            //5 - Update Machine Name
            case 5:
                
                //prompt user
                cout << "Enter a new machine name:  ";
                cin >> newMachineName;
                //getline(cin, newMachineName);
                
                //set the new machine name
                MyCokeMachine.setMachineName(newMachineName);
                
                //print message
                cout << "Machine name has been updated" << endl;
                
                
                break;
            
            //5 - Update Coke Price
            case 6:
                cout << "\nupdate coke price selected\n" << endl;
                
                //prompt user
                cout << "Enter a new Coke price" << endl;
                cin >> newCokePrice;
                
                //set the new coke price
                MyCokeMachine.setCokePrice(newCokePrice);
                
                //print message
                cout << "Coke price has been updated" << endl;
                
                break;
                
                
             
            //any other input
            default:
                cout << "\nincorrect input entered. Please try again.\n";
                break;
        }
        
    }
    while(choice != 0);//loops until user chooses to exit
    
    
    
    return 0;
}

