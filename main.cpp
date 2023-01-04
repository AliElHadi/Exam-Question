#include<iostream>
#include<vector>
using namespace std;

class customer{
    private:
        int id=0;//must be set to the vector index so that it would be easily accessed
        string name="";
        int powerConsumption=0;//presents the KW used
        int powerGeneratorID=0;
        double amountDue=0;
    public:
        customer(int Id, string Name,int GID){id=Id;name=Name;powerGeneratorID=GID;}
        void setConsumption(){
            int c;
            cout<<"Enter the Consumption Ammount:";
            cin>>c;
            powerConsumption = c;
        }
        void getAmountDue(){
            double a;
            cout<<"Enter the price of the KW:";
            cin>>a;
            amountDue = amountDue + a*powerConsumption;
            cout<<"Ammount due is:"<<amountDue;
            powerConsumption=0;//since the amount due for this consumption has been added we remove the consumptions registered
        }
        void payAccount(){
            double a;
            cout<<"Enter the amount paid:";
            cin>>a;
            if(a>0){
                amountDue -= a;
            }
        }
        int getId(){return id;}
        string getName(){return name;}
        int getPowerConsumption(){return powerConsumption;}
        int getPowerGeneratorID(){return powerGeneratorID;}
        double getAmountDue(){return amountDue;}
};
class powerGenerator{
    private:
        int id=0;
        int maximumGeneration=0; //maximum Generation per hour
        int consumedGeneration=0; // consumed generation by currently connected consumers
    public:
        powerGenerator(int ID,int mG){id=ID;maximumGeneration=mG;}
        bool checkIfCanAdded(int generation){
            if(maximumGeneration>=generation+consumedGeneration){
                return true;
            }
            else{return false;}
        }
        void addNewUser(){
            int g;
            cout<<"Please enter the number of generation needed:";
            cin>>g;
            if(checkIfCanAdded(g)){consumedGeneration+=g;}
            else{cerr<<"You cannot add this amount!!";}
        }
        int getId(){return id;}
        int getMaximumGeneration(){return maximumGeneration;}
        int getConsumedGeneration(){return consumedGeneration;}
};

int main(){
    int choice;
    vector<customer> customerVector;
    vector<powerGenerator> generatorsVector;
    cout<<"To exit enter 0"<<endl;
    cout<<"To add a new customer enter 1"<<endl;
    cout<<"To add a new generator enter 2"<<endl;
    cout<<"To add a new customer to a generator enter 3"<<endl;
    cout<<"To set a customer consumption enter 4"<<endl;
    cout<<"To get amount due of customer enter 5"<<endl;
    cout<<"To pay an amount to the account enter 6"<<endl;
    cin>>choice;cout<<endl;
    while(choice!=0){
        if(choice==0){
            exit();
        }
        if(choice==1){
            int id,Gid=0;
            string name;
            cout<<"Please enter the customer Id, Name and Generator Id seperated by enters:"<<endl;
            cin>>id;
            cin>>name;
            cin>>Gid;
            customer c (id,name,Gid);
            //we must check if the generator with the given id has enough power
            customerVector.push_back(c);
        }
        //if choice is equal to 2 we prompt the user to enter the generator id with the maximum generation and add it to the vector
        //if choice is equal to 3 we prompt the user to enter the customer id with the generator id and check if the customer can be added to this generator
        //if choice is equal to 4 we prompt the user to enter the customer id  and consumption and set it
        //if choice is equal to 5 we prompt the user to enter the customer id and print the amount due
        //if choice is equal to 6 we prompt the user to enter the customer id and amount wanted to be paid and pay it
        cout<<"To exit enter 0"<<endl;
        cout<<"To add a new customer enter 1"<<endl;
        cout<<"To add a new generator enter 2"<<endl;
        cout<<"To add a new customer to a generator enter 3"<<endl;
        cout<<"To set a customer consumption enter 4"<<endl;
        cout<<"To get amount due of customer enter 5"<<endl;
        cout<<"To pay an amount to the account enter 6"<<endl;
    }
    return 0;
}
