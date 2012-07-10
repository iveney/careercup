// Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees Can you do this in place?

#include <cstdio>
#include <cstdlib>

const int MAXINT = 10000;

void generate_image(int **im, int N) {
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			im[i][j] = rand() % MAXINT;
		}
	}
}

void print_image(int **im, int N) {
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			printf("%8d", im[i][j]);
		}
		printf("\n");
	}
}

// rotate the image clockwise 90 degrees in place
// idea: if we divide the image into four equal pieces 
// from the center, observe that we only need to traverse the 
// the top left part, and for each element, move it to the rotated space
// and do the same thing for the element in the rotated space and so on
// i.e., move the four elements clockwise.
// their indices can be precomputed.
// in the following: (i,j)->(i0,j0)->(i1,j1)->(i2,j2)->(i,j)
void rotate_image(int **im, int N) {
	int i, j;
	for(i = 0; i < (N)/2; i++) {
		// note that for odd N, don't rotate the elements in the center row
		for(j = 0; j < (N+1)/2; j++) {
			int i0 = j;
			int j0 = N - i - 1;
			int i1 = j0;
			int j1 = N - i0 - 1;
			int i2 = j1;
			int j2 = N - i1 - 1;
			int num = im[i][j];
			im[i][j] = im[i2][j2];
			im[i2][j2] = im[i1][j1];
			im[i1][j1] = im[i0][j0];
			im[i0][j0] = num;
		}
	}
}

int** allocate2D(int** &p, int N) {
	p = new int*[N];
	for(int i = 0; i < N; ++i)
	{
		p[i] = new int[N];
	}
	return p;
}

void release2D(int** p, int N) {
	for(int i = 0; i < N; ++i)
	{
		delete p[i];
	}
	delete p;
}

int main (int argc, char const *argv[])
{
	const int N = 7;
	int **im;
	
	im = allocate2D(im, N);
	generate_image(im, N);
	print_image(im, N);

	rotate_image(im, N);
	printf("\n");
	print_image(im, N);
	release2D(im, N);
	return 0;
}