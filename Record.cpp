//
// Created by ericc on 5/21/2021.
//
#include "Record.h"

void Record::setSeat(const string &valueType, any value) {
    carrierRec[valueType] = value; // todo Test this and see if it actually sets the map's value properly
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
any Record::getSeat(const string &valueType, const any&value) {
    //This should find the specific Map value via the key and then return "second" which is its value
    return carrierRec.find(valueType)->second;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void Record::coreParse() {
    //Ask what file going to parse -> open function for that file-type
    string fileType;

    cout << "File Types: billgen, cargodesc, cosignee, container, hazmat, hazmatclass, header, marksnumbers, notifyingparty, shipper, tariff" << endl;
    cout << "Enter which file you want to read: ";
    cin >> fileType;

    if (fileType == "billgen"){
        billgenParse();
    } else if (fileType == "cargodesc"){
        cargodescParse();
    } else if (fileType == "cosignee"){
        cosigneeParse();
    } else if (fileType == "container"){
        containerParse();
    } else if (fileType == "hazmat"){
        hazmatParse();
    } else if (fileType == "hazmatclass"){
        hazmatclassParse();
    } else if (fileType == "header"){
        headerParse();
    } else if (fileType == "marksnumber"){
        marksnumberParse();
    } else if (fileType == "notifyingparty"){
        notifyingpartyParse();
    } else if (fileType == "shipper"){
        shipperParse();
    } else if (fileType == "tariff"){
        tariffParse();
    } else {
        error("fileType entered did not match any of the presented opens");
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void Record::billgenParse() {
    string billgenName;
    bool processingFile = true; // True or false based on catching the eof() statuses etc to keep or stop reading each line

    cout << "Enter the CSV file name for this BillGen: ";
    cin >> billgenName;

    ifstream billgenIn {billgenName};
    if (!billgenIn){
        error("Billgen file was not opened correctly");
    }

    // Billgen file is now opened at this point, need to begin figuring out how to parse it properly
    while(processingFile){


        // ToDo begin creating the parser logic here: possibly a for() where I create a string and keep it running as long as it is taking in a string -> determine how I want to handle commas that are prematurely entered etc
        int i = 0;
        while(i<20) {

            for (string line; getline(billgenIn, line);) {

                stringstream ss(line);

                for (string data; getline(ss, data, ',');) {
                    cout << " " << data;
                    // ToDo make it add the data element to the Map here once we confirm it is outputting the basic right element
                }

            }

            if (billgenIn.eof()) {
                cout << "End of BillGen file reached\n";
                processingFile = false;
                break;
            }
            if (billgenIn.fail()) {
                cout << "BillGen file reached FAIL state";
                processingFile = false;
                //billgenIn.clear(); ToDo determine if I want to use this, is for clearing the state and assuming I handle it via where it was called
            }
            ++i;
        }
    }


}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void Record::cargodescParse() {

}
void Record::cosigneeParse() {

}
void Record::containerParse() {

}
void Record::hazmatParse() {

}
void Record::hazmatclassParse() {

}
void Record::headerParse() {

}
void Record::marksnumberParse() {

}
void Record::notifyingpartyParse() {

}
void Record::shipperParse() {

}
void Record::tariffParse() {

}
