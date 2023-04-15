#include "generator.h"

Generator::Generator()
{

}

double Generator::generateNumber()
{
    static float _saveInterval = 0;
    double _generatedNumber;
    if(m_status)
    {
        _generatedNumber = AMPLITUDE * sin(2 * PI_NUMBER * FREQUENCY * _saveInterval) + AMPLITUDE ;
        _saveInterval += INTERVAL;
    }
    else
    {
        _saveInterval = 0;
        _generatedNumber = 0.0;
    }

    return _generatedNumber;
}

void Generator::setStatus(bool newStatus)
{
    m_status = newStatus;
}

Generator::~Generator()
{

}
