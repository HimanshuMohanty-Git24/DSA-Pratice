#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> PairIntInt;
typedef vector<PairIntInt> VectorPairIntInt;
typedef vector<ll> VectorInt;
typedef vector<VectorInt> VectorVectorInt;
typedef long long LongLong;

const int MAX_NUMBER = 1e6 + 5;

vector<int> primeNumbers;
bitset<MAX_NUMBER + 5> isPrime;
vector<int> smallestPrimeFactor(MAX_NUMBER + 5, 1e9);

void getPrimeNumbers() {
    iota(smallestPrimeFactor.begin(), smallestPrimeFactor.end(), 0);
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int number = 2; number <= sqrt(MAX_NUMBER) + 2; number++) {
        if (isPrime[number]) {
            primeNumbers.push_back(number);
            for (int multiple = number * number; multiple <= MAX_NUMBER; multiple += number) {
                isPrime[multiple] = 0;
                smallestPrimeFactor[multiple] = min(smallestPrimeFactor[multiple], number);
            }
        }
    }
    for (int number = sqrt(MAX_NUMBER) + 3; number < MAX_NUMBER; number++)
        if (isPrime[number])
            primeNumbers.push_back(number);
}

VectorInt prefixSumPrimes;

void sumOfN() {
    ll number;
    cin >> number;
    int index = upper_bound(primeNumbers.begin(), primeNumbers.end(), smallestPrimeFactor[number]) - primeNumbers.begin();
    index--;
    ll product = number * (prefixSumPrimes[index]);
    cout << product << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;
    getPrimeNumbers();
    prefixSumPrimes.assign(primeNumbers.size(), 0);
    for (int index = 0; index < primeNumbers.size(); index++) {
        prefixSumPrimes[index] = primeNumbers[index];
        if (index)
            prefixSumPrimes[index] += prefixSumPrimes[index - 1];
    }
    for (int testNo = 1; testNo <= totalTests; testNo++) {
        sumOfN();
    }
    return 0;
}