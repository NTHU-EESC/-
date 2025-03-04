PSR+

.protect
.lib 'cic018.l' TT
.unprotect
.option post acout=0 accurate
.include "My_op.spi" 

.param rload=10k cload=80p supplyp=1.8 supplyn=0 comon='supplyp/2'

Xop  iref vdd vinn vinp vocm von vop vss AICOP
rload1 von 0 rload
rload2 vop 0 rload
cload1 von 0 cload
cload2 vop 0 cload

vdd vdd 0 dc supplyp ac 1
vgnd vss 0 dc supplyn
vocm vocm 0 dc comon

vinp vinp 0 dc comon
vinn vinn 0 dc comon

Iref vdd iref 63u

.ac dec 10 10 1g

.meas ac psp_in_db find vdb(vop) at=10k
.alter
.lib 'cic018.l' FF
.alter
.lib 'cic018.l' SS
.alter
.lib 'cic018.l' SF
.alter
.lib 'cic018.l' FS
.end
