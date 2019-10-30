#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class TStack {
  T *arr;
  int size;
  int num;
public:
  TStack(int _size = 10000) {
    if (_size <= 0) throw _size;
    size = _size;
    arr = new T[size];
    num = -1;
  }
  TStack(const TStack& st) {
    size = st.size;
    arr = new T[size];
    num = st.num;
    for (int i = 0; i <= num; i++) arr[i] = st.arr[i];
  }
  TStack& operator= (const TStack& st) {
    if (this != &st) {
      delete[] arr;
      size = st.size;
      arr = new T[size];
      num = st.num;
      for (int i = 0; i <= num; i++) arr[i] = st.arr[i];
    }
    return *this;
  }
  bool IsEmpty()const {
    if (num == -1) return true;
    return false;
  }
  bool IsFull()const {
    if (num == size - 1) return true;
    return false;
  }
  void push(T el) {
    if (num == size - 1) throw num;
    else {
      arr[num + 1] = el;
      num++;
    }
  }
  T pop() {
    if (num == 0) throw num;
    else {
      num--;
      return arr[num + 1];
    }
  }
  T top() {
    if (num == size - 1) throw num;
    else {
      return arr[num + 1];
    }
  }
  void Clear() {
    num = -1;
  }
};

class Calculator {
  string expr, postfix;
  TStack<char> stc;
public:
  Calculator() :stc(50) {}
  void SetExpr(const string& _expr) {
    expr = _expr;
  }
  string GetExpr() {
    return expr;
  }
  bool CheckBrackets() const {
    stc.Clear();
    for (int i = 0; i < expr.size(); i++) {
      if (expr[i] == '(') stc.push('(');
      if (expr[i] == ')'){
        if (stc.IsEmpty) return false;
        stc.pop();
      }
      return stc.IsEmpty;
    }
  }
  int Prior(char c) {
    if (c == '(') return 0;
    if (c == '+') return 1;
    if (c == '-') return 1;
    if (c == '/') return 2;
    if (c == '*') return 2;
    if (c == '^') return 3;
  }
  void To_Postfix() {
    string str = "(";
    str += expr += ")";
    postfix = "";
    stc.Clear();
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(') stc.push('(') ;
      if (str[i] >= '0' && str[i] <= 9 || str[i] == '.') {
        char t = stc.pop();
        while (t != '(') {
          postfix += t;
          t = stc.pop();
        }
      }
    }
  }
};
