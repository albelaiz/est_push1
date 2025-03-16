#include <unistd.h>


void int_to_string(int a)
{
	char nb[4];
	
	if (a < 9)
	{
		nb[0] = a + '0';
		nb[1] = '\n';
		nb[2] = '\0';
	}
	else if (a > 9 && a < 100)
	{
		nb[0] = (a / 10) + '0';
		nb[1] = (a % 10) + '0';
		nb[2] = '\n';
		nb[3] = '\0';
	}
	int i = 0;
	while(nb[i])
	{
		write(1, &nb[i], 1);
		i++;
	}
}

int int_size(int a)
{
	int i = 1;
	while(a / 10 > 0)
	{
		a = a / 10;
		i++;
	}
	return i;
}

int main()
{
	int i = 1;
	while(i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 != 0))
			write(1, "fizz\n", 5);
		else if ((i % 3 != 0) && (i % 5 == 0))
			write(1, "buzz\n", 5);
		else if ((i % 3 == 0) && (i % 5 == 0))
			write(1, "fizzbuzz\n", 9);
		else
			int_to_string(i);
		i++;
	}
	return 0;
}
