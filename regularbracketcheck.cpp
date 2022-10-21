#include<bits/stdc++.h>
using namespace std;
bool check(string input)
{

    stack <char> s;
    int length = input.length();
    char top;

    for(int i = 0; i< length; i++)
    {

        if(input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            s.push(input[i]);
        }
        else
        {

            if(s.empty())
            {
                return false;
            }
            else
            {
                top = s.top();
                if(input[i] == ')' && top == '(' ||
                        input[i] == '}' && top == '{' ||
                        input[i] == ']' && top == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
}
int main()
{
    string s="()()()(())()";
    if(check(s))cout<<"YES valid"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
