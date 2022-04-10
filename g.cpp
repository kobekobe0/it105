#include <iostream>
#include <string>
using namespace std;

class SIM1 {
public:
    string name = " ";
    string contactNumber = " ";
    string contacts[5][2];
    int arrlen = 0;

    void deleteContact(string name1)
    {
        //cout << "length for delete " << arrlen << endl;

        for (int i = 0; i < arrlen; i++)
        {
            if(contacts[i][0] == name1)
            {
                for(int j = i; j < (arrlen - 1); j++)
                {
                    contacts[j][0] = contacts[j+1][0];
                    contacts[j][1] = contacts[j+1][1];
                }
                i--;
                arrlen -= 1;
            }
        }
        cout << "Delete Successful" << endl;
    }


    void editContact(string oldName, string newName, string newNum) {
        for (int i = 0; i < 5; i++)
        {
            if(oldName == contacts[i][0]){
                contacts[i][0] = newName;
                contacts[i][1] = newNum;
            }
        }
    }

    void searchContact(string name1) {
        for (int i = 0; i < 5; i++)
        {
            if(name1 == contacts[i][0]){
                cout << "Name: " << contacts[i][0] << endl;
                cout << "Con. Number: " << contacts[i][1] << endl;
            }
        }
    }

    void viewContacts() {
        cout << "SIM1 Contacts" << endl;

        if(arrlen == 0){
            cout << "No contacts" << endl;
        }

        if(arrlen == 1){
            cout << contacts[0][0] << endl;
            cout << contacts[0][1] << endl;
        }

        else{

            for (int i = 0; i < arrlen; i++) {
                cout << "Name: " << contacts[i][0] << endl;
                cout << "Con. Number: " << contacts[i][1] << endl;
                cout << endl;
            }
        }
    }

    void addContact() {

        if(arrlen >= 5){
            cout << "SIM has reached max capacity (5 contacts)" << endl;
        }
        else{
            for (int i = 0; i < 5; i++) {
                if (contacts[i][0] == "") {
                    contacts[i][0] = name;
                    contacts[i][1] = contactNumber;
                    break;
                }
            }
            arrlen++;
        }


        /*
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 1; j++) {
                if (contacts[i][j] == "") {
                    contacts[i][0] = name;
                    contacts[i][1] = contactNumber;
                    break;
                }
            }
        }
        */

    }
};

class SIM2 {
public:
    string name = " ";
    string contactNumber = " ";
    string contacts[5][2];
    int arrlen = 0;

    void deleteContact(string name1)
    {
        //cout << "length for delete " << arrlen << endl;

        for (int i = 0; i < arrlen; i++)
        {
            if(contacts[i][0] == name1)
            {
                for(int j = i; j < (arrlen - 1); j++)
                {
                    contacts[j][0] = contacts[j+1][0];
                    contacts[j][1] = contacts[j+1][1];
                }
                i--;
                arrlen -= 1;
            }
        }
        cout << "Delete Successful" << endl;
    }


    void editContact(string oldName, string newName, string newNum) {
        for (int i = 0; i < 5; i++)
        {
            if(oldName == contacts[i][0]){
                contacts[i][0] = newName;
                contacts[i][1] = newNum;
            }
        }
    }

    void searchContact(string name1) {
        for (int i = 0; i < 5; i++)
        {
            if(name1 == contacts[i][0]){
                cout << "Name: " << contacts[i][0] << endl;
                cout << "Con. Number: " << contacts[i][1] << endl;
            }
        }
    }

    void viewContacts() {
        cout << "SIM1 Contacts" << endl;

        if(arrlen == 0){
            cout << "No contacts" << endl;
        }

        if(arrlen == 1){
            cout << contacts[0][0] << endl;
            cout << contacts[0][1] << endl;
        }

        else{

            for (int i = 0; i < arrlen; i++) {
                cout << "Name: " << contacts[i][0] << endl;
                cout << "Con. Number: " << contacts[i][1] << endl;
                cout << endl;
            }
        }
    }

    void addContact() {

        if(arrlen >= 5){
            cout << "SIM has reached max capacity (5 contacts)" << endl;
        }
        else{
            for (int i = 0; i < 5; i++) {
                if (contacts[i][0] == "") {
                    contacts[i][0] = name;
                    contacts[i][1] = contactNumber;
                    break;
                }
            }
            arrlen++;
        }
    }
};

SIM1 contact1;
SIM2 contact2;

void addContact(int simNum) {
    string conName;
    string conNumber;

    cin.ignore();
    cout << "Name: ";
    getline(cin, conName);
    cout << "Contact number: ";
    getline(cin, conNumber);

    switch (simNum)
    {
    case 1:
        contact1.name = conName;
        contact1.contactNumber = conNumber;

        contact1.addContact();
        break;
    case 2:
        contact2.name = conName;
        contact2.contactNumber = conNumber;

        contact2.addContact();
        break;
    default:
        cout << "invalid choice" << endl;
        break;
    }


}

void editContact(int simNum) {
    string conName, newName, newNum;

    cin.ignore();
    cout << "Enter name of contact to edit: ";
    getline(cin,conName);
    cout << endl;

    switch (simNum)
    {
    case 1:
        contact1.searchContact(conName);
        break;
    case 2:
        contact2.searchContact(conName);
        break;
    default:
        cout << "invalid choice" << endl;
        break;
    }

    cout << "Enter new name: ";
    getline(cin,newName);
    cout << endl;

    cout << "Enter new number: ";
    getline(cin,newNum);
    cout << endl;

    switch (simNum)
    {
    case 1:
        contact1.editContact(conName, newName, newNum);
        break;
    case 2:
        contact2.editContact(conName, newName, newNum);
        break;
    default:
        cout << "invalid choice" << endl;
        break;
    }

}

void viewContacts(int simNum) {
    switch (simNum)
    {
    case 1:
        contact1.viewContacts();
        break;
    case 2:
        contact2.viewContacts();
        break;
    default:
        cout << "invalid choice" << endl;
        break;
    }
}

void deleteContact(int simNum) {
    string name;

    cin.ignore();
    cout << "Enter name of contact to delete: ";
    getline(cin,name);

    switch (simNum)
    {
    case 1:
        contact1.deleteContact(name);
        break;
    case 2:
        contact2.deleteContact(name);
        break;
    default:
        cout << "invalid choice" << endl;
        break;
    }
}

void searchContact(int simNum) {
    string name;

    cin.ignore();
    cout << "Enter name: ";
    getline(cin,name);

    switch (simNum)
    {
    case 1:
        contact1.searchContact(name);
        break;
    case 2:
        contact2.searchContact(name);
        break;
    default:
        cout << "invalid choice" << endl;
        break;
    }


}

int main()
{
    cout << "CONTACTS" << endl;
    int state = 1;
    while (state == 1) {
        int op = 0;
        int simNum = 0;

        cout << "Select SIM 1 or 2 (1 or 2): ";
        cin >> simNum;
        cout << endl;

        cout << "Operations: " << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Edit Contact" << endl;
        cout << "3. View Contacts" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Search Contact" << endl;
        cout << "Pick an operation (1-5): ";
        cin >> op;
        cout << endl;

        switch (op) {
            case 1:
                addContact(simNum);
                break;
            case 2:
                editContact(simNum);
                break;
            case 3:
                viewContacts(simNum);
                break;
            case 4:
                deleteContact(simNum);
                break;
            case 5:
                searchContact(simNum);
                break;
            default:
                cout << "Pick a number 1-5!";
        }

        char ans = ' ';

        cout << "Do you need to do another operation? (Y/N)? ";
        cin >> ans;

        if (ans == 'N' || ans == 'n') {
            break;
        }
    }
    return 0;
}