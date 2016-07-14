//
// Created by Saksham Sachdev on 2016-07-13.
//

#include "TableView.h"

TableView::TableView(Controller *c, Game* m) : View::View(c, m) {

    model_->subscribe(this);
}

void TableView::update() {
    View::update();
}

TableView::~TableView() {

}





