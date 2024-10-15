#include<stdio.h>

int Recursive(int hour) {
	if (hour <= 1) {
		return 100;
	}
	return (Recursive(hour - 1) * 2 - 50);
}

int main() {

    int hours = 10;  // 比較する時間数
    int hourlyWage = 1072;  // 一般的な賃金体系の時給
    int recursiveWage;
    int resultHourlyWage = 0;
    int resultRecursiveWage = 0;

    printf("時間\t一般的な賃金\t再帰的な賃金\n");

    for (int i = 1; i <= hours; i++) {
        recursiveWage = Recursive(i);  // 再帰的な賃金計算
        resultHourlyWage += hourlyWage;   // 一般的な賃金の合計
        resultRecursiveWage += recursiveWage; // 再帰的な賃金の合計
        printf("%d時間目\t%d円\t\t%d円\n", i, hourlyWage * i, recursiveWage);
    }

    printf("一般的な賃金体系の総額: %d円\n", resultHourlyWage);
    printf("再帰的な賃金体系の総額: %d円\n", resultRecursiveWage);

	return 0;
}