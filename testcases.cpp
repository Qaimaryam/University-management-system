#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// ---------- Faculty Profile Data ----------
struct FacultyProfile {
    string facultyId;
    string name;
    string email;
    string department;
};

FacultyProfile* facultyProfiles = new FacultyProfile[10];
int facultyCount = 0;

void SeedFacultyData() {
    facultyProfiles[0] = { "Dr.Ahmed", "Ahmed Khan", "ahmed@uni.edu", "Computer Science" };
    facultyCount = 1;
}

// ---------- Refactored Helper Function ----------
int FindFacultyIndex(string facultyId) {
    for (int i = 0; i < facultyCount; i++) {
        if (facultyProfiles[i].facultyId == facultyId) {
            return i;
        }
    }
    return -1; // faculty nahi mila
}

// ---------- Core Functions (Now Using Helper) ----------
bool UpdateFacultyProfile(string facultyId, string newEmail, string newDepartment) {
    int index = FindFacultyIndex(facultyId);
    if (index == -1) {
        return false;
    }
    facultyProfiles[index].email = newEmail;
    facultyProfiles[index].department = newDepartment;
    return true;
}

FacultyProfile GetFacultyProfile(string facultyId) {
    int index = FindFacultyIndex(facultyId);
    if (index == -1) {
        FacultyProfile empty = { "", "", "", "" };
        return empty;
    }
    return facultyProfiles[index];
}

// ---------- Test Case ----------
void TestUpdateProfile_ChangesReflectedImmediately() {
    SeedFacultyData();

    bool updated = UpdateFacultyProfile("Dr.Ahmed", "ahmed.khan@uni.edu", "Software Engineering");
    assert(updated == true);

    FacultyProfile profile = GetFacultyProfile("Dr.Ahmed");
    assert(profile.email == "ahmed.khan@uni.edu");
    assert(profile.department == "Software Engineering");

    cout << "TestUpdateProfile_ChangesReflectedImmediately PASSED\n";
}

// ---------- Main ----------
int main() {
    TestUpdateProfile_ChangesReflectedImmediately();

    cout << "\nAll faculty tests PASSED successfully!\n";

    delete[] facultyProfiles;
    return 0;
}