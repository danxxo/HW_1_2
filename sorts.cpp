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

template<typename T>
void quicksort(T& array, size_t size) {

    for(int k = size -1; k > 0; k--){
        typeof(array[size - 1]) central_num = array[size / 2];
        int central_num_pos = size / 2;
        int i = 0, j = size - 1;
        while (i <= j) {
            while (i < central_num_pos && array[i] < central_num) {
                i++;
            }
            while (j > central_num_pos && array[j] > central_num) {
                j--;
            }
            swap(array[i], array[j]);
            i++;
            j--;
        }
        quicksort(array, k);
    }
}
