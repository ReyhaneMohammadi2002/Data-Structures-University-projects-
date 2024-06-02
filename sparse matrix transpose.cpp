#include <iostream>
#include <vector>
#include <algorithm> // ÈÑÇí ÇÓÊİÇÏå ÇÒ ÊÇÈÚ std::sort

struct Element {
    int row;
    int col;
    int value;
};

// ÊÇÈÚ ãŞÇíÓå ÈÑÇí ÇÓÊİÇÏå ÏÑ ÊÇÈÚ std::sort
bool compareElements(const Element& elem1, const Element& elem2) {
    if (elem1.row < elem2.row) {
        return true;
    } else if (elem1.row == elem2.row) {
        return elem1.col < elem2.col;
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Element> sparseMatrix;
    for (int i = 0; i < n; i++) {
        Element elem;
        std::cin >> elem.row >> elem.col >> elem.value;
        sparseMatrix.push_back(elem);
    }

    // ãÍÇÓÈå ÊÑÇäåÇÏå ãÇÊÑíÓ ÎáæÊ
    std::vector<Element> transposedSparseMatrix;
    for (const auto& elem : sparseMatrix) {
        Element transposedElem;
        transposedElem.row = elem.col;
        transposedElem.col = elem.row;
        transposedElem.value = elem.value;
        transposedSparseMatrix.push_back(transposedElem);
    }

    // ãÑÊÈÓÇÒí ãÇÊÑíÓ ÊÑÇäåÇÏå Èå ÊÑÊíÈ ÕÚæÏí
    std::sort(transposedSparseMatrix.begin(), transposedSparseMatrix.end(), compareElements);

    // Ç ãÇÊÑíÓ ÊÑÇäåÇÏå ãÑÊÈ ÔÏå
    for (const auto& elem : transposedSparseMatrix) {
        std::cout << elem.row << " " << elem.col << " " << elem.value << std::endl;
    }

    return 0;
}
