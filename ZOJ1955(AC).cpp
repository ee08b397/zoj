#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int M = 1024;
unsigned char map[M][M >> 3];

void Run(int t, int l, int s)
{
	int i, j, m;

	switch(getchar()){
	case 'W':
		for(i = t; i < t + s; ++i){
			for(j = l; j < l + s; ++j){
				map[i][j >> 3] &= ~(1 << (j & 7));
			}
		}
		break;
	case 'B':
		for(i = t; i < t + s; ++i){
			for(j = l; j < l + s; ++j){
				map[i][j >> 3] |= (1 << (j & 7));
			}
		}
		break;
	case 'Q':
		m = s >> 1;
		Run(t, l, m);
		Run(t, l + m, m);
		Run(t + m, l, m);
		Run(t + m, l + m, m);
		break;
	}
}

int main()
{
	int n, i, j;

	scanf("%d ", &n);
	Run(0,0,n);
	printf("#define quadtree_width %d\n", n);
	printf("#define quadtree_height %d\n", n);
	puts("static char quadtree_bits[] = {");

	for(i = 0; i < n; ++i){
		for(j = 0; j < (n >> 3); ++j){
			printf("0x%02x,",map[i][j]);
		}
		puts("");
	}
	puts("};");

	return 0;
}
