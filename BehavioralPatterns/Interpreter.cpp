#include<iostream>
#include<string>
#include<vector>

using namespace std;

// AbstractExpression
class Expression {
    public:
    virtual int interpret() = 0;
};

// TerminalExpression
class NumberExpression : public Expression {
    private:
    int number;
    
    public:
    NumberExpression(int number) { this->number = number; }
    
    int interpret() override {
        return number;
    }
};

// NonterminalExpression
class AddExpression : public Expression {
    private:
    Expression* left;
    Expression* right;
    
    public:
    AddExpression(Expression* left, Expression* right) {
        this->left = left;
        this->right = right;
    }
    
    int interpret() override {
        return left->interpret() + right->interpret();
    }
};

int main(int argc, char* argv[]) {
    // Create a simple expression tree: 1 + 2 + 3
    vector<Expression*> expressions;
    expressions.push_back(new NumberExpression(1));
    expressions.push_back(new NumberExpression(2));
    expressions.push_back(new NumberExpression(3));

    expressions.push_back(new AddExpression(expressions[0], expressions[1]));
    expressions.push_back(new AddExpression(expressions[2], expressions[3]));
    cout << expressions[4]->interpret() << endl;

    for (auto expression : expressions) {
        delete expression;
    }
    return 0;
}

/* Output: */
/*
6
*/