;==================================================
;      Definitions the Master Boot Record
;--------------------------------------------------
; 2020.3.30  ValjeanTheWolfie  Create
;==================================================
%define CR 0x0d
%define LF 0x0a

; ---------------------------------
;          Disk layout
; ---------------------------------
HD_SECTOR_GDT                    equ 2      ; BIOS INT uses CHS mode, whose sector starts from 1
HD_SECTOR_LOADER                 equ 4
HD_LBA_KERNEL                    equ 8 - 1  ; LBA starts from 0

HD_SECTOR_CNT_GDT                equ HD_SECTOR_LOADER - HD_SECTOR_GDT
HD_SECTOR_CNT_LOADER             equ HD_LBA_KERNEL    - HD_SECTOR_LOADER
HD_SECTOR_CNT_KERNEL             equ 255


; ---------------------------------
;         Memory layout
; ---------------------------------
BASE_ADDRESS_UNLIMITED           equ 0
BASE_ADDRESS_GDT                 equ 0xE00
BASE_ADDRESS_PAGE_DIR            equ 0x1000
BASE_ADDRESS_PAGE_TABLE_SYS      equ 0x2000
BASE_ADDRESS_LOADER              equ 0x8000
BASE_ADDRESS_STACK               equ 0x70000
BASE_ADDRESS_VIDEO_MEMORY        equ 0xb8000
BASE_ADDRESS_READ_KERNEL_BUFF    equ 0x100000

VIRTUAL_ADDRESS_KERNEL           equ 0xC0010000   ; 3GiB space

LIMIT_UNLIMITED                  equ 0xFFFFF
LIMIT_STACK                      equ 23      ;96 Kib
LIMIT_VIDEO                      equ 7       ;32 KiB

SELECTOR_GDT                     equ (1 << 3)
SELECTOR_VIDEO                   equ (2 << 3)
SELECTOR_LOADER_CODE             equ (3 << 3)
SELECTOR_LOADER_DATA             equ (4 << 3)
SELECTOR_KERNEL_CODE             equ (3 << 3)

GDT_TABLE_SIZE                   equ 512  ; 512 Bytes, i.e. 64 entries

STACK_TOP_PROTECT_MODE           equ 0x80000

