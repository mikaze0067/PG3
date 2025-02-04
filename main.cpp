//void MyClass::Update() {
//
//	// 関数ポインタのテーブルから関数を実行
//	(this->*table[index])();
//
//	int num;
//
//	puts("次の行動へ\n");
//	scanf_s("%d", &num);
//
//	if (num == 0) {
//		index++;
//		if (index > 2)
//			index = 0;
//	}
//}
//
//
//
//int main()
//{
//	MyClass my;
//
//	while (1) {
//		my.Update();
//	}
//
//	return 0;
//}
//------------------------------------------------------------------------------------------------//

#include <iostream>
using namespace std;

// 自作クラス
class MyClass {
public:

	void Update();
	void a();
	void b();
	void c();

	// メンバ関数ポインタのテーブル
	static void (MyClass::* table[])();

private:
	// メンバ関数ポインタのテーブルを参照するインデックス
	int index = 0;
};

void MyClass::a() {
	cout << "敵の接近！" << endl;
}

void MyClass::b() {
	cout << "敵の攻撃！" << endl;
}

void MyClass::c() {
	cout << "敵の離脱！" << endl;
}

void MyClass::Update() {

	// 関数ポインタのテーブルから関数を実行
	(this->*table[index])();
	int num;

	puts("次の行動へ\n");
	scanf_s("%d", &num);
	if (num == 0) {
		index++;
		if (index > 2){
			index = 0;
		}
	}
	else {
		/*ゼロ以外の入力ならインデックスを更新せずに同じ行動を繰り返す*/
		scanf_s("%d", &num);
	}
}

// static宣言したメンバ関数ポインタテーブルの実体
void (MyClass::* MyClass::table[])() = {
  &MyClass::a,	// インデックス番号0
  &MyClass::b,	// インデックス番号1
  &MyClass::c	// インデックス番号2
};


int main()
{
	MyClass my;

	my.Update();
	return 0;
}