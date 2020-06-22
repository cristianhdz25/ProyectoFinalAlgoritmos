#include "DeleteWindow.h"

DeleteWindow::DeleteWindow() {
    this->set_size_request(220, 230);
    this->set_title("Administrador");
    init();
}//constructor

void DeleteWindow::init() {
    this->lblConsulta.set_text("Tiquete");
    this->fixed.put(this->lblConsulta, 90, 20);
    this->fixed.put(this->etConsulta, 90, 50);

    this->btnEliminar.set_label("Get in");
//    this->btnEliminar.signal_clicked().connect(sigc::mem_fun(*this, &DeleteWindow::clickedIn));
    this->fixed.put(this->btnEliminar, 90, 100);
    
    this->add(this->fixed);
    this->show_all_children();
}//init

void DeleteWindow::clickedIn() {

}//clickedIn
