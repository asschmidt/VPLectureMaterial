double powern (double d, unsigned n)
{
	double x = 1.0;
	unsigned j;

	for (j = 1; j <= n; j++)
	{
		x *= d;
	}

	return x;
}

int main(int argc, char* argv[])
{
	double sum = 0.0;
	unsigned i;

	for (i = 1; i <= 100000000; i++)
	{
		sum += powern (i, i % 5);
	}

	return 0;
}