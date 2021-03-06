﻿/*
문제
		7
	  3   8
	8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라.
아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

예제 입력 1
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
예제 출력 1
30
*/

// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
#define MAX 500

using namespace std;

int main() {

	int tri[MAX][MAX], n, max = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &tri[i][j]);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (0 < j && i > j) { // 첫 번째 순서와 마지막 순서 사이에 있는 숫자에서
				if (tri[i][j] + tri[i - 1][j - 1] > tri[i][j] + tri[i - 1][j]) // 왼쪽 대각선 위에 있는 수가 크면
					tri[i][j] = tri[i][j] + tri[i - 1][j - 1]; // 왼쪽 대각선 위에 있는 수를 합한다
				else // 오른쪽 대각선 위에 있는 수가 크면
					tri[i][j] = tri[i][j] + tri[i - 1][j]; // 오른쪽 대각선 위에 있는 수를 합한다
			}
			else {  // 삼각형의 한 줄에서 처음과 맨 끝에 있는 순서라면
				if (j == 0) // 첫 번째 순서라면
					tri[i][j] = tri[i][j] + tri[i - 1][0]; // 전 줄에 있는 첫 번째 순서 숫자와 합한다
				else // 마지막 순서라면
					tri[i][j] = tri[i][j] + tri[i - 1][j - 1]; // 전 줄에 있는 마지막 순서 숫자와 합한다
			}
		}
	}

	// n번째 줄에서 최대값 골라내기
	for (int i = 0; i < n; i++) {
		if (tri[n - 1][i] > max)
			max = tri[n - 1][i];
	}

	printf("%d", max);

	return 0;
}

/*
[실수 기록]

조건식 (0 < j && j > i)을 (0 < j < i)로 적어서, 계속 오답 처리 되었음
조건식 제대로 잘 적을 것!
*/