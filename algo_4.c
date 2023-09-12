#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool IsPowerOfTwo(int x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

typedef struct node
{
	int data;
	int **tsched;
	struct node* left;
	struct node* right;
} node;
node* DAC(int n, int* a, int k)
{
	int i, j;
	
	node* o;
	o = (node*)malloc(sizeof(node));
	if (n > 1) {
		o->left = DAC(n / 2, a, 0);
		
		o->right = DAC(n / 2, a + n/2, n / 2);
		int** base = (int**)malloc(n * sizeof(int*));
		for (i = 0; i < n; i++)
			base[i] = (int*)malloc(n * sizeof(int));
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i < n/2 && j < n/2) {
					*(*(base+j)+i) = *(*(o->left->tsched + j) + i);
				}
				if (i<n / 2 && j>=n / 2) {
					*(*(base+j)+i) = *(*(o->right->tsched + j- (n / 2)) + i);
				}
				if (i >= n / 2 && j >= n / 2) {
					*(*(base + j) + i) = *(*(o->left->tsched + j- (n / 2)) + i- n / 2);
				}
				if (i>= n / 2 && j< n / 2) {
					*(*(base + j) + i) = *(*(o->right->tsched + j) + i-( n / 2));
				}
			}
		}
		o->tsched = base;
	}
	if (n == 1) {
		int** base = (int**)malloc(n * sizeof(int*));
		for (i = 0; i < n; i++)
			base[i] = (int*)malloc(n * sizeof(int));
		base[0][0] = *(a);
		o->tsched = base;
	}
	return o;
}

int main() {
	int n;
	printf("Give Number of participants: ");
	scanf("%d", &n);
	while(!IsPowerOfTwo(n)){
        printf("Number has to be power of 2\nGive Number of participants: ");
        scanf("%d", &n);
    	}
	int  i,j;
	int* sched;
	int* arr = (int*)malloc(n * sizeof(int)); //athletes array 
	for (i = 0; i < n; i++) {
		*(arr + i) = i+1; //fill the array with athlete numbers
	}
	node* o = DAC(n, arr, 0);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf(" %d ", *(*(o->tsched+i)+j));
		}
		printf("\n");
	}
        gets();
	return 0;
}
