// Jonah Godfrey-Cornish
// Assignment 2

//This is a note, the 5 and 3 at the top of the input.txt file represent 5 processes and 3 resource types
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool canProceed(const vector<int>& need, const vector<int>& work) {
    for (size_t j = 0; j < need.size(); ++j) {
        if (need[j] > work[j]) {
            return false;
        }
    }

    return true;
}

void printVector(const vector<int>& v, const string& name) {
    cout << name << ": [";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << '\n';
}

void printMatrix(const vector<vector<int>>& m, const string& name) {
    cout << name << ":\n";
    for (size_t i = 0; i < m.size(); ++i) {
        cout << "P" << i << ": [";
        for (size_t j = 0; j < m[i].size(); ++j) {
            cout << m[i][j];
            if (j < m[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << '\n';
    }
}

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "Error opening input.txt" << '\n';
        return 1;
    }

    int n, m;
    fin >> n >> m;

    vector<vector<int>> Allocation(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) {
            fin >> Allocation[i][j];
        }
    }
    printMatrix(Allocation, "Allocation");

    vector<vector<int>> Max(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fin >> Max[i][j];
        }
    }
    printMatrix(Max, "Max");

    vector<int> Available(m);
    for (int j = 0; j < m; ++j) {
        fin >> Available[j];
    }
    fin.close();
    printVector(Available, "Available");

    vector<vector<int>> Need(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    vector<int> Work = Available;
    vector<bool> Finish(n, false);
    vector<int> safeSequence;

    bool found;
    do {
        found = false;
        for (int i = 0; i < n; ++i) {
            if (!Finish[i] && canProceed(Need[i], Work)) {
                for (int j = 0; j < m; ++j) {
                    Work[j] += Allocation[i][j];
                }
                Finish[i] = true;
                safeSequence.push_back(i);
                found = true;
                break;
            }
        }
    } while (found);

    bool isSafe = true;
    for (bool f : Finish) {
        if (!f) {
            isSafe = false;
            break;
        }
    }

    if (isSafe) {
        cout << "The system is in a safe state, the safe sequence is: ";
        for (size_t i = 0; i < safeSequence.size(); ++i) {
            cout << "P" << safeSequence[i];
            if (i < safeSequence.size() - 1) {
                cout << ", ";
            }
        }
        cout << '\n';
    }

    else {
        cout << "The system is not in a safe state" << endl;
    }

    return 0;
}