section .data
    format db 'Hello, Holberton', 0

section .text
    global main
    extern printf

main:
    ; Prepare arguments for printf: edi = address of format string
    mov edi, format

    ; Clear eax register (return value of printf)
    xor eax, eax

    ; Call printf function
    call printf

    ; Set return value to 0
    mov eax, 0

    ; Return from main
    ret
