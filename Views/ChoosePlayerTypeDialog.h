#ifndef STR8S_CHOOSEPLAYERTYPE_H
#define STR8S_CHOOSEPLAYERTYPE_H

#include <gtkmm/dialog.h>
#include <gtkmm/box.h>
#include <gtkmm/radiobuttongroup.h>
#include <gtkmm/radiobutton.h>
#include <string>
#include <vector>


class ChoosePlayerTypeDialog : Gtk::Dialog {
public:
	// Specifies the parent window of the dialog box and the title of the dialog box.
	ChoosePlayerTypeDialog( Gtk::Window & parentWindow, std::string title);
	virtual ~ChoosePlayerTypeDialog();
    bool isHuman();
	
private:
	Gtk::RadioButton::Group group;                   // Used to group the radio buttons so only one can be active at a time.
	std::vector<Gtk::RadioButton *> buttons;         // Buttons for the messages.
    bool selection;
};

#endif
