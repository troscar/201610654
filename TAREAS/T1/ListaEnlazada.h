#include <iostream>
#include <string>
using namespace std;
class Lista
{
    class Nodo{
    public:
        Nodo(string x, string n)
        {
            next = 0;
            carne = x;
            nombre = n;
        }

        Nodo *getNext(){ return next;}
        void setNext(Nodo *n) { next = n;}
        string getCarne(){ return carne;}
        string getNombre(){ return nombre;}
        
     private:
        Nodo *next;
        string carne;
        string nombre;
    };
     public:
         Lista()
         {
             first = 0;
             last = 0;
             size = 0;
         }

        int getSize(){return size;}

        void add_first(string car, string nom)
        {
            Nodo *n = new Nodo(car,nom);
            if(this->isEmpty())
            {
                this->first = n;
                this->last = n;
                this->size++;
            }
            else
            {
                n->setNext(this->first);
                this->first = n;
                this->size++;
            }
        }

        void add_last(string car, string nom)
        {
            if(this->isEmpty())
            {
                this->add_first(car, nom);
            }
            else
            {
                Nodo *n = new Nodo(car,nom);
                this->last->setNext(n);
                this->last = n;
                this->size++;
            }
        }

        void add_at(string car, string nom, int index)
        {
            if(index >= 0 && index <= this->size)
            {
                if(index == 0){ this->add_first(car,nom); return;}
                if(index == this->size) {this->add_last(car,nom); return;}
                Nodo *aux = this->first;
                Nodo *aux2 = 0;
                int x = 0;
                while(aux!=0)
                {
                    if(x == index){break;}
                    aux2 = aux;
                    aux = aux->getNext();
                    x++;
                }
                Nodo *n = new Nodo(car,nom);
                aux2->setNext(n);
                n->setNext(aux);
                this->size++;
            }
        }

        bool element_exist(string index)
        {
            if (getSize()>0)
            {
                Nodo *iterador = this->first;
                while (iterador!= 0)
                {
                    if(iterador->getCarne().compare(index))
                    {
                        return true;
                    }
                    iterador= iterador->getNext();
                }
                return false;
            }
            else
            {
                return false;
            }
            
        }

        void get_element(string index)
        {
            if(element_exist(index))
            {
                Nodo *iterador = first;
                while (iterador!= 0)
                {
                    if(iterador->getCarne().compare(index))
                    {
                        cout<< "Carne: "+ index+"  Nombre: "+iterador->getNombre()<< endl;
                        break;
                    }
                    iterador= iterador->getNext();
                }
            }else{
                cout<< "carne inexistente "<< endl;
            }
        }

        void remove(string index){
            if(this->first!=0){
                Nodo *iterador = this->first;
                Nodo *aux = iterador->getNext();
                while (iterador->getNext()!= 0)
                {
                    if(aux->getCarne().compare(index))
                    {
                        iterador->setNext(iterador->getNext()->getNext());
                        cout<< "alumno eliminado "<< endl;
                        break;
                    }
                    
                    iterador= iterador->getNext();
                    aux= iterador->getNext();
                }
            }
            else{ 
                cout<< "carne inexistente "<< endl;
            }
        }

        void mostar()
        {
            if(!this->isEmpty())
            {
                Nodo *iterador = first;
                while (iterador!= 0)
                {
                    cout<< "Carne: "+ iterador->getCarne() + "; Nombre: " + iterador->getNombre()<< endl;
                    iterador = iterador->getNext();
                }
            }
        }
        
        private:
            bool isEmpty(){return size == 0;}
            int size;
            Nodo *first;
            Nodo *last;
};