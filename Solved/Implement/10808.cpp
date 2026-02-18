#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	vector<int> v(26,0);
	string word;

	cin >> word;

	for(int i = 0; i < word.size(); ++i)
	{
		int idx = word[i] - 97;
		if(idx >= 0 && idx <= 26)
		{
			v[idx] += 1;
		}
	}

	for(int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}

    
    return 0;
}