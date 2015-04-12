struct input
{
	int n;
	int c;
};

struct output
{
	int result;
};

program FIBOP
{
	version FIBOV
	{
		struct output FIBO (struct input i) = 1;
	}=1;
}=2222;
