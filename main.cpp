#include <stdio.h>
#include <functional>
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

int main(int argc,const char *argv[]) {
   

    int dice;
    int num;

    // サイコロを振る
    srand((unsigned int)time(NULL));
    dice = rand() % 6 + 1;  // 1から6のランダムな数字を生成

    printf("サイコロの出目が半(奇数)か丁(偶数)かを当ててください\n");
    printf("1が半(奇数), 2が丁(偶数): ");
    scanf_s("%d", &num);
   
    // ユーザー入力のチェックを行うラムダ関数（1か2のみを許容）
    std::function<int(int)> validateInput = [](int n) {
        if (n != 1 && n != 2) {
             // ユーザーに1か2（奇数か偶数か）で入力させる
            printf("無効な入力です。1（奇数）か2（偶数）を入力してください。\n");
        }
        return n;
        };

    // ユーザーの入力を検証
    num = validateInput(num);

    // 3秒後に結果を表示
    setTimeout(DispResult, 3);

    // ユーザーの回答を判定
    if ((dice % 2 == 1 && num == 1) || (dice % 2 == 0 && num == 2)) {
        printf("正解です！\n");
    }
    else {
        printf("不正解です！\n");
    }

    return 0;
}
