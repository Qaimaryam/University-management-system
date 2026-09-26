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

// Sirf declaration - body nahi likhi abhi
bool UpdateFacultyProfile(string facultyId, string newEmail, string newDepartment);
FacultyProfile GetFacultyProfile(string facultyId);

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