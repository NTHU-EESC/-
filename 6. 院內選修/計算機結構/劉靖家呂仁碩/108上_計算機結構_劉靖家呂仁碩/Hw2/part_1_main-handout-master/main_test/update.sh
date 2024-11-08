FILE=../main_debug/main.S
if ! test -f "$FILE"; then
    echo "$FILE does not exists!"
    exit 1
fi

fl=lfsr.S
cp ../main_debug/main.S $fl
sed -i 's/seed:/#seed:/1' $fl 
sed -i 's/feedback:/#feedback:/1' $fl 
sed -i 's/\.global main/.global lfsr64/1' $fl 
sed -i 's/main:/lfsr64:;addi  sp, sp, -40;sd    ra, 32(sp);sd    s3, 24(sp);sd    s2, 16(sp);sd    s1,  8(sp);sd    s0,  0(sp);/1' $fl 
tac $fl | sed 's/ret//1' | tac > "a.tmp"
mv "a.tmp" $fl
tac $fl | sed 's/li\s\+a0,\s\+0/ld    s0,  0(sp);ld    s1,  8(sp);ld    s2, 16(sp);ld    s3, 24(sp);ld    ra, 32(sp);addi  sp, sp, 40;ret#return/1' | tac > "a.tmp"
tr ';' '\n' < "a.tmp" > "${fl}.tmp"
perl -p -i -e "s/\r//g" "${fl}.tmp"
rm a.tmp
mv "${fl}.tmp" $fl







