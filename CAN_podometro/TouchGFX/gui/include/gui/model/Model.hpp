#ifndef MODEL_HPP
#define MODEL_HPP


class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
    char RData[4];//Del uart 4 caracteres
    int podometro; //Del can
};

#endif // MODEL_HPP
