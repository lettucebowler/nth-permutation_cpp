#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char *argv[]) {

  if (argc < 3) {
		printf("Missing arguments!\n\n");
		printf("Usage: nth-permutation string n\n\n");
		return 1;
	}

  string input;
  int letters;
  int factorial;
  int n;
  vector<std::string> sorted;

  input = argv[1];
  cout << "input : " << input << endl;
  letters = input.length();
  factorial = 1;

  for(int k = 1; k <= n; k++) {
    factorial *= (k);
  }
  //cout << p << endl;
  n = atoi(argv[2]);
  cout << "n : " << n << endl;

  for(int i = 0; i < letters; i++) {
    string temp = "";
    temp += input[i];
    sorted.push_back(temp);
  }
  sort(sorted.begin(), sorted.end());

  return 0;
}
