//This sorting is a key value based sorting system. Unlike comparison based ones,here we
//key values to sort. In CountSort, the key values are usually from 0-9, though there maybe differences
//We have to check that too.
//We will count the elements having distinct key values.
#include<stdio.h>
int main()
{
	int max,n,i,j,a[10000],b[10000],count[10000];
	scanf("%d",&n);

	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
	max=a[0];

	for(i=1;i<n;i++)
		{
		if(a[i]>max) max=a[i];
		}
//If we know the max value, we are sure that the array contains at most
//distinct values from 0-max, though in some cases, the minimum value might not be 0.
//There may be no elements of a certain key value, eg:
//for the array 1 2 3 6, max element is 6, but there are no elements belonging to
//key values 4 &5.

	for(i=0;i<=max;i++)
		{
		count[i]=0;
		}
//Initialize the whole count array with 0 so that no garbage value exists.

	for(i=0;i<n;i++)
		{
		count[a[i]]++;
		}
//We want to store elements from the main array based on key values. So we
//store the numbers of those distinct values. FE: for i=0, a[i] is 1.
//So we go to the 1th position of the count array and increase it's value by one.
//If we find 1 again for some value of i, we will go the same place again and
//increase it by 1.

	for(i=1;i<=max;i++)
		{
		count[i] += count[i-1];
		}
//Now we now the total amount of each distinct number. FE: 11 is 5 times, 0 is 3 times etc.
//But how will we distribute them in a sorted manner? The snip above and under deals with this.
//First we take cumulative sum of count array. FE in count[0] there is 3, which tells us that
//there should be three 0s from 0-2. After taking the sum, if we find count[1]=7
//that tells us that  there should be 7-3=4 1s from 3-6 position.

	for(i=n-1;i>=0;i--)
		{
		b[--count[a[i]]] =a[i];
		}
//Now we start calculating from the end of the array to maintain stability, which means that we want
//to sort rigorously, like we want to put a 17 ahead of the 17 which was behind the first in
//unsorted array. So we take a[i], and try to put it in the sorted array.b[]
//To do that we go to the count array, find the value corresponding to a[i],
//decrease it by one and then put it in array b. FE a[i]=9, so we go to the 9th  location of count
//and find, say, 17 is stored there. This indicates that we have to put 9 aka a[i] in the 17th position
//of b array.


	for(i=0;i<n;i++)
		{
		printf("%d ",b[i]);
		}
//And that's it!
}
