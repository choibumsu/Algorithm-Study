/*
문제
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

예제 입력 1
3 1
4 4 2
예제 출력 1
2
4
예제 입력 2
4 2
9 7 9 1
예제 출력 2
1 7
1 9
7 1
7 9
9 1
9 7
9 9
예제 입력 3
4 4
1 1 1 1
예제 출력 3
1 1 1 1
*/

// 백트래킹 문제

#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
#define MAX 8

using namespace std;

int N, M, cnt; // cnt: 방문한 원소의 개수
int buffer[MAX], num[MAX]; // buffer: M개의 숫자를 오름차순으로 저장할 배열, num: 출력될 숫자를 저장할 배열
bool visited[MAX]; // 배열의 원소 방문 여부(선언하면 자동으로 false로 초기화)

void func(int cnt);

int main() {

	int i, j;
	scanf("%d %d", &N, &M); // cout, cin 사용 시 시간 초과 -> printf, scanf로 변경

	for (i = 0; i < N; i++) {
		scanf("%d", &buffer[i]);

		for (j = 0; j < i; j++) { // 중복된 값 있는지 검사
			if (buffer[j] == buffer[i]) { // 중복된 값 있으면
				--i; // i 값 감소
				--N; // N 값 감소
			}
		}
	}
	sort(buffer, buffer + N);

	func(0); // 방문한 원소가 0개일 때부터 시작
	return 0;
}

void func(int cnt) {

	if (cnt == M) { // 방문한 원소의 개수가 M값(= 출력해야 하는 숫자 개수)과 같다면
		for (int i = 0; i < M; i++) {
			printf("%d ", num[i]); // 방문한 원소들을 모두 출력
		}
		printf("\n");
		return; // 그리고 끝내기
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) { // 방문하지 않은 원소라면

			visited[i] = true; // 방문한다
			num[cnt] = buffer[i]; // buffer에 있는 원소 num에 저장
			func(cnt + 1); // 방문한 원소가 (cnt+1)개로 증가(Recursive)
			visited[i] = false; // 출력을 다 했으면, 방문한 원소 false로 변경
		}
	}
}