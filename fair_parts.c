/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : fair_parts.c

 * Purpose : Educational

 * Creation Date : 06-05-2016

 * Last Modified : Sat 14 May 2016 02:14:42 PM EEST

 * Created By :  Stamatios Anoustis, Artemis Zografou

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


#define inf 100000001

long unsigned int result[90000];
unsigned char res[90000];

struct Range
{
	long unsigned int left ;
	long unsigned int right ;
};

int main(int argc, char** argv)
{
	//open input file
	FILE *fp = fopen(argv[1],"r");
	long unsigned int M, N;

	if (fp==NULL)
	{
		perror("Error opening file");
	}
	else    //first line
	{
		fscanf(fp, "%lu", &M);   //N number of parts
		fscanf(fp, "%lu", &N);   //M number of objects

	}

	//second line
	long unsigned int i;
	float kArray[M];

	for (i=0; i<M; i++)
	{
		fscanf(fp, "%f", &kArray[i]);
	}

	float sum1,r1;

	sum1 = 0;

	for (i=0; i<M; i++)
	{
		sum1 = sum1 +kArray[i];

	}

	r1 = sum1;

	float psum =0;
	for (i=N - 1; i<M; i++)
	{
		psum = psum + kArray[i];
	}


	float max,r2,r;
	max = kArray[0];

	for (i=1; i<N -1; i++)
	{
		if (kArray[i] > max)
			max = kArray[i];
	}
	if (psum > max)
		max = psum;
	r2 = max;

	r = (((r1)<(r2)) ? (r1) : (r2));

	float l1,l2,l;
	max = kArray[0];

	for (i=0; i<M; i++)
	{
		if (kArray[i] > max)
			max = kArray[i];
	}

	l1 = max;
	l2 = sum1/N;

	l = (((l1)>(l2)) ? (l1) : (l2));

	//printf("r1=%f, r2=%f, l1=%f, l2=%f", r1, r2, l1, l2);
	//printf("The range of search is (%f, %f)\n", l, r);

	long unsigned int L,R;
	L = (long unsigned int) l;
	//printf("The l = %lu\n",L);

	R = (long unsigned int) r;
	//printf("The r = %lu\n",R);

	long  int diff=0;
	long unsigned int j,c;

	//Choose a candidate maximum part-weight
	struct Range range;
	range.left=L,range.right=R;

	for (i = 0; i<M+N; i++)
		result[i] = 0;
	//printf("The Li is %lu\n", Li);


	int k = 0;
	long unsigned int Li = floor((range.left + range.right)/2);
	long unsigned int  sum = 0;

	long unsigned int count=0; 


	do                              //iterative binary search
	{
		i = 0;                          //object counter
		c = 1;                          //parts counter
		sum = 0;
         
	        //count=0;                    //result index

		for (j = 0; j < M + N; j++)
			result[j] = 0;

		while ( i < M )                         {
			sum = sum + kArray[i];
			//      printf("The current sum is %lu\n", sum);
			if (sum > Li)           //change part

			{
				c = c + 1;
				sum = 0;
			//	result[count] = inf ;
			//	count++;
				//printf("if\n %lu",i);
				i--;
			}
			//else            //inser object
			//{
			//	result[count] = kArray[i];
			//	count++;
				//printf("else\n");
			//}
			i++;
		}
		//      printf("The count is %d\n", count);

		//for (i = 0; i < (M + N); i++)
			//printf("%lu\n", result[i]);

			if (c > N)
				range.left = Li + 1;
			else
				range.right = Li;

		Li = floor((range.left + range.right)/2);
		diff= range.right - range.left;

		if (diff == 0)
			k++;

		printf("The Li is %lu\n", Li);
	printf("The range is (%lu,%lu)\n", range.left, range.right);
	}while(diff >  0 || k != 2);

		printf("The Li is %lu\n", Li);
	//printf("The range is (%lu,%lu)\n", range.left, range.right);
	//Li = range.left;
	printf("c is %lu\n", c);
	//Ensure exact number of parts

	long unsigned int d = N - c;
	printf("d = %lu\n", d);
	if (c < N)
	{
		int co = 0;
		for (i=0; i < d; i++)
		{
			result[co] = kArray[i];
			co++;
			result[co] = inf;
			co++;
		}
	}
		long unsigned int jj = M - 1;
		count = M + N -2;
		sum = 0;

		while (jj >= d)
		{
			sum = sum + kArray[jj];
			//printf("kArray is %lu %f %lu\n", sum, kArray[jj], Li);
			if (sum > Li)           //change part
			{
				sum = 0;
				result[count] = inf ;
				count--;
				//printf("if %lu \n", jj);
				jj++;
			}
			else            //inser object
			{
				result[count] = kArray[jj];
				count--;
			//	printf("else %lu \n", jj);
				
			if (jj == 0) break;
			}
				jj--;
			//printf("jj = %lu\n", jj);

		}

	


	//Display the result
	//unsigned char* res = malloc((M+N)*sizeof(unsigned char));
	for (i = 0; i < M + N; i++)
	{
		if (result[i] == inf )
		{       res[i] = (unsigned char) '|';
			printf("| ");
		}
		else if (result[i] == 0)
		{
			res[i] = (unsigned char) '\0';
			printf("\n");
		}
		else
		{
			res[i] =(unsigned char) result[i];
			printf("%u ",res[i]);
		}
	}




	//printf("The Result is %s\n", res);
	return 0;

}

