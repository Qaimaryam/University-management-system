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

bool CheckAndSendReminder(string facultyId, int minutesUntilClass) {
    if (minutesUntilClass == REMINDER_THRESHOLD_MINUTES) {
        NotifyUser(facultyId, "Reminder", "You have a class in 15 minutes");
        return true;
    }
    return false;
}

// Sirf declaration - body nahi likhi abhi
bool DisableNotificationType(string studentId, string type);
bool WillReceiveNotification(string userId, string type);

void TestDisableNotification_StopsReceiving() {
    DisableNotificationType("Ali", "Announcement");
    bool willReceive = WillReceiveNotification("Ali", "Announcement");
    assert(willReceive == false);
    cout << "TestDisableNotification_StopsReceiving PASSED\n";
}

int main() {
    TestDisableNotification_StopsReceiving();
    return 0;
}