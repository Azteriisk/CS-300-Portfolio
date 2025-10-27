//============================================================================
// Name        : VectorSorting.cpp
// Author      : Alec Brandt
// Date        : 2025-09-14
// Description : Vector Sorting Algorithms
//============================================================================

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Simple helpers
//============================================================================

// Print one bid on a single line
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

// Prompt user for one bid from stdin
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

// Read bids from CSV. Columns used: title=0, id=1, amount=4, fund=8
vector<Bid> loadBids(string csvPath) {
    cout << "Loading CSV file " << csvPath << endl;

    // storage for results
    vector<Bid> bids;

    // parse the file
    csv::Parser file = csv::Parser(csvPath);

    try {
        // read each row
        for (unsigned int i = 0; i < file.rowCount(); ++i) {

            // map CSV row -> Bid
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // keep it
            bids.push_back(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    return bids;
}

// Partition around a pivot using Hoare scheme; returns end of low partition
int partition(vector<Bid>& bids, int begin, int end) {
    int low = begin;
    int high = end;

    // pick middle as pivot so it behaves ok on nearly sorted data
    int middlePoint = begin + (end - begin) / 2;
    string pivot = bids[middlePoint].title;

    // classic Hoare partitioning
    while (true) {
        while (bids[low].title < pivot) {
            ++low;
        }
        while (pivot < bids[high].title) {
            --high;
        }
        if (low >= high) {
            return high; // indices crossed; high is last element in low partition
        }
        swap(bids[low], bids[high]);
        ++low;
        --high;
    }
}

// Quick sort by title (in-place)
void quickSort(vector<Bid>& bids, int begin, int end) {
    // nothing to do for empty or single-element slices
    if (begin >= end) {
        return;
    }

    // split around a pivot; mid is last index of low side
    int mid = partition(bids, begin, end);

    // sort each side
    quickSort(bids, begin, mid);
    quickSort(bids, mid + 1, end);
}

// Selection sort by title (ascending)
void selectionSort(vector<Bid>& bids) {
    const size_t n = bids.size();
    for (size_t pos = 0; pos + 1 < n; ++pos) {
        size_t min = pos;
        for (size_t j = pos + 1; j < n; ++j) {
            if (bids[j].title < bids[min].title) {
                min = j;
            }
        }
        if (min != pos) {
            swap(bids[pos], bids[min]);
        }
    }
}

// Remove a char (like '$') and parse the number
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

// Program entry + simple menu
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";
    }

    // Define a vector to hold all the bids
    vector<Bid> bids;

    // Define a timer variable
    clock_t ticks;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Quick Sort All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            // start timer
            ticks = clock();

            // load bids
            bids = loadBids(csvPath);

            cout << bids.size() << " bids read" << endl;

            // stop timer and report
            ticks = clock() - ticks;
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 2:
            // Loop and display the bids read
            for (size_t i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }
            cout << endl;

            break;

        // Selection sort then report timing
        case 3:
            ticks = clock();
            selectionSort(bids);
            ticks = clock() - ticks;
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        // Quick sort then report timing
        case 4:
            if (!bids.empty()) {
                ticks = clock();
                quickSort(bids, 0, static_cast<int>(bids.size()) - 1);
                ticks = clock() - ticks;
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            }
            break;

        }
    }

    cout << "Good bye." << endl;

    return 0;
}
