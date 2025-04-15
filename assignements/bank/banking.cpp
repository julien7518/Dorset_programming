#include <iostream>
#include <string>

using namespace std;

#define MAX_ACCOUNT 10

// This class define a bank account
class BankAccount
{
private:
    // We need to stock the account number, the name of the holder, and the ammout
    int uuid;
    string first_name;
    string last_name;
    int ammount;

public:
    // This is the default constructer, used only to initialize default account in the account array.
    BankAccount()
    {
        uuid = -1;
        ammount = -1;
        first_name = "default";
        last_name = "default";
    }

    // This is the constructer we'll use every time after
    BankAccount(int id, int initial_deposit, string f_name, string l_name)
    {
        uuid = id;
        ammount = initial_deposit;
        first_name = f_name;
        last_name = l_name;

        cout << "Account n" << uuid << " created succesfully." << endl;
        currentAmmount();
    }

    // Permit access in read-only mode to uuid outside of the class (used for transfer)
    int getUuid()
    {
        return uuid;
    }

    // Permit access in read-only mode to name outside of the class (used for transfer)
    string getName()
    {
        return first_name + " " + last_name;
    }

    // Used to avoid redundancy when we need to print the balance of the account
    void currentAmmount()
    {
        cout << "Current ammount : " << ammount << "€" << endl;
    }

    void printInfos()
    {
        cout << "Informations of the account" << endl;
        cout << "Account Number : " << getUuid() << endl;
        cout << "Account holder : " << getName() << endl;
        currentAmmount();
    }

    void deposit(int deposit_ammount)
    {
        ammount += deposit_ammount;
        cout << deposit_ammount << " added succesfully." << endl;
        currentAmmount();
    }

    void withdrawal(int withdrawal_deposit)
    {
        // Check if there is enought money on the account
        if (ammount < withdrawal_deposit)
        {
            cout << "Operation impossible, ammount insufficient." << endl;
        }
        else
        {
            ammount -= withdrawal_deposit;
            cout << withdrawal_deposit << " withdrawed." << endl;
            currentAmmount();
        }
    }

    // Method to make a transfer between to account, by veryfing if there is enought money on the first account
    void transfer(BankAccount &other, int transfer_ammount)
    {
        if (ammount < transfer_ammount)
        {
            cout << "Operation impossible, ammount insufficient." << endl;
        }
        else
        {
            ammount -= transfer_ammount;
            other.ammount += transfer_ammount;
            cout << "Tranfer made succesfully." << endl;
            currentAmmount();
            cout << "Account n" << other.getUuid() << " of " << other.getName() << endl;
            other.currentAmmount();
        }
    }
};

/*
This shows the first menu, where you can choose to create an account or choose an other action.
This function also can create accounts in the limit of banking requirements.
*/
void createAccount(int *length, BankAccount **accounts)
{
    int choice;
    do
    {
        cout << "Select action." << endl;
        cout << "1 : Create an account" << endl;
        cout << "2 : Other operations" << endl;
        cin >> choice;
    } while (choice > 2 || choice < 1);

    if (choice == 1)
    {
        if (*length < MAX_ACCOUNT)
        {
            int id, balance;
            string f_name, l_name;
            cout << "Enter an id for your account : ";
            cin >> id;
            cout << "Enter your balance : ";
            cin >> balance;
            cout << "Enter your first name : ";
            cin >> f_name;
            cout << "Enter your last name : ";
            cin >> l_name;
            accounts[*length] = new BankAccount(id, balance, f_name, l_name);
            (*length)++;
            createAccount(length, accounts);
        }
        else
        {
            cout << "The bank does not accept more client for the moment." << endl;
        }
    }
}

// List all accounts in the bank and permit to choose one
BankAccount &chooseAccount(int *number_of_account, BankAccount **accountList)
{
    int account;
    do
    {
        cout << "Choose an account" << endl;
        for (int i = 0; i < *number_of_account; i++)
        {
            cout << (i + 1) << " : Account n" << accountList[i]->getUuid() << endl;
        }
        cin >> account;
    } while (account < 1 || account > *number_of_account);

    return *accountList[account - 1];
}

// Display a menu and permit to choose an action
int chooseAction()
{
    int action;
    do
    {
        cout << "Choose an action" << endl;
        cout << "1 : Make a deposit" << endl;
        cout << "2 : Withdraw money" << endl;
        cout << "3 : Transfer to an other account" << endl;
        cout << "4 : Get account infos" << endl;
    } while (action < 1 || action > 4);
    cin >> action;

    return action;
}

int main()
{
    // Initialize an array of BankAccount
    BankAccount *accounts[MAX_ACCOUNT];
    int accounts_length = 0;

    while (true)
    {
        // Display the first menu
        createAccount(&accounts_length, accounts);
        // Choose an account for future action
        BankAccount &account = chooseAccount(&accounts_length, accounts);
        int action = chooseAction();
        int ammount;
        BankAccount *other = nullptr;

        switch (action)
        {
        case 1:
            cout << "How much do you want to deposit ? ";
            cin >> ammount;
            account.deposit(ammount);
            break;
        case 2:
            cout << "How much do you want to withdraw ? ";
            cin >> ammount;
            account.withdrawal(ammount);
            break;
        case 3:
        {
            cout << "To who you want to send money ?" << endl;
            other = &chooseAccount(&accounts_length, accounts);
            cout << "How much do you want to send ? ";
            cin >> ammount;
            account.transfer(*other, ammount);
            break;
        }
        case 4:
            account.printInfos();
            break;
        }
    }
}