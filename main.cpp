#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int findDifference(string b, string a){
  int x = b.length();
  char arrb[x+1];

  strcpy(arrb, b.c_str());

  int y = a.length();
  char arra[x+1];
  strcpy(arra, a.c_str());

  int sum=0;

  for(int i=0; i < x+1 || i < y+1; ++i){
    sum += abs(arrb[i] - arra[i]);
  }
  return sum;
}

int dictionary(string x) {
  ifstream inFile;
  inFile.open("dictionary");

  string arr[58110];
  int a = 10000;

  for(int i = 0; i != 58110; ++i){
    inFile >> arr[i];

    if(findDifference(x, arr[i]) < a){
      a = findDifference(x, arr[i]);
    }
  }
  int g=0;
  for(int i = 0; i != 58110; ++i){
    if(findDifference(x, arr[i]) < a+3){
      if(g!=0){
        cout << " or ";
      }
      g++;
      cout << arr[i];
    }
  }
  return 0;
}

int main(){
  string a;
  cin >> a;

  dictionary(a);
  return 0;
}