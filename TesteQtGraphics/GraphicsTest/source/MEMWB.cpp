#include "include/MEMWB.hpp"

MEMWB::MEMWB(){
    ir = "";
    RegWrite = 0;
    MemtoReg = 0;
    ALUOut = 0;
    LMemoryData = 0;
    wr_address = 0;
}

string MEMWB::getir(){
    return ir;
}

void MEMWB::setir(string ir){
    this->ir=ir;
}

int MEMWB::getALUOut(){
    return ALUOut;
}

void MEMWB::setALUOut(int val){
    ALUOut = val;
}

int MEMWB::getLMemoryData(){
    return LMemoryData;
}

void MEMWB::setLMemoryData(int val){
    LMemoryData = val;
}

bool MEMWB::getRegWrite(){
    return RegWrite;
}

void MEMWB::setRegWrite(bool val){
    RegWrite = val;
}

bool MEMWB::getMemtoReg(){
    return MemtoReg;
}

void MEMWB::setMemtoReg(bool val){
    MemtoReg = val;
}

int MEMWB::get_reg_address(){
    return wr_address;
}
void MEMWB::set_reg_address(int val){
    wr_address = val;
}
