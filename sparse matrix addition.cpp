#include <iostream>
#include <vector>
using namespace std;
struct Element {
    int row;
    int col;
    int value;
};

  vector<Element> add_sparse_matrices(const vector<Element>& A, const vector<Element>& B) {
    vector<Element> result;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result.push_back(A[i]);
            i++;
        } else if (A[i].row > B[j].row || (A[i].row == B[j].row && A[i].col > B[j].col)) {
            result.push_back(B[j]);
            j++;
        } else {
            Element sum;
            sum.row = A[i].row;
            sum.col = A[i].col;
            sum.value = A[i].value + B[j].value;
            result.push_back(sum);
            i++;
            j++;
        }
    }

    while (i < A.size()) {
        result.push_back(A[i]);
        i++;
    }

    while (j < B.size()) {
        result.push_back(B[j]);
        j++;
    }

    return result;
}

int main() {
    
    int numElements;
    
       
    cin >> numElements;

    vector<Element> A;
    for (int i = 0; i < numElements; i++) {
        Element elem;
        cin >> elem.row >> elem.col >> elem.value;
        A.push_back(elem);
    }

    cin >> numElements;

    vector<Element> B;
    for (int i = 0; i < numElements; i++) {
        Element elem;
        cin >> elem.row >> elem.col >> elem.value;
        B.push_back(elem);
    }
 

    std::vector<Element> result = add_sparse_matrices(A, B);
    cout<<result.size()<<endl;

    for (const auto& elem : result) {
        std::cout << elem.row << "\t" << elem.col << "\t " << elem.value << endl;
    }

    return 0;
}
