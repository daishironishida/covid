#pragma once

#include "ofMain.h"

template <class T>
class KdTree {
    std::shared_ptr<T> person = nullptr;
    std::shared_ptr<KdTree> leftChild = nullptr;
    std::shared_ptr<KdTree> rightChild = nullptr;

public:
    bool isLeaf() {
        return person == nullptr;
    };

    KdTree(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, int depth = 0) {
        int size = end - begin;
        if (size == 0) {
            return;
        }

        // divide in half along axis
        int axis = depth % begin->getPosition().DIM;
        auto median = begin + (end - begin) / 2;
        std::nth_element(begin, median, end, [axis](T a, T b){ return a.getPosition()[axis] < b.getPosition()[axis]; });

        leftChild = std::make_shared<KdTree>(begin, median, depth+1);
        rightChild = std::make_shared<KdTree>(median + 1, end, depth+1);

        person = std::make_shared<T>(*median);
    }

    void findPointsInRange(T base, float range, std::vector<T> &result, int depth = 0) {
        if (isLeaf()) {
            return;
        }
        int axis = depth % person->getPosition().DIM;
        float personPos = person->getPosition()[axis];
        float basePos = base.getPosition()[axis];

        if (basePos <= personPos || basePos - personPos < range) {
            leftChild->findPointsInRange(base, range, result, depth+1);
        }
        if (basePos > personPos || personPos - basePos < range) {
            rightChild->findPointsInRange(base, range, result, depth+1);
        }
        if (base.getPosition().squareDistance(person->getPosition()) < range * range) {
            result.push_back(*person);
        }
    }
};
