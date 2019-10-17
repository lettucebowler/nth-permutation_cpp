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

  string input;
  string nperm;
  int letters;
  int factorial;
  int partition;
  int n;
  vector<std::string> sorted;

  //Check for proper number of arguments
  if (argc < 3) {
		printf("Missing arguments!\n\n");
		printf("Usage: nth-permutation string n\n\n");
    cout << "String to permute : ";
    cin >> input;
    cout << "n : ";
    cin >> n;
	}

  //Take in input from arguments
  input = argv[1];
  letters = input.length();\
  factorial = find_factorial(letters);
  n = atoi(argv[2]);
  if(n > factorial || n < 1) {
    cout << "n out of bounds! mush be between " << 1 << " and " << factorial << "!" << endl;
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

  int q = n - 1;
  for(int i = 0; i < sorted.size(); i++) {
    //calculate index of next letter to add to nperm
    int index = q;
    index /= find_factorial(sorted2.size() - 1);
    index = index % sorted2.size();
    //add selected letter to string
    nperm += sorted2[index];
    //Erase used letter from list of available letters
    if(index != 0) {
    sorted2.erase(sorted2.begin() + index);
    }
    else {
      sorted2.erase(sorted2.begin());
    }
  }

  cout << n << "th permutation : " << nperm << endl;

  return 0;
}
