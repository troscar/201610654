#include <iostream>
#include <string>
#include <fstream>
#include "ListaEnlazada.h"
using namespace std;

int main()
{
    Lista *l = new Lista();
    l->add_first("2020","oz") ;
    l->add_first("2021","car") ;
    l->add_first("2022","ra") ;
    l->add_last("2023","ul");
    l->add_last("2024","avi");
    l->mostar();
    cout<< "------------1-------" <<endl;
    l->add_at("2025","la",3);
    l->mostar();cout<< "-------------2------" <<endl;
    cout<< l->element_exist("2021") <<endl;cout<< "------3-------------" <<endl;
    l->get_element("2020");cout<< "----------4---------" <<endl;
    l->remove("2021");cout<< "------------5-------" <<endl;
    l->mostar();
    system("pause");

    return 0;
}
