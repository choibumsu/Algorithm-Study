
/*
문제
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.
맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 
이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 
아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.


예제 입렵 1
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

예제 출력 1
30

 */
import java.util.Scanner;

public class IntegerTriangle {

	public static void main(String[] args) throws NumberFormatException {
		Scanner bf = new Scanner(System.in);

		int num = bf.nextInt();
		int answer = 0;
		int[][] pyramid = new int[num][num];

		pyramid[0][0] = bf.nextInt();

		for (int i = 1; i < num; i++) {
			for (int j = 0; j <= i; j++) {
				pyramid[i][j] = bf.nextInt();
				// 피라미드의 첫번째 수 = '대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다' 조건때문에
				if (j == 0) {
					pyramid[i][0] = pyramid[i - 1][0] + pyramid[i][0];
				}
				// 피라미드의 마지막수 = '대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다' 조건때문에
				else if (j == i) {
					pyramid[i][j] = pyramid[i - 1][j - 1] + pyramid[i][j];
				}
				// 나머지  = Max함수를 통해 자신의 위의 왼쪽이랑 더했을때 큰지 오른쪽이랑 더했을 때 큰지를 확인한다
				else {
					pyramid[i][j] = pyramid[i][j] + Max(pyramid[i - 1][j - 1], pyramid[i - 1][j]);
				}
				// answer 보다 크면 교체
				if (pyramid[i][j] > answer)
					answer = pyramid[i][j];
			}
		}
		System.out.println(answer);
	}
	// a와 b 중 어느 것이 큰지 확인
	public static int Max(int a, int b) {
		if (a >= b) {
			return a;
		}
		return b;

	}

}
