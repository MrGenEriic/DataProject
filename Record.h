
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Created by ericc on 5/21/2021.
//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef ERICIMPORTPARSE_RECORD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <any>
#include <map>
#include <string>
#include <sstream>
using namespace std;


// error() simply disguises throws:
inline void error(const string& s)
{
    throw runtime_error(s);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
// Refer to https://mrgeneriic.atlassian.net/wiki/spaces/PE/pages/11042818/CSV+File+Contents+Outline
// For documentation on what the datamebers for class Record indicate
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
class Record{
// ToDo need to lay out the design framework for when I create the HashTable of <string,Record> where/how I define string -- most likely string will be the identifier # from the CSV's
public:

    Record() {

    }

    any getValue(const string&, const any&);
    void setValue(const string&, any);

    // Core function that determines which file type (by name) I want to read and then parses it
    // ToDo need to determine how I am going to store / insert the successfully parsed lines -- To be Considering: Store in a "middle" layer to check if it does it properly while testing somehow before sending to a fully setup "final" location
    void coreParse();

private:
    map<string,any> carrierRec;
    void billgenParse();
    void cargodescParse();
    void cosigneeParse();
    void containerParse();
    void hazmatParse();
    void hazmatclassParse();
    void headerParse();
    void marksnumberParse();
    void notifyingpartyParse();
    void shipperParse();
    void tariffParse();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------





#define ERICIMPORTPARSE_RECORD_H

#endif //ERICIMPORTPARSE_RECORD_H


// This class will have the functions which run for the BillGen file to read and then
// write the results into the Map<string,any> defined HERE in record
//class Billgen;
/*class Record::Billgen{
public:
    friend class Record;

    int potato1 = 5;

    void test1(){
        cout << "wtf";
    }

    // Example, but this is how we can access the Map<string,any> for the Record
    void test(){
        testvec.push_back(25);
    }

};*/