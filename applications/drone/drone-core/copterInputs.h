#ifndef COPTERINPUTS_H
#define COPTERINPUTS_H

#include <initializer_list>



class CopterInputs
{
public:
    enum ChannelID {
        CHANNEL_0,
        CHANNEL_THROTTLE = CHANNEL_0,
        CHANNEL_1,
        CHANNEL_ROLL     = CHANNEL_1,
        CHANNEL_2,
        CHANNEL_PITCH    = CHANNEL_2,
        CHANNEL_3,
        CHANNEL_YAW      = CHANNEL_3,

        CHANNEL_CONTROL_LAST,

        CHANNEL_4 = CHANNEL_CONTROL_LAST,
        CHANNEL_5,
        CHANNEL_6,
        CHANNEL_7,

        CHANNEL_LAST
    };

    int axis[CHANNEL_LAST];           //here we put CH walue, btw it must not be equal sticks order

    CopterInputs();

    CopterInputs(std::initializer_list<int> list)
    {
        int i = 0;
        auto it = list.begin();
        for (; (it != list.end()) && (i < CHANNEL_LAST); i++, it++)
        {
            axis[i] = *it;
        }

    }

    static const char *getName(ChannelID value);
    void print();

};



#endif // COPTERINPUTS_H
