#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Newspaper {
public:string name;
public:vector<double> price;
public:double totalPrice;

public:Newspaper(string name, vector<double> price) {
        this->name = name;
        this->price = price;
        for (double price : price) {
            this->totalPrice += price;
        }
    }
};

class ActiveNewspapers {
public:vector<Newspaper> newspaperList;
public:map<string, double> newspaperNameToPriceMap;

public:ActiveNewspapers(vector<Newspaper> newspaperList) {
        this->newspaperList = newspaperList;
        for (Newspaper newspaper : newspaperList) {
            double price = 0.0;
            for (double newspaperPrice : newspaper.price) {
                price += newspaperPrice;
            }
            newspaperNameToPriceMap[newspaper.name] = price;
        }
    }

public:void availableNewspapers(int budget){
    vector<pair<string, string>> pairs;
    for (int i = 0; i < newspaperList.size(); i++) {
        for (int j = i + 1; j < newspaperList.size(); j++) {
            if (newspaperList.at(i).totalPrice + newspaperList.at(j).totalPrice <= budget) {
                pairs.push_back(make_pair(newspaperList.at(i).name, newspaperList.at(j).name));
            }
        }
    }
    cout << "Available Papers : " << endl;
    for (pair<string, string> pair : pairs) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

};

int main() {
    Newspaper toi("TOI", {3,3,3,3,3,5,6});
    Newspaper hindu("Hindu", {2.5,2.5,2.5,2.5,2.5,4,4});
    Newspaper et("ET", {4,4,4,4,4,4,10});
    Newspaper bm("BM", {1.5,1.5,1.5,1.5,1.5,1.5,1.5});
    Newspaper ht("HT", {2,2,2,2,2,4,4});

    ActiveNewspapers activeNewspapers({toi, hindu, et, bm, ht});

    cout << "Enter Your Budget : ";
    int budget;
    cin >> budget;

    activeNewspapers.availableNewspapers(budget);

    return 0;
}
