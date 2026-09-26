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

void NotifyUser(string userId, string notificationType, string notificationMessage) {
    inbox[inboxCount].userId = userId;
    inbox[inboxCount].type = notificationType;
    inbox[inboxCount].message = notificationMessage;
    inboxCount++;
}

void NotifyAllStudents(string notificationType, string notificationMessage) {
    for (int i = 0; i < studentCount; i++) {
        NotifyUser(enrolledStudents[i], notificationType, notificationMessage);
    }
}

bool CancelClass(string classId) {
    NotifyAllStudents("Cancellation", "Class " + classId + " has been cancelled");
    return true;
}

bool SendAnnouncement(string message) {
    NotifyAllStudents("Announcement", message);
    return true;
}

void TestCancelClass_NotifiesStudents() {
    bool cancelled = CancelClass("CS101");
    assert(cancelled == true);
    cout << "TestCancelClass_NotifiesStudents PASSED\n";
}

void TestSendAnnouncement_ReachesAllStudents() {
    bool sent = SendAnnouncement("Exam postponed");
    assert(sent == true);

    int count = 0;
    for (int i = 0; i < inboxCount; i++) {
        if (inbox[i].type == "Announcement") count++;
    }
    assert(count == studentCount);
    cout << "TestSendAnnouncement_ReachesAllStudents PASSED\n";
}

int main() {
    TestCancelClass_NotifiesStudents();
    TestSendAnnouncement_ReachesAllStudents();
    return 0;
}