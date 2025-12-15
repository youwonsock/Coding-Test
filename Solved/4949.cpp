#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	string line;
	int idx = 0;
	bool isBalenced = true;
	stack<int> stack;

	while(true)
	{
		getline(cin, line);
		idx = 0;
		isBalenced = true;

		while(!stack.empty())
			stack.pop();

		if(line == ".")
		{
			break;
		}

		while(true)
		{
			char alpha = line[idx++];
			if(alpha == '.')
			{
				if(stack.size() > 0)
					isBalenced = false;

				break;
			}
			
			if(alpha == '(' || alpha == '[')
			{
				stack.push(alpha);
			}
			else if (alpha == ')' || alpha == ']')
			{
				if(stack.empty())
				{
					isBalenced = false;
					break;
				}

				char top = stack.top();

				if( (alpha == ')' && top == '(') 
					|| (alpha == ']' && top == '[') )
				{
					stack.pop();
				}
				else
				{
					isBalenced = false;
					break;
				}
			}
		}

		if(isBalenced)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}

    return 0;
}