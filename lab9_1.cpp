#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double loan, rate, payPerYear;

    cout << "Enter initial loan: ";
    cin >> loan;

    cout << "Enter interest rate per year (%): ";
    cin >> rate;

    cout << "Enter amount you can pay per year: ";
    cin >> payPerYear;

    // ห้ามขึ้นบรรทัดใหม่
    cout << setw(13) << left << "EndOfYear#"
         << setw(13) << left << "PrevBalance"
         << setw(13) << left << "Interest"
         << setw(13) << left << "Total"
         << setw(13) << left << "Payment"
         << setw(13) << left << "NewBalance"
         << "\n";

    cout << fixed << setprecision(2);

    int year = 1;
    double prevBalance = loan;

    while (prevBalance > 0) {
        double interest = prevBalance * rate / 100.0;
        double total = prevBalance + interest;
        double payment = (total <= payPerYear) ? total : payPerYear;
        double newBalance = total - payment;

        cout << setw(13) << left << year
             << setw(13) << left << prevBalance
             << setw(13) << left << interest
             << setw(13) << left << total
             << setw(13) << left << payment
             << setw(13) << left << newBalance
             << "\n";

        prevBalance = newBalance;
        year++;
    }

    return 0;
}
