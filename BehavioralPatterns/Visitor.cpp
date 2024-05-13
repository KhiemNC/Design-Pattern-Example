#include<iostream>
#include<vector>

using namespace std;

class Book;
class Journal;
class Newspaper;

// Visitor interface
class Visitor {
public:
    virtual void visit(Book *book) = 0;
    virtual void visit(Journal *journal) = 0;
    virtual void visit(Newspaper *newspaper) = 0;
};

// Element interface
class Element {
public:
    virtual void accept(Visitor *visitor) = 0;
};

// Concrete element
class Book : public Element {
public:
    void accept(Visitor *visitor) {
        visitor->visit(this);
    }
};
class Journal : public Element {
public:
    void accept(Visitor *visitor) {
        visitor->visit(this);
    }
};
class Newspaper : public Element {
public:
    void accept(Visitor *visitor) {
        visitor->visit(this);
    }
};

// Concrete visitor
class PrintVisitor : public Visitor {
public:
    void visit(Book *book) {
        cout << "Printing book" << endl;
    }
    void visit(Journal *journal) {
        cout << "Printing journal" << endl;
    }
    void visit(Newspaper *newspaper) {
        cout << "Printing newspaper" << endl;
    }
};
class BorrowVisitor : public Visitor {
public:
    void visit(Book *book) {
        cout << "Borrowing book" << endl;
    }
    void visit(Journal *journal) {
        cout << "Borrowing journal" << endl;
    }
    void visit(Newspaper *newspaper) {
        cout << "Borrowing newspaper" << endl;
    }
};

int main() {
    vector<Element*> elements = {new Book(), new Journal(), new Newspaper()};
    PrintVisitor *printVisitor = new PrintVisitor();
    BorrowVisitor *borrowVisitor = new BorrowVisitor();
    for (Element *element : elements) {
        element->accept(printVisitor);
    }
    cout << endl;
    for (Element *element : elements) {
        element->accept(borrowVisitor);
    }

    for (Element *element : elements) {
        delete element;
    }
    return 0;
}

/* Output: */
/*
Printing book
Printing journal
Printing newspaper

Borrowing book
Borrowing journal
Borrowing newspaper
*/