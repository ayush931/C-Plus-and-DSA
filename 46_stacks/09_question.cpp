// remove at bottom

#include <bits/stdc++.h>
using namespace std;

void removeAtBottom(stack<int> &st) {
  stack<int> temp;
  int size = st.size();
  int count = 0;

  while (st.size() != 1) {
    int curr = st.top();
    st.pop();
    temp.push(curr);
  }

  st.pop();

  while (not temp.empty()) {
    int curr = temp.top();
    temp.pop();
    st.push(curr);
  }
}

int main() {
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);

  removeAtBottom(st);

  while (not st.empty()) {
    int curr = st.top();
    st.pop();
    cout << curr << endl;
  }

  return 0;
}
