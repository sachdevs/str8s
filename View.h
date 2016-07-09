#ifndef _VIEW_
#define _VIEW

#include "Observer.h"

class Controller;
class Model;

class View : public Observer {
public:
    View(Controller*, Model*);
    virtual ~View();
    virtual void update();              //Concrete update() method for Observer pattern
private:
    Model* model_;
    Controller* controller_;
};

#endif
