#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>

using namespace std;

int main() {
    fstream input ("input.txt");
    if(input.fail()) {
        std::cout << "file not found\n";
    }
    string s;

    getline(input,s);

    unordered_multiset<char> res(s.begin(), s.end());
    s.clear();
    getline(input, s);
    input.close();
   

    for(auto i : s) {
        auto it = res.find(i);
        if(it != res.end()) {
            res.erase(it);
        }else{
            std::ofstream output("output.txt");
            output << i;
            output.close();
            break;
        }
    }


}

