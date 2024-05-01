#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int r, l;
    cin >> r;  
    cin >> l;  
    vector<int> array = {r};  

    for (int i = 1; i < l; i++) {
        vector<int> new_array;
        int num = 0;
        int last = -1;

        for (int v : array) {
            if (v != last) {
                if (num != 0) {
                    new_array.push_back(num);
                    new_array.push_back(last);
                }
                num = 1;
            } else {
                num++;
            }
            last = v;
        }

        new_array.push_back(num);  
        new_array.push_back(last); 
        array = new_array;         
    }

    stringstream ss;
    for (int v : array) {
        ss << v << " ";
    }

    string result = ss.str();
    result.pop_back();  
    cout << result << endl;

    return 0;
}
