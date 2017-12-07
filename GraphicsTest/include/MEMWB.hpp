#ifndef MEMWB_H
#define MEMWB_H

#include <string>

using namespace std;

class MEMWB{
    public:
        MEMWB();

        string getir();
        void setir(string ir);
        int getALUOut();
        void setALUOut(int val);

        int getLMemoryData();
        void setLMemoryData(int val);

        bool getRegWrite();
        void setRegWrite(bool val);

        bool getMemtoReg();
        void setMemtoReg(bool val);

        int get_reg_address();
        void set_reg_address(int val);

        void reset();


    private:
        string ir;
        int ALUOut;
        int LMemoryData;
        bool RegWrite;
        bool MemtoReg;
        int wr_address;
};

#endif // MEMWB_H
