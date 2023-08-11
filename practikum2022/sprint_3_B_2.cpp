#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Data {
    string name;
    int P;
    int F;
};

int partition(vector<Data>&datas, int low, int high) {
    int pivot = datas[high].P;

    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {
        if(datas[j].P <= pivot) {
            i++;
            swap(datas[i], datas[j]);
        }
    }
    swap(datas[i + 1], datas[high]);
    return (i + 1);
}

void quickSort(vector<Data>&datas, int low, int high) {
    if(low < high) {
        int pi = partition(datas, low, high);
        quickSort(datas, low, pi -1);
        quickSort(datas, pi + 1, high);
    }

    auto pa = make_pair((double )123,(float )123);

}

int main() {
    vector<Data>datas {
            {"alla", 4, 100},
            {"gena" ,0 ,1008},
            {"gosha", 2, 96},
            {"rica" ,2, 90 },
            {"timofey",  4, 80}
    };
    quickSort(datas, 0, datas.size() - 1);

    for(auto &it : datas) {
        std::cout << it.name << " " << it.P << " " << it.F << endl;
    }
}
