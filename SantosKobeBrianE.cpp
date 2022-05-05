#include <iostream>
#include <vector>
using namespace std;

class Book {       
    public:             
        int ISBN;       
        string title;  
        string author;
        string publisher;
        int year;
};  

int BOOKCOUNTER = 0;
int BORROWEDCOUNTER = 0;
Book books[10];
int BOOKSLENGTH = 10;
Book borrowedBooks[10];

void pushZerosToEnd(Book arr[], int n)
{
    int count = {0}; 

    for (int i = 0; i < n; i++){
        if (arr[i].ISBN != 0){
           arr[count++] = arr[i]; 
        }    
    }
    
    while (count < n){
        arr[count++] = {};
    }
}

void pushBack(){
    int n = sizeof(books) / sizeof(books[0]);
    pushZerosToEnd(books, n);
    
}

int listOfBooks() {  
    
    string list = "";
    cout << "List of books available: " << endl;
    for (int i = 0; i < 10; i++) {
        list += "[" + to_string(i) + "]" + " " + to_string(books[i].ISBN) + " " + books[i].title + " " + books[i].author + " " + books[i].publisher + " " + to_string(books[i].year) + "\n";
    }
    
    cout << list;
    return 0;   
}
int listOfBorrowedBooks() {  
    string list = "";
    cout << "List of borrowed books: " << endl;
    for (int i = 0; i < 10; i++) {
        list += "[" + to_string(i) + "]" + " " + to_string(borrowedBooks[i].ISBN) + " " + borrowedBooks[i].title + " " + borrowedBooks[i].author + " " + borrowedBooks[i].publisher + " " + to_string(borrowedBooks[i].year) + "\n";
    }
    cout << list;
    return 0;   
}

class User{
    public:
        string name;
        string password;
        //function that creates a new user
        void createUser(string name, string password){
            this->name = name;
            this->password = password;
        };
        void createBook(string title, string author, string publisher, int year, int ISBN){
            Book newBook;
            newBook.title = title;
            newBook.author = author;
            newBook.publisher = publisher;
            newBook.year = year;
            newBook.ISBN = ISBN;
            books[BOOKCOUNTER] = newBook; //find a way to get the index of the book
            BOOKCOUNTER++;
            listOfBooks();
        };
        int borrowBook(int ISBN){
            int nothing = false;
            for(int i = 0; i < BOOKSLENGTH; i++){
                if(books[i].ISBN == ISBN){
                    cout << "Book borrowed" << endl;
                    borrowedBooks[BORROWEDCOUNTER] = books[i];
                    books[i] = {};
                    nothing = false;
                    BORROWEDCOUNTER++;
                    BOOKCOUNTER--;
                } else {
                    nothing = true;
                }
            }
            if(nothing){
                cout << "Book not found" << endl;
                return 0;
            }
            
            return 0;
        }
        int returnBook(int ISBN){
            int nothing = false;
            for(int i = 0; i < BOOKSLENGTH; i++){
                if(borrowedBooks[i].ISBN == ISBN){
                    books[BOOKCOUNTER] = borrowedBooks[i];
                    borrowedBooks[i] = {};
                    nothing = false;
                    BORROWEDCOUNTER--;
                    BOOKCOUNTER++;
                }else{
                    nothing = true;
                }
            }
            if(nothing){
                cout << "Book not found" << endl;
                return 0;
            }
            
            return 0;
        }
        int updateBook(){
            int nothing = false;
            listOfBooks();
            cout<<"Enter the index of the book you want to update: ";
            int indexOfBook;
            cin>>indexOfBook;
            
            string book = "";
            //cout << book += to_string(books[indexOfBook].ISBN) + " - " + books[indexOfBook].title + " - " + books[indexOfBook].author + " - " + books[indexOfBook].publisher + " - " + to_string(books[indexOfBook].year) << endl;
            cout << "What do you want to update?" << endl;
            cout << "[1] Title" << endl;
            cout << "[2] Author" << endl;
            cout << "[3] Publisher" << endl;
            cout << "[4] Year" << endl;
            cout << "[5] ISBN" << endl;
            int choice;
            cin>>choice;

            string title;
            string author; 
            string publisher;
            int year;
            int ISBN;

            switch(choice){               
                case 1:              
                    cout << "Enter the new title: ";
                    cin>>title;     
                    books[indexOfBook].title = title;
                    break;
                case 2:
                    cout << "Enter the new author: ";
                    cin>>author;
                    books[indexOfBook].author = author;
                    break;
                case 3:
                    cout << "Enter the new publisher: ";
                    cin>>publisher;
                    books[indexOfBook].publisher = publisher;
                    break;
                case 4:
                    cout << "Enter the new year: ";
                    cin>>year;
                    books[indexOfBook].year = year;
                    break;
                case 5:
                    cout << "Enter the new ISBN: ";
                    cin>>ISBN;
                    books[indexOfBook].ISBN = ISBN;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }

            return 0;
        }
        int searchBook(){
            int ISBN;
            string bookk = "Book not found";
            cout<<"Enter the ISBN of the book you want to search: ";
            cin>>ISBN;
            for(int i = 0; i < BOOKSLENGTH; i++){
                if(books[i].ISBN == ISBN){
                    cout << "Book found" << endl;
                    bookk = to_string(books[i].ISBN) + " " + books[i].title + " " + books[i].publisher + " " + books[i].author + " " + to_string(books[i].year) + "\n";
                    //cout <<  book += to_string(books[i].ISBN) + " - " + books[i].title + " - " + books[i].author + " - " + books[i].publisher + " - " + to_string(books[i].year) << endl;                             
                }
            }
            cout << bookk;

            return 0;
        }
};


User user;

int Menu(){
    cout << "Create Account" << endl;
    return 0;
}

bool login;

int Login(){   
    string name, password;
    cout << "name: ";
    cin >> name;
    cout << "password: ";
    cin >> password;

    if(user.name != name || user.password != password){
        cout << "Invalid user" << endl;
        login = false;
        return 0;
    } 

    cout << "Welcome " << user.name << endl;

    login = true;

    return 0;

}

int createUser(){
    string name = "";
    string password = "";
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> password;
    User user1;
        user1.createUser(name, password);
        if(user1.name == "" && user1.password == ""){
            cout << "invalid user" << endl;
        } else {
            cout << "User created" << endl;
            user = user1;
            Login();
        }  
    return 0;
}

int createABook(){
    string title;
    string author;
    string publisher;
    int year;
    int ISBN;

    cout << "Enter the title: ";
    cin >> title;
    cout << "Enter the author: ";
    cin >> author;
    cout << "Enter the publisher: ";
    cin >> publisher;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the ISBN: ";
    cin >> ISBN;

    user.createBook(title, author, publisher, year, ISBN);

    return 0;
}

int EmptyBookAction(){  //Initialize when BOOKCOUNTER is 0
    cout << " " << endl;    
    cout << "No books available" << endl;
    cout << " " << endl;
    cout << "Enter a new book" << endl;
    createABook();
    return 0;
}

int Actions(){ //Initialize when BOOKCOUNTER is not 0
    int choice;
    cout << " " << endl;
    cout << "[1] Enter a new book" << endl;
    cout << "[2] Borrow a book" << endl;
    cout << "[3] Return a book" << endl;
    cout << "[4] Update a book" << endl;
    cout << "[5] Search a book" << endl;
    cout << "[6] List all available books" << endl;
    cout << "[7] List all borrowed books" << endl;
    cout << "[8] Logout" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    int ISBN;

    switch(choice){
        case 1:
            createABook();
            break;
        case 2:
            cout << "Enter the ISBN of the book you want to borrow: ";           
            cin >> ISBN;
            user.borrowBook(ISBN);
            break;
        case 3:
            cout << "Enter the ISBN of the book you want to return: ";
            cin >> ISBN;
            user.returnBook(ISBN);
            break;
        case 4:
            user.updateBook();
            break;
        case 5:
            user.searchBook();
            break;
        case 6:
            listOfBooks();
            break;
        case 7:
            listOfBorrowedBooks();
            break;
        case 8:
            cout << "Logged out" << endl;
            login = false;
            break;           
    }
    return 0;
}

int main()
{
    Menu();
    createUser();

    if(login){
        do{
            pushBack(); // pushes empty values at the end of the array
            if(BOOKCOUNTER == 0){
                EmptyBookAction();
            } else {
                Actions();
            }
        }  while (login); 
    }
        
    return 0;
}