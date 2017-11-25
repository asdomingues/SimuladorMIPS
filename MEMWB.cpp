#include "MEMWB.hpp"

MEMWB::MEMWB(){
    ir = "";
    RegWrite = 0;
    MemtoReg = 0;
}

string getir(){
    return ir;
}

int getALUOut(){
    return ALUOut;
}

void setALUOut(int val){
    val = ALUOut;
}

int getLMemoryData(){
    return LMemoryData;
}

void setLMemoryData(int val){
    LMemoryData = val;
}

int MEMWB::getRegWrite(){
    return RegWrite;
}

void MEMWB::setRegWrite(int val){
    RegWrite = val;
}

int MEMWB::getMemtoReg(){
    return MemtoReg;
}

void MEMWB::setMemtoReg(int val){
    MemtoReg = val;
}
