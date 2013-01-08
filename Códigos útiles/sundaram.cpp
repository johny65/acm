#include <iostream>
#include <vector>
	
int const N = 100; // Generate the primes up to 2*N

int main() {
	std::vector<bool> l(N,true);
	for (int j=1;;++j) {
		int k=1+3*j;
		if (k>=N)
			break;
		do {
			l[k] = false;
			k += 2*j+1;
		} while (k<N);
	}
	
	for (int i=1; i<N; ++i) {
		if (l[i])
			std::cout << (2*i+1) << '\n';
	}
}


