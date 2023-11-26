#pragma once

class Egyenleg
{
    unsigned egyenleg;
public:
    Egyenleg();
    Egyenleg& operator+=(const Egyenleg& other);
    unsigned getEgyenleg() const;
    void setEgyenleg(unsigned ujegyenleg);

};
