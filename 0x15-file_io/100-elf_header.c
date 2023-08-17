#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ELF_MAGIC_SIZE 16

typedef struct {
    uint8_t magic[ELF_MAGIC_SIZE];
    uint8_t class;
    uint8_t data;
    uint8_t version;
    uint8_t abi;
    uint8_t abi_version;
    uint8_t _pad[7];
    uint16_t type;
    uint16_t _pad2;
    uint32_t _pad3;
    uint64_t entry_point;
} ElfHeader;

void print_elf_header(const ElfHeader *header) {
    printf("ELF Header:\n");
    printf("  Magic:");
    for (int i = 0; i < ELF_MAGIC_SIZE; ++i) {
        printf(" %02x", header->magic[i]);
    }
    printf("\n");
    printf("  Class:                             ");
    if (header->class == 1) {
        printf("ELF32\n");
    } else if (header->class == 2) {
        printf("ELF64\n");
    } else {
        printf("<unknown>\n");
    }
    printf("  Data:                              ");
    if (header->data == 1) {
        printf("2's complement, little endian\n");
    } else if (header->data == 2) {
        printf("2's complement, big endian\n");
    } else {
        printf("<unknown>\n");
    }
    printf("  Version:                           %d (current)\n", header->version);
    printf("  OS/ABI:                            ");
    switch (header->abi) {
        case 0: printf("UNIX - System V\n"); break;
        case 6: printf("UNIX - Solaris\n"); break;
        /* Add more cases for other OS/ABI values if needed*/
        default: printf("<unknown: %d>\n", header->abi); break;
    }
    printf("  ABI Version:                       %d\n", header->abi_version);
    printf("  Type:                              %d\n", header->type);
    printf("  Entry point address:               0x%llx\n", (unsigned long long)header->entry_point);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 98;
    }

    ElfHeader header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        fprintf(stderr, "Error reading ELF header\n");
        close(fd);
        return 98;
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}

