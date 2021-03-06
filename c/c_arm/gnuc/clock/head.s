.text
.global _start
_start:
    b _reset    @0x0
    b .         @0x4,undef instruction
    b .         @0x8,software irq
    b .         @0xc,ins abort
    b .         @0x10,data abort
    b .         @0x14,reserve
    b _irq      @0x18,
    b .         @0x1c,fast irq

_irq:
    sub lr,lr,#4
    @stmfd sp!,{r0-r3}
    stmdb sp!,{r0-r3,lr}
    bl interrupt_f
    @ldmfd sp!,{r0-r3,pc}^
    ldmia sp!,{r0-r3,pc}^
    @^ =>spsr->cpsr

_reset:
	@关闭看门狗
	ldr r0,=0x53000000
	mov r1,#0
	str r1,[r0]

	mov sp,#4096
	@bl main
    @手动切换到irq模式
    mrs r0,cpsr
    bic r0,r0,#0x1f
    orr r0,r0,#0x12
    msr cpsr_c,r0
    mov sp,#3072

    @手动切换到svc模式,并打开中断屏蔽
    mrs r0,cpsr
    bic r0,r0,#0x9f
    orr r0,r0,#0x13
    msr cpsr_c,r0

    bl main

stop:
	b .	@=>b stop

