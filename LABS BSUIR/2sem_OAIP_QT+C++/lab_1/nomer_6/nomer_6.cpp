class Expression
{
public:
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
};

class Number : public Expression
{
public:
    Number(double value) : value(value)
    {

    }

    double evaluate() const
    {
        return this->value;
    }
private:
    double value;
};

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* left, char op, Expression* right) : left(left), op(op), right(right)
    {

    }

    ~BinaryOperation();
    double evaluate() const;

private:
    Expression* left;
    Expression* right;
    char op;
};

BinaryOperation::~BinaryOperation()
{
    delete this->left;
    delete this->right;
}

double BinaryOperation::evaluate() const
{
    switch (this->op)
    {
    case '+':
    {
        return this->left->evaluate() + this->right->evaluate();
    }
    case '-':
    {
        return this->left->evaluate() - this->right->evaluate();
    }
    case '*':
    {
        return this->left->evaluate() * this->right->evaluate();
    }
    case '/':
    {
        if (this->right->evaluate())
        {
            return this->left->evaluate() / this->right->evaluate();
        }
    }
    default: return 0.0;
    }
}

bool check_equals(Expression* left, Expression* right)
{
    return *(size_t**)left == *(size_t**)right;
}

#include <iostream>
#include <string>
int main()
{
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));

    Expression* expr = new BinaryOperation(new Number(3), '+', sube); 

    Expression* tree = new BinaryOperation(new BinaryOperation(new Number(4.5), '*', new Number(5)), '+', new BinaryOperation(new Number(4.5), '*', new Number(5)));
    

    std::cout << check_equals(tree, expr);

    delete expr;
}
