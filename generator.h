#ifndef GENERATOR_H
#define GENERATOR_H
#include <string>
#include <math.h>
#include <iostream>

#define PI_NUMBER   3.14
#define FREQUENCY   0.5
#define INTERVAL    0.00555
#define AMPLITUDE   4

using namespace std;

class Generator
{
public:
    Generator();
    ~Generator();

    string generateNumber();

    void setStatus(bool newStatus);

private:
    bool m_status{false};
};

#endif // GENERATOR_H
