 org $8000

 ldaa #$80
 staa $0010

 ldaa #$02
 staa $0011
 staa $0012

 ldaa $0010
 lsra
 lsra
 lsra
 lsra
 lsra
 lsra
 lsra

 ldab $0010
 stab $000f 
 ldab $0011
 stab $0010
 ldab $0012
 stab $0011

 bclr $0011 #$01
 
 oraa $0011
 staa $0011

 jmp $8000