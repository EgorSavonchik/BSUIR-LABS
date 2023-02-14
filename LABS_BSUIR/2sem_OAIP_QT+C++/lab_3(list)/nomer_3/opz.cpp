#include "opz.h"

opz::opz()
{

}

opz::opz(const QString input, double x1, double x2, double x3, double x4, double x5)
{
    expr = input;

    a = x1;
    b = x2;
    c = x3;
    d = x4;
    e = x5;
}

int opz::prior(QChar op)
{
    if(op == '(')
    {
        return 1;
    }
    else if(op == '+' || op == '-')
    {
        return 2;
    }
    else if(op == '*' || op == '/')
    {
        return 3;
    }
}

bool opz::is_op(QChar c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool opz::is_alpha(QChar c)
{
    return c >= 'a' && c <= 'z';
}

QString opz::OPN()
{
    Stack <QChar> S;
    int i = 0, j = 0;
    QString out = expr;

    for(int i = 0; i < out.size(); i++)
    {
        out[i] = ' ';
    }

    while (expr[i] != '\n')
    {
        if (is_alpha(expr[i]))
        {
            out[j] = expr[i];
            j++;
        }
        else
            if (is_op(expr[i]))
            {
                if (S.empty() || prior(S.peek()) < prior(expr[i]))
                {
                    S.push(expr[i]);
                }
                else
                {
                    while (!S.empty() && (prior(S.peek()) >= prior(expr[i])))
                    {
                        out[j++] = S.peek();
                        S.pop();
                    }
                    S.push(expr[i]);
                }
            }
            else
                if (expr[i] == '(')
                {
                    S.push(expr[i]);
                }
                else
                    if (expr[i] == ')')
                    {
                        if (S.empty() || S.peek() == '(')
                        {
                            //cout << "Input error!";
                        }
                        else
                        {
                            while (S.peek() != '(')
                            {
                                out[j] = S.peek();
                                S.pop();
                                j++;
                            }
                        }
                        S.pop();
                    }
        i++;
    }
    while (!S.empty())
    {
        if (S.peek() == '(')
        {
            //cout << "Input error!";
        }
        else
        {
            out[j] = S.peek();
            S.pop();
            j++;
        }
    }

    QString rigth_out = "";

    for(int i = 0; i < out.size() && out[i] != ' '; i++)
    {
        rigth_out += out[i];
    }

    return rigth_out;
}

double opz::Calc()
{
    QString out = OPN() + '\n';
    double j = 0, r1 = 0, r2 = 0;
    Stack <double> S;

    QChar list_ch[5] = {'a', 'b', 'c', 'd', 'e'};
    double list_int[5] = {a, b, c, d, e};

    while (out[j] != '\n')
    {
        if (out[j] >= 'a' && out[j] <= 'z')
        {
            for(int i = 0; i < 5; i++)
            {
                if(out[j] == list_ch[i])
                {
                    S.push(list_int[i]);

                    break;
                }
            }
        }
        else
            if (is_op(out[j]))
            {
                r1 = S.peek();
                S.pop();
                r2 = S.peek();
                S.pop();

                if(out[j] == '+')
                {
                    S.push(r2 + r1);
                }
                else if(out[j] == '-')
                {
                    S.push(r2 - r1);
                }
                else if(out[j] == '*')
                {
                    S.push(r2 * r1);
                }
                else if(out[j] == '/')
                {
                    S.push(r2 / r1);
                }
            }
        j++;
    }

    return (S.peek());
}
