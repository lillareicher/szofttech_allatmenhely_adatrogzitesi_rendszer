#ifndef EGYENLEG_H
#define EGYENLEG_H


class Egyenleg
{
    unsigned egyenleg;
public:
    Egyenleg();
    Egyenleg& operator+=(const Egyenleg& other);
    unsigned getEgyenleg() const;
    void setEgyenleg(unsigned ujegyenleg);

};

#endif // EGYENLEG_H