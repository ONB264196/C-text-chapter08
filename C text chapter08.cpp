#include<stdio.h>
#include <cstdlib>
#define _0810

#ifdef _0801

#define diff(x, y) ((x)-(y))

int main(void) {
	float a, b;
	printf("実数1 : "); scanf_s("%f", &a);
	printf("実数2 : "); scanf_s("%f", &b);
	putchar('\n');

	printf("二つの数の差は%fです。", (abs)diff(a, b));

	return 0;
}
#endif

#ifdef _0802

#define Mx(x, y) (((x) > (y)) ? (x) : (y))

int main(void) {
	int a = rand() % 100;
	int b = rand() % 100;
	int c = rand() % 100;
	int d = rand() % 100;

	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
	putchar('\n');

	printf("max(max(a, b), max(c, d)) : %d\n", Mx(Mx(a, b), Mx(c, d)));
	printf("まず「aとb」、「cとd」を比較し、次にその二つを比較する。\n");
	putchar('\n');
	printf("max(max(max(a, b), c), d) : %d\n", Mx(Mx(Mx(a, b), c), d));
	printf("「aとb」を比較し、それと「c」を比較、最後にそれを「d」と比較する。");
	return 0;
}
#endif

#ifdef _0803

#define swap(type, a, b) do{type t = a; a = b; b = t;}while(0)

int main(void) {
	int a = rand() % 20;
	int b = rand() % 20;

	printf("入れ替え前\na = %d\nb = %d\n", a, b);
	putchar('\n');
	swap(int, a, b);
	printf("入れ替え後\na = %d\nb = %d", a, b);


	return 0;
}
#endif

#ifdef _0804

#define NUMBER 5

void bsort(int a[], int n) {
	int i, j;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j - 1] > a[j]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

int main(void) {
	int i;
	int height[NUMBER];

	for (i = 0; i < NUMBER; i++) {
		height[i] = rand() % 20 + 129;
		printf("%d番 : %dcm\n", i + 1, height[i]);
	}
	putchar('\n');
	bsort(height, NUMBER);

	puts("昇順にソートしました。");
	for (i = 0; i < NUMBER; i++) {
		printf("%d番 : %dcm\n", i + 1, height[i]);
	}

	return 0;
}
#endif

#ifdef _0805

enum LittleLirical { Kyoka, Misogi, Mimi, Yuni, Invalid };

void mimi(void) {
	puts("「ユニちゃんいい子いい子♪」");
}

void misogi(void) {
	puts("「トリックオアトリック！」");
}

void kyoka(void) {
	puts("「やっぱりあなたはへんたいふしんしゃさんですね！」");
}

void yuni(void) {
	puts("「うわはぁい♪ ママもっとぉ、ママー、  ママー」");
}

enum LittleLirical select(void) {
	int tmp= 0;
	
	do {
		printf("選択 : ");
		scanf_s("%d", &tmp);
	} while (tmp < Kyoka || tmp > Invalid);
	return (enum LittleLirical)tmp;
}
int main(void) {
	printf("//選択肢//\n0…キョウカ\n1…ミソギ\n2…ミミ\n3…ユニちゃん8歳(18)\n4…防犯魔石\n\n");
	enum LittleLirical selected;
	
	do {
		switch (selected = select()) {
		case Kyoka  :  kyoka(); break;
		case Misogi : misogi(); break;
		case Mimi   : mimi();   break;
		case Yuni   : yuni();   break;
		}
	} while (selected != Invalid);

	return 0;
}
#endif

#ifdef _0806

int factorial(int n) {
	if (n > 0) {
		int tmp = n;
		for (int i = n - 1; i > 0; i--) {
			n--;
			tmp *= n;
		}
		return tmp;
	}
	else {
		return 1;
	}
}

int main(void) {
	int num;

	printf("整数を入力してください : ");
	scanf_s("%d", &num);

	printf("%dの階乗は%dです。\n", num, factorial(num));

	return 0;
}
#endif

#ifdef _0807
int factorialN(int n) {
	if (n > 0)
		return n * factorialN(n - 1);
	else
		return 1;
}
int factorialR(int r) {
	if (r > 0)
		return r * factorialN(r - 1);
	else
		return 1;
}
int factorialNR(int nr) {
	if (nr > 0)
		return nr * factorialN(nr - 1);
	else
		return 1;
}

int main(void) {
	int n, r, sets;
	
	printf("総数 : "); scanf_s("%d", &n);
	printf("一組当たりの数 : "); scanf_s("%d", &r);
	int nr = n - r;

	if (r == 1) { sets = n; }
	else { sets = factorialN(n) / (factorialR(r) * factorialNR(nr)); }

	printf("%d通り", sets);

	return 0;
}
#endif

#ifdef _0808

int gct(int x, int y) {
	int r;
	if (x > y) {
		while (y != 0) {
			r = x % y;
			x = y;
			y = r;
		}
		return x;
	}
	else {
		while (x != 0) {
			r = y % x;
			y = x;
			x = r;
		}
		return y;
	}
}

int main(void) {
	int a, b;

	printf("二つの整数値を入力してください\n");
	printf("整数1 : "); scanf_s("%d", &a);
	printf("整数2 : "); scanf_s("%d", &b);

	printf("最大公約数は%dです。", gct(a, b));


	return 0;
}
#endif

#ifdef _0809
int main(void) {
	int ch;
	int cnt = 1;

	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			cnt++;
		}
	}

	printf("行数は%d行です。", cnt);

	return 0;
}
#endif

#ifdef _0810
int main(void) {
	int ch;
	int cnt[10] = { 0 };

	while ((ch = getchar()) != EOF) {
		if (ch >= '0' && ch <= '9') {
			cnt[ch - '0']++;
		}
	}

	puts("---数字文字の出現回数---");
	for (int i = 0; i < 10; i++) {
		printf("'%d'", i);
		for (int j = 0; j < cnt[i]; j++) {
			putchar('*');
		}
		putchar('\n');
	}

	return 0;
}
#endif

