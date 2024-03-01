#include <iostream>
#include <vector>

template<class Item>
int partion(Item a[], int l, int r) {
    int pivot = r;
    int j = l;

    for (int i = l; i < r; i++) {
        if (a[i] < a[pivot]) {
            std::swap(a[i], a[j]);
            j++;
        }
    }
    std::swap(a[j], a[pivot]);
    return j;
}

template<class Item>
void quicksort(Item a[], int l, int r) {
    if (l < r) {
        int i = partion(a, l, r);
        quicksort(a, l, i - 1);
        quicksort(a, i + 1, r);
    }
}

template <class Item>
void selectionsort(Item a[], int l, int r) {
    for (int i = l; i < r; i++) {
        int min = i;
        for (int j = i + 1; j < r; j++) {
            if (a[j] < a[min]) min = j;
        }
        std::swap(a[i], a[min]);
    }
}

template <class Item>
void bubblesort(Item a[], int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = i + 1; j < r; j++) {
            if (a[i] < a[j]) {
                std::swap(a[i], a[j]);
            }
        }
    }
}

template <class Item>
void printSortedArray(Item a[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}

template<class Item>
void fillArray(Item a[], int n) {
    std::cout << "Enter " << n << " elements: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
}



int main()
{
    std::cout << "Enter n: ";
    int n;
    std::cin >> n;
    int* a = new int[n];

    fillArray(a, n);
    quicksort(a, 0, n-1);
    //bubblesort(a, 0, n);
    //selectionsort(a, 0, n);
    printSortedArray(a, n);
}

