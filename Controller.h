#ifndef _CONTROLLER_
#define _CONTROLLER_

class Model;

class Controller {
public:
    Controller(Model*);

private:
    Model* model_;
};

#endif