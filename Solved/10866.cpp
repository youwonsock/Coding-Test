#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	deque<int> dq;
	int count = 0;
	string command;
	cin >> count;

	for(int i = 0; i < count; ++i)
	{
		cin >> command;

		if(command == "push_front")
		{
			int input = 0;
			cin >> input;

			dq.push_front(input);
		}
		else if(command == "push_back")
		{
			int input = 0;
			cin >> input;

			dq.push_back(input);
		}
		else if(command == "pop_front")
		{
			if(dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				int output = dq.front();
				dq.pop_front();

				cout << output << '\n';
			}
		}
		else if(command == "pop_back")
		{
			if(dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				int output = dq.back();
				dq.pop_back();

				cout << output << '\n';
			}
		}
		else if(command == "size")
		{
			cout << dq.size() << '\n';
		}
		else if(command == "empty")
		{
			if(dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(command == "front")
		{
			if(dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';
		}
		else if(command == "back")
		{
			if(dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.back() << '\n';
		}
	}

    return 0;
}