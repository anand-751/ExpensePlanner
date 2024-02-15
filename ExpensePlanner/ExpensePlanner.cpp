#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class TripExpensePlanner {
private:
    int numPersons;
    vector<string> names;
    vector<double> expenses;

public:
    TripExpensePlanner() {
        cout << "Enter the number of persons on the trip: ";
        cin >> numPersons;
        names.resize(numPersons);
        expenses.resize(numPersons, 0.0);
    }

    void inputExpenses() {
        cout << "Enter names and individual expenses:\n";
        for (int i = 0; i < numPersons; ++i) {
            cout << "Enter name for Person " << i + 1 << ": ";
            cin.ignore();
            getline(cin, names[i]);

            cout << "Enter expenses for " << names[i] << ": $";
            cin >> expenses[i];
        }
    }

    void calculateExpenses() {
        double totalExpenses = 0.0;
        for (double expense : expenses) {
            totalExpenses += expense;
        }

        double equalShare = totalExpenses / numPersons;

        cout << "\nExpense summary:\n";
        for (int i = 0; i < numPersons; ++i) {
            cout << names[i] << ": $ " << expenses[i] << "\n";
        }

        cout << "\nTotal expenses: $" << totalExpenses << "\n";
        cout << "Equal share for each person: $" << equalShare << "\n";

        cout << "\nSettlements:\n";
        for (int i = 0; i < numPersons; ++i) {
            double difference = expenses[i] - equalShare;
            if (difference > 0) {
                cout << names[i] << " has to take $" << difference / (numPersons - 1) << " from the individuals in the group.\n";
            } else if (difference < 0) {
                cout << names[i] << " has to give $" << -difference / (numPersons - 1) << " to the individuals in the group.\n";
            } else {
                cout << names[i] << " is settled.\n";
            }
        }
    }
};

int main() {
    TripExpensePlanner tripPlanner;
    tripPlanner.inputExpenses();
    tripPlanner.calculateExpenses();

    return 0;
}
