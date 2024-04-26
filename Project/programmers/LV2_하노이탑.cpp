#include <bits/stdc++.h>

using namespace std;

/*
하노이 탑(Tower of Hanoi)은 퍼즐의 일종입니다. 세 개의 기둥과 이 기동에 꽂을 수 있는 크기가 다양한 원판들이 있고, 퍼즐을 시작하기 전에는 한 기둥에 원판들이 작은 것이 위에 있도록 순서대로 쌓여 있습니다. 게임의 목적은 다음 두 가지 조건을 만족시키면서, 한 기둥에 꽂힌 원판들을 그 순서 그대로 다른 기둥으로 옮겨서 다시 쌓는 것입니다.

한 번에 하나의 원판만 옮길 수 있습니다.
큰 원판이 작은 원판 위에 있어서는 안됩니다.
하노이 탑의 세 개의 기둥을 왼쪽 부터 1번, 2번, 3번이라고 하겠습니다. 1번에는 n개의 원판이 있고 이 n개의 원판을 3번 원판으로 최소 횟수로 옮기려고 합니다.

1번 기둥에 있는 원판의 개수 n이 매개변수로 주어질 때, n개의 원판을 3번 원판으로 최소로 옮기는 방법을 return하는 solution를 완성해주세요.

제한사항
    n은 15이하의 자연수 입니다.
*/

/*
* 04/22
* 재귀 호출을 사용해 해결하는 문제
* 
* 하노이의 탑에서 n개의 판을 이동시키려면 n-1개의 판을 다른 곳에 이동시켜야한다
* 이것을 재귀 호출을 사용하여 코드로 표현하면된다.
* 
*/

/// <summary>
/// 
/// </summary>
/// <param name="n"> 판 개수</param>
/// <param name="from"> 시작 위치</param>
/// <param name="by"> 임시 기둥 </param>
/// <param name="to"> 목적지 기둥 </param>
/// <param name="answer"></param>
void Hanoi(int n, int from, int by, int to, vector<vector<int>>& answer)
{
    if (n == 0)
        return;

    Hanoi(n - 1, from, to, by, answer); // n-1개의 판을 목적지 옆으로 일단 이동

    vector<int> temp = { from, to };
    answer.push_back(temp);

    Hanoi(n - 1, by, from, to, answer); // 이동시켰던 n-1개에서 다시 하노이 탑 시작
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;

    Hanoi(n, 1, 2, 3, answer);

    return answer;
}
