/*
Event Scheduler [10]: Implement an event scheduler that manages upcoming events
or appointments. Each event can be represented as a node in the linked list.
Each event node should have a name, date, and event details. The system should
support operations such as adding new events, removing events, updating event
details, and displaying the list of upcoming events. Choose an appropriate
format of your choice for the date. The events in the linked list should always
be sorted based on date. Whenever you add a new event, it should be added to the
position with respect to its date.
*/

#include <iostream>
#include <string>
using namespace std;

class EventScheduler {
   private:
    struct Event {
        string name;
        string date;
        string details;
        Event *next;
    };
    Event *head, *tail;

   public:
    // Constructor and destructor
    EventScheduler() {
        head = nullptr;
        tail = nullptr;
    }
    ~EventScheduler() {}

    // Method definitions
    void add_event(string name, string date, string details) {
        // add a new event to the list with the given date
        Event *new_event = new Event;
        new_event->name = name;
        new_event->date = date;
        new_event->details = details;
        new_event->next = nullptr;

        if (head == nullptr) {
            head = new_event;
            tail = new_event;
        } else {
            Event *current = head;
            Event *prev = nullptr;
            while (current != nullptr && current->date < date) {
                prev = current;
                current = current->next;
            }
            if (prev == nullptr) {
                new_event->next = head;
                head = new_event;
            } else if (current == nullptr) {
                tail->next = new_event;
                tail = new_event;
            } else {
                prev->next = new_event;
                new_event->next = current;
            }
        }
    }

    void remove_event(string date) {
        // remove the event with the given date from the list
        Event *current = head;
        Event *prev = nullptr;
        while (current != nullptr) {
            if (current->date == date) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Event with date " << date << " not found." << endl;
    }

    void update_event(string date, string new_name, string new_details) {
        // update the event with the given date with the new name and details
        Event *current = head;
        while (current != nullptr) {
            if (current->date == date) {
                current->name = new_name;
                current->details = new_details;
                return;
            }
            current = current->next;
        }

        cout << "Event with date " << date << " not found." << endl;
    }

    void display_events() {
        // display all the events in the list
        Event *current = head;
        while (current != nullptr) {
            cout << "- Name" << current->name << ", Date: " << current->date
                 << ", Details: " << current->details << endl;

            current = current->next;
        }
    }
};

int main() {
    EventScheduler scheduler;

    cout << "Adding events" << endl;
    scheduler.add_event("Meeting", "2021/10/15", "Discuss project progress");
    scheduler.add_event("Lunch", "2021/10/16", "Meet with friends");
    scheduler.add_event("Dinner", "2021/10/17", "Family gathering");
    scheduler.add_event("Conference", "2021/10/18", "Attend tech conference");
    scheduler.add_event("Birthday", "2019/10/19", "Celebrate with friends");
    scheduler.display_events();

    cout << "\nRemoving event on 2021/10/17" << endl;
    scheduler.remove_event("2021/10/17");
    scheduler.display_events();

    cout << "\nUpdating event on 2021/10/16" << endl;
    scheduler.update_event("2021/10/16", "Brunch",
                           "Meet with friends and family");
    scheduler.display_events();

    return 0;
}