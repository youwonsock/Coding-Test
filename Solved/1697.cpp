#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100002;

int array[SIZE];
int dist[SIZE];

void Determine(int next, int current, queue<int>& q)
{
	if(next < 0 || next >= SIZE)
		return;

	if(dist[next] != -1)
		return;

	dist[next] = dist[current] + 1;
	q.push(next);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n, k;
	queue<int> q;
	cin >> n >> k;
	fill(dist, dist + (SIZE-1), -1);

	dist[n] = 0;
	q.push(n);

	while(!q.empty())
	{
		int current = q.front(); q.pop();

		// find
		if(current == k)
		{
			cout << dist[current];
			return 0;
		}

		// +1
		Determine(current + 1, current, q);

		// -1
		Determine(current - 1, current, q);

		// * 2
		Determine(current * 2, current, q);
	}

	cout << dist[k];

    return 0;
}