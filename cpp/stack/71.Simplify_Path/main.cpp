#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

string simplifyPath(string path) {
  vector<string> pieces;
  string temp = "";
  for (int i = 0; i < path.size(); i++) {
    if (path[i] == '/') {
      pieces.push_back(temp);
      temp = "";
    } else {
      temp += path[i];
      if (i == path.size() - 1) {
        pieces.push_back(temp);
      }
    }
  }

  vector<string> string_stack;
  for (string piece : pieces) {
    if (piece == "." || piece == "") continue;
    if (piece == "..") {
      if (!string_stack.empty()) {
        string_stack.pop_back();
      } else {
        continue;
      }
    } else {
      string_stack.push_back(piece);
    }
  }

  string result = "";
  for (string s : string_stack) {
    if (s != "") {
      result += "/" + s;
    }
  }
  if (result == "") result = "/";
  return result;
}

int main() {
  string path = "/.../a/../b/c/../d/./";
  cout << simplifyPath(path) << endl;
  return 0;
}