#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void calculateSwappedSums(string num, vector<int> &permutations) {
    sort(num.begin(), num.end()); //sorts the number, ex 93148 becomes 13489
    do {
        permutations.push_back(stoi(num)); //adds permutation to the vector of permutaitions
    } while (next_permutation(num.begin(), num.end())); // finds the next permutation of the number 
}

int main() {
    auto start = high_resolution_clock::now(); 
    bool obtained [1000001] = {false}; //set all permutations to not found

    for (int i = 10; i <= 1000000; ++i) {
        vector<int> permutations; 
        calculateSwappedSums(to_string(i), permutations);
        for (auto permutation : permutations){ //for every permutation of some number
            if (permutation + i <= 1000000) { //s.t. the swapped sum is less than 1 mil
                obtained[permutation + i] = true; //say that you found the swapped sum
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time to calculate: " << float(duration.count())/1000 << " seconds" << endl; //time to execute

    //prints to txt file
    ofstream myfile;
    myfile.open ("impossiblesums.txt");
    for (int i = 10; i <= 1000000; ++i) {
        if (!obtained[i]) {
            myfile << i << endl;
        }
    }
    myfile.close();

    return 0;
}