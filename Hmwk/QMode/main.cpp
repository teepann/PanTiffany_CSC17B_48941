/*
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on October 22, 2015, 2:52 PM
 */

#include <QCoreApplication>
#include <QMap>// Map Library
#include <QVector>// Vector Library
#include <qalgorithms.h>//Algorithm Library
#include <iostream> // Input/Output Stream Library
#include <cstdlib>
#include <time.h>

using namespace std;

/*The helper is used for comparing frequencies of a vector of pairs<value, frequency>
 *The frequencies are sorted in a decreasing order
 */
bool cmpValue(const QPair<int, int> &v1, const QPair<int, int> &v2) {
    return v1.second > v2.second;
}

/**
 *
 * @param a : an array of integer values
 * @param n : the size of a
 * @param m : the size of the return array
 * @return the array containing all the mode values of a
 */
QVector<int> findMode(QVector<int> v) {

    //This vector contains all the values having the same highest frequency in the array a
    QVector<int> result;

    // The input array a should have more than a element
    if (v.size() <= 1) {
        return result;
    }

    /*This map containing pairs of values (in the array a) and their frequencies*/
    QMap<int, int> afreq;

    /*This vector of pairs is parallel to the map afreq*/
    QVector< QPair<int, int> > afreqv;


    //Finding the frequency of each value in the array a
    for (int i = 0; i < v.size(); i++) {

        if (afreq.contains(v[i])){ // Check if a value has already existed in the map
            // Increasing the frequency of an existing value
            afreq[v[i]]++;
        }else{
            // Start the frequency of a new value with 1
            afreq.insert(v[i], 1);
        }

    }

    // Binding all map entries into a vector of pairs (values, frequencies))
    for (QMap<int,int> ::iterator i = afreq.begin(); i != afreq.end(); ++i) {
        afreqv.append(QPair<int,int>(i.key(), i.value()));
    }


    /*
     * Take advantage of the build-in sort algorithm for vectors
     * Sort the vector of pairs<value, frequency> by a decreasing order of frequencies
     */
    sort(afreqv.begin(), afreqv.end(), cmpValue);

    // If the highest frequency of a value in the array a is equal to 1, then that array has no mode
    if (afreqv.begin()->second == 1) {
        return result;
    }

    //Finding values that have the same highest frequency
    for (int i = 0; i < afreqv.size(); ++i) {
        if(afreqv[i].second == afreqv.begin()->second){
            result.push_back(afreqv[i].first);
        }else{
            break;
        }

    }


    //Add the frequency to the end of the result vector
    result.push_back(afreqv.begin()->second);

    return result;
}

/*
 * This program is used for finding the mode of a set of data
 */
int main(int argc, char** argv) {

    QCoreApplication a(argc, argv);

    // Generate testing data - start.
    srand(time(NULL));

    int n = 10 + rand() % 41;

    QVector<int> va;

    for (int i = 0; i < n; i++) {

        va.append(rand() % 100);
        cout << va[i] << " ";

        if (((i + 1) % 10) == 0) {
            cout << endl;
        }
    }
    // Generate testing data - end.

    QVector<int> result = findMode(va);

    if (result.empty()) {
        cout << "\nThere is no mode of the input array !";
    } else {

        //The real size of the mode array
        int rSize = result.size() - 1;

        cout << "\nThe highest frequency is "<< result[rSize] <<" and the mode array contains: " << endl;

        for (int j = 0; j < rSize; j++) {
            cout << result[j] << " ";
        }
    }

    return a.exec();

}

