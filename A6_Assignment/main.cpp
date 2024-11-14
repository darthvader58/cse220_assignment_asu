#include <iostream>
#include <string>
#include "Dict.hpp"  

using namespace std;

struct Person {
    string name;
    int age;

    Person() : name("Unknown"), age(0) {} 
    Person(string name, int age) : name(name), age(age) {}
};

int main() {
    // Test 1: 
    Dict<int, float> intFloatDict;
    intFloatDict.add(1, 1.23f);
    intFloatDict.add(2, 4.56f);
    cout << "intFloatDict[1]: " << intFloatDict[1] << endl;
    cout << "intFloatDict[2]: " << intFloatDict[2] << endl;

    // Test 2: 
    Dict<char, double> charDoubleDict;
    charDoubleDict.add('A', 3.1415);
    charDoubleDict.add('B', 2.718);
    cout << "charDoubleDict['A']: " << charDoubleDict['A'] << endl;
    cout << "charDoubleDict['B']: " << charDoubleDict['B'] << endl;

    // Test 3: 
    Dict<float, string> floatStringDict;
    floatStringDict.add(1.1f, "One Point One");
    floatStringDict.add(2.2f, "Two Point Two");
    cout << "floatStringDict[1.1]: " << floatStringDict[1.1f] << endl;
    cout << "floatStringDict[2.2]: " << floatStringDict[2.2f] << endl;

    // Test 4: 
    Dict<string, Person> personDict;
    personDict.add("Shash", Person("Shash", 25));
    personDict.add("Kenisha", Person("Kenisha", 30));

    cout << "personDict['Shash']: Name: " << personDict["Shash"].name 
         << ", Age: " << personDict["Shash"].age << endl;
    cout << "personDict['Kenisha']: Name: " << personDict["Kenisha"].name 
         << ", Age: " << personDict["Kenisha"].age << endl;

    // Test 5: 
    Dict<double, bool> doubleBoolDict;
    doubleBoolDict.add(3.14, true);
    doubleBoolDict.add(1.61, false);
    cout << "doubleBoolDict[3.14]: " << doubleBoolDict[3.14] << endl;
    cout << "doubleBoolDict[1.61]: " << doubleBoolDict[1.61] << endl;

    return 0;
}
