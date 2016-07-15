//
// Created by Saksham Sachdev on 2016-07-14.
//

#ifndef STR8S_INFOTEXTDIALOGVIEW_H
#define STR8S_INFOTEXTDIALOGVIEW_H


#include <gtkmm/window.h>
#include <gtkmm/dialog.h>

class InfoTextDialogView : Gtk::Dialog {
public:
    // Specifies the parent window of the dialog box and the title of the dialog box.
    InfoTextDialogView( Gtk::Window& parentWindow, std::string title);
    virtual ~InfoTextDialogView();
};


#endif //STR8S_INFOTEXTDIALOGVIEW_H
