#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	string line;

	char prev = 'a';
	int count = 0;
	stack<int> stack;

	getline(cin, line);

	for(auto c : line)
	{
		if(c == '(')
		{
			stack.push(c);
		}
		else if (c == ')')
		{
			stack.pop();

			if(prev == '(')
			{
				count += stack.size();
			}
			else if(prev == ')')
			{
				count += 1;
			}
		}
		prev = c;
	}

	cout << count;

    return 0;
}