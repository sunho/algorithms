#include <algorithm>
#include <iostream>

using namespace std;

bool check(string s) {
    int open = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s.c_str()[i] == '(') {
            open ++;
        } else if (s.c_str()[i] == ')') {
            if (open <= 0) {
                return false;
            }
            open --;
        }
    }
    return open == 0;
}

bool solve(int i, string s, string rem) {
    if (s.c_str()[i] == ')') {
        return solve(i+1, s, rem +")");
    }
     if (s.c_str()[i] == '(') {
        return solve(i+1, s, rem +"(");
    }
    if (i == s.size()) {
        return check(rem);
    }
    int count = 0;
    for (; i < s.size(); ++i) {
        char c = s.c_str()[i];
        if (c != '?') {
            break;
        } else {
            ++count;
        }
    }
    if (count % 2 == 0) {
        if (solve(i, s, rem + "((")) {
            return true;
        }
        if (solve(i, s, rem + "))")) {
            return true;
        }
        if (solve(i, s, rem)) {
            return true;
        }
    } else {
        if (solve(i, s, rem + "(")) {
            return true;
        }
        if (solve(i, s, rem + ")")) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // when ),
        //  open > 0
        // at the end open == 0
        // when ?,
        //   if ( open ++
        //   if ) 
        // ()()(
        // ? even -> open += 2*n or open -= 1*n open += 0
        //  ()()
        // )()
        // ? odd ->  open += 1*n or open -= 1*n
        // ???|)|???|(|?
        // a | ) | b | ( | c
        // a 
        if (solve(0, s, "")) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}