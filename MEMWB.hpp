#ifndef MEMWB_H
#define MEMWB_H

#include <string>

using namespace std;

class MEMWB{
    public:
        MEMWB();

        string getir();

        int getALUOut();
        void setALUOut(int val);

        int getLMemoryData();
        void setLMemoryData(int val);

        int getRegWrite();
        void setRegWrite(int val);

        int getMemtoReg();
        void setMemtoReg(int val);

        int get_reg_address();
        void set_reg_address(int val);



    private:
        string ir;
        int ALUOut;
        int LMemoryData;
        int RegWrite;
        int MemtoReg;
        int wr_address;
};

#endif // MEMWB_H
