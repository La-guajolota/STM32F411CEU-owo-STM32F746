#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    /*
     * Funciones virtuales
     */
    virtual void uart_Data (char *data);
    virtual void can_Data (int data);

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
