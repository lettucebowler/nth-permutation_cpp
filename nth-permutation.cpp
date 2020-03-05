#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long find_factorial(int input) {
  unsigned long long temp = 1;
  for(int i = 1; i <= input; i++) {
    temp *= i;
  }
  return temp;
}

int main(int argc, char *argv[]) {
  string input;
  string nperm;
  int letters;
  unsigned long long factorial;
  unsigned long long partition;
  unsigned long long n;
  vector<std::string> sorted;

  //Check for proper number of arguments
  if (argc < 3) {
		cout << "Missing arguments!" << endl;
		cout << "Usage: nth-permutation string n" << endl;
    cout << "This program can't properly compute results with repeat letters"
         << endl;
    cout << "String to permute : ";
    cin >> input;
    cout << "n : ";
    cin >> n;
	}
  //Poplate variables with command-line arguments
  else {
    input = argv[1];
    // n = (unsigned long long)atoi(argv[2]);
    sscanf(argv[2], "%llu", &n);
  }

  //Take in input from arguments
  letters = input.length();\
  factorial = find_factorial(letters);

  if(n > factorial || n < 1) {
    cout << "n out of bounds! mush be and integer between " << 1
         << " and " << factorial << "!" << endl;
    return 0;
  }

  //convert string into vector of single-character strings
  for(int i = 0; i < letters; i++) {
    string temp = "";
    temp += input[i];
    sorted.push_back(temp);
  }

  //Prepare data for use
  sort(sorted.begin(), sorted.end());
  partition = factorial;
  vector<std::string> sorted2;
  for(int i = 0; i < sorted.size(); i++) {
    sorted2.push_back(sorted[i]);
  }

  //Find next letter in the specified permutation, add it to the end,
  //and remove that letter from the list of available letters.
  int q = n - 1;
  for(int i = 0; i < sorted.size(); i++) {
    int index = q;
    index /= find_factorial(sorted2.size() - 1);
    index = index % sorted2.size();
    nperm += sorted2[index];
    sorted2.erase(sorted2.begin() + index);
  }

  cout << n << "th permutation : " << nperm << endl;
  return 0;
}
