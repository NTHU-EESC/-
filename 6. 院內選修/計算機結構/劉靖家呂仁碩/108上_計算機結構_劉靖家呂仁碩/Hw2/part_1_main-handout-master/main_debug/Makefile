XLEN ?=64

src_dir = .

RISCV_PREFIX ?= riscv$(XLEN)-unknown-elf-
RISCV_GCC ?= $(RISCV_PREFIX)gcc
RISCV_GCC_OPTS ?= -mcmodel=medany -static -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf
RISCV_LINK ?= $(RISCV_GCC) -T $(src_dir)/common/test.ld $(incs)
RISCV_LINK_MT ?= $(RISCV_GCC) -T $(src_dir)/common/test-mt.ld
RISCV_LINK_OPTS ?= -nostdlib -nostartfiles -ffast-math -lgcc -lc
RISCV_OBJDUMP ?= $(RISCV_PREFIX)objdump --disassemble-all --disassemble-zeroes --section=.text --section=.text.startup --section=.data
RISCV_SIM ?= spike

VPATH += $(addprefix $(src_dir)/, $(bmarks))
VPATH += $(src_dir)/common

#incs  += -I$(src_dir)/env -I$(src_dir)/common
incs += -I$(src_dir)/common
objs  :=

bmarks_defs   = -DPREALLOCATE=1 -DHOST_DEBUG=0


##
#
# Source files
#

	
c_src = \
	syscalls.c \
	
riscv_src = \
	crt.S \
	tmp.S \

## 
#
# Executable name
#
riscv_bin = lfsr.riscv
riscv_dump = $(riscv_bin).dump


c_objs     = $(patsubst %.c, %.o, $(c_src))
riscv_objs = $(patsubst %.S, %.o, $(riscv_src))


all: $(riscv_bin)  $(riscv_dump)


$(riscv_dump): $(riscv_bin)
	$(RISCV_OBJDUMP) $(riscv_bin) > $(riscv_dump)

$(riscv_bin) : $(c_objs) $(riscv_objs)
	$(RISCV_LINK) $(c_objs) $(riscv_objs) $(RISCV_LINK_OPTS) -o $(riscv_bin)

%.o: %.c
	$(RISCV_GCC) $(RISCV_GCC_OPTS) $(bmarks_defs) \
	             -c $(incs) $< -o $@

%.o: %.S tmp.S 
	$(RISCV_GCC) $(RISCV_GCC_OPTS) $(bmarks_defs) -D__ASSEMBLY__=1 \
	             -c $(incs) $< -o $@
tmp.S: main.S 
	sed --expression="s/SEED/17/" $< | sed --expression="s/FEEDBACK/0x800000000000000D/"  > $@

clean:
	rm -rf $(c_objs) $(riscv_objs) $(riscv_bin) $(riscv_dump) tmp.S
