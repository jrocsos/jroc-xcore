# J-Roc XCore Real Core Stage

Implemented and compiled:

- Multiboot memory detection API
- Physical page allocator
- Kernel allocator foundation
- GDT setup
- IDT setup
- PIC remapping
- PIT timer programming
- IRQ foundation
- Device registry
- PS/2 keyboard access
- Process table
- PID allocation
- Scheduler foundation

The existing bootable kernel remains the protected runtime baseline.

Next integration work:

- connect GDT safely during kernel startup
- install real ISR stubs
- connect PIC/IRQ handlers
- timer-driven scheduling
- complete paging
- user/kernel privilege separation
- context switching
