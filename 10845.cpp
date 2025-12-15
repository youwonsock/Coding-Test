#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	queue<int> q;
	int count = 0;
	string command;
	cin >> count;

	for(int i = 0; i < count; ++i)
	{
		cin >> command;

		if(command == "push")
		{
			int input = 0;
			cin >> input;

			q.push(input);
		}
		else if(command == "pop")
		{
			if(q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				int output = q.front();
				q.pop();

				cout << output << '\n';
			}
		}
		else if(command == "size")
		{
			cout << q.size() << '\n';
		}
		else if(command == "empty")
		{
			if(q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(command == "front")
		{
			if(q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if(command == "back")
		{
			if(q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

    return 0;
}