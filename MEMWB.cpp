#include "MEMWB.hpp"

MEMWB::MEMWB(){
    ir = "";
    RegWrite = 0;
    MemtoReg = 0;
}

string MEMWB::getir(){
    return ir;
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

int MEMWB::get_reg_address(){
    return wr_address;
}
void MEMWB::set_reg_address(int val){
    wr_address = val;
}