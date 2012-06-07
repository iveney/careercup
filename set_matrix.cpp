// 1.7 Write an algorithm such that if an element in an MxN matrix is 0,
// its entire row and column is set to 0
const int MAX = 100;

void set_matrix(int mat[][MAX], int m, int n) {
	int *rows = new int[m];
	int *cols = new int[n];
	memset(rows, 0, m * sizeof(int));
	memset(cols, 0, n * sizeof(int));
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(mat[i][j] == 0) {
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}
	
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(rows[i] == 1 || cols[j] == 1)
			{
				mat[i][j] = 0;
			}
		}
	}	
}

void print_mat(int mat[][MAX], int m, int n) {
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}
}

int mat[][MAX] = {
	{1, 0, 1},
	{1, 3, 0},
	{4, 5, 7},
	{7, 8, 9}
};

int main (int argc, char const *argv[])
{
	int m = 4, n = 3;
	print_mat(mat, m, n);
	set_matrix(mat, m, n);
	print_mat(mat, m, n);
	return 0;
}