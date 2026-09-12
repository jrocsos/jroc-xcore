# J-Roc Stages 24-25

## Stage 24
Protected-mode foundation:
- TSS
- kernel stack metadata
- privilege selector validation
- user-entry frame
- protected user boundary API

## Stage 25
System-call and IPC foundation:
- syscall table
- syscall registration
- user-memory validation
- IPC channels
- IPC messages

## Runtime integration still required
- install the TSS descriptor into the GDT
- complete ring-3 transition
- install a real syscall entry mechanism
- save/restore user register frames
- switch process page directories
- enforce IPC permissions
- integrate IPC with scheduler/process lifecycle

These requirements are deliberately separated from the current bootable kernel.
