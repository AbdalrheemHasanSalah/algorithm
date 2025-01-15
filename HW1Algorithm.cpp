

#include <iostream>
#include<chrono>

using namespace std::chrono;


void sort(int* A, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (A[j] > A[j + 1])
			{
				int temp;
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				
				
			}

		}
	}

}
int Sequentialsearch(int A[],int size,int key) {
	for (int i = 0; i < size; i++) {
		if (A[i] == key)return i;
		
	}
	return 0;
}

 int bsearch(int L[],int i,int j,int key) {

	if (i <= j) {

		int k = (i + j) / 2;

		if (L[k] == key)
		{
			return k;
		}

			else if (L[k] < key)

				bsearch(L, k + 1, j, key);

			else if (L[k] > key)
				bsearch(L, i, k - 1, key);

	}

	return -1;

}	



int main()
{
	int size; 
	std::cout << "size is: ";
	std::cin >> size;

	int * A=new int[size];
	
	for (int i = 0; i < size; i++) {
		*(A+i)=rand()%(9-0+1)+0;
	}

	

	std::cout << std::endl;
	
	auto start_sequentialsearch = high_resolution_clock::now();

	std::cout << "sequential search is found in index : " << Sequentialsearch(A, size,10);

	auto stop_sequentialsearch = high_resolution_clock::now();


	double duration_sequentialsearch = std::chrono::duration_cast<std::chrono::microseconds>(stop_sequentialsearch - start_sequentialsearch).count();


	std::cout << std::endl;
	std::cout << "duration_sequentialsearch is " << duration_sequentialsearch << " microseconds ";
	std::cout << std::endl;
	std::cout << std::endl;
	
	auto start_sort = high_resolution_clock::now();

	sort(A, size);

	auto stop_sort = high_resolution_clock::now();


	double duration_sort =std::chrono::duration_cast<std::chrono::microseconds>(stop_sort - start_sort).count();
	
	std::cout << std::endl;
	std::cout <<"duration_sort is " << duration_sort << " microseconds ";
	std::cout << std::endl;
	
	std::cout << std::endl;

	

	auto start_bsearch = high_resolution_clock::now();


	std::cout<<"index is if found (bsearch):" << bsearch(A, 0, size, 10);



	auto stop_bsearch = high_resolution_clock::now();
	
	double duration_bsearch = std::chrono::duration_cast<std::chrono::microseconds>(stop_bsearch - start_bsearch).count();
	
	std::cout << std::endl;
	std::cout << "duration_bsearch is " << duration_bsearch << " microseconds ";
	std::cout << std::endl;
}

