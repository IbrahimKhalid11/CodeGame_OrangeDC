#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node{
    map<int, Node*>seq;
};

Node* head;
int cnt;
void add(string str){
     auto node = head;
     for (int i = 0; i < str.size(); i++) {
        int num=str[i]+'0';
        auto it = node->seq.find(num);
        if(it==node->seq.end()){
            node->seq[num] = new Node{};
            cnt++;
        }
        node = node->seq[num];
}
}
int main()
{
    int n;
    cnt = 0;
    head = new Node{};
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str; cin.ignore();
         add(str);
    }
    cout<<cnt<<endl;

}
