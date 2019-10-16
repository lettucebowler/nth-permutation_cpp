#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int find_factorial(int input) {
  int temp = 1;
  for(int i = 1; i <= input; i++) {
    temp *= i;
  }
  return temp;
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
  letters = input.length();\
  factorial = find_factorial(letters);
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

  vector<std::string> sorted2;
  for(int i = 0; i < sorted.size(); i++) {
    sorted2.push_back(sorted[i]);
  }

  int q = n - 1;
  for(int i = 0; i < sorted.size(); i++) {
    int index = q;
    index /= find_factorial(sorted2.size() - 1);
    index = index % sorted2.size();

    for(int i = 0; i < sorted2.size(); i++) {
      cout << sorted2[i];
    }
    cout << endl;
    cout << "index : " << index << endl;
    nperm += sorted2[index];
    if(index != 0) {
    sorted2.erase(sorted2.begin()+index);
    }
  }

  cout << n << "th permutation : " << nperm << endl;

  return 0;
}
