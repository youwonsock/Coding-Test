#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	stack<int> s;
	int N;
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int input;
			cin >> input;

			s.push(input);
		}
		else if (command == "pop")
		{
			if(s.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (command == "size")
		{
			cout << s.size() << '\n';
		}
		else if (command == "empty")
		{
			if(s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else
		{
			if(s.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << s.top() << '\n';
			}
		}
	}

    return 0;
}