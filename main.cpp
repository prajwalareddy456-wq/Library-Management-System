#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Book Class
class Book {
public:
    int bookID;
    string title;
    string author;
    bool issued;

    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        issued = false;
    }
};


// Member Class
class Member {
public:
    int memberID;
    string name;
    vector<int> borrowedBooks;

    Member(int id, string n) {
        memberID = id;
        name = n;
    }
};


// Library Class
class Library {

private:
    vector<Book> books;
    vector<Member> members;


public:

    // Add Book
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "Book Added Successfully!\n";
    }



    // Add Member
    void addMember() {

        int id;
        string name;

        cout << "\nEnter Member ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);


        members.push_back(Member(id, name));

        cout << "Member Added Successfully!\n";
    }




    // Display Books
    void displayBooks() {

        if(books.empty()) {
            cout << "No Books Available\n";
            return;
        }


        cout << "\n----- Book List -----\n";

        for(auto &b : books) {

            cout << "ID: " << b.bookID
                 << "\nTitle: " << b.title
                 << "\nAuthor: " << b.author
                 << "\nStatus: ";

            if(b.issued)
                cout << "Issued\n";
            else
                cout << "Available\n";

            cout << "-------------------\n";
        }
    }





    // Search Book
    void searchBook() {

        string keyword;

        cout << "\nEnter Title or Author to Search: ";

        cin.ignore();
        getline(cin, keyword);


        bool found=false;


        for(auto &b : books) {

            if(b.title.find(keyword)!=string::npos ||
               b.author.find(keyword)!=string::npos) {


                cout << "\nBook Found\n";

                cout << "ID: " << b.bookID;
                cout << "\nTitle: " << b.title;
                cout << "\nAuthor: " << b.author;


                found=true;
            }
        }


        if(!found)
            cout << "Book Not Found\n";
    }







    // Issue Book
    void issueBook() {

        int bookID, memberID;

        cout << "\nEnter Book ID: ";
        cin >> bookID;


        cout << "Enter Member ID: ";
        cin >> memberID;



        for(auto &b : books) {


            if(b.bookID == bookID) {


                if(b.issued) {

                    cout << "Book Already Issued\n";
                    return;
                }


                for(auto &m : members) {

                    if(m.memberID == memberID) {

                        b.issued=true;

                        m.borrowedBooks.push_back(bookID);


                        cout << "Book Issued Successfully!\n";

                        return;
                    }
                }

            }
        }


        cout << "Invalid Book or Member ID\n";
    }







    // Return Book
    void returnBook() {


        int bookID, memberID;


        cout << "\nEnter Book ID: ";
        cin >> bookID;


        cout << "Enter Member ID: ";
        cin >> memberID;



        for(auto &b : books) {

            if(b.bookID == bookID) {


                b.issued=false;


                for(auto &m : members) {


                    if(m.memberID == memberID) {


                        for(auto it=m.borrowedBooks.begin();
                            it!=m.borrowedBooks.end();
                            it++) {


                            if(*it==bookID) {

                                m.borrowedBooks.erase(it);
                                break;
                            }
                        }


                        cout << "Book Returned Successfully!\n";

                        return;
                    }
                }
            }
        }


        cout << "Invalid Details\n";

    }







    // Show Borrow Records
    void showRecords() {


        cout << "\n----- Borrow Records -----\n";


        for(auto &m : members) {


            cout << "\nMember ID: " << m.memberID;
            cout << "\nName: " << m.name;


            cout << "\nBorrowed Books: ";


            if(m.borrowedBooks.empty())
                cout<<"None";


            else {

                for(int id:m.borrowedBooks)
                    cout << id << " ";
            }


            cout << "\n--------------------\n";
        }
    }

};






int main() {


    Library library;


    int choice;


    do {


        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";

        cout << "\n1. Add Book";
        cout << "\n2. Add Member";
        cout << "\n3. Display Books";
        cout << "\n4. Search Book";
        cout << "\n5. Issue Book";
        cout << "\n6. Return Book";
        cout << "\n7. Show Borrow Records";
        cout << "\n8. Exit";


        cout << "\nEnter Choice: ";
        cin >> choice;



        switch(choice) {


        case 1:
            library.addBook();
            break;


        case 2:
            library.addMember();
            break;


        case 3:
            library.displayBooks();
            break;


        case 4:
            library.searchBook();
            break;


        case 5:
            library.issueBook();
            break;


        case 6:
            library.returnBook();
            break;


        case 7:
            library.showRecords();
            break;


        case 8:
            cout<<"Exiting System...";
            break;


        default:
            cout<<"Invalid Choice!";
        }


    } while(choice!=8);



    return 0;
}
