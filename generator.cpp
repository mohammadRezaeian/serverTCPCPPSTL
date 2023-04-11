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
        double _numbers;
        _generatedNumber = AMPLITUDE * sin(2 * PI_NUMBER * FREQUENCY * _saveInterval);
        _saveInterval += INTERVAL;
    }
    else
    {
        _saveInterval = 0;
        double _numbers = 0;
        _generatedNumber = _numbers;
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
