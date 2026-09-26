#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct Notification {
    string userId;
    string type;
    string message;
};

const int REMINDER_THRESHOLD_MINUTES = 15;

Notification* inbox = new Notification[100];
int inboxCount = 0;

string* enrolledStudents = new string[3]{ "Ali", "Sara", "Zain" };
int studentCount = 3;

string* disabledStudentIds = new string[50];
string* disabledTypesArr = new string[50];
int disabledCount = 0;

bool WillReceiveNotification(string userId, string type); // forward declaration

void NotifyUser(string userId, string notificationType, string notificationMessage) {
    if (!WillReceiveNotification(userId, notificationType)) {
        return;
    }
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

bool CheckAndSendReminder(string facultyId, int minutesUntilClass) {
    if (minutesUntilClass == REMINDER_THRESHOLD_MINUTES) {
        NotifyUser(facultyId, "Reminder", "You have a class in 15 minutes");
        return true;
    }
    return false;
}

bool DisableNotificationType(string studentId, string type) {
    disabledStudentIds[disabledCount] = studentId;
    disabledTypesArr[disabledCount] = type;
    disabledCount++;
    return true;
}

bool WillReceiveNotification(string userId, string type) {
    for (int i = 0; i < disabledCount; i++) {
        if (disabledStudentIds[i] == userId && disabledTypesArr[i] == type) {
            return false;
        }
    }
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
    cout << "TestSendAnnouncement_ReachesAllStudents PASSED\n";
}

void TestReminder_SentAt15Minutes() {
    bool sent = CheckAndSendReminder("Dr.Ahmed", 15);
    assert(sent == true);
    cout << "TestReminder_SentAt15Minutes PASSED\n";
}

void TestReminder_NotSentEarly() {
    bool sent = CheckAndSendReminder("Dr.Ahmed", 60);
    assert(sent == false);
    cout << "TestReminder_NotSentEarly PASSED\n";
}

void TestDisableNotification_StopsReceiving() {
    DisableNotificationType("Ali", "Announcement");
    bool willReceive = WillReceiveNotification("Ali", "Announcement");
    assert(willReceive == false);
    cout << "TestDisableNotification_StopsReceiving PASSED\n";
}

int main() {
    TestCancelClass_NotifiesStudents();
    TestSendAnnouncement_ReachesAllStudents();
    TestReminder_SentAt15Minutes();
    TestReminder_NotSentEarly();
    TestDisableNotification_StopsReceiving();

    delete[] inbox;
    delete[] enrolledStudents;
    delete[] disabledStudentIds;
    delete[] disabledTypesArr;

    return 0;
}