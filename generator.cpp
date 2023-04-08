#include "generator.h"

Generator::Generator()
{

}

string Generator::generateNumber()
{
    static float saveInterval = 0;
    string _generatedNumber;
    if(m_status)
    {
        double _numbers;
        _numbers = AMPLITUDE * sin(2 * PI_NUMBER * FREQUENCY * (saveInterval) ) + AMPLITUDE;
        saveInterval += INTERVAL;
        _generatedNumber = to_string(_numbers);
    }
    else
    {
        saveInterval = 0;
        double _numbers = 0;
        _generatedNumber = to_string(_numbers);
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
