#!/bin/python

import sys

def minimumNumber(n, password):
    TypesDict = {"digits": 0, "upper": 0, "lower": 0, "special": 0}
    specialchars = "!@#$%^&*()-+"
    for char in password:
        if char.isdigit():
            TypesDict["digits"]+=1
        if char.islower():
            TypesDict["lower"]+=1
        if char.isupper():
            TypesDict["upper"]+=1
        elif char in specialchars :
            TypesDict["special"]+=1
    cnt = 0
    for i in TypesDict.values():
        if i < 1:
            cnt+=1
    return max(6-n, cnt)

if __name__ == "__main__":
    n = int(raw_input().strip())
    password = raw_input().strip()
    answer = minimumNumber(n, password)
    print answer

    
    
    
#!/bin/python3

import sys

numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"

def minimumNumber(n, password):
    add = 0
    if all(n not in password for n in numbers):
        add += 1

    if all(l not in password for l in lower_case):
        add += 1

    if all(u not in password for u in upper_case):
        add += 1
    if all(s not in password for s in special_characters):
        add += 1
        
    return add + max(0, 6 - len(password) - add)

if __name__ == "__main__":
    n = int(input().strip())
    password = input().strip()
    answer = minimumNumber(n, password)
    print(answer)
    
    
    
    
    
#include <bits/stdc++.h>

using namespace std;

int check(string s, string w) {
  for (char c : s) {
    if (w.find(c) != string::npos) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string numbers = "0123456789";
  string lower_case = "abcdefghijklmnopqrstuvwxyz";
  string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string special_characters = "!@#$%^&*()-+";
  int ans = 0;
  ans += check(s, numbers);
  ans += check(s, lower_case);
  ans += check(s, upper_case);
  ans += check(s, special_characters);
  ans = max(ans, 6 - n);
  printf("%d\n", ans);
  return 0;
}
    
