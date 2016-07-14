#include "View.h"
#include "Observer.h"
#include "Controller.h"
#include "Model.h"
#include "Subject.h"

View::View(Controller* c, Game* m) : controller_(c), model_(m) {
    // Register view as observer of model
    model_->subscribe(this);
}

View::~View() {};

void View::update() {

}