#include <bits/stdc++.h>
using namespace std;
char NextToken(string s)
{
    static int i = 0;
    return s[i++];
}
int isp(char a)
{
    if (a == '^')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else if (a == '#')
        return -1;
    else
        return 0;
}
int icp(char a)
{
    if (a == '(')
        return 5;
    else if (a == '^')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else if (a == '#')
        return -1;
    else
        return -2;
}

void Postfix(string s)
{
    stack<char> s1;
    s1.push('#');
    for (char in = NextToken(s); in != '#'; in = NextToken(s))
    {
        if (in == ')')
        {
            for (in = s1.top(); in != '('; in = s1.top())
            {
                cout << s1.top();
                s1.pop();
            }
            s1.pop();
        }

        else if (in >= 'A' && in <= 'Y')
        {
            cout << in;
        }

        else
        {
            while (icp(in) <= isp(s1.top()))
            {
                cout << s1.top();
                s1.pop();
            }
            s1.push(in);
        }
    }
    while (s1.top() != '#')
    {
        cout << s1.top();
        s1.pop();
    }
}
int main()
{
    string s = "(A+B)*C^D/(E-F)*G";
    Postfix(s);
    return 0;
}