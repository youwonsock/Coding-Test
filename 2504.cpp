#include <bits/stdc++.h>

using namespace std;

struct Data
{
	char ch;
	char modifier;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	string line;

	int total = 0;
	int sum = 0;
	stack<Data> stack;


	getline(cin, line);

	for(auto c : line)
	{
		if(c == '(' || c == '[')
		{
			Data v;
			
			v.ch = c;
			if(stack.empty())
				v.modifier = '+';
			else
				v.modifier = '*';

			stack.push(c);
		}
		else if (c == ')' || c == ']')
		{
			if(stack.empty())
			{
				total = 0;
				break;
			}

			char top = stack.top();
			stack.pop();

			if( (c == ')' && top == '(') 
				|| (c == ']' && top == '[') )
			{
				Data value = stack.top();
				int modiNum = c == ')' ? 2 : 3;

				if(value.modifier == '+')
				{
					total += sum;
					sum = 0;
				}
				else
				{
					sum *= modiNum;
				}
			}
			else
			{
				total = 0;
				break;
			}
		}
	}

	if(!stack.empty())
		total = 0;

	cout << total;

    return 0;
}