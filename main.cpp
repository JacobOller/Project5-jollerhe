#include "CollegeStudent.h"
#include "SeparateChaining.h"
#include "OpenAddressing.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <ostream>
using namespace std;


/* Examples of getKey functions
 *
 * If your unique attribute is a string:
 * string getLecturerName(Lecturer lec) {
 *     return lec.getName();
 * }
 *
 * If your unique attribute is not a string:
 * string getEmployeeID(Employee e) {
 *     return to_string(e.getID());
 * }
 *
 * If you only have one unique field in your class,
 * concatenate it with another field for your second key:
 * string getLecturerClassName(Lecturer lec) {
 *     return to_string(lec.getClass1()) + lec.getName();
 * }
 * */
string getCollegeStudentId(const CollegeStudent& student) {
    return to_string(student.getUniqueNumber()) + student.getId();
}
string getCollegeStudentIq(const CollegeStudent& student) {
    return to_string(student.getUniqueNumber()) + to_string(student.getIq());
}

int main() {
    // Create college student vector.
    vector<CollegeStudent> collegeStudents;
    // Get the file name as a string.
    string fileName = "./college_student_placement_dataset.csv";
    // call the getDataFromFile function in order to read the csv students data into a vector.
    getDataFromFile(fileName, collegeStudents);
    unsigned long dataSize = collegeStudents.size();
    cout << "College Students Vector Size: " << dataSize << endl;

    // Create a vector to hold the different table sizes
    vector<unsigned long> tableSizes;
    tableSizes.push_back(dataSize * 1.1);
    tableSizes.push_back(dataSize * 1.4);
    tableSizes.push_back(dataSize * 1.9);
    tableSizes.push_back(dataSize * 2.2);
    tableSizes.push_back(dataSize * 2.5);

    // Create 20 table objects
    // separate chaining hash tables with an id key
    vector<SeparateChaining<CollegeStudent>> scTablesId;
    // separate chaining hash tables with an iq key
    vector<SeparateChaining<CollegeStudent>> scTablesIq;
    // open addressing hash tables with an id key
    vector<QuadraticProbing<CollegeStudent>> oaTablesId;
    // open addressing hash tables with an iq key
    vector<QuadraticProbing<CollegeStudent>> oaTablesIq;

    // Create 20 tables with varying sizes.
    int i = 0;
    cout << "Creating 20 table objects and initiating each to varying sizes:" << endl;
    for (auto &size : tableSizes) {
        scTablesId.push_back(SeparateChaining<CollegeStudent>(size));
        scTablesIq.push_back(SeparateChaining<CollegeStudent>(size));
        oaTablesId.push_back(QuadraticProbing<CollegeStudent>(size));
        oaTablesIq.push_back(QuadraticProbing<CollegeStudent>(size));

        i++;
        cout << "Current size for each table on iteration #" << i << ": " << size << endl;
    }
    cout << "-------------------------------------------------------" << endl << endl;

    // Open 4 files for collision data
    std::ofstream sc_id_file("./data/sc_id_collisions.csv");
    std::ofstream sc_iq_file("./data/sc_iq_collisions.csv");
    std::ofstream oa_id_file("./data/oa_id_collisions.csv");
    std::ofstream oa_iq_file("./data/oa_iq_collisions.csv");

    // Write the header for each file
    string header = "TableType,KeyType,InitialTableSize,Index,Key,Collisions\n";
    sc_id_file << header;
    sc_iq_file << header;
    oa_id_file << header;
    oa_iq_file << header;

    cout << "--- Original Table Sizes ---" << endl << endl;

    cout << "Separate Chaining (ID Key):" << endl;
    for (const auto& table : scTablesId) {
        cout << "  Initial Size: " << table.getTableSize() << endl;
    }

    cout << "Separate Chaining (IQ Key):" << endl;
    for (const auto& table : scTablesIq) {
        cout << "  Initial Size: " << table.getTableSize() << endl;
    }

    cout << "Open Addressing (ID Key):" << endl;
    for (const auto& table : oaTablesId) {
        cout << "  Initial Size: " << table.getTableSize() << endl;
    }

    cout << "Open Addressing (IQ Key):" << endl;
    for (const auto& table : oaTablesIq) {
        cout << "  Initial Size: " << table.getTableSize() << endl;
    }
    cout << "\n" << "Now Inserting " << dataSize << " items into 20 tables and recording data:" << endl;
    for (int i = 0; i < dataSize; ++i) {
        auto &student = collegeStudents[i];
        string id_key = getCollegeStudentId(student);
        string iq_key = getCollegeStudentIq(student);

        unsigned long initialCollisions, finalCollisions, currentCollisions;

        // Separate Chaining with ID key
        for (auto &table : scTablesId) {
            initialCollisions = table.getNumCollisions();
            table.insert(id_key, student);
            finalCollisions = table.getNumCollisions();
            currentCollisions = finalCollisions - initialCollisions;
            sc_id_file << "SeparateChaining,ID," << table.getTableSize() << "," << i << "," << id_key << "," << currentCollisions << "\n";
        }
        // Separate Chaining with IQ key
        for (auto &table : scTablesIq) {
            initialCollisions = table.getNumCollisions();
            table.insert(iq_key, student);
            finalCollisions = table.getNumCollisions();
            currentCollisions = finalCollisions - initialCollisions;
            sc_iq_file << "SeparateChaining,IQ," << table.getTableSize() << "," << i << "," << iq_key << "," << currentCollisions << "\n";
        }
        // Open Addressing with ID key
        for (auto &table : oaTablesId) {
            initialCollisions = table.getNumCollisions();
            table.insert(id_key, student);
            finalCollisions = table.getNumCollisions();
            currentCollisions = finalCollisions - initialCollisions;
            oa_id_file << "OpenAddressing,ID," << table.getTableSize() << "," << i << "," << id_key << "," << currentCollisions << "\n";

        }
        // Open Addressing with IQ key
        for (auto &table : oaTablesIq) {
            initialCollisions = table.getNumCollisions();
            table.insert(iq_key, student);
            finalCollisions = table.getNumCollisions();
            currentCollisions = finalCollisions - initialCollisions;
            oa_iq_file << "OpenAddressing,IQ," << table.getTableSize() << "," << i << "," << iq_key << "," << currentCollisions << "\n";
        }
    }
    // Close all the files
    sc_id_file.close();
    sc_iq_file.close();
    oa_id_file.close();
    oa_iq_file.close();
    cout << "Insertion complete, Collision data saved to 4 separate files." << endl;

    cout << "Final open addressing table sizes after rehashing:" << endl;

    cout << "Open Addressing (ID Key):" << endl;
    for (auto& table : oaTablesId) {
        // Call the getter function to print its final size
        cout << "Final Size: " << table.getTableSize() << endl;
    }

    cout << "\nOpen Addressing (IQ Key):" << endl;
    // Loop through the 5 tables in the oaTablesIq vector
    for (auto& table : oaTablesIq) {
        // Call the getter function to print its final size
        cout << "Final Size: " << table.getTableSize() << endl;
    }
        return 0;
}