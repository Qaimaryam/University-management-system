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

// Sirf declaration - body nahi likhi abhi
bool CancelClass(string classId);

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