#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

string nthletter(int partition, vector<std::string> sorted, int t, string nperm) {
  int i = 0;
  int k = 0;
  int index = sorted.size() - nperm.length();
  while()
}

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
  // cout << "input : " << input << endl;
  letters = input.length();
  factorial = 1;

  for(int k = 1; k <= letters; k++) {
    factorial *= (k);
  }
  //cout << p << endl;
  n = atoi(argv[2]);
  if(n > factorial || n < 1) {
    cout << "n out of bounds! mush be between " << 1 << " and " << factorial << "!" << endl;
    return 0;
  }
  // cout << "n : " << n << endl;

  for(int i = 0; i < letters; i++) {
    string temp = "";
    temp += input[i];
    sorted.push_back(temp);
  }
  sort(sorted.begin(), sorted.end());


  int partition = factorial;
  string nperm;
  for(int i = 0; i < sorted.size(); i++) {
    partition /= (letters - i)
    int t = n / partition;
    nperm += nthletter(partition, sorted, t, nperm);
  }

  cout << n << "th permutation : " << nperm << endl;

  return 0;
}
