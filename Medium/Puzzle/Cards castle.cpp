#include <iostream>
#include <vector>
#include <string>

using namespace std;

int height, weight;
vector<string> v;
bool stable(int i, int j) {

    if(v[i][j]=='/'){
         return (j != weight-1 && v[i][j+1] == '\\') &&(i == height-1 || v[i+1][j] == '\\');
    }else if(v[i][j]=='\\'){
        return (j != 0 && v[i][j-1] == '/') &&
                   (i == height-1 || v[i+1][j] == '/');
    }
    return true;
}

int main() {
    cin >> height;
    cin.ignore(); 
    weight = height * 2;
    v.resize(height);

    for (int i = 0; i < height; ++i) {
        getline(cin, v[i]);
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < weight; ++j) {
            if (!stable(i, j)) {
                cout << "UNSTABLE"<<endl;
               return 0;
            }
        }
    }

    cout << "STABLE"<<endl;
    return 0;
}
