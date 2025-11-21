//
// Created by jacob on 9/7/2025.
//

#ifndef PROJECT1_COLLEGEPLACEMENT_H
#define PROJECT1_COLLEGEPLACEMENT_H

#include <cmath>
#include <fstream>
#include <iostream> // Allows you to print to the console
#include <iomanip>
#include <string>
#include <vector>


using std::ifstream, std::left, std::right, std::setw, std::stod, std::stoi,std::ostream, std::string, std::vector;


class CollegeStudent {
private:
    // Fields
    string collegeId, internshipExperience, placement;
    int iq, academicPerformance, extraCurricularScore, communicationSkills, projectsCompleted, uniqueNumber;
    double prevSemResult, cGPA;

    public:
    // Methods

    // Default Constructor
    CollegeStudent() {
        // String
        collegeId = "ABC123";
        internshipExperience = "ABC123";
        placement = "ABC123";
        // Int
        iq = 100;
        academicPerformance = 5;
        extraCurricularScore = 0;
        communicationSkills = 5;
        projectsCompleted = 0;
        uniqueNumber = 0;
        // Double
        prevSemResult = 5.0;
        cGPA = 5.0;
    }
    /*
     * Main Constructor for a College Student Object.
     * @param collegeId the student's college identification.
     * @param iq the student's IQ.
     * @param academicPerformance on a scale of 1 to 10.
     * @param extraCurricularScore on a scale of 1 to 10.
     * @param communicationSkills on a scale of 1 to 10.
     * @param projectsCompleted on a scale of 1 to 5.
     * @param prevSemResult the student's previous semester GPA.
     * @param cGPA the student's cumulative GPA.
     * @param internshipExperience Yes or No.
     * @param placement Yes or No.
     * @param uniqueNumber the row number.
     */
    CollegeStudent(string collegeId, int iq, int academicPerformance,
        int extraCurricularScore, int communicationSkills,
        int projectsCompleted, double prevSemResult, double cGPA,
        string internshipExperience, string placement, int uniqueNumber) {
        this->collegeId = collegeId;
        this->iq = iq;
        this->academicPerformance = academicPerformance;
        this->extraCurricularScore = extraCurricularScore;
        this->communicationSkills = communicationSkills;
        this->projectsCompleted = projectsCompleted;
        this->prevSemResult = prevSemResult;
        this->cGPA = cGPA;
        this->internshipExperience = internshipExperience;
        this->placement = placement;
        this->uniqueNumber = uniqueNumber;
    }


    // Getters
    string getId() const {
        return collegeId;
    }
    int getIq() const {
        return iq;
    }
    int getAcademicPerformance() const {
        return academicPerformance;
    }
    int getExtraCurricularScore() const {
        return extraCurricularScore;
    }
    int getCommunicationSkills() const {
        return communicationSkills;
    }
    int getProjectsCompleted() const {
        return projectsCompleted;
    }
    double getPrevSemResult() const {
        return prevSemResult;
    }
    double getCGPA() const {
        return cGPA;
    }
    string getInternship() const {
        return internshipExperience;
    }
    string getPlacement() const {
        return placement;
    }
    int getUniqueNumber() const {
        return uniqueNumber;
    }
    // Setters
    void setID(string collegeId) {
        this->collegeId = collegeId;
    }
    void setIQ(int iq) {
        this->iq = iq;
    }
    void setAcademicPerformance(int academicPerformance) {
        this->academicPerformance = academicPerformance;
    }
    void setExtraCurricularScore(int extraCurricularScore) {
        this->extraCurricularScore = extraCurricularScore;
    }
    void setCommunicationSkills(int communicationSkills) {
        this->communicationSkills = communicationSkills;
    }
    void setProjectsCompleted(int projectsCompleted) {
        this->projectsCompleted = projectsCompleted;
    }
    void setPrevSemResult(double prevSemResult) {
        this->prevSemResult = prevSemResult;
    }
    void setCGPA(double cGPA) {
        this->cGPA = cGPA;
    }
    void setInternshipExperience(string internshipExperience) {
        this->internshipExperience = internshipExperience;
    }
    void setPlacement(string placement) {
        this->placement = placement;
    }
    void setUniqueNumber(int uniqueNumber) {
        this->uniqueNumber = uniqueNumber;
    }

    // Overloaded Stream Insertion
    friend ostream &operator<<(ostream &outs, const CollegeStudent &s) {
        outs << setw(7) <<  left << s.collegeId;
        outs << setw(4) << right << s.iq;
        outs << setw(5) << s.prevSemResult;
        outs << setw(5) << s.cGPA;
        outs << setw(2) << s.academicPerformance;
        outs << setw(4) << s.internshipExperience;
        outs << setw(2) << s.extraCurricularScore;
        outs << setw(2) << s.communicationSkills;
        outs << setw(1) << s.projectsCompleted;
        outs << setw(4) << s.placement;
        outs << setw(6) << s.uniqueNumber;
        return outs;
    }

    // Overloaded Operators

    // Overloaded < Operator for object comparison
    friend bool operator < (const CollegeStudent &lStudent, const CollegeStudent &rStudent) {
        return lStudent.getId() < rStudent.getId();
    }
    // Overloaded > Operator for object comparison
    friend bool operator > (const CollegeStudent &lStudent, const CollegeStudent &rStudent) {
        return lStudent.getId() > rStudent.getId();
    }
    // Overloaded <= Operator for object comparison
    friend bool operator <= (const CollegeStudent &lStudent, const CollegeStudent &rStudent) {
        return lStudent.getId() <= rStudent.getId();
    }
    // Overloaded >- Operator for object comparison
    friend bool operator >= (const CollegeStudent &lStudent, const CollegeStudent &rStudent) {
        return lStudent.getId() >= rStudent.getId();
    }
    // Overloaded == Operator for object comparison
    friend bool operator == (const CollegeStudent &lStudent, const CollegeStudent &rStudent) {
        return lStudent.getId() == rStudent.getId();
    }
    // Overloaded != Operator for object comparison
    friend bool operator != (const CollegeStudent &lStudent, const CollegeStudent &rStudent) {
        return lStudent.getId() != rStudent.getId();
    }
};


bool getDataFromFile(string fileName, vector<CollegeStudent> &objs) {
    // Getting the file
    ifstream fileIn;
    fileIn.open(fileName);

    // Skip the first line (header)
    if (fileIn) {
        string header;
        getline(fileIn, header);
    }

    // Declare Variables
    string collegeId;
    string internshipExperience;
    string placement;
    int iq, extraCurricularScore, academicPerformance, communicationSkills, projectsCompleted, uniqueNumber;
    double cGPA, prevSemResult;
    char comma;
    // bool internshipExperience, placement;

    // While the file is in a good state and not at end of file (EOF)
    // peek checks the next line
    while (fileIn && fileIn.peek() != EOF) {
        collegeId = "ABC123";
        iq = -1;
        extraCurricularScore = -1;
        communicationSkills = -1;
        projectsCompleted = -1;
        uniqueNumber = -1;
        cGPA = -1.0;
        prevSemResult = -1.0;
        internshipExperience = "Hello";
        placement = "Hello";
        comma = ',';

        // College ID Column
        getline(fileIn, collegeId, ',');
        // IQ Column
        fileIn >> iq;
        fileIn >> comma;
        // Previous Semester Result Column
        fileIn >> prevSemResult;
        fileIn >> comma;
        // Cumulative GPA Column
        fileIn >> cGPA;
        fileIn >> comma;
        // Academic Performance Column
        fileIn >> academicPerformance;
        fileIn >> comma;
        // Internship Experience Column
        getline(fileIn, internshipExperience, ',');
        // Extra Curricular Score Column
        fileIn >> extraCurricularScore;
        fileIn >> comma;
        // Communication Skills Column
        fileIn >> communicationSkills;
        fileIn >> comma;
        // Projects Completed Column
        fileIn >> projectsCompleted;
        fileIn >> comma;
        // Placement Column
        getline(fileIn, placement, ',');
        // Unique Number Column
        fileIn >> uniqueNumber;
        fileIn >> comma;

        CollegeStudent student(collegeId, iq, academicPerformance, extraCurricularScore,
            communicationSkills, projectsCompleted, prevSemResult, cGPA,
            internshipExperience, placement, uniqueNumber);

        objs.push_back(student);
    }
    fileIn.close();
    return true;
}


/* Calculate Function for the mean of the dataset (vector).
 * Uses a template in order to allow the function to return
 * any type, such as IQ returning int and CPA returning double.
 * @param getterValue A pointer to a getter from the CollegeStudent class;
 * I used Gemini AI to help explain this concept to me, as I really wanted
 * To make my calculate functions more general instead of specific to one getter.
 * @param objs the vector objects, AKA the students in the dataset.
 * @return The calculated mean.
 */
template <typename T>
T calculateMean(T (CollegeStudent::*getterValue)() const ,const vector<CollegeStudent> &objs) {
    double sum = 0.0;
    for (int i = 0; i < objs.size(); i++) {
        sum += (objs[i].*getterValue)();
    }
    return sum / objs.size();
}
/* Calculate Function for the max of the dataset (vector).
 * Uses a template in order to allow the function to return
 * any type, such as IQ returning int and CPA returning double.
 * @param getterValue a pointer to a getter from the CollegeStudent class;
 * @param objs the vector objects, AKA the students in the dataset.
 * @return the calculated max.
 */
template <typename T>
T calculateMax(T (CollegeStudent::*getterValue)() const, const vector<CollegeStudent> &objs) {
    double currentHighest = 0;
    for (int i = 0; i < objs.size(); i++) {
        if ((objs[i].*getterValue)() > currentHighest) {
            currentHighest = (objs[i].*getterValue)();
        }
    }
    return currentHighest;
}
/* Calculate Function for the min of the dataset (vector).
 * Uses a template in order to allow the function to return
 * any type, such as IQ returning int and CPA returning double.
 * @param getterValue A pointer to a getter from the CollegeStudent class;
 * @param objs the vector objects, AKA the students in the dataset.
 * @return The calculated min.
 */
template <typename T>
T calculateMin(T (CollegeStudent::*getterValue)() const, const vector<CollegeStudent> &objs) {
    int LARGE_NUM = 1000;
    int currentLowest = LARGE_NUM;
    for (int i = 0; i < objs.size(); i++) {
        if ((objs[i].*getterValue)() < currentLowest) {
            currentLowest = (objs[i].*getterValue)();
        }
    }
    return currentLowest;
}


 template <typename T>
 T calculateStDev(T (CollegeStudent::*getterValue)() const, const vector<CollegeStudent> &objs) {
     double const MEAN = calculateMean(getterValue, objs);
     double numeratorOfFormula = 0.0;
     double denominatorOfFormula = objs.size() - 1;
     for (int i = 0; i < objs.size(); i++) {
         numeratorOfFormula += pow((objs[i].*getterValue)() - MEAN, 2);
     }
     return sqrt(numeratorOfFormula / denominatorOfFormula);
}

/*
 * Function that filters the dataset into three new vectors:
 * lowerData, middleData, and upperData, which are the lower middle and upper
 * values of the data based off of the cGPA mean and standard deviation.
 * @param getterValue a pointer to a getter from the CollegeStudent class;
 * @param objs the vector objects, AKA the students in the dataset.
 * @param lowerUnplaced the lower values of the dataset based off of cGPA that weren't placed.
 * @param middleUnplaced the middle values of the dataset based off of cGPA that weren't placed.
 * @param upperUnplaced the upper values of the dataset based off of cGPA that weren't placed.
* * @param lowerPlaced the lower values of the dataset based off of cGPA that were placed.
 * @param middlePlaced the middle values of the dataset based off of cGPA that were placed.
 * @param upperPlaced the upper values of the dataset based off of cGPA that were placed.
 */
template <typename T>
 void filterStudents(T (CollegeStudent::*getterValue)() const, const vector<CollegeStudent> &objs,
     vector <CollegeStudent> &lowerUnplaced,
     vector <CollegeStudent> &middleUnplaced,
     vector <CollegeStudent> &upperUnplaced,
     vector <CollegeStudent> &lowerPlaced,
     vector <CollegeStudent> &middlePlaced,
     vector <CollegeStudent> &upperPlaced) {

    // Constants:

    // Mean constant calculated with the function calculateMean()
    double const MEAN = calculateMean(getterValue, objs);
    // Standard Deviation constant calculated with the function calculateStDev()
    double const STDEV = calculateStDev(getterValue, objs);
    // Lower Deviation constant calculated through the two constants above
    double const LOWERDEVIATION = MEAN - STDEV;
    // Upper Deviation constant calculated through the two constants above
    double const UPPERDEVIATION = STDEV + MEAN;

    // For loop that iterates through the student objects
    for (int i = 0; i < objs.size(); i++) {
        // The T will be of type double and will be used for the student's cGPA
        T valueCGPA = (objs[i].*getterValue)();
        // Case for when the student's cGPA is less than the lower deviation
        if (valueCGPA < LOWERDEVIATION) {
            // Whether the student was placed
            if (objs[i].getPlacement() == "Yes") {
                lowerPlaced.push_back(objs[i]);
            }
            else {
                lowerUnplaced.push_back(objs[i]);
            }
        }
        // Case for when the student's cGPA is greater than the upper deviation
        else if (valueCGPA > UPPERDEVIATION) {
            // Whether the student was placed
            if (objs[i].getPlacement() == "Yes") {
                upperPlaced.push_back(objs[i]);
            }
            else {
                upperUnplaced.push_back(objs[i]);
            }
        }
        // Case for when the student's cGPA is greater than the lower deviation
        // but less than the upper deviation (average)
        else {
            // Whether the student was placed
            if (objs[i].getPlacement() == "Yes") {
                middlePlaced.push_back(objs[i]);
            }
            else {
                middleUnplaced.push_back(objs[i]);
            }
        }
    }
}

#endif //PROJECT1_COLLEGEPLACEMENT_H