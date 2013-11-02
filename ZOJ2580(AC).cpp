#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int hi[9][10];
int hj[9][10];
int hb[3][3][10];
int m[9][9];
int mc;
bool suc;

void dfs()
{
	int i, j, k;

	if(suc){
		return;
	}

	if(mc == 0){
		suc = true;
		return;
	}

	for(i = 0; i < 9; ++i){
		for(j = 0; j < 9; ++j){
			if(m[i][j]){
				continue;
			}
			for(k = 9; k >= 1; --k){
				if(hi[i][k] || hj[j][k] || hb[i / 3][j / 3][k]){
					continue;
				}else{
					hi[i][k] = 1;
					hj[j][k] = 1;
					hb[i / 3][j / 3][k] = 1;
					m[i][j] = k;
					--mc;
					dfs();
					if(!suc){
						++mc;
						m[i][j] = 0;
						hi[i][k] = 0;
						hj[j][k] = 0;
						hb[i / 3][j / 3][k] = 0;
					}else{
						return;
					}
				}
			}
			if(k <= 0){
				//some contradiction is detected
				return;
			}
		}
	}
}

int main()
{
	int i, j, k;
	int t, ti;
	char s[20];

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			memset(m, 0, 9 * 9 * sizeof(int));
			for(i = 0; i < 9; ++i){
				scanf("%s", s);
				for(j = 0; j < 9; ++j){
					m[i][j] = s[j] - '0';
				}
			}

			memset(hi, 0, 9 * 10 * sizeof(int));
			memset(hj, 0, 9 * 10 * sizeof(int));
			memset(hb, 0, 3 * 3 * 10 * sizeof(int));
			mc = 0;
			for(i = 0; i < 9; ++i){
				for(j = 0; j < 9; ++j){
					if(m[i][j]){
						hi[i][m[i][j]] = 1;
						hj[j][m[i][j]] = 1;
						hb[i / 3][j / 3][m[i][j]] = 1;
					}else{
						++mc;
					}
				}
			}

			if(mc == 0){
				suc = true;
				for(i = 0; i < 9; ++i){
					for(j = 0; j < 9; ++j){
						printf("%d",  m[i][j]);
					}
					printf("\n");
				}
				continue;
			}

			suc = false;
			for(i = 0; i < 9; ++i){
				for(j = 0; j < 9; ++j){
					if(m[i][j]){
						continue;
					}
					for(k = 9; k >= 1; --k){
						if(hi[i][k] || hj[j][k] || hb[i / 3][j / 3][k]){
							continue;
						}else{
							hi[i][k] = 1;
							hj[j][k] = 1;
							hb[i / 3][j / 3][k] = 1;
							m[i][j] = k;
							--mc;
							dfs();
							if(!suc){
								++mc;
								m[i][j] = 0;
								hi[i][k] = 0;
								hj[j][k] = 0;
								hb[i / 3][j / 3][k] = 0;
							}
						}

						if(suc){
							break;
						}
					}

					if(suc){
						break;
					}
				}

				if(suc){
					break;
				}
			}

			for(i = 0; i < 9; ++i){
				for(j = 0; j < 9; ++j){
					printf("%d",  m[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}

