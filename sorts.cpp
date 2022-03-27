#include <algorithm>
#include <random>
#include <gtest/gtest.h>
#include <array>

#pragma once
#ifndef EXAMPLE_POPOPO_H
#define EXAMPLE_POPOPO_H

#endif //EXAMPLE_POPOPO_H



class SortTest : public ::testing::Test {
protected:
    void SetUp() override {
        Test::SetUp();
        auto gen = [this]() {
            return number_distance(mercenne_engine);
        };
        arr_10.resize(10);
        arr_100.resize(100);
        arr_1000.resize(1000);
        arr_10000.resize(10000);
        arr_100000.resize(100000);
        arr_250000.resize(250000);
        std::generate(arr_10.begin(), arr_10.end(), gen);
        std::generate(arr_100.begin(), arr_100.end(), gen);
        std::generate(arr_1000.begin(), arr_1000.end(), gen);
        std::generate(arr_10000.begin(), arr_10000.end(), gen);
        std::generate(arr_100000.begin(), arr_100000.end(), gen);
        std::generate(arr_250000.begin(), arr_250000.end(), gen);
    }
    void TearDown() override {
        Test::TearDown();
    }
public:
    std::vector<int> arr_10;
    std::vector<int> arr_100;
    std::vector<int> arr_1000;
    std::vector<int> arr_10000;
    std::vector<int> arr_100000;
    std::vector<int> arr_250000;
    std::vector<void *> arrays{&arr_10, &arr_100, &arr_1000, &arr_10000, &arr_10000, &arr_250000};
//
private:
    std::random_device rnd_device;
    std::mt19937 mercenne_engine{rnd_device()};
    std::uniform_int_distribution<int> number_distance{1, 1000000};
};


template <typename T>
void swap(T &num1, T &num2) {
    T k = num1;
    num1 = num2;
    num2 = k;
};

//            size_t a_length = a.size();
//            int key, i;
//            int j = 1;
//            for (int j = 1; j < a_length ; ++j) {
//                key = a[j];
//                i = j - 1;
//                while (i >= 0 && a[i] > key) {
//                    swap(a[i], a[i+1]);
//                    i--;
//                }
//            }
//            for (int i = 0; i < a_length; i++) std::cout << a[i] << " " ;

///insertion already
template <typename T>
void insertion_sort(T &array, size_t size) {
    int i, j;
    typeof(array[size-1])key;
    for (i = 1; i < size; ++i) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

///функция которая берет число стоящему на position_min и ставит его на позицию final_position_min
///смещая все числа впереди указанного на 1 позицию вперед
template <typename T>
void min_to_up__others_down (T& array, int position_min, int final_position_min) {
    int i = position_min;
    typeof(array[i]) min = array[i];
    int j = final_position_min;
    i--;
    while (i>=j) {
        array[i+1] = array[i];
        i--;
    }
    array[j] = min;
}

///puziryok
template <typename T>
void puzir_sort(T &array, size_t size){
    ///ищем максимальное число чтобы избежать проблем с минимальным
    typeof(array[size-1]) max = array[0];
    for (int k = 0; k < size - 1; k++) {
        if(size==1) break;
        if((array[k] <= array[k+1]) && (max <= array[k+1])) max = array[k+1];
    }
    typeof(max) min = max+1;
    int min_pos = 0;
    int j = 0;
    int i = 0;
    ///реализация бабл сорт
    while (j < size) {
        while ( i < size) {
            if (array[i] < min) {
                min = array[i];
                min_pos = i;
            }
            i++;
        }
        min_to_up__others_down(array,min_pos,j);
        min = max+1;
        min_pos = 0;
        i = j + 1;
        j++;
    }
}


//void merge_sort(int* array, size_t size){
//
//}

template<typename SomeIterator>
void merge_sort(SomeIterator begin, SomeIterator end) {
    size_t size = std::distance(begin, end);
    if (size > 1) {
        size_t left_size = size / 2;
        size_t right_size = size - left_size;
        SomeIterator sep = begin;
        std::advance(begin, left_size);
        merge_sort(sep, begin);
        merge_sort(begin, end);
        std::advance(begin, -left_size);
        size_t lindex = 0, rindex = left_size, index = 0;
        SomeIterator *tmp_array = new SomeIterator[size];
        while (lindex < left_size || rindex < size) {
            std::advance(begin, lindex);
            SomeIterator lin = begin;
            std::advance(begin, -lindex);
            std::advance(begin, rindex);
            SomeIterator rin = begin;
            std::advance(begin, -rindex);
            if (*lin < *rin) {
                std::advance(begin, lindex);
                tmp_array[index++] = begin;
                std::advance(begin, -lindex);
                ++lindex;
            } else {
                std::advance(begin, rindex);
                tmp_array[index++] = begin;
                std::advance(begin, -rindex);
                ++rindex;
            }
            if (lindex == left_size) {
                for (size_t i = rindex; i < size; i++) {
                    std::advance(begin, i);
                    tmp_array[index++] = begin;
                    std::advance(begin, -i);
                }
                break;
            }
            if (rindex == size) {
                for (size_t i = lindex; i < left_size; i++) {
                    std::advance(begin, i);
                    tmp_array[index++] = begin;
                    std::advance(begin, -i);
                }
                break;
            }
        }
        std::vector<typeof(*begin)> tmp_array2;
        tmp_array2.resize(size);
        for (int i = 0; i < size; ++i)
            tmp_array2[i] = *tmp_array[i];
        for (auto i = 0; i < size; ++i) {
            std::advance(begin, i);
            *begin = tmp_array2[i];
            std::advance(begin, -i);
        }
        delete[] tmp_array;
    }
}
//template<typename T>
//void partition(T& array, size_t low, size_t high){
//    typeof(array[high]) pivot = array[high];
//    size_t higher_pointer = 0;
//    size_t lower_pointer;
//
//    while(higher_pointer<high) {
//        if(array[higher_pointer] > pivot) {
//
//        }
//    }
//    swap(array[lower_pointer], pivot);
//
//}

template<typename T>
int partition(T& array, int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(array[i], array[j]);
        }
    }

    // swap pivot with the greater element at i
    swap(array[i + 1], array[high]);

    // return the partition point
    return (i + 1);
}

template<typename T>
void quicksort(T& array, int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quicksort(array, low, pi - 1);

        // recursive call on the right of pivot
        quicksort(array, pi + 1, high);
    }
}
