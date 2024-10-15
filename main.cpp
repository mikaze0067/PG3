#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

typedef void(*PFunc)(int*);

// コールバック関数
void DispResult(int* result) {
    if (*result % 2 == 0) {
        printf("サイコロの出目は %d です。偶数！\n", *result);
    }
    else {
        printf("サイコロの出目は %d です。奇数！\n", *result);
    }
}

void setTimeout(PFunc p, int second) {
    //コールバック関数を呼び出す
    Sleep(second * 1000);
    p(&second);
}

int main() {
    int dice;
    int n;

    printf("サイコロを振ります\n");

    // サイコロを振る（1〜6のランダムな数値を生成）
    srand((unsigned int)time(NULL));
    dice = rand() % 6 + 1;

    // ユーザーに1か2で入力させる
    printf("サイコロの出目が半(奇数)か丁(偶数)かを当ててください\n");
    printf("1が半(奇数), 2が丁(偶数): ");
    scanf_s("%d", &n);

    // 3秒後に結果を表示
    setTimeout(DispResult, 3);

    // ユーザーの回答を判定
    if ((dice == 1 && n == 2) || (dice == 2 && n == 1) || (dice == 3 && n == 2) || (dice == 4 && n == 1) || (dice == 5 && n == 2)  || (dice == 6 && n == 1)) {
        printf("正解\n");
    }
    else {
        printf("不正解\n");
    }

    return 0;
}