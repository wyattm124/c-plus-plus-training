#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> NonEmpty(vector<string> v) {
  vector<string> newV(v.size());
  int cnt = 0;
  for(string s : v) {
    if(s != "")
      newV[cnt++] = s;
  }
  newV.resize(cnt);
  return newV;
}

void print (vector<string> v) {
  for(string s : v)
    std::cout << s << ", ";
  std::cout << std::endl;
}

int main() {
  vector<string> v1(10, "");
  v1[1] = "one";
  v1[5] = "two";
  v1[7] = "three";
  vector<string> v2{"uno", "dos", "tres", "quatro", "cinco", "ses"};
  vector<string> v3(7, "");
  std::cout << "vectors : " << std::endl;
  print(v1);
  print(v2);
  print(v3);
  vector<string> newV1 = NonEmpty(v1);
  vector<string> newV2 = NonEmpty(v2);
  vector<string> newV3 = NonEmpty(v3);
  std::cout << "new Vectors : " << std::endl;
  print(newV1);
  print(newV2);
  print(newV3);
  std::cout << "Test Done" << std::endl;
}
