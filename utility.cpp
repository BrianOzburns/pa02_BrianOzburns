// cs24, Mirza
// Brian Ozawa Burns, 05/24/2021

// contains any other classes needed for bst implementation
#include "utility.h"
#include <queue>

double getMedian(vector<double>& times){
    priority_queue<double> left;
    priority_queue<double, vector<double>, std::greater<double>> right;
    for ( auto n : times ){
        if ( left.empty() ){
            left.push(n);
        }
        else {
            if ( left.size() > right.size() ){
                if ( n < left.top() ){
                    right.push(left.top());
                    left.pop();
                    left.push(n);
                }
                else {
                    right.push(n);
                }
            }
            else {
                if ( n > right.top() ){
                    left.push(right.top());
                    right.pop();
                    right.push(n);
                }
                else {
                    left.push(n);
                }
            }
        }
    }
    if ( left.size() == right.size() ){
        return (left.top() + right.top())/2;
    }
    return left.top();
}