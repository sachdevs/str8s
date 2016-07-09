#include "View.h"
#include "Observer.h"
#include "Controller.h"
#include "Model.h"
#include "Subject.h"

View::View(Controller* c, Model* m) : controller_(c), model_(m) {};

View::~View() {};

void View::update() {

}