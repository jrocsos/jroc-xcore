# J-Roc XCore 1.0 System Manifest

## Core
Kernel
CPU
Memory
Paging foundation
Interrupt foundation
Timer
Drivers
Hardware

## Process
Process model
Scheduler
Context structures
System calls
IPC
Userspace foundation

## Storage
Block layer
Disk abstraction
VFS
Filesystem API

## Network
Device layer
Ethernet API
IP
TCP
UDP
DNS
Socket API

## Security
Identity
Permissions
Sandbox
Audit
Crypto API

## Services
Service manager
Logging
Updates
Diagnostics

## User Experience
Userspace
Shell
Desktop
Display
Window manager
Settings
File manager
Notifications
Themes

## Developer Platform
SDK
Headers
Libraries
Compiler interface
Debugger
Tester
Profiler

## Ecosystem
Apps
Package database
Package installer
Package updater
Store interface
AI interface
Cloud interface
Accounts
Sync
Backup

## Release
Installer
Recovery
Rollback
Release manager
Health checks

## Important
A subsystem marked as an API/foundation is structurally integrated but may still
require hardware-specific or production-scale implementation before being treated
as complete.
