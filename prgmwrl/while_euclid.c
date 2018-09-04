#include <stdio.h>
#include <math.h>

int gcd(int var1, int var2);

int main(void)
{
	int var1, var2, res;
	printf("input 2 positive int number,interval with space: ");
	scanf("%d %d", &var1, &var2);
	if (var1 <= 0 || var2 <= 0) {
		printf("input positive num plz!\n");
		return 0;
	}

	res = gcd(var1, var2);
	printf("GCD IS %d\n", res);
	return 0;

}


int gcd(int var1, int var2)
{
	int tep;
	if (var1 < var2) {
		tep = var1;
		var1 = var2;
		var2 = tep;
	}

	while (0 != var1 % var2) {
		var1 = var1 % var2;

		if (var1 < var2) {
			tep = var1;
			var1 = var2;
			var2 = tep;
		}
	}

	return var2;
}
