# J-Roc Stages 22-23

## Stage 22
- Interrupt frame structure
- Interrupt frame accounting
- Interrupt registration
- Interrupt dispatch API
- User/kernel interrupt-origin detection

## Stage 23
- CPU register context
- Context initialization
- Context-switch assembly ABI
- Scheduler handoff state
- Context-switch decision logic

The currently bootable kernel remains unchanged.

Full live preemption still requires:
- interrupt-frame capture from the CPU
- register save/restore
- kernel stack switching
- TSS
- timer-to-scheduler integration
