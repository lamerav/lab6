#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <random>
#include <set>

using namespace std;


int main() {
    random_device rd;

    unordered_multimap<int, std::string> unmap;

    for (int i; i < 5; i++){
        unmap.insert({rd()%100 - 50, to_string(rd()%100 - 50)});
    }

    std::map<int, std::string> map;

    cout << "First task:" << endl;

    unmap.erase(5);
    unmap.erase(8);
    unmap.insert({2, "One"});
    unmap.insert({2, "Two"});

    int n = 0;

    for (auto i: unmap) {
        n++;
        map.insert({n, i.second});
    }
    for (auto i : map) {
        cout << i.first << " " << i.second;
    }
    cout << endl;

    cout << "Second task:" << endl;

    n = count_if(map.begin(), map.end(), [](pair<int, string> i){return (i.first < 3);});
    cout << n << endl;
    vector<int> m(map.size());
    transform(map.begin(), map.end(), m.begin(), [](pair<int, string> i){return (i.first);});
    for (auto i: m){
        cout << i << " ";
    }
    cout << endl;

    cout << "Third task:" << endl;
    cout << find(m.begin(), m.end(), 2) - m.begin() << endl;
    sort(m.begin(), m.end());
    list<int> l;
    for (auto i: m){
        l.push_back(i);
    }

    cout << "Fourth task:" << endl;

    replace_if(l.begin(), l.end(),[](int i){ return (i < 0);}, 10);
    l.sort(std::greater<int>());
    set<int> s_m;
    for (int i: l){
        s_m.insert(i);
    }

    if (s_m.find(6) != end(s_m)){
        cout << "True" << endl;
    }
    else{
        cout << "False";
    }

    for_each(s_m.begin(), s_m.end(), [](int i){cout << i;});

    return 0;
}
