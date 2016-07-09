#include "Subject.h"
#include "Observer.h"

void Subject::subscribe(Observer* newView) {
    observers.insert(newView);
}

void Subject::unsubscribe(Observer* targetView) {
    observers.erase(targetView);
}

void Subject::notify() {
    for (auto it = observers.begin(); it != observers.end(); it++) {
        (*it)->update();
    }
}