#include <iostream>
#include <cstdlib>

void allocate_mem(int*** arr, int n, int m)
{
  *arr = (int**)malloc(n*sizeof(int*));
  for(int i=0; i<n; i++)
    (*arr)[i] = (int*)malloc(m*sizeof(int));
}  

void input(int** mt, int m, int n) {
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			std::cin >> *(*(mt+i)+j);
		}
	}
}

void output(int** mt, int m, int n) {
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			std::cout << *(*(mt+i)+j);
		}
		std::cout << std::endl;
	}
}

int process(int** mt, int m, int n) {
	return 1;
}

void free_mem(int*** arr, int n){
    for (int i = 0; i < n; i++)
        free((*arr)[i]);
    free(*arr); 
}

int main () {
// 	int m, n, ***mt;
//     //std::cout << "Enter m, n = " << std::endl;
//     //std::cin >> m >> n;
//     m = 3;
//     n = 5;
//     allocate_mem(mt, m, n);

// //    printf("The sum of all even elements is %d", process(mt, m, n));
//     free_mem(mt, m);
// 	return 0;
	
	printf("Hello world");
}