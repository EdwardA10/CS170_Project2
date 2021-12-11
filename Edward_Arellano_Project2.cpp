#pragma optimize("O2")

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <cfloat>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<long double> v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11;
vector<long double> z1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13, y14, y15, y16, y17, y18, y19, y20, y21, y22, y23, y24, y25;
vector<long double> y26, y27, y28, y29, y30, y31, y32, y33, y34, y35, y36, y37, y38, y39, y40, y41, y42, y43, y44, y45, y46, y47, y48, y49, y50, y51;
long double accuracy;

vector<long double> data(int i) {
    vector<long double> value;
    value.push_back(v2.at(i));
    value.push_back(v3.at(i));
    value.push_back(v4.at(i));
    value.push_back(v5.at(i));
    value.push_back(v6.at(i));
    value.push_back(v7.at(i));
    value.push_back(v8.at(i));
    value.push_back(v9.at(i));
    value.push_back(v10.at(i));
    value.push_back(v11.at(i));

    return value;
}

vector<long double> data_2(int i) {
    vector<long double> value;
    value.push_back(y2.at(i)); value.push_back(y3.at(i)); value.push_back(y4.at(i)); value.push_back(y5.at(i)); value.push_back(y6.at(i)); value.push_back(y7.at(i)); value.push_back(y8.at(i)); value.push_back(y9.at(i)); value.push_back(y10.at(i));
    value.push_back(y11.at(i)); value.push_back(y12.at(i)); value.push_back(y13.at(i)); value.push_back(y14.at(i)); value.push_back(y15.at(i)); value.push_back(y16.at(i)); value.push_back(y17.at(i)); value.push_back(y18.at(i)); value.push_back(y19.at(i));
    value.push_back(y20.at(i)); value.push_back(y21.at(i)); value.push_back(y22.at(i)); value.push_back(y23.at(i)); value.push_back(y24.at(i)); value.push_back(y25.at(i)); value.push_back(y26.at(i)); value.push_back(y27.at(i)); value.push_back(y28.at(i)); value.push_back(y29.at(i));
    value.push_back(y30.at(i)); value.push_back(y31.at(i)); value.push_back(y32.at(i)); value.push_back(y33.at(i)); value.push_back(y34.at(i)); value.push_back(y35.at(i)); value.push_back(y36.at(i)); value.push_back(y37.at(i)); value.push_back(y38.at(i)); value.push_back(y39.at(i));
    value.push_back(y40.at(i)); value.push_back(y41.at(i)); value.push_back(y42.at(i)); value.push_back(y43.at(i)); value.push_back(y44.at(i)); value.push_back(y45.at(i)); value.push_back(y46.at(i)); value.push_back(y47.at(i)); value.push_back(y48.at(i)); value.push_back(y49.at(i));
    value.push_back(y50.at(i)); value.push_back(y51.at(i));

    return value;
}

long double sum(vector<long double> arr) {
    long double val = 0;
    for (int i = 0; i < arr.size(); ++i) {
        val = val + arr.at(i);
    }
    return val;
}

void delay(int x) {
    for(int i = 0; i < x; ++i) { }
}

long double leave_one_out_cross_validation(vector<long double> vec2, vector<int> current_set, int feature_to_add) {

    //vector<long double> data = data();
    long double number_correctly_classified = 0;

    for (int i = 0; i < v1.size(); ++i) {
        vector<long double> object_to_classify = data(i);
        long double label_object_to_classify = v1.at(i);

        long double nearest_neighbor_distance = LDBL_MAX;
        int nearest_neighbor_location = INT_MAX;
        long double nearest_neighbor_label = LDBL_MAX;
        for(int k = 1; k < v1.size(); ++k) {
            if(k != i) {
                long double distance = sqrt(pow(sum(object_to_classify) - sum(data(k)), 2));
                if(distance < nearest_neighbor_distance) {
                    nearest_neighbor_distance = distance;
                    nearest_neighbor_location = k;
                    nearest_neighbor_label = v1.at(nearest_neighbor_location);
                }
            }
        }

        if(label_object_to_classify == nearest_neighbor_label) {
            number_correctly_classified = number_correctly_classified + 1;
        }

        cout << "Object " << i + 1 << " is class " << label_object_to_classify << endl;
        cout << "Its nearest neighbor is " << nearest_neighbor_location << " which is class " << nearest_neighbor_label << endl; 
    }
    
    return (number_correctly_classified / static_cast<long double>(v1.size())) * 100;
}

long double leave_one_out_cross_validation_2(vector<long double> vec2, vector<int> current_set, int feature_to_add) {

    long double number_correctly_classified = 0;

    for (int i = 0; i < z1.size(); ++i) {
        vector<long double> object_to_classify = data_2(i);
        long double label_object_to_classify = z1.at(i);

        long double nearest_neighbor_distance = LDBL_MAX;
        int nearest_neighbor_location = INT_MAX;
        long double nearest_neighbor_label = LDBL_MAX;
        for (int k = 1; k < z1.size(); ++k) {
            if (k != i) {
                long double distance = sqrt(pow(sum(object_to_classify) - sum(data_2(k)), 2));
                if (distance < nearest_neighbor_distance) {
                    nearest_neighbor_distance = distance;
                    nearest_neighbor_location = k;
                    nearest_neighbor_label = z1.at(nearest_neighbor_location);
                }
            }
        }

        if (label_object_to_classify == nearest_neighbor_label) {
            number_correctly_classified = number_correctly_classified + 1;
        }

        cout << "Object " << i + 1 << " is class " << label_object_to_classify << endl;
        cout << "Its nearest neighbor is " << nearest_neighbor_location << " which is class " << nearest_neighbor_label << endl;
    }

    return (number_correctly_classified / static_cast<long double>(z1.size())) * 100;
}

bool contains(vector<int> v, int k) {
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i) == k) {
            return true;
        }
    }
    return false;
}

void printVector(vector<int> x) {
    for (int i = 0; i < x.size(); ++i) {
        cout << x.at(i) << " ";
    }
}

long double feature_search_demo(vector<long double> vec2) {
    vector<int> current_set_of_features;
    vector<int> final_set;
    long double final_accuracy = 0;

    for (int i = 1; i < 11; i++) { //(int i = 1; i < vec2.size() - 1; i++) {
        cout << "On the " << i << "th level of the search tree" << endl;

        int feature_to_add_at_this_level = INT_MIN;
        int local_feature = INT_MIN;
        vector<int> tmp;
        long double best_so_far_accuracy = 0;

        for (int k = 1; k < 11; k++) { //(int k = 1; k < vec2.size(); k++) {
            if (contains(current_set_of_features, k) != true) { //(current_set_of_features.at(k) != k) {
                tmp = current_set_of_features;
                tmp.push_back(k);
                cout << "--Considering adding the " << k << "th feature" << endl;
                accuracy = leave_one_out_cross_validation(vec2, current_set_of_features, k + 1);
                cout << endl << "Using features: "; printVector(tmp); cout << " accuracy is " << accuracy << "%" << endl;
                delay(INT_MAX);

                if (accuracy > final_accuracy) {
                    final_accuracy = accuracy;
                    feature_to_add_at_this_level = k;
                }
                if (accuracy > best_so_far_accuracy) {
                    best_so_far_accuracy = accuracy;
                    local_feature = k;
                }
            }
        }
        if (feature_to_add_at_this_level >= 0) {
            current_set_of_features.push_back(feature_to_add_at_this_level);
            final_set.push_back(feature_to_add_at_this_level);
            cout << endl << "Feature set ";
            printVector(current_set_of_features);
            cout << " was best, accuracy is " << best_so_far_accuracy << "%" << endl << endl;
            //delay(INT_MAX);
        }
        else {
            cout << "Accuracy has decreased! Checking for best accuracy..." << endl;
            current_set_of_features.push_back(local_feature);
            cout << "Feature set ";
            printVector(current_set_of_features);
            cout << " was best, accuracy is " << best_so_far_accuracy << "%" << endl << endl;
            //delay(INT_MAX);
        }
    }

    return final_accuracy;
}

long double feature_search_demo_2(vector<long double> vec2) {
    vector<int> current_set_of_features;
    vector<int> final_set;
    long double final_accuracy = 0;

    for (int i = 1; i < 51; i++) { //(int i = 1; i < vec2.size() - 1; i++) {
        cout << "On the " << i << "th level of the search tree" << endl;

        int feature_to_add_at_this_level = INT_MIN;
        int local_feature = INT_MIN;
        vector<int> tmp;
        long double best_so_far_accuracy = 0;

        for (int k = 1; k < 51; k++) { //(int k = 1; k < vec2.size(); k++) {
            if (contains(current_set_of_features, k) != true) { //(current_set_of_features.at(k) != k) {
                tmp = current_set_of_features;
                tmp.push_back(k);
                cout << "--Considering adding the " << k << "th feature" << endl;
                accuracy = leave_one_out_cross_validation_2(vec2, current_set_of_features, k + 1);
                cout << endl << "Using features: "; printVector(tmp); cout << " accuracy is " << accuracy << "%" << endl;

                if (accuracy > final_accuracy) {
                    final_accuracy = accuracy;
                    feature_to_add_at_this_level = k;
                }
                if (accuracy > best_so_far_accuracy) {
                    best_so_far_accuracy = accuracy;
                    local_feature = k;
                }
            }
        }
        if (feature_to_add_at_this_level >= 0) {
            current_set_of_features.push_back(feature_to_add_at_this_level);
            final_set.push_back(feature_to_add_at_this_level);
            cout << endl << "Feature set ";
            printVector(current_set_of_features);
            cout << " was best, accuracy is " << best_so_far_accuracy << "%" << endl << endl;
            //delay(INT_MAX);
        }
        else {
            cout << "Accuracy has decreased! Checking for best accuracy..." << endl;
            current_set_of_features.push_back(local_feature);
            cout << "Feature set ";
            printVector(current_set_of_features);
            cout << " was best, accuracy is " << best_so_far_accuracy << "%" << endl << endl;
            //delay(INT_MAX);
        }
    }

    return final_accuracy;
}

long double backwardElimination(vector<long double> vec2, long double pre_accuracy) {
    vector<int> subset(10);
    vector<int> final_set(10);

    long double best_accuracy = pre_accuracy;

    for (int i = 1; i < 11; ++i) {
        int feature = INT_MIN;
        int local_feature = INT_MIN;
        long double featureAccuracy = 0;
        for (int j = 1; j < 11; ++j) {
            if (contains(subset, j) == true) { //(subset.at(j) == j) {
                vector<int> temp = subset;
                temp.erase(temp.begin() + (j-1));
                accuracy = leave_one_out_cross_validation(vec2, subset, j + 1);
                cout << endl << "Using features ";
                printVector(temp);
                cout << ". Accuracy is " << accuracy << "%" << endl;

                if (accuracy > best_accuracy) {
                    best_accuracy = accuracy;
                    feature = j;
                }
                if (accuracy > featureAccuracy) {
                    featureAccuracy = accuracy;
                    local_feature = j;
                }
            }
        }
        if (feature >= 0) {
            subset.erase(subset.begin() + (feature - 1));
            final_set.erase(final_set.begin() + (feature - 1));
        }
        /*else {
            cout << "Our accuracy has decreased! Checking for best features..." << endl << endl;
            subset.erase(subset.begin() + (local_feature - 1));
            cout << "Our set of features ";
            printVector(subset);
            cout << " is the best subset. Its accuracy is: " << featureAccuracy << "%" << endl << endl;
        }*/
    }
    cout << "We've completed our search of features! The best feature set is ";
    printVector(final_set);
    cout << ". This set has an accuracy of: " << best_accuracy << "%" << endl;
    return best_accuracy;
}

long double backwardElimination_2(vector<long double> vec2, long double pre_accuracy) {
    vector<int> subset(50);
    vector<int> final_set(50);

    long double best_accuracy = pre_accuracy;

    for (int i = 1; i < 51; ++i) {
        int feature = INT_MIN;
        int local_feature = INT_MIN;
        long double featureAccuracy = 0;
        for (int j = 1; j < 51; ++j) {
            if (contains(subset, j) == true) { //(subset.at(j) == j) {
                vector<int> temp = subset;
                temp.erase(temp.begin() + (j - 1));
                accuracy = leave_one_out_cross_validation_2(vec2, subset, j + 1);
                cout << endl << "Using features ";
                printVector(temp);
                cout << ". Accuracy is " << accuracy << "%" << endl;

                if (accuracy > best_accuracy) {
                    best_accuracy = accuracy;
                    feature = j;
                }
                if (accuracy > featureAccuracy) {
                    featureAccuracy = accuracy;
                    local_feature = j;
                }
            }
        }
        if (feature >= 0) {
            subset.erase(subset.begin() + (feature - 1));
            final_set.erase(final_set.begin() + (feature - 1));
        }
    }
    cout << "We've completed our search of features! The best feature set is ";
    printVector(final_set);
    cout << ". This set has an accuracy of: " << best_accuracy << "%" << endl;
    return best_accuracy;
}

int main()
{
    ifstream infile;
    int num = 1;
    string line;

    cout << "Welcome to Edward Arellano's Feature Selection Algorithm!" << endl;
    cout << "Please enter the name of the file to test: ";
    cin >> line;
    cout << endl;

    if (line == "Ver_2_CS170_Fall_2021_Small_data__89.txt") {

        infile.open("Ver_2_CS170_Fall_2021_Small_data__89.txt");
        if (infile.fail()) {
            cout << "Error reading file!" << endl;
            return 1;
        }

        long double n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
        while (infile >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10 >> n11) {
            v1.push_back(n1); v2.push_back(n2); v3.push_back(n3);
            v4.push_back(n4); v5.push_back(n5); v6.push_back(n6);
            v7.push_back(n7); v8.push_back(n8); v9.push_back(n9);
            v10.push_back(n10); v11.push_back(n11);
        }

        vector<int> current_set(v2.size());
        int userInput;
        cout << "Type the number of the algorithm you want to run: " << endl;
        cout << "\t 1) Forward Selection" << endl;
        cout << "\t 2) Backward Elimination" << endl;
        //delay(INT_MAX);
        cin >> userInput;

        if (userInput == 1) {
            auto start = high_resolution_clock::now();
            cout << endl << "FINAL ACCURACY: " << feature_search_demo(v2) << endl;
            auto stop = high_resolution_clock::now();
            infile.close();
            auto duration = duration_cast<seconds>(stop - start);
            cout << "Total time elapsed: " << duration.count() << endl;
        }
        if (userInput == 2) {
            auto start = high_resolution_clock::now();
            long double curr_accuracy = leave_one_out_cross_validation(v2, current_set, 10);
            cout << endl << "FINAL ACCURACY: " << backwardElimination(v2, curr_accuracy) << endl;
            auto stop = high_resolution_clock::now();
            infile.close();
            auto duration = duration_cast<seconds>(stop - start);
            cout << "Total time elapsed: " << duration.count() << endl;
        }
    }
    else if (line == "Ver_2_CS170_Fall_2021_LARGE_data__16.txt") {
        long double x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25;
        long double x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51;
        infile.open("Ver_2_CS170_Fall_2021_LARGE_data__16.txt");
        if (infile.fail()) {
            cout << "Error reading file!" << endl;
            return 1;
        }
        while (infile >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 >> x8 >> x9 >> x10 >> x11 >> x12 >> x13 >> x14 >> x15 >> x16 >> x17 >> x18 >> x19 >> x20 >> x21 >> x22 >> x23 >> x24 >> x25 >> x26 >> x27 >> x28 >> x29 >> x30 >> x31 >> x32 >> x33 >> x34 >> x35 >> x36 >> x37 >> x38 >> x39 >> x40 >> x41 >> x42 >> x43 >> x44 >> x45 >> x46 >> x47 >> x48 >> x49 >> x50 >> x51) {
            z1.push_back(x1); y2.push_back(x2); y3.push_back(x3); y4.push_back(x4); y5.push_back(x5); y6.push_back(x6); y7.push_back(x7); y8.push_back(x8); y9.push_back(x9); y10.push_back(x10); y11.push_back(x11); y12.push_back(x12);
            y13.push_back(x13); y14.push_back(x14); y15.push_back(x15); y16.push_back(x16); y17.push_back(x17); y18.push_back(x18); y19.push_back(x19); y20.push_back(x20); y21.push_back(x21); y22.push_back(x22); y23.push_back(x23); y24.push_back(x24);
            y25.push_back(x25); y26.push_back(x26); y27.push_back(x27); y28.push_back(x28); y29.push_back(x29); y30.push_back(x30); y31.push_back(x31); y32.push_back(x32); y33.push_back(x33); y34.push_back(x34); y35.push_back(x35); y36.push_back(x36);
            y37.push_back(x37); y38.push_back(x38); y39.push_back(x39); y40.push_back(x40); y41.push_back(x41); y42.push_back(x42); y43.push_back(x43); y44.push_back(x44); y45.push_back(x45); y46.push_back(x46); y47.push_back(x47); y48.push_back(x48);
            y49.push_back(x49); y50.push_back(x50); y51.push_back(x51);
        }

        vector<int> current_set(y2.size());

        int userInput;
        cout << "Type the number of the algorithm you want to run: " << endl;
        cout << "\t 1) Forward Selection" << endl;
        cout << "\t 2) Backward Elimination" << endl;
        //delay(INT_MAX);
        cin >> userInput;

        if (userInput == 1) {
            auto start = high_resolution_clock::now();
            cout << endl << "FINAL ACCURACY: " << feature_search_demo_2(y2) << endl;
            auto stop = high_resolution_clock::now();
            infile.close();
            auto duration = duration_cast<seconds>(stop - start);
            cout << "Total time elapsed: " << duration.count() << endl;
        }
        if (userInput == 2) {
            auto start = high_resolution_clock::now();
            long double curr_accuracy = leave_one_out_cross_validation_2(y2, current_set, 50);
            cout << endl << "FINAL ACCURACY: " << backwardElimination_2(y2, curr_accuracy) << endl;
            auto stop = high_resolution_clock::now();
            infile.close();
            auto duration = duration_cast<seconds>(stop - start);
            cout << "Total time elapsed: " << duration.count() << endl;
        }
    }
    else {
        cout << "INVALID FILE NAME! PLEASE TRY AGAIN!" << endl;
        cout << "Exiting program..." << endl;
    }

    return 0;
}
