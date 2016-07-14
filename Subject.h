#ifndef _SUBJECT_
#define _SUBJECT_

#include <set>

class Observer;

class Subject {
public:
    void subscribe(Observer*);
    void unsubscribe(Observer*);
    std::set<Observer*> observers;

protected:
    void notify();

private:
};

#endif