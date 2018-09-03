#define MEMSIZE                         0xffff

uint memory[MEMSIZE];

void printRegister(uint *rs){
  cout << hex << *rs << ", " << dec <<  *rs << std::endl;
}

uint ADD(uint *rd, uint *rs, uint *rn){
  *rd = *rs + *rn;
}

uint ADD(uint *rd, uint *rs, uint rn){
  *rd = *rs + rn;
}

uint SUB(uint *rd, uint *rs, uint *rn){
  *rd = *rs - *rn;
}

uint SUB(uint *rd, uint *rs, uint rn){
  *rd = *rs - rn;
}

uint SUB(uint *rd, uint rs, uint rn){
  *rd = rs - rn;
}

uint RSB(uint *rd, uint *rs, uint *rn){
  *rd = *rn - *rs;
}

uint RSB(uint *rd, uint *rs, uint rn){
  *rd = rn - *rs;
}

uint RSB(uint *rd, uint rs, uint rn){
  *rd = rn - rs;
}

uint AND(uint *rd, uint *rs){
  *rd = *rd & *rs;
}

uint AND(uint *rd, uint rs){
  *rd = *rd & rs;
}

uint NAND(uint *rd, uint *rs){
  *rd = ~(*rd & *rs);
}

uint NAND(uint *rd, uint rs){
  *rd = ~(*rd & rs);
}

uint OR(uint *rd, uint *rs){
  *rd = *rd | *rs;
}

uint NOR(uint *rd, uint *rs){
  *rd = ~(*rd | *rs);
}

uint XOR(uint *rd, uint *rs){
  *rd = *rd ^ *rs;
}

uint XNOR(uint *rd, uint *rs){
  *rd = ~(*rd ^ *rs);
}

uint BIC(uint *rd, uint *rs){
  *rd = *rd & ~(*rs);
}

uint BIC(uint *rd, uint rs){
  *rd = *rd & ~(rs);
}

uint MOV(uint *rd, uint rs){
  *rd = rs;
}

uint MOV(uint *rd, uint *rs){
  *rd = *rs;
}

uint MOV(uint *rd, uint *rs, uint offset){
  *rd = rs[offset];
}

uint LDR(uint *rd, uint memoryAddr){
  *rd = memory[memoryAddr];
}

uint STR(uint memoryAddr, uint *rs){
  memory[memoryAddr] = *rs;
}

uint LDRB(uint *rd, uint memoryAddr){
  *rd = (memory[memoryAddr] & 0xff);
}

uint STRB(uint memoryAddr, uint *rs){
  memory[memoryAddr] = (*rs & 0xff);
}
