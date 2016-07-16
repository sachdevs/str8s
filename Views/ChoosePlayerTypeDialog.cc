/*
 *  MyDialogBox.cc
 *
 *  Created by Caroline Kierstead on 28/05/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */
#include "ChoosePlayerTypeDialog.h"
#include <gtkmm/stock.h>
#include <iostream>

using std::string;
using std::vector;

// Specifies the parent window of the dialog box and the title of the dialog box.
ChoosePlayerTypeDialog::ChoosePlayerTypeDialog( Gtk::Window & parentWindow, string title) : Dialog( title, parentWindow, true, true ) {
	vector<string> messages;
	messages.push_back( "AI" );
	messages.push_back( "Human" );

	// Obtain the dialog box's vertical alignment box.
	Gtk::VBox* contentArea = this->get_vbox();
	
	// Set up a group of radio buttons
	for ( unsigned int i = 0; i < messages.size(); i++ ) {
		buttons.push_back( Gtk::manage( new Gtk::RadioButton( group, messages[i] ) ) );
		contentArea->add( *buttons[i] );
	} 
	
	// Make a button other than the first radio button the initial active choice.
	buttons[ messages.size() - 1 ]->set_active();
	
	// Add a standard "ok" button with the appropriate responses when clicked.
  add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);
	show_all_children();
	
    // Wait for a response from the dialog box.
	int result = run();
  switch (result) {
    case Gtk::RESPONSE_OK:
      for ( unsigned int i = 0; i < messages.size(); i++ ) {
				if ( buttons[i]->get_active() ) {
                    selection = i != 0;
					break;
				}
			}
      break;
  }     	
}

ChoosePlayerTypeDialog::~ChoosePlayerTypeDialog() {
	for ( unsigned int i = 0; i < buttons.size(); i++ ) delete buttons[i];
	buttons.clear();
}

bool ChoosePlayerTypeDialog::isHuman() {
    return selection;
}
