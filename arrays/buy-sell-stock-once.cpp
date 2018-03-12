/**
 * Buy and sell stock once to maximize the profit.
 */

#include <iostream>
#include <vector>
#include <limits>


using namespace std;

double buy_sell_once(const vector<double> & prices) {
    double min_so_far = numeric_limits<double>::max();
    double max_profit = 0;
    for (const double & price : prices) {
        double max_profit_sell_today = price - min_so_far;
        max_profit = max(max_profit, max_profit_sell_today);
        min_so_far = min(min_so_far, price);
    }
    return max_profit;
}


int main() {
    auto v = vector<double>{310,315,275,295,260,270,290,230,255,250};
    cout<<"Max profit: "<<buy_sell_once(v)<<endl;
}

