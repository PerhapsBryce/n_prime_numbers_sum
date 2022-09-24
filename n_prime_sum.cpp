#include <iostream>;
#include <vector>;

int IsPrimeNumber(int numberToCheck, const std::vector<int>& rPrimeNumbers) 
{
	for (auto currentPrime : rPrimeNumbers)
	{
		if (numberToCheck % currentPrime == 0) 
		{
			return 0;
		}
		if (currentPrime > (numberToCheck / 2)) 
		{
			break;
		}
	}

	return 1;
}

std::vector<int> GeneratePrimeNumbers(int size) 
{
	std::vector<int> primeNumbers;
	primeNumbers.push_back(2);

	//check all odd numbers starting with 5
	for (int currentNumber = 3; primeNumbers.size() < size; currentNumber += 2)
	{
		if (IsPrimeNumber(currentNumber, primeNumbers)) 
		{
			primeNumbers.push_back(currentNumber);
		}
	}

	return primeNumbers;
}

int SumVectorInt(const std::vector<int>& rVectorToSum) 
{
	int sum = 0;
	for (auto currentValue : rVectorToSum)
	{
		sum += currentValue;
	}

	return sum;
}

int main() 
{
	//Prompt for prime number vector size
	int userSize;
	std::cin >> userSize;

	//generate and sum prime numbers, print result to console
	std::vector<int> primeNumbers = GeneratePrimeNumbers(userSize);
	std::cout << SumVectorInt(primeNumbers);

	return 0;
}