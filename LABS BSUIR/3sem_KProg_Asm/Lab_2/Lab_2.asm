 org $8000

 ldaa #$10
 staa $0000
 ldaa #$10
 staa $0001
 ldaa #$10
 staa $0002
 ldaa #$10
 staa $0003

 ldd $0002
 subd $0000
 aba
 
 ldab #$00
  ;staa $0100
 psha

 ldx #$10 // обнулить флаг нулевого значения
 
 tpa
 psha
 ;staa $0101
 pulx
 pshx
 pshx
 pula
 pula 
;ldaa $0100
 cba
 tpa
 pulb
 ;ldab $0101
 sba
 jmp $8000