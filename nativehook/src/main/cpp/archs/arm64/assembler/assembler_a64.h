//
// Created by swift on 2019/5/11.
//

#ifndef SANDHOOK_NH_ASSEMBLER_A64_H
#define SANDHOOK_NH_ASSEMBLER_A64_H

#include <assembler.h>
#include "register_a64.h"
#include "inst_arm64.h"

namespace SandHook {
    namespace Assembler {

        class AssemblerA64 {

        public:
            AssemblerA64(CodeBuffer* codeBuffer);
            void* finish();


            void Emit(Unit<Base>& unit);


            void MoveWide(RegisterA64& rd, INST_A64(MOV_WIDE)::OP op, U64 imme, INST_A64(MOV_WIDE)::Shift shift);

            void Movz(RegisterA64& rd, U64 imme, INST_A64(MOV_WIDE)::Shift shift);
            void Movk(RegisterA64& rd, U64 imme, INST_A64(MOV_WIDE)::Shift shift);
            void Movn(RegisterA64& rd, U64 imme, INST_A64(MOV_WIDE)::Shift shift);

            void Mov(WRegister& rd, U32 imme);

            void Mov(XRegister& rd, U64 imme);



        private:
            CodeContainer codeContainer = CodeContainer(nullptr);
        };

    }
}

#endif //SANDHOOK_NH_ASSEMBLER_A64_H
