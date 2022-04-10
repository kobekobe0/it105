#include <iostream>
#include <string>

using namespace std;

string askDetailsSim(string& name, string& num, string& newContact, int& counter1,int& counter2, int chad){
    cout << "Enter contact name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter mobile number: ";
    cin >> num;
    
    if(chad == 1){
        counter1 = counter1 + 1;
    } else if(chad == 2){
        counter2 = counter2 + 1;
    }
    
    return newContact = name + ": " + num;
}



//define mobile num and contact then join it and store it to array as string then cout


//create a function that push the string to the array


int main()
{
    string num;
    string name, newContact;
    string sim1[6];
    string sim2[6];
    int counter1 = 0, counter2 = 0;
    int sim;
    int choice;
    int choiceContinue;

    start:

        cout << "Choose what you want to do: " << endl;
        cout << "1. Add contact" << endl;
        cout << "2. View contacts" << endl;
        cout << "3. Edit contact" << endl;
        cout << "4. Delete contact" << endl;
        cout << "5. Exit" << endl;
        cin>>choice;
        
        switch (choice)
        {
            case 1:
                cout << "Choose which sim you want to add contact: " << endl;
                cout << "1. Sim 1" << endl;
                cout << "2. Sim 2" << endl;
                cin >> sim;
                if (sim == 1)
                {
                    cout << "this is sim1" << endl;
                    askDetailsSim(name, num, newContact, counter1, counter2, 1);
                    sim1[counter1] = newContact;
                }
                else if (sim == 2)
                {
                    cout << "this is sim2" << endl;
                    askDetailsSim(name, num, newContact, counter1, counter2, 2);
                    sim2[counter2] = newContact;
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
                break;
            case 2:
                cout << "Choose which sim you want to view contacts: " << endl;
                cout << "1. Sim 1" << endl;
                cout << "2. Sim 2" << endl;
                cin >> sim;
                if (sim == 1)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        cout << sim1[i] << endl;
                    }
                }
                else if (sim == 2)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        cout << sim2[i] << endl;
                    }
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
                break;
            case 3:
                cout << "Choose which sim you want to edit contact: " << endl;
                cout << "1. Sim 1" << endl;
                cout << "2. Sim 2" << endl;
                cin >> sim;
                if (sim == 1)
                {
                    cout << "Enter contact name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter mobile number: ";
                    cin >> num;
                    for (int i = 0; i < 6; i++)
                    {
                        if (sim1[i].find(name) != string::npos)
                        {
                            sim1[i] = name + ": " + num;
                        }
                    }
                }
                else if (sim == 2)
                {
                    cout << "Enter contact name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter mobile number: ";
                    cin >> num;
                    for (int i = 0; i < 6; i++)
                    {
                        if (sim2[i].find(name) != string::npos)
                        {
                            sim2[i] = name + ": " + num;
                        }
                    }
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
                break;
            case 4: 
                cout << "Choose which sim you want to delete contact: " << endl;
                cout << "1. Sim 1" << endl;
                cout << "2. Sim 2" << endl;
                cin >> sim;
                if (sim == 1)
                {
                    cout << "Enter contact name: ";
                    cin.ignore();
                    getline(cin, name);
                    for (int i = 0; i < 6; i++)
                    {
                        if (sim1[i].find(name) != string::npos)
                        {
                            sim1[i] = "";
                        }
                    }
                }
                else if (sim == 2)
                {
                    cout << "Enter contact name: ";
                    cin.ignore();
                    getline(cin, name);
                    for (int i = 0; i < 6; i++)
                    {
                        if (sim2[i].find(name) != string::npos)
                        {
                            sim2[i] = "";
                        }
                    }
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
                break;
            case 5:
                cout << "Do you want to continue? " << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> choiceContinue;
                if (choiceContinue == 1)
                {
                    return 0;
                }
                else if (choiceContinue == 2)
                {
                    cout << "Goodbye" << endl;
                    return 0;
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
                break;
        }
        
    cout << "Do you want to continue? " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choiceContinue;
    if (choiceContinue == 1)
    {
        goto start;
    }
    else if (choiceContinue == 2)
    {
        cout << "Exiting..." << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
    }
     
    
    return 0;   
}