#ifndef SINKABLE_H
#define SINKABLE_H


class Sinkable
{
public:
    virtual bool isFloated()=0;
    virtual void sink()=0;
    virtual ~Sinkable();
};

#endif // SINKABLE_H
