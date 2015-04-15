/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "fibo.h"

struct output *
fibo_1_svc(struct input *argp, struct svc_req *rqstp)
{
	static struct output  result;

	/*
	 * insert server code here
	 */
	 
	int res = 1, i;
	int a=0, b=1, c;
	switch (argp->c)
	{
		case 1:
			for (i=argp->n; i>=2; i--)
				res *= i;
			result.result = res;
			break;
			
		case 2:
			i = 0;
			while (i <= argp->n)
			{
				c = a+b;
				printf ("%d\n", c);
				a = b;
				b = c;
				i++;
			}
			result.result = c;
			break;
	}

	return &result;
}