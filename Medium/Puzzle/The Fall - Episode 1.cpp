#include <iostream>
#include <vector>
using namespace std;

pair<int, int> next_position(int x, int y, string pos, int room_type) {
    if (room_type == 0) {
        return {x, y};  
    }
    if (room_type == 1) {
        return {x, y + 1};
    }
    if (room_type == 2 || room_type == 6) {
        if (pos == "LEFT") {
            return {x + 1, y};
        } else if (pos == "RIGHT") {
            return {x - 1, y};
        }
    }
    if (room_type == 3) {
        if (pos == "TOP") {
            return {x, y + 1};
        }
    }
    if (room_type == 4) {
        if (pos == "TOP") {
            return {x - 1, y};
        } else if (pos == "RIGHT") {
            return {x, y + 1};
        }
    }
    if (room_type == 5) {
        if (pos == "TOP") {
            return {x + 1, y};
        } else if (pos == "LEFT") {
            return {x, y + 1};
        }
    }
    if (room_type == 7 || room_type == 8 || room_type == 9 || room_type == 12 || room_type == 13) {
        return {x, y + 1};
    }
    if (room_type == 10) {
        return {x - 1, y};
    }
    if (room_type == 11) {
        return {x + 1, y};
    }
    return {x, y}; 
}

int main() {
    int w, h;
    cin >> w >> h;
    
    vector<vector<int>> grid(h, vector<int>(w));
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    string ignore;
    getline(cin, ignore);
    getline(cin, ignore);
    
    while (true) {
        int xi, yi;
        string pos;
        cin >> xi >> yi >> pos;
        
        int room_type = grid[yi][xi];
        pair<int, int> next = next_position(xi, yi, pos, room_type);
        
        cout << next.first << " " << next.second << endl;
    }
    
    return 0;
}
