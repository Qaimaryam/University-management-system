#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct Notification {
    string userId;
    string type;
    string message;
};

Notification* inbox = new Notification[100];
int inboxCount = 0;

string* enrolledStudents = new string[3]{ "Ali", "Sara", "Zain" };
int studentCount = 3;

void NotifyUser(string userId, string type, string message) {
    inbox[inboxCount].userId = userId;
    inbox[inboxCount].type = type;
    inbox[inboxCount].message = message;
    inboxCount++;
}

bool CancelClass(string classId) {
    for (int i = 0; i < studentCount; i++) {
        NotifyUser(enrolledStudents[i], "Cancellation", "Class " + classId + " has been cancelled");
    }
    return true;
}

void TestCancelClass_NotifiesStudents() {
    bool cancelled = CancelClass("CS101");
    assert(cancelled == true);

    bool found = false;
    for (int i = 0; i < inboxCount; i++) {
        if (inbox[i].userId == "Ali" && inbox[i].type == "Cancellation") {
            found = true;
        }
    }
    assert(found == true);
    cout << "TestCancelClass_NotifiesStudents PASSED\n";
}

int main() {
    TestCancelClass_NotifiesStudents();
    return 0;
}