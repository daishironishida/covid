#pragma once

#include "ofMain.h"

template <class T>
class KdTree {
    T position;
    std::shared_ptr<KdTree> leftChild = nullptr;
    std::shared_ptr<KdTree> rightChild = nullptr;

public:
    bool isLeaf() {
        return position == nullptr;
    };

    KdTree(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, int depth = 0) {
        int size = end - begin;
        if (size == 0) {
            return;
        }

        // divide in half along axis
        int axis = depth % begin->DIM;
        auto median = begin + (end - begin) / 2;
        std::nth_element(begin, median, end, [axis](T a, T b){ return a[axis] < b[axis]; });

        leftChild = std::make_shared<KdTree>(begin, median, depth+1);
        rightChild = std::make_shared<KdTree>(median + 1, end, depth+1);

        position = *median;
    }
};
