/*
 * Ahmed Amine Boustani
 * Check whether a given number is prime using Sieve of Eratosthenes
 * Compile using g++ -std=c++11 -o isprime isprime.cc && ./isprime [number]
 *
 */

#include <string.h>
#include <iostream>
#include <set>

using namespace std;

bool prime[123456];
set<int> primes;

void Usage(void) {
  fprintf(stderr, "usage: isprime [integer]\n");
  exit(EXIT_FAILURE);
}

bool isPrime(int number) {
    return primes.find(number) != primes.end();
}

void SieveOfEratosthenes(int n) {
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
       if (prime[p])
          primes.insert(p);
}

int main(int argc, char** argv) {
    if (argc < 2)
        Usage();
    SieveOfEratosthenes(123455);
    cout << (isPrime(atoi(argv[1])) ? "YES" : "NO") << endl;
    return 0;
}
