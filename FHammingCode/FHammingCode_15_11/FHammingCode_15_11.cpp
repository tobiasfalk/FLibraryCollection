#include "FHammingCode_15_11.h"

std::bitset<15> FHammingCode_15_11::encode(std::bitset<11> Data)
{
    std::bitset<15> Message = (0);
    //Data
    Message[2] = Data[0];
    Message[4] = Data[1];
    Message[5] = Data[2];
    Message[6] = Data[3];
    Message[8] = Data[4];
    Message[9] = Data[5];
    Message[10] = Data[6];
    Message[11] = Data[7];
    Message[12] = Data[8];
    Message[13] = Data[9];
    Message[14] = Data[10];

    //Parity
    Message[0] = (Data[4] ^ Data[8] ^ Data[12] ^ Data[2] ^ Data[6] ^ Data[10] ^ Data[14]);
    Message[1] = (Data[5] ^ Data[9] ^ Data[13] ^ Data[2] ^ Data[6] ^ Data[10] ^ Data[14]);

    Message[3] = (Data[4] ^ Data[5] ^ Data[6] ^ Data[11] ^ Data[12] ^ Data[13] ^ Data[14]);
    Message[7] = (Data[8] ^ Data[9] ^ Data[10] ^ Data[11] ^ Data[12] ^ Data[13] ^ Data[14]);
    return Message;
}

std::bitset<11> FHammingCode_15_11::decode(std::bitset<15> Message)
{
    std::bitset<16> WMessage(0);
    std::vector<std::bitset<4>> pos;
    std::bitset<4> error(0);
    std::bitset<11> Data(0);
    for(int i = 0; i < WMessage.size(); i++)
    {
        int x = 0 + 1;
        WMessage[x] = Message[i];
    }

    for(int i = 0; i < WMessage.size(); i++)
    {
        if(WMessage[i] == 1)
        {
            pos.push_back(i);
        }
    }

    for(int i = 0; i < error.size(); i++)
    {
        for(int x = 0; x < pos.size(); x++)
        {
            error[i] = pos[x][i];
        }
    }

    WMessage[error.to_ulong()] = (WMessage[error.to_ulong()] ^ 1);

    Data[0] = WMessage[3];
    Data[1] = WMessage[5];
    Data[2] = WMessage[6];
    Data[3] = WMessage[7];
    Data[4] = WMessage[9];
    Data[5] = WMessage[10];
    Data[6] = Message[11];
    Data[7] = Message[12];
    Data[8] = Message[13];
    Data[9] = Message[14];
    Data[10] = Message[15];

    return Data;
}
