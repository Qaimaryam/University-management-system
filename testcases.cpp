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

bool UpdateFacultyProfile(string facultyId, string newEmail, string newDepartment) {
    for (int i = 0; i < facultyCount; i++) {
        if (facultyProfiles[i].facultyId == facultyId) {
            facultyProfiles[i].email = newEmail;
            facultyProfiles[i].department = newDepartment;
            return true;
        }
    }
    return false;
}

FacultyProfile GetFacultyProfile(string facultyId) {
    for (int i = 0; i < facultyCount; i++) {
        if (facultyProfiles[i].facultyId == facultyId) {
            return facultyProfiles[i];
        }
    }
    FacultyProfile empty = { "", "", "", "" };
    return empty;
}
void TestUpdateProfile_ChangesReflectedImmediately() {
    SeedFacultyData();

    bool updated = UpdateFacultyProfile("Dr.Ahmed", "ahmed.khan@uni.edu", "Software Engineering");
    assert(updated == true);

    FacultyProfile profile = GetFacultyProfile("Dr.Ahmed");
    assert(profile.email == "ahmed.khan@uni.edu");
    assert(profile.department == "Software Engineering");

    cout << "TestUpdateProfile_ChangesReflectedImmediately PASSED\n";
}

int main() {
    TestUpdateProfile_ChangesReflectedImmediately();

    delete[] facultyProfiles;
    return 0;
}