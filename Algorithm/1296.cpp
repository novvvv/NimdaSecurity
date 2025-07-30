#include <iostream>
#include <string>
using namespace std;

string name;
int n;
string teams[51];

int count_char(const string& s, char ch) {
    int count = 0;
    for (char c : s) {
        if (c == ch) count++;
    }
    return count;
}

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> name;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> teams[i];
    }

    string best_team = "";
    int max_score = -1;

    for (int i = 0; i < n; i++) {
        string total = name + teams[i];

        int L = count_char(total, 'L');
        int O = count_char(total, 'O');
        int V = count_char(total, 'V');
        int E = count_char(total, 'E');

        int score = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

        if (score > max_score || (score == max_score && teams[i] < best_team)) {
            max_score = score;
            best_team = teams[i];
        }
    }

    cout << best_team << endl;
}
