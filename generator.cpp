#include "generator.h"

Generator::Generator()
{

}

string Generator::generateNumber()
{
    static float _saveInterval = 0;
    string _generatedNumber;
    if(m_status)
    {
        double _numbers;
        _numbers = AMPLITUDE * sin(2 * PI_NUMBER * FREQUENCY * (_saveInterval) );
         cout << "is here\t" << _numbers;
        _saveInterval += INTERVAL;
        _generatedNumber = to_string(_numbers);
    }
    else
    {
        _saveInterval = 0;
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
