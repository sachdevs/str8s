#ifndef _VIEW_
#define _VIEW_

#include <gtkmm.h>
#include "Observer.h"
#include "Controller.h"
#include "Model.h"

class View : public Observer {
public:
    View(Controller*, Game*);
    virtual ~View();
    virtual void update();              //Concrete update() method for Observer pattern
protected:
    Game* model_;
    Controller* controller_;

};

#endif
