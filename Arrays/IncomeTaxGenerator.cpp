#include <iostream>
using namespace std;

class Solution
{
public:
    int fourToEightSlab = 20000;
    int eightToTwelveSlab = 40000;
    int twelveToSixteenSlab = 60000;
    int sixteenToTwentySlab = 80000;
    int twentyToTwentyfourSlab = 100000;
    double incomeTaxGenerator(double salary)
    {
        double tax = 0;
        double extraMoney = 0;
        double percentAmount = 0;
        if (salary <= 400000) return 0;
        if (salary > 2400000) {
            extraMoney = salary - 2400000;
            percentAmount = 0.3 * extraMoney;
            tax = percentAmount + fourToEightSlab + eightToTwelveSlab + twelveToSixteenSlab + sixteenToTwentySlab + twentyToTwentyfourSlab;
        }
        else if (salary <= 2400000 && salary > 2000000) {
            extraMoney = salary - 2000000;
            percentAmount = 0.25 * extraMoney;
            tax = percentAmount + fourToEightSlab + eightToTwelveSlab + twelveToSixteenSlab + sixteenToTwentySlab;
        }
        else if (salary <= 2000000 && salary > 1600000) {
            extraMoney = salary - 1600000;
            percentAmount = 0.2 * extraMoney;
            tax = percentAmount + fourToEightSlab + eightToTwelveSlab + twelveToSixteenSlab;
        }
        else if (salary <= 1600000 && salary > 1200000) {
            extraMoney = salary - 1200000;
            percentAmount = 0.15 * extraMoney;
            tax = percentAmount + fourToEightSlab + eightToTwelveSlab;
        }
        else if (salary <= 1200000 && salary > 800000) {
            extraMoney = salary - 800000;
            percentAmount = 0.1 * extraMoney;
            tax = percentAmount + fourToEightSlab;
        }
        else if (salary <= 800000 && salary > 400000) {
            extraMoney = salary - 400000;
            percentAmount = 0.05 * extraMoney;
            tax = percentAmount;
        }
        return tax;
    }
};

int main() {
    Solution sol;
    double Salary;
    cin >> Salary;
    cout << "Total tax: " << sol.incomeTaxGenerator(Salary) << endl;
    return 0;
}
