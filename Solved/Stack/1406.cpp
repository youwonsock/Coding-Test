#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	list<char> l;
	string line;
	int N;

	cin >> line;
	cin >> N;

	for(auto c : line)
		l.push_back(c);

	auto cursor = l.end();
	for(int i = 0; i < N; ++i)
	{
		char command;
		cin >> command;

		if(command == 'L')
		{
			if(cursor != l.begin())
				cursor--;
		}
		else if(command == 'D')
		{	
			if(cursor != l.end())
				cursor++;
		}
		else if(command == 'B')
		{
			if(cursor != l.begin())
			{
				cursor--;
				cursor = l.erase(cursor);
			}
		}
		else if(command == 'P')
		{
			char add;
			cin >> add;

			l.insert(cursor, add);
		}
	}

	for(auto c : l)
		cout << c;

    return 0;
}