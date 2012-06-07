// 1.6 Given an image represented by an NxN matrix, 
// where each pixel in the image is 4 bytes, write a 
// method to rotate the image by 90 degrees Can you do this in place?

const int MAX = 100;

// notice the case when n is odd or even
void rotate(short mat[][MAX], int n) {
	for(int i = 0; i <= (n-2)/2; ++i)
	{
		for(int j = 0; j <= (n-1)/2; ++j)
		{
			int p = i, q = j, v = mat[i][j];
			for(int k = 0; k < 4; ++k)
			{
				int s = n - q - 1, t = p;
				int tmp = mat[s][t];
				mat[s][t] = v;
				p = s;
				q = t;
				v = tmp;
			}
		}
	}
}

short mat[][MAX] = {
	{1, 2, 3, 4, },
	{5, 6, 7, 8, },
	{11, 12, 13, 14, },
	{15, 16, 17, 18}
};

void print_mat(short mat[][MAX], int n) {
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}
}

int main (int argc, char const *argv[])
{
	print_mat(mat, 4);
	printf("\n");
	rotate(mat, 4);
	print_mat(mat, 4);
	return 0;
}