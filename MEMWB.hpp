#ifndef MEMWB_H
#define MEMWB_H


class MEMWB{
    public:
        MEMWB();

        string getIr();
        string setIr();
        int getALUOut();
        void setALUOut(int val);

        int getLMemoryData();
        void setLMemoryData(int val);

        int getRegWrite();
        void setRegWrite(int val);

        int getMemtoReg();
        void setMemtoReg(int val);



    private:
        string ir;
        int ALUOut;
        int LMemoryData;
        int RegWrite;
        int MemtoReg;
};

#endif // MEMWB_H
