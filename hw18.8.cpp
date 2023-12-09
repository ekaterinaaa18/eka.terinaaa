#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

template <typename T>
class Interval {
public:
    T lower;
    T upper;
    bool lowerInclusive;
    bool upperInclusive;

    Interval(T lower, T upper, bool lowerInclusive, bool upperInclusive)
        : lower(lower), upper(upper), lowerInclusive(lowerInclusive), upperInclusive(upperInclusive) {}

    bool contains(const T& value) const {
        if (value < lower || value > upper) {
            return false;
        }
        if (value == lower && !lowerInclusive) {
            return false;
        }
        if (value == upper && !upperInclusive) {
            return false;
        }
        return true;
    }

    bool intersects(const Interval<T>& other) const {
        if (upper < other.lower || other.upper < lower) {
            return false;
        }
        if (upper == other.lower && (!upperInclusive || !other.lowerInclusive)) {
            return false;
        }
        if (lower == other.upper && (!lowerInclusive || !other.upperInclusive)) {
            return false;
        }
        return true;
    }

    Interval<T> intersection(const Interval<T>& other) const {
        if (!intersects(other)) {
            // No intersection
            return Interval<T>(std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity(), false, false);
        }

        T newLower = std::max(lower, other.lower);
        T newUpper = std::min(upper, other.upper);

        bool newLowerInclusive = (newLower == lower && lowerInclusive) || (newLower == other.lower && other.lowerInclusive);
        bool newUpperInclusive = (newUpper == upper && upperInclusive) || (newUpper == other.upper && other.upperInclusive);

        return Interval<T>(newLower, newUpper, newLowerInclusive, newUpperInclusive);
    }

    Interval<T> unionWith(const Interval<T>& other) const {
        T newLower = std::min(lower, other.lower);
        T newUpper = std::max(upper, other.upper);

        bool newLowerInclusive = (newLower == lower && lowerInclusive) || (newLower == other.lower && other.lowerInclusive);
        bool newUpperInclusive = (newUpper == upper && upperInclusive) || (newUpper == other.upper && other.upperInclusive);

        return Interval<T>(newLower, newUpper, newLowerInclusive, newUpperInclusive);
    }
};

template <typename T>
Interval<T> findCommonIntersection(const std::vector<Interval<T>>& intervals) {
    if (intervals.empty()) {
        return Interval<T>(std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity(), false, false);
    }

    Interval<T> commonIntersection = intervals.front();

    for (const auto& interval : intervals) {
        commonIntersection = commonIntersection.intersection(interval);
    }

    return commonIntersection;
}

int main() {
    Interval<double> interval1(1.0, 5.0, true, true);
    Interval<double> interval2(3.0, std::numeric_limits<double>::infinity(), true, false);
    Interval<double> interval3(-std::numeric_limits<double>::infinity(), 2.0, false, true);

    std::vector<Interval<double>> intervals = { interval1, interval2, interval3 };

    Interval<double> commonIntersection = findCommonIntersection(intervals);

    std::cout << "Common Intersection: "<< (commonIntersection.upperInclusive ? "[" : "(") << commonIntersection.lower << ", " << commonIntersection.upper
        << (commonIntersection.lowerInclusive ? "]" : ")")<< std::endl;

    return 0;
}