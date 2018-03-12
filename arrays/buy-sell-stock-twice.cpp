/**
 * Buy and sell stock twice, buy second time on another day.
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

double buy_sell_twice(const vector<double> & prices) {
    double min_so_far = numeric_limits<double>::max();
    double max_profit_total = 0;
    vector<double> first_buy_sell_profits;
    first_buy_sell_profits.reserve(prices.size());

    for (const double & price : prices) {
        double max_profit_sell_today = price - min_so_far;
        max_profit_total = max(max_profit_sell_today, max_profit_total);
        min_so_far = min(price, min_so_far);
        first_buy_sell_profits.push_back(max_profit_total);
    }

    double max_price_second_sweep = numeric_limits<double>::min();
    for (int i = prices.size() - 1; i > 0; --i) {
        max_price_second_sweep = max(max_price_second_sweep, prices[i]);
        max_profit_total = max(max_profit_total,
                                max_price_second_sweep - prices[i] + first_buy_sell_profits[i-1]);
    }
    return max_profit_total;
}

int main() {
    vector<double> v {12,11,13,9,12,8,14,13,15};
    cout<<"Max profit sell twice: "<<buy_sell_twice(v)<<endl;
}



